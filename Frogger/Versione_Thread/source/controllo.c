#include "include.h"
#include "extern.h"

//****************************************************************************************************************************************


void f_controllo(){

    pthread_t suono, splash, crash, ping;

    while(true){

        if(restart == true){
            return;
        }

        //check rana fuori dal tronco
    //****************************************************************************************************************************************
        
        for(int i=0; i<N_TRONCHI; i++){
            if(rana.y==tronchi[i].y){
                if(rana.x<tronchi[i].x || rana.x>=tronchi[i].x+8){
                    pthread_mutex_lock(&mutex);
                        pthread_create(&splash, NULL, &playSplash, NULL);
                        
                        rana.x = MAXX/2;
                        rana.y = MAXY-9;
                        vite-=1;
                        new_manche = true;

                        strcpy(reason,"La rana è caduta nel fiume");
                        tempo.x = n_tempo;
                    pthread_mutex_unlock(&mutex);
                    break;
                }
            }
        }

        //check nemico sul tronco
    //****************************************************************************************************************************************
        for(int i=0; i<N_TRONCHI; i++){
            if(rana.y==tronchi[i].y){
                if(tronchi[i].sparato==true && loghit[i]==0){
                    pthread_mutex_lock(&mutex);
                        rana.x = MAXX/2;
                        rana.y = MAXY-9;
                        vite-=1;
                        new_manche = true;
                        strcpy(reason,"La rana ha tentato di salire su un tronco con un nemico sopra");
                        tempo.x = n_tempo;
                    pthread_mutex_unlock(&mutex);
                    break;
                }
            }
        }
        
        //collisioni tra macchine e rana
    //****************************************************************************************************************************************

        for(int i = 0; i < N_CARS; i++){
            if (macchine[i].x >= BORDER && ((macchine[i].x+8 <= MAXX && macchine[i].sparato == false) || (macchine[i].sparato == true && macchine[i].x+6 <= MAXX))){  //viene fatto prima un controllo sul fatto che la macchina sia stampata a schermo, se non è stampata non controllo le collisioni con quella macchina
                //contollo la collisione con la rana se il veicolo è un camion o una macchina usando la flag
                if (rana.y == macchine[i].y && rana.x+2 >= macchine[i].x && rana.x <= macchine[i].x+8 && macchine[i].sparato == false){
                    
                    pthread_mutex_lock(&mutex);
                    pthread_create(&crash, NULL, &playCrash,NULL);
                    rana.x = MAXX/2;
                    rana.y = MAXY-9;

                    vite -= 1;
                    new_manche = true; //inizio una nuova manche
                    strcpy(reason,"La rana è stata colpita da un camion");
                    tempo.x = n_tempo;
                    pthread_mutex_unlock(&mutex);
                    break;
                }
                else if(rana.y == macchine[i].y && rana.x+2 >= macchine[i].x && rana.x <= macchine[i].x+6 && macchine[i].sparato == true){
                    
                    pthread_mutex_lock(&mutex);
                    pthread_create(&crash, NULL, &playCrash,NULL);
                    rana.x = MAXX/2;
                    rana.y = MAXY-9;

                    vite -= 1; 
                    new_manche = true; //inizio una nuova manche

                    strcpy(reason,"La rana è stata colpita da una macchina");
                    tempo.x = n_tempo;
                    pthread_mutex_unlock(&mutex);
                    break;
                }
            }
        }

    //****************************************************************************************************************************************

            //collisioni tra proiettili e macchine, quando un qualunque proiettile colpisce una macchina questo viene distrutto
    //****************************************************************************************************************************************

        for(int i = 0; i < N_CORSIE; i++){ //nel primo for vengono fatti scorrere tutti i proiettili dei nemici
            for (int j = 0; j < N_CARS; j++){ //nel secondo for vengono fatti scorrere tutte le macchine

                if (macchine[j].x >= BORDER && ((macchine[j].x+8 <= MAXX && macchine[j].sparato == false) || (macchine[j].sparato == true && macchine[j].x+6 <= MAXX))){  //viene fatto prima un controllo sul fatto che la macchina sia stampata a schermo, se non è stampata non controllo le collisioni con quella macchina

                    if (proiettili_tronchi[i].y == macchine[j].y && proiettili_tronchi[i].x >= macchine[j].x && proiettili_tronchi[i].x <= macchine[j].x+8 && macchine[j].sparato == false){
                        
                        pthread_mutex_lock(&mutex);
                        proiettili_tronchi[i].sparato = false;
                        pthread_mutex_unlock(&mutex);
                    }
                    else if(proiettili_tronchi[i].y == macchine[j].y && proiettili_tronchi[i].x >= macchine[j].x && proiettili_tronchi[i].x <= macchine[j].x+6 && macchine[j].sparato == true){
                        
                        pthread_mutex_lock(&mutex);
                        proiettili_tronchi[i].sparato = false;
                        pthread_mutex_unlock(&mutex);

                    }
                }   
            }
        }

        //controllo collisione tra proiettile della rana e macchina

        for (int i = 0; i < N_CARS; i++){
            if (macchine[i].x >= BORDER && ((macchine[i].x+8 <= MAXX && macchine[i].sparato == false) || (macchine[i].sparato == true && macchine[i].x+6 <= MAXX))){  //viene fatto prima un controllo sul fatto che la macchina sia stampata a schermo, se non è stampata non controllo le collisioni con quella macchina

                if ((proiettile_rana.y == macchine[i].y || proiettile_rana.y == macchine[i].y+1 || proiettile_rana.y == macchine[i].y+2) && proiettile_rana.x >= macchine[i].x && proiettile_rana.x <= macchine[i].x+8 && macchine[i].sparato == false){
                    pthread_mutex_lock(&mutex);
                    proiettile_rana.sparato = false;
                    proiettile_rana.y = 0;
                    pthread_mutex_unlock(&mutex);
                }
                else if((proiettile_rana.y == macchine[i].y || proiettile_rana.y == macchine[i].y+1 || proiettile_rana.y == macchine[i].y+2) && proiettile_rana.x >= macchine[i].x && proiettile_rana.x <= macchine[i].x+6 && macchine[i].sparato == true){
                    pthread_mutex_lock(&mutex);
                    proiettile_rana.sparato = false;
                    proiettile_rana.y = 0;
                    pthread_mutex_unlock(&mutex);
                }
            }   
        }

        //controllo collisione tra proiettile della rana e nemici
        for(int i=0; i<N_TRONCHI; i++){
            if(tronchi[i].sparato==true && (proiettile_rana.y==tronchi[i].y || proiettile_rana.y==tronchi[i].y+1 || proiettile_rana.y==tronchi[i].y+2) && proiettile_rana.x>tronchi[i].x+3 && proiettile_rana.x<tronchi[i].x+7 &&loghit[i] == 0){
                pthread_mutex_lock(&mutex);
                    pthread_create(&suono, NULL, &playSound,NULL);
                    loghit[i] = 1;
                    tronchi[i].sparato=false;
                    proiettile_rana.sparato=false;
                    proiettile_rana.y=0;
                    punteggio += 50;
                pthread_mutex_unlock(&mutex);
            }
        }

        //controllo collisione tra proiettile nemico e rana
        for(int i=0; i<N_TRONCHI; i++){
            if(proiettili_tronchi[i].y==rana.y && proiettili_tronchi[i].x>=rana.x &&proiettili_tronchi[i].x<rana.x+3 && proiettili_tronchi[i].sparato == true && tronchi[i].sparato == true){
                pthread_mutex_lock(&mutex);
                    rana.x=MAXX/2;
                    rana.y=MAXY-9;
                    vite -=1; //se la rana prova ad andare in una tana già chiusa perderà una vita e farà rincominciare la manche
                    proiettili_tronchi[i].sparato=false; 
                    new_manche = true;
                    strcpy(reason,"La rana è stata colpita dal proiettile di un nemico");
                    tempo.x = n_tempo;
                pthread_mutex_unlock(&mutex);
                break;
            }
        }

        //controllo collisione tra proiettile nemico e proiettile rana
        for(int i=0; i<N_TRONCHI; i++){
            if(proiettili_tronchi[i].y==proiettile_rana.y && proiettili_tronchi[i].x==proiettile_rana.x){
                pthread_mutex_lock(&mutex);
                    proiettili_tronchi[i].sparato=false; 
                    proiettile_rana.sparato=false;
                    proiettile_rana.y=0;
                pthread_mutex_unlock(&mutex);
            }
        }

    //****************************************************************************************************************************************

        //controllo fine tempo
    //****************************************************************************************************************************************

        if (tempo.x == 0){
            pthread_mutex_lock(&mutex);
                vite -= 1;
                new_manche = true;
                rana.x=MAXX/2;
                rana.y=MAXY-9;
                strcpy(reason,"Il tempo per la manche è terminato");
                tempo.x = n_tempo;

            pthread_mutex_unlock(&mutex);
        }



    //****************************************************************************************************************************************
    
        //controllo ingresso rana nella sezione tane
    //****************************************************************************************************************************************
        
        
        if (rana.y == 5){ // i controlli iniziano se la y della rana è la stessa di quella delle tane
            
            if (rana.x >= 14 && rana.x <21){ //controllo che la rana sia entrata nella prima tana
                if(tane[0] == true){ //se la flag di quella tana è true significa che è ancora vuota e quindi la rana la può chiudere non perdendo vite
                    pthread_mutex_lock(&mutex);
                    tane[0] = false; //la tana diventa riempita, nel caso la rana ci dovesse tornare perderebbe una vita
                    punteggio+=100; //per ogni tana chiusa il punteggio aumenta di 100
                    new_manche = true; 
                    tempo.x = n_tempo;
                    strcpy(reason,"La rana ha chiuso una tana");
                    pthread_create(&ping, NULL, &playPing, NULL);
                    pthread_mutex_unlock(&mutex);
                }
                else{
                    pthread_mutex_lock(&mutex);
                    vite -=1; //se la rana prova ad andare in una tana già chiusa perderà una vita e farà rincominciare la manche 
                    new_manche = true;
                    tempo.x = n_tempo;

                    strcpy(reason,"La rana ha cercato di chiudere una tana già chiusa");
                    pthread_mutex_unlock(&mutex);
                }
            }
            else if(rana.x >= 32 && rana.x <39){//controllo che la rana sia entrata nella seconda tana
                if(tane[1] == true){
                    pthread_mutex_lock(&mutex);
                    tane[1] = false;
                    tane_riempite++;
                    punteggio+=100;
                    new_manche = true;
                    tempo.x = n_tempo;

                    strcpy(reason,"La rana ha chiuso una tana");
                    pthread_create(&ping, NULL, &playPing, NULL);
                    pthread_mutex_unlock(&mutex);
                }
                else{
                    pthread_mutex_lock(&mutex);
                    vite -=1;
                    new_manche = true;
                    tempo.x = n_tempo;
                    strcpy(reason,"La rana ha cercato di chiudere una tana già chiusa");
                    pthread_mutex_unlock(&mutex);
                }
            }
            else if(rana.x >= 50 && rana.x <57){//controllo che la rana sia entrata nella terza tana
                if(tane[2] == true){
                    pthread_mutex_lock(&mutex);
                    tane[2] = false;
                    tane_riempite++;
                    punteggio+=100;
                    new_manche = true;
                    tempo.x = n_tempo;

                    strcpy(reason,"La rana ha chiuso una tana");
                    pthread_create(&ping, NULL, &playPing, NULL);
                    pthread_mutex_unlock(&mutex);
                }
                else{
                    pthread_mutex_lock(&mutex);
                    vite -=1;
                    new_manche = true;
                    tempo.x = n_tempo;
                    strcpy(reason,"La rana ha cercato di chiudere una tana già chiusa");
                    pthread_mutex_unlock(&mutex);
                }
            }
            else if(rana.x >= 68 && rana.x <75){//controllo che la rana sia entrata nella quarta tana
                if(tane[3] == true){
                    pthread_mutex_lock(&mutex);
                    tane[3] = false;
                    tane_riempite++;
                    punteggio+=100;
                    new_manche = true;
                    tempo.x = n_tempo;

                    strcpy(reason,"La rana ha chiuso una tana");
                    pthread_create(&ping, NULL, &playPing, NULL);
                    pthread_mutex_unlock(&mutex);
                }
                else{
                    pthread_mutex_lock(&mutex);
                    vite -=1;
                    new_manche = true;
                    tempo.x = n_tempo;
                    strcpy(reason,"La rana ha cercato di chiudere una tana già chiusa");
                    pthread_mutex_unlock(&mutex);
                }
            }
            else if(rana.x >= 86 && rana.x <93){//controllo che la rana sia entrata nella quinta tana
                if(tane[4] == true){
                    pthread_mutex_lock(&mutex);
                    tane[4] = false;
                    tane_riempite++;
                    punteggio+=100;
                    new_manche = true;
                    tempo.x = n_tempo;
                    strcpy(reason,"La rana ha chiuso una tana");
                    pthread_create(&ping, NULL, &playPing, NULL);
                    pthread_mutex_unlock(&mutex);
                }
                else{
                    pthread_mutex_lock(&mutex);
                    vite -=1;
                    new_manche = true;
                    tempo.x = n_tempo;
                    strcpy(reason,"La rana ha cercato di chiudere una tana già chiusa");
                    pthread_mutex_unlock(&mutex);
                }
            }
            else{ //nel caso la rana non vada in nessuna delle tane comunque dovrà tornare nella posizione iniziale perdendo una vita
                pthread_mutex_lock(&mutex);
                vite-=1;
                new_manche = true;
                tempo.x = n_tempo;
                strcpy(reason,"La rana ha oltrepassato il limite dell'area di gioco");
                pthread_mutex_unlock(&mutex);
            }

            pthread_mutex_lock(&mutex);
                rana.x = MAXX/2;
                rana.y = MAXY-9;
            pthread_mutex_unlock(&mutex);
        }
    }
}

//****************************************************************************************************************************************

void stampa(){

    erase();

    print_background_screen();
    colorazione_background();
    colorazione_tane(tane);

    for (int i = 0; i < N_CORSIE; i++){
        if(loghit[i]==1){
            tronchi[i].sparato=false;
        }
        stampa_tronco(tronchi[i], proiettili_tronchi[i]);
    }

    for (int i = 0; i<N_CARS; i++){
        if (macchine[i].x >= BORDER && ((macchine[i].x+8 <= MAXX && macchine[i].sparato == false) || (macchine[i].sparato == true && macchine[i].x+6 <= MAXX))){ 
            stampa_macchina(macchine[i]); 
        } 
    }

    mvprintw(rana.y,rana.x,"/^\\");
    mvprintw(rana.y+1,rana.x,"|0|");
    mvprintw(rana.y+2,rana.x,"\\_/");

    if(proiettile_rana.sparato == true){
        mvprintw(proiettile_rana.y, proiettile_rana.x, "^");
    }

    stampa_timer(tempo.x);

    mvprintw(3, BORDER, "PUNTEGGIO: %d", punteggio);
    mvprintw(3, MAXX-7, "VITE: %d", vite);
    refresh();
}

void restart_manche(){

    pthread_t win, gameover;

    if(new_manche == true){
        
        //controllo sulla fine della partita, sia in caso di vittoria che di sconfitta
        if(vite <= 0){
        
            erase();
            mvprintw(MAXY/2, MAXX/2-16, "<--------  GAME OVER  -------->");
            mvprintw(MAXY/2-10, MAXX/2-7, "PUNTEGGIO = %d", punteggio);
            refresh();
            sleep(2);

            pthread_mutex_lock(&mutex);
            vite = 5;
            punteggio = 0;
            tempo.x = n_tempo;
            restart = true;
            rana.x = MAXX/2;
            rana.y = MAXY-9;
            new_manche = false;
            for(int i = 0; i < 5; i++){
                tane[i] = true;
            }
            pthread_create(&gameover, NULL, &playGameOver, NULL);
            pthread_mutex_unlock(&mutex);

            
        }
        else if(tane_riempite == 5){
            erase();
            mvprintw(MAXY/2, MAXX/2-17, "! <--------  YOU WON  --------> !");
            mvprintw(MAXY/2-10, MAXX/2-7, "PUNTEGGIO = %d", punteggio);
            refresh();
            sleep(2);

            pthread_mutex_lock(&mutex);
            vite = 5;
            punteggio = 0;
            tempo.x = n_tempo;
            restart = true;
            rana.x = MAXX/2;
            rana.y = MAXY-9;
            new_manche = false;

            for(int i = 0; i < 5; i++){
                tane[i] = true;
            }
            pthread_create(&win, NULL, &playWin, NULL);
            pthread_mutex_unlock(&mutex);

            
        }
        else if(tane_riempite < 5 && vite > 0){

            pthread_mutex_lock(&mutex);
            for (int i = 0; i < N_CORSIE; i++){
                loghit[i] = 0;
            }
            rana.x = MAXX/2;
            rana.y = MAXY-9;
            pthread_mutex_unlock(&mutex);

            //resetto anche la posizione del proiettile della rana

            erase();
            mvprintw(MAXY/2, MAXX/2-7, "NUOVA MANCHE...");
            mvprintw(MAXY/2 +5, BORDER+20-6, "PUNTEGGIO: %d", punteggio); //stampo schermo il punteggio cumulato
            mvprintw(MAXY/2 +5, MAXX -36, "VITE RIMANENTI: %d", vite); //stampo le vite rimanenti
            mvprintw(MAXY/2 +10, MAXX/2 - (strlen(reason)/2), "%s",reason);
            
            refresh();

            sleep(1); //sleep di un secondo prima che la nuova manche rincominci
            new_manche = false;

        }
    }
}