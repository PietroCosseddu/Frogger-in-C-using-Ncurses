#include "include.h"
#include "extern.h"

void* f_tronco(void *ID){

    int identifier = *((int *) ID); //identificatore del tronco preso dal valore passato alla funzione
    srand(ID);
    int arr_flusso[] = {20,17,14,11,8}; //array che contiene la y dei 5 flussi attraversati dai 5 tronchi

    pthread_mutex_lock(&mutex);

    //inizializzazione dei valori del tronco
    proiettili_tronchi[identifier].sparato = false;
    tronchi[identifier].x = BORDER+1+rand()%70;
    tronchi[identifier].y = arr_flusso[identifier];
    tronchi[identifier].sparato = false;
    tronchi[identifier].ID = identifier;

    pthread_mutex_unlock(&mutex);

    int arr_direzione[] = {-1,1}; //array che contiene le direzioni possibili, da destra verso sinistra o viceversa
    int direzione = arr_direzione[rand()%2]; // la direzione viene scelta randomicamente

    int lim_timer = 60+rand()%250;
    int spawn_timer = 0;

    int lim_shoot = 30+rand()%90;
    int shoot_timer = 0;

    int bull_timer;
    int speed;
    //l'intervallo di sparo dei nemici e la velocità di movimento dei tronchi cambia in base alla difficoltà selezionata
    if (difficolta == 1){
        bull_timer = 300;
        speed = 65000;
    } 
    else if(difficolta == 2){
        bull_timer = 150;
        speed = 50000;
    }
    else if(difficolta == 3){
        bull_timer = 0;
        speed = 40000;
    }

    while(true){

        if(restart == true){
            return 0;
        }

        if (tronchi[identifier].x >= MAXX-10 || tronchi[identifier].x <= BORDER){
            direzione *= -1;
        }

        pthread_mutex_lock(&mutex);

        if(spawn_timer > lim_timer && tronchi[identifier].sparato == false && rana.y != tronchi[identifier].y){ //controllo che il timer per lo spawn sia maggiore di lim_timer e che il flag sia false
            
            tronchi[identifier].sparato = true; //flag viene settata a true e il nemico spawna nel tronco

            //i timer vengono ripristinati
            spawn_timer += 250+rand()%200; 
            lim_timer = 60+rand()%300;
        }

        else if(spawn_timer < 0){ // se il timer dello spawn diventa < 0 la flag viene messa a false, quindi il nemico despowna dal tronco 
            tronchi[identifier].sparato = false;
        }
        
        if(tronchi[identifier].sparato == false){
            spawn_timer++; // una volta despownato il nemico perché lo spawn_timer è arrivato a < 0 si rincomincia ad incrementare finché non supera il lim_timer e quindi respawna il nemico sul tronco 
        }

        if(tronchi[identifier].sparato == true){ //il nemico è sul tronco

            if (shoot_timer >= lim_shoot && proiettili_tronchi[identifier].sparato == false){
                shoot_timer = 0;
                lim_shoot = 10+rand()%bull_timer; //viene ricalcolato il timer per sparare un nuovo proiettile
                proiettili_tronchi[identifier].sparato = true;
            }

            shoot_timer++; //il timer per sparare aumenta ad ogni iterazione fino ad essere maggiore del lim_shoot e poter sparare il proiettile.
            spawn_timer--; //viene decrementato anche lo spawn_timer fino ad arrivare < 0, quando succede il nemico despowna
        }
        
        tronchi[identifier].x += direzione; //movimento del tronco 

        if(rana.y==tronchi[identifier].y && (rana.x>tronchi[identifier].x || rana.x<tronchi[identifier].x+10)){ //se la rana si trova sopra un tronco segue la posizione di quest'ultimo
            rana.x+=direzione;
        }

        pthread_mutex_unlock(&mutex);

        usleep(speed);
    }
}

//****************************************************************************************************************************************

void* f_proiettile_tronco(void*ID){

    int identifier = *((int *) ID);

    int speed;
    //la velocità di movimento del proiettile cambia in base alla difficoltà scelta
    if(difficolta == 1){
        speed = 60000;
    }
    else if(difficolta == 2){
        speed = 45000;
    }
    else if(difficolta == 3){
        speed = 25000;
    }

    while(true){

        if(restart == true){
            return 0;
        }

        if(proiettili_tronchi[identifier].sparato == true){

            pthread_mutex_lock(&mutex);
            //inizializzazione delle coordinate del proiettile data la posizione del tronco
            proiettili_tronchi[identifier].y = tronchi[identifier].y+2; 
            proiettili_tronchi[identifier].x = tronchi[identifier].x+5;
            pthread_mutex_unlock(&mutex);

            while(proiettili_tronchi[identifier].y <= MAXY-8){

                pthread_mutex_lock(&mutex);
                proiettili_tronchi[identifier].y++; //movimento del proiettile
                pthread_mutex_unlock(&mutex);

                usleep(speed);
            }

            pthread_mutex_lock(&mutex);
            proiettili_tronchi[identifier].sparato = false; //una volta finito la flag viene settata a false e può essere sparato un altro proiettile
            pthread_mutex_unlock(&mutex);
        }
    }
}

//****************************************************************************************************************************************
