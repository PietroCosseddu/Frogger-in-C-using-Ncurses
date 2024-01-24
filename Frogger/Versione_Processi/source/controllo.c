#include "include.h"
#include "extern.h"

void f_controllo(int p[2], int pc[2], int pt[2], int p_2[2], int p_3[2]){  

    close(p[1]);

    srand(getpid());//inizializzazione del seed random
    
    //dichiarazione degli oggetti che verranno utilizzati 
    posizione data, frog, bull, time, oldfrog;
    //le posizioni della rana sono inizializzate al centro del marciapiede
    frog.y = MAXY-9;
    frog.x = MAXX/2;

    posizione logs[N_TRONCHI];
    for (int i = 0; i < N_TRONCHI; i++){ //inizialmente tutti i tronchi hanno la flag false ovvero non hanno un nemico sopra
        logs[i].flag = false;
    }

    _Bool enemy_block[N_TRONCHI] = {false, false, false, false, false}; //array di booleani usato per non far spownare un nemico in un tronco che ha già la rana sopra

    posizione enemy_bullets[N_TRONCHI];
    posizione cars[N_CARS];
    for (int i = 0; i < N_CARS; i++){
        cars[i].x = -10;
    }

    posizione reset_bullets; //oggetto che serve per comunicare al tronco che il proiettile del nemico deve essere resettato in quanto una nuova manche sta rincominciando
    reset_bullets.flag = false; 

    posizione reset_bull;
    reset_bull.flag = false;

    oldfrog.y=-1;

    posizione oldlog[N_TRONCHI]; //serve per tracciare la vecchia posizione per ogni tronco

    //inizializzazione delle vite e del punteggio
    int punteggio = 0;
    int vite = 5;

    _Bool check_bull_enemy_bull[N_TRONCHI] = {false, false, false, false, false};
    _Bool check_enemy[N_TRONCHI] = {false, false, false, false, false}; //array di booleani utilizzato per capire quale nemico è stato colpito da un proiettile e quindi deve despownare
    _Bool check_enemy_bull_hit[N_TRONCHI] = {false, false, false, false, false}; //array di booleani utlizzato per smettere di printare un proiettile di un nemico quando questo subisce una collisione
    _Bool tane[N_TANE] = {true, true, true, true, true}; //array di booleani che segna quali sono le tane non ancora occupate, quando diventano tutte false il gioco finisce
    _Bool bull_hit = false; //variabile booleana usata per non stampare a schermo il proiettile quando avviene una collisione 
    _Bool new_manche = false; //variabile booleana inizialzzata a false, quanto diventa true significa che deve incominciare una nuova manche
    _Bool hit_flag = false; //flag che termina il controllo tra proiettile della rana e nemici una volta che un nemico viene colpito

    int tane_riempite = 0; //counter delle tane che sono state riempite, quando arriva a 5 il gioco termina con una vittoria

    time.x = n_tempo+5;//inizializzazione del tempo 

    char reason[100] = "nessuna ragione"; //ragione del cambio della manche 

    pid_t HitSound;
    pid_t StartSound;
    pid_t SplashSound;
    pid_t CarHit;
    pid_t ping;
    pid_t win;
    pid_t game_over;

    StartSound = fork(); //musica di caricamento del gioco 
    if(StartSound == 0){
        startSound(p);
    }

    controllo_macchine_in_generazione(p, p_2); //viene lanciata la funzione che controlla le posizioni delle macchine e le riinizializza finché non ci sono collisioni, una volta che questa termina con esito positivo si può entrare nel while e il gioco ha inizio
    
    while(true){

        erase();
        colorazione_background(); //colorazione dell'area di gioco
        colorazione_tane(tane); //coloriazione delle tane

        //read dalla pipe principale 
        read(p[0], &data,sizeof(posizione));
        if (data.ID == 'R'){
            frog = data;
        }
        else if (data.ID == 'P'){
            bull = data;
        }
        else if(data.ID == 't'){
            time = data;
        }
        else if (data.ID == 20){
            logs[0] = data;
        }
        else if (data.ID == 21){
            logs[1] = data;
        }
        else if (data.ID == 22){
            logs[2] = data;
        }
        else if (data.ID == 23){
            logs[3] = data;
        }
        else if (data.ID == 24){
            logs[4] = data;
        }
        else if (data.ID == 200){
            enemy_bullets[0] = data;
        }
        else if (data.ID == 210){
            enemy_bullets[1] = data;
        }
        else if (data.ID == 220){
            enemy_bullets[2] = data;
        }
        else if (data.ID == 230){
            enemy_bullets[3] = data;
        }
        else if (data.ID == 240){
            enemy_bullets[4] = data;
        }
        else if(data.ID == 1)
            cars[1] = data;
        else if(data.ID == 2)
            cars[2] = data;
        else if(data.ID == 3)
            cars[3] = data;
        else if(data.ID == 4)
            cars[4] = data;
        else if(data.ID == 5)
            cars[5] = data;
        else if(data.ID == 6)
            cars[6] = data;
        else if(data.ID == 7)
            cars[7] = data;
        else if(data.ID == 8)
            cars[8] = data;
        else if(data.ID == 9)
            cars[9] = data;
        else if(data.ID == 0)
            cars[0] = data;
        
        //RANA SUL FIUME E SUI TRONCHI
//*********************************************************************************************************************************************************************

        //CHECK RANA SCENDE DAL FIUME
        if(oldfrog.y==logs[0].y && frog.y==PRATO){
            frog.flag=true; 
            write(pc[1], &frog, sizeof(posizione)); //se la rana scende dal fiume, si scrive alla funzione rana di cambiare la posizione di questa con quella nuova
            frog.flag=false; 
        }
        
        //CHECK RANA SUL FIUME
        if(frog.y<=logs[0].y && frog.y>=logs[4].y){  //controllo che la rana sia nell'area del fiume

            frog.flag=true; //il flag è settato a true perché la rana deve cambiare posizione ogni iterazione
            
            for(int i=0; i<N_TRONCHI; i++){
                if(logs[i].x != oldlog[i].x && frog.y == logs[i].y){ //controllo che il tronco abbia cambiato posizione e che la rana sia su un certo tronco 
                    frog.x=frog.x+logs[i].x-oldlog[i].x; //scostamento della rana sul tronco 
                    //CHECK RANA SUI TRONCHI
                    if(frog.y==logs[i].y && (frog.x<logs[i].x || frog.x>=logs[i].x+8)){ //rana scende dal tronco e cade sul fiume

                        SplashSound = fork();
                        if(SplashSound == 0){
                            splashSound(p);
                        }

                        frog.x=MAXX/2;
                        frog.y=MAXY-9;
                        vite-=1;
                        new_manche = true;

                        strcpy(reason, "La rana è caduta nel fiume");
                    }
                    //write che serve per comunicare alla funzione rana la nuova posizione di questa ogni volta che cambia con il movimento del tronco, serve anche in caso la rana scenda dal tronco e cada nel fime
                    write(pc[1],&frog, sizeof(posizione)); 
                }
            }
        }
        

//*********************************************************************************************************************************************************************

        //CONTROLLO CHE SE LA RANA SALE SU UN TRONCO CON SENZA NEMICO QUESTO NON POSSA SPOWNARE QUANDO QUESTA é SALITA
//*********************************************************************************************************************************************************************

        for (int i = 0; i < N_TRONCHI; i++){
            //se la rana è salita su un tronco vuoto in questo tronco il nemico non può spownare finché la rana non scende 
            if (oldlog[i].flag == false && logs[i].flag == true && frog.y == logs[i].y && oldfrog.y == logs[i].y){
                enemy_block[i] = true;
            }
            //quando la rana cambia tronco il blocco per il nemico sparisce
            if (frog.y != oldfrog.y){
                enemy_block[i] = false;
            }
            if(enemy_block[i] == true){
                logs[i].flag = false;
            }
        }

        //AGGIORNAMENTO OLDLOG e OLDFROG
        for(int i=0; i<5; i++){ 
            oldlog[i]=logs[i]; //in oldlog vengono salvati i dati del tronco per confrontarli nelle iterazioni successive
        }
        oldfrog=frog;//aggiorno oldfrog utilizzato nel controllo quando la rana passa dal tronco al prato 


//*********************************************************************************************************************************************************************

        //COLLISIONI TRA PROIETTILE DELLA RANA E NEMICI SUI TRONCHI
//*********************************************************************************************************************************************************************
        for (int i = 0; i < N_TRONCHI; i++){
            if(hit_flag == false){ //controllo che non ci siano cià state collisioni con i nemici con questo proiettile, un proiettile può uccidere solo un nemico
                if (logs[i].flag == true && check_enemy[i] == false){ //fa il controllo solo dei tronchi che hanno nemici 
                    if ((bull.x == logs[i].x +4 || bull.x == logs[i].x +5 || bull.x == logs[i].x+6 || bull.x == logs[i].x+7) && (bull.y == logs[i].y+2 || bull.y == logs[i].y+1 || bull.y == logs[i].y)){
                        check_enemy[i] = true; //segna nell'array booleano che il nemico di quel tronco è stato eliminato e potrà respownare solo al termine della manche
                        bull_hit = true; //il proiettile ha fatto una collisione con un nemico e non deve essere più stampato a schermo
                        punteggio += 50; //per ogni nemico ucciso il punteggio aumenta di 50
                        hit_flag = true; //flag che ritorna false soltanto quando il proiettile esce dallo schermo e quindi ne viene flag un'altro

                        HitSound = fork(); //creo un processo per il suono
                        if(HitSound == 0){
                            playSound(p);
                        }
                    }
                }
            }
            if (bull.y <= 2){ //controllo che il proiettile sia uscito dallo schermo
                hit_flag = false;
            }
        }

        //se c'è stata una collisione tra proiettile e nemico non lo faccio più spownare
        for (int i = 0; i < 5; i++){
            if(check_enemy[i] == true){
                logs[i].flag = false;
            }
        }
//*********************************************************************************************************************************************************************


        //COLLISIONE TRA I PROIETTILI SPARATI DAI NEMICI E LA RANA
//*********************************************************************************************************************************************************************
        
        //controllo per la collisione tra i proiettili dei nemici e la rana
        for (int i = 0; i < N_TRONCHI; i++){
            if((enemy_bullets[i].x == frog.x || enemy_bullets[i].x == frog.x+1 || enemy_bullets[i].x == frog.x+2) && enemy_bullets[i].y == frog.y && check_enemy_bull_hit[i] == false && enemy_block[i] == false && enemy_bullets[i].flag == true && logs[i].flag == true){ //non faccio il controllo sui proiettili che hanno già hittato la rana
                //in caso di collisione la rana torna al punto di partenza e la manche deve ricominciare
                frog.x=MAXX/2;
                frog.y=MAXY-9;
                frog.flag = true;
                write(pc[1],&frog, sizeof(posizione)); //scrivo alla funzione rana le nuove posizioni che deve assumere la rana
                frog.flag = false;

                check_enemy_bull_hit[i] = true; //nell'array di booleani segno che il proiettile dopo che ha hittato la rana non deve più essere flag 
                vite-=1;
                new_manche = true; //deve incominciare una nuova manche
                strcpy(reason, "La rana è stata colpita da un proiettile dei nemici");
                break;
            }
        }

        //se c'è stata una collisione non faccio più stampare quel proiettile

        for(int i = 0; i < N_TRONCHI; i++){
            if(check_enemy_bull_hit[i] == true){
                enemy_bullets[i].flag = false;
            }
        }

        for(int i = 0; i <N_TRONCHI; i++){
            if(enemy_bullets[i].y == MAXY-7){
                check_enemy_bull_hit[i] = false;
            }
        }

//*********************************************************************************************************************************************************************


        //CONTROLLO SE LA RANA SALE SU UN TRONCO CON GIÀ UN NEMICO SOPRA
//*********************************************************************************************************************************************************************
        //se la rana sale su un tronco con il nemico torna al punto di partenza
        for(int i=0; i<N_TRONCHI; i++){
            if (logs[i].flag == true && frog.y == logs[i].y && enemy_block[i] == false){ //guardo la flag del tronco, se è true allora c'è un nemico sopra, poi controllo la y della rana

                frog.x=MAXX/2;
                frog.y=MAXY-9;
                frog.flag = true;
                write(pc[1],&frog, sizeof(posizione)); //comunico alla funzione rana le sue nuove coordinate
                frog.flag = false;

                vite-=1; //diminuisco la vita 
                new_manche = true; //una nuova manche deve essere iniziata
                strcpy(reason,"La rana ha tentato di salire su un tronco con già un nemico sopra");
                break;
            }
        }
//*********************************************************************************************************************************************************************


        //CONTROLLO COLLISIONE TRA PROIETTILE DELLA RANA E PROIETTILE DI UN NEMICO
//*********************************************************************************************************************************************************************

        for(int i = 0; i < N_TRONCHI; i++){
            if(bull.y == enemy_bullets[i].y && bull.x == enemy_bullets[i].x){
                enemy_bullets[i].y = -50;
                check_enemy_bull_hit[i] = true;
                bull_hit = true;
            }
        }

//*********************************************************************************************************************************************************************


        //CONTROLLO COLLISIONE TRA RANA E MACCHINE
//*********************************************************************************************************************************************************************

        for(int i = 0; i < N_CARS; i++){
            if (cars[i].x >= BORDER && ((cars[i].x+8 <= MAXX && cars[i].flag == false) || (cars[i].flag == true && cars[i].x+6 <= MAXX))){  //viene fatto prima un controllo sul fatto che la macchina sia stampata a schermo, se non è stampata non controllo le collisioni con quella macchina
                //contollo la collisione con la rana se il veicolo è un camion o una macchina usando la flag
                if (frog.y == cars[i].y && frog.x+2 >= cars[i].x && frog.x <= cars[i].x+8 && cars[i].flag == false){
                    frog.x=MAXX/2;
                    frog.y=MAXY-9;
                    frog.flag = true;
                    write(pc[1],&frog, sizeof(posizione)); //comunico alla funzione rana le sue nuove coordinate
                    frog.flag = false;
                    vite -= 1;
                    new_manche = true; //inizio una nuova manche

                    CarHit = fork();
                    if (CarHit == 0){
                        car_hitSound(p);
                    }

                    strcpy(reason,"La rana è stata colpita da un camion");
                    break;
                }
                else if(frog.y == cars[i].y && frog.x+2 >= cars[i].x && frog.x <= cars[i].x+6 && cars[i].flag == true){
                    frog.x=MAXX/2;
                    frog.y=MAXY-9;
                    frog.flag = true;
                    write(pc[1],&frog, sizeof(posizione)); //comunico alla funzione rana le sue nuove coordinate
                    frog.flag = false;
                    vite -= 1; 
                    new_manche = true; //inizio una nuova manche

                    CarHit = fork();
                    if (CarHit == 0){
                        car_hitSound(p);
                    }

                    strcpy(reason,"La rana è stata colpita da una macchina");
                    break;
                }
            }
        }
//*********************************************************************************************************************************************************************




        //CONTROLLO COLLISIONE TRA PROIETTILI (DEI NEMICI E DELLA RANA E MACCHINE)
//*********************************************************************************************************************************************************************


        for(int i = 0; i < N_CORSIE; i++){ //nel primo for vengono fatti scorrere tutti i proiettili dei nemici
            for (int j = 0; j < N_CARS; j++){ //nel secondo for vengono fatti scorrere tutte le macchine

                if (cars[j].x >= BORDER && ((cars[j].x+8 <= MAXX && cars[j].flag == false) || (cars[j].flag == true && cars[j].x+6 <= MAXX))){  //viene fatto prima un controllo sul fatto che la macchina sia stampata a schermo, se non è stampata non controllo le collisioni con quella macchina

                    if (enemy_bullets[i].y == cars[j].y && enemy_bullets[i].x >= cars[j].x && enemy_bullets[i].x <= cars[j].x+CAMION_LENGTH && cars[j].flag == false){
                        enemy_bullets[i].y = -50;
                        check_enemy_bull_hit[i] = true;
                    }
                    else if(enemy_bullets[i].y == cars[j].y && enemy_bullets[i].x >= cars[j].x && enemy_bullets[i].x <= cars[j].x+CAR_LENGTH && cars[j].flag == true){
                        enemy_bullets[i].y = -50;
                        check_enemy_bull_hit[i] = true;
                    }
                }   
            }
        }

        //controllo collisione tra proiettile della rana e macchina

        for (int i = 0; i < N_CARS; i++){
            if (cars[i].x >= BORDER && ((cars[i].x+CAMION_LENGTH <= MAXX && cars[i].flag == false) || (cars[i].flag == true && cars[i].x+CAR_LENGTH <= MAXX))){  //viene fatto prima un controllo sul fatto che la macchina sia stampata a schermo, se non è stampata non controllo le collisioni con quella macchina

                if ((bull.y == cars[i].y || bull.y == cars[i].y+1 || bull.y == cars[i].y+2) && bull.x >= cars[i].x && bull.x <= cars[i].x+CAMION_LENGTH && cars[i].flag == false){
                    bull_hit = true;
                }
                else if((bull.y == cars[i].y || bull.y == cars[i].y+1 || bull.y == cars[i].y+2) && bull.x >= cars[i].x && bull.x <= cars[i].x+CAR_LENGTH && cars[i].flag == true){
                    bull_hit = true;
                }
            }   
        }



//*********************************************************************************************************************************************************************

        //STAMPE
//*********************************************************************************************************************************************************************
        
        stampa_timer(time.x); //stampa della barra del tempo

        //stampa macchine
        for (int i = 0; i < N_CARS; i++){
            if (cars[i].x >= BORDER && ((cars[i].x+8 <= MAXX && cars[i].flag == false) || (cars[i].flag == true && cars[i].x+6 <= MAXX))){ 
                stampa_macchina(cars[i]); 
            }
        }

        //per ogni tronco viene chiamata la funzione che stampa a schermo i tronchi
        for(int i=0; i<5; i++){
            stampa_tronco(logs[i], enemy_bullets[i]);
        }

        //stampa della rana 
        mvprintw(frog.y,frog.x,"@^@");
        mvprintw(frog.y+1,frog.x,"(o)");
        mvprintw(frog.y+2,frog.x,"( )");

        //il proiettile viene stampato soltanto se visibile a schermo
        if(bull.y <= 2){
            bull_hit = false;
        }
        if(bull_hit == false && bull.y > 2){
            mvprintw(bull.y, bull.x, "^"); //stampa del proiettile
        }

         //punteggio e VITE
        mvprintw(3, BORDER, "PUNTEGGIO: %d", punteggio);
        mvprintw(3, MAXX-7, "VITE: %d", vite);

//*********************************************************************************************************************************************************************


        //CONTROLLO DELL' INGRESSO DELLA RANA IN UNA DELLE TANE
//*********************************************************************************************************************************************************************
        
        if (frog.y == SEZIONE_TANE){ // i controlli iniziano se la y della rana è la stessa di quella delle tane
            
            new_manche = true;  //in ogni caso una nuova manche dopo questa iterazione deve incominciare, che la rana entri in una tana vuota o meno

            if (frog.x >= 14 && frog.x <21){ //controllo che la rana sia entrata nella prima tana
                if(tane[0] == true){ //se la flag di quella tana è true significa che è ancora vuota e quindi la rana la può chiudere non perdendo vite
                    tane[0] = false; //la tana diventa riempita, nel caso la rana ci dovesse tornare perderebbe una vita
                    tane_riempite++; //aumento il counter del numero di tane riempite

                    frog.x=MAXX/2;
                    frog.y=MAXY-9;
                    frog.flag = true;
                    write(pc[1],&frog, sizeof(posizione)); //comunico alla funzione rana che questa deve tornare al punto di partenza in quanto una nuova manche sta incominciando 

                    punteggio+=100; //per ogni tana chiusa il punteggio aumenta di 100
                    new_manche = true; 
                    ping = fork();
                    if(ping == 0){
                        pingSound(p);
                    }

                    strcpy(reason,"La rana ha chiuso una tana");
                }
                else{
                    vite -=1; //se la rana prova ad andare in una tana già chiusa perderà una vita e farà rincominciare la manche 
                    new_manche = true;

                    strcpy(reason,"La rana ha cercato di chiudere una tana già chiusa");
                }
            }

            else if(frog.x >= 32 && frog.x <39){//controllo che la rana sia entrata nella seconda tana
                if(tane[1] == true){
                    tane[1] = false;
                    tane_riempite++;

                    frog.x=MAXX/2;
                    frog.y=MAXY-9;
                    frog.flag = true;
                    write(pc[1],&frog, sizeof(posizione)); //comunico alla funzione rana che questa deve tornare al punto di partenza in quanto una nuova manche sta incominciando 

                    punteggio+=100;
                    new_manche = true;
                    ping = fork();
                    if(ping == 0){
                        pingSound(p);
                    }

                    strcpy(reason,"La rana ha chiuso una tana");
                }
                else{
                    vite -=1;
                    new_manche = true;

                    strcpy(reason,"La rana ha cercato di chiudere una tana già chiusa");
                }
            }

            else if(frog.x >= 50 && frog.x <57){//controllo che la rana sia entrata nella terza tana
                if(tane[2] == true){
                    tane[2] = false;
                    tane_riempite++;

                    frog.x=MAXX/2;
                    frog.y=MAXY-9;
                    frog.flag = true;
                    write(pc[1],&frog, sizeof(posizione));//comunico alla funzione rana che questa deve tornare al punto di partenza in quanto una nuova manche sta incominciando 

                    punteggio+=100;
                    new_manche = true;
                    ping = fork();
                    if(ping == 0){
                        pingSound(p);
                    }

                    strcpy(reason,"La rana ha chiuso una tana");
                }
                else{
                    vite -=1;
                    new_manche = true;

                    strcpy(reason,"La rana ha cercato di chiudere una tana già chiusa");
                }
            }

            else if(frog.x >= 68 && frog.x <75){//controllo che la rana sia entrata nella quarta tana
                if(tane[3] == true){
                    tane[3] = false;
                    tane_riempite++;
                    
                    frog.x=MAXX/2;
                    frog.y=MAXY-9;
                    frog.flag = true;
                    write(pc[1],&frog, sizeof(posizione));//comunico alla funzione rana che questa deve tornare al punto di partenza in quanto una nuova manche sta incominciando 

                    punteggio+=100;
                    new_manche = true;
                    ping = fork();
                    if(ping == 0){
                        pingSound(p);
                    }

                    strcpy(reason,"La rana ha chiuso una tana");
                }
                else{
                    vite -=1;
                    new_manche = true;

                    strcpy(reason,"La rana ha cercato di chiudere una tana già chiusa");
                }
            }

            else if(frog.x >= 86 && frog.x <93){//controllo che la rana sia entrata nella quinta tana
                if(tane[4] == true){
                    tane[4] = false;
                    tane_riempite++;
                    
                    frog.x=MAXX/2;
                    frog.y=MAXY-9;
                    frog.flag = true;
                    write(pc[1],&frog, sizeof(posizione));//comunico alla funzione rana che questa deve tornare al punto di partenza in quanto una nuova manche sta incominciando 

                    punteggio+=100;
                    new_manche = true;
                    ping = fork();
                    if(ping == 0){
                        pingSound(p);
                    }

                    strcpy(reason,"La rana ha chiuso una tana");
                }
                else{
                    vite -=1;
                    new_manche = true;

                    strcpy(reason,"La rana ha cercato di chiudere una tana già chiusa");
                }
            }

            else{ //nel caso la rana non vada in nessuna delle tane comunque dovrà tornare nella posizione iniziale perdendo una vita

                frog.x=MAXX/2;
                frog.y=MAXY-9;
                frog.flag = true;
                write(pc[1],&frog, sizeof(posizione)); //viene comunicato alla funzione rana che deve tornare alla posizione iniziale

                vite-=1;
                new_manche = true;

                strcpy(reason,"La rana ha oltrepassato il limite dell'area di gioco");
            }
        }
//*********************************************************************************************************************************************************************

        //controllo se il tempo è finito allora rincomincia la manche e si perde una vita
        if(time.x <= 0){
            vite -=1;
            new_manche = true;
            time.x = n_tempo;

            frog.x=MAXX/2;
            frog.y=MAXY-9;
            frog.flag = true;
            write(pc[1],&frog, sizeof(posizione));

            strcpy(reason,"Il tempo è terminato");
        }

        if(new_manche == true){
            
            //controllo sulla fine della partita, sia in caso di vittoria che di sconfitta
            if(vite <= 0){
            
                erase();
                mvprintw(MAXY/2, MAXX/2-16, "<--------  GAME OVER  -------->");
                mvprintw(MAXY/2-10, MAXX/2-7, "PUNTEGGIO = %d", punteggio);
                refresh();
                game_over = fork();
                if(game_over == 0){
                    gameOverSound(p);
                }
                sleep(2);
                
                return;
            }
            else if(tane_riempite == 5){
                erase();
                mvprintw(MAXY/2, MAXX/2-17, "! <--------  YOU WON  --------> !");
                mvprintw(MAXY/2-10, MAXX/2-7, "PUNTEGGIO = %d", punteggio);
                refresh();
                win = fork();
                if(win == 0){
                    winSound(p);
                }
                sleep(2);
                
                return;
            }

            time.flag = true;
            write(pt[1], &time, sizeof(posizione)); //si comunica alla funzione che gestisce lo scorrere del tempo che la manche è rincominciata e questo deve essere inizializzato
             
            for (int i = 0; i < N_TRONCHI; i++){           

                check_enemy[i] = false; //tutti i nemici possono di nuovo spownare 
                
                enemy_bullets[i].x = -50; //per evitare che i proiettili rimangano stampati a schermo per errore la la y viene settata in modo da non essere visibile
                enemy_bullets[i].flag = false;
            }

            //resetto anche la posizione del proiettile della rana
            bull.y = -50;

            erase();
            mvprintw(MAXY/2, MAXX/2-7, "NUOVA MANCHE...");
            mvprintw(MAXY/2 +5, BORDER+20-6, "PUNTEGGIO: %d", punteggio); //stampo schermo il punteggio cumulato
            mvprintw(MAXY/2 +5, MAXX -36, "VITE RIMANENTI: %d", vite); //stampo le vite rimanenti
            mvprintw(MAXY/2 +10, MAXX/2 - (strlen(reason)/2), "%s",reason);
            
            refresh();

            sleep(1); //sleep di un secondo prima che la nuova manche rincominci
            new_manche = false;
        }

        refresh();
        usleep(500);
    }
    return;
}