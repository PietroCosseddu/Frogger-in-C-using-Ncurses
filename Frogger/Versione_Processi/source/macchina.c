#include "include.h"
#include "extern.h"


void f_macchina(int p[2], int ID, int p_2[2], int p_3[2]){

    srand(time(NULL));

    int direzioni[] = {-1, 1};
    int direzione = direzioni[rand()%2];

    srand(getpid());

    posizione macchina;

    //inizializzo le posizioni della macchina in modo che non sia visibile a schermo
    macchina.x = -10;
    macchina.y = -10;

    int possible_lane[N_CORSIE]={26,29,32,35,38};
    bool flag = true;

    // randomicamente decidiamo se il veicolo generato sarà un camion oppure una macchina
    if (1+rand()%6 > 4){
        macchina.flag = true; //macchina
    }
    else{
        macchina.flag = false; //camion
    }
    // inizializzo la prima posizione della macchina
    macchina.y=possible_lane[(rand()%5)];
    macchina.x=(BORDER+rand()%MAXX-CAMION_LENGTH);
    macchina.ID=ID;

    int line_change = 0; //intero che cambia da 0 ad 1 serve per comunicare quando una macchina può cambiare la riga oppure se una macchina la sta già cambiando e perciò deve aspettare

    // scrivo nella pipe 1 la prima posizione della macchina per effettuare un controllo
    write(p[1],&macchina,sizeof(posizione));

    //in base alla difficoltà scelta cambia la velocità di movimento delle macchine
    int speed;

    if(difficolta == EASY){
        speed = 60000;
    }
    else if(difficolta == MEDIUM){
        speed = 40000;
    }
    else if(difficolta == HARD){
        speed = 25000;
    }


    // controllo che la posizione non sia contestata
    while (flag){
        int collision = 0;
        read(p_2[0], &collision, sizeof(int)); //read non bloccante che controlla che non ci siano stare collisioni nella generazione delle macchine,
        usleep(100);
        if (collision == 1){ // se ci sono state delle collisioni le posizioni della macchina vengono inizializzate
            macchina.y=possible_lane[(rand()%5)]; //scelta random della corsia
            macchina.x=(BORDER+rand()%MAXX-CAMION_LENGTH);  //scelta random della posizione sulla corsia
            write(p[1],&macchina,sizeof(posizione)); //scrivo nella pipe le nuove posizioni della macchia, esse andranno ricontrollate falla funzione controllo macchine in generazione prima di essere mandate nella funzione controllo per stamparle 
        }
        else if (collision == 0){
            flag = false; //se non ci sono state collisioni la flag diventa false e quindi esce dal while
        }
    }

    while (true){ //while principale
        flag = true;
        //controllo se la macchina è uscita dai bordi e quindi deve cambiare corsia randomicamente
        if (macchina.x < BORDER || (macchina.x+CAR_LENGTH > MAXX && macchina.flag == false) || (macchina.flag == true && macchina.x+CAR_LENGTH > MAXX)){ // verifico se c'è stata una collisione con i bordi dell'area di gioco 

            while(flag){ // se si entro nel while 
                line_change = 0; //il cambio corsia è libero 
                read(p_3[0], &line_change, sizeof(int)); // leggo dalla pipe 3 line_change, per controllare se qualche altra macchina ha chiesto di cambiare riga

                if (line_change == 1){ // se un'altra macchina sta cambiando riga allora aspetto un tempo definito e ci riprovo
                    usleep(speed*3); //il tempo che si aspetta è la velocità delle macchine moltiplicato per 3
                }
                else{ // se la coda è libera allora imposto la flag a false, occupo il cambio corsia scrivendo 1 e effettuo il cambio
                    flag = false; //esco dal while 
                    line_change = 1; //cambio corsia occupato e vengono decise le nuove posizioni della macchina 
                    for (int i = 0; i < N_CARS; i++){
                        write(p_3[1], &line_change, sizeof(int));
                    }
                    macchina.y=possible_lane[(rand()%5)]; //inizializzazione random
                    if((macchina.y == 29 || macchina.y == 35) && direzione == 1){ //se la macchina sta nella corsia 2 o 4 il dovrà spownare a ridosso del bordo destro dello schermo 
                        macchina.x = MAXX-CAMION_LENGTH;
                    }
                    else if((macchina.y == 29 || macchina.y == 35) && direzione == -1){
                        macchina.x = BORDER;
                    }
                    else if(direzione == 1){
                        macchina.x = BORDER;
                    }
                    else if(direzione == -1){
                        macchina.x = MAXX-CAMION_LENGTH;
                    }
                }
            }
        }
        else{ //movimento della macchina
            if (macchina.y == 29 || macchina.y == 35){// se la macchina sta nella corsia 2 o 4 il movimento sarà da destra verso sinistra
                macchina.x += (direzione*-1);
            }
            else{
                macchina.x += direzione;
            }
        }
        usleep(speed);
        write(p[1], &macchina, sizeof(posizione)); //scrivo nella pipe i dati della macchina che saranno passati alla funzione controllo per la stampa
    }
}

void controllo_macchine_in_generazione(int p[2], int p_2[2]){

    int counter = 0; //inizializzo il contatore che aumenta fino ad arrivare a 10, se arriva a 10 significa che ho nella matrice una x e una y per ognuna delle 10 macchine
    posizione data;
    posizione macchine[N_CARS];
    int matricePosizioniIniziali[10][2] = {{0}}; //creo una matrice che contiene le posizioni delle macchine per confrontarle tra loro e trovare delle collisioni
    int controlloLettura[10] = {0};
    bool flag = true;

    while(flag){
        read(p[0], &data, sizeof(posizione)); //leggo dalla pipe le macchine
        if (counter < 10){ //continuo ad accumulare valori nella matrice fino a che non leggo almeno una volta tutte le macchine
            for (int i = 0; i < 10; i++){
                if (data.ID == i && controlloLettura[i] == 0){ //controllo se la macchina letta è già stata letta, se è così non salvo una nuova posizione ma tengo la prima letta
                    
                    macchine[i] = data;
                    counter++; //aumento il counter in quanto una nuova macchina è stata salvata nella matrice
                    matricePosizioniIniziali[i][0] = macchine[i].x;
                    matricePosizioniIniziali[i][1] = macchine[i].y;
                    controlloLettura[i] = 1;
                    
                }             
            }
        }
        if (counter == 10){ //se ho letto tutte le macchine proseguo facendo il controllo delle collisioni
            int collision = 0;

            // devo avviare il controllo
            for (int i = 0; i<10; i++){ //confronto le posizioni di ogni macchina con tutte quelle presenti
                for (int j = 0; j<10; j++){
                    if (i != j){ //controllo che i e j siano diversi, se fossero uguali troverebbe sicuramente una collisione dato che starebbe confrontando la stessa macchina
                        if (matricePosizioniIniziali[i][1] == matricePosizioniIniziali[j][1]){ //controlla prima che la y sia uguale poi va avanti e controlla la x
                            if (!(matricePosizioniIniziali[j][0] > matricePosizioniIniziali[i][0]+7 || matricePosizioniIniziali[j][0]+7 <= matricePosizioniIniziali[i][0])){ //c'è stata una collisione in generazione
                                //se trova una collisione esco da entrambi i for
                                j = 10; 
                                i = 10;
                                counter = 0; //azzero il counter che aumenta fino a salvare i dati di tutte le macchine presenti

                                collision = 1;
                                // scrivo nella pipe che una collisione è stata trovata, questo verrà letto dalla funzione della macchina e rigenererà una nuova posizione senza collisioni
                                for (int i = 0; i<10; i++){
                                    write(p_2[1], &collision, sizeof(int));
                                }

                                // riazzero l'array che controllava la lettura di ogni singola macchina
                                for (int i = 0; i < 10; i++){
                                    controlloLettura[i] = 0;
                                }
                            }
                        }
                    }
                }
            }
            //se non ci sono state collisioni scrive il messaggio alle funzioni delle macchine che andranno avanti con la loro esecuzione
            if (collision == 0){
                for (int i = 0; i < 10; i++){
                    write(p_2[1], &collision, sizeof(int));
                }
                flag = false; //esce dal while 
            }
        }
    }
    return;
}