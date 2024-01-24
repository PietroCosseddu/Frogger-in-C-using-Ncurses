#include "include.h"
#include "extern.h"

void* f_macchina(void*id){

    srand(time(NULL));
    //inizialzzazione della direzione della prima corsia, in base a questa verranno decise quelle di tutte le altre
    int direzioni[] = {-1, 1};
    int direzione = direzioni[rand()%2];

    int identifier = *((int *) id); //identificatore di ogni macchina

    srand(id);

    macchine[identifier].ID = identifier;
    
    bool bandiera = true, flag = true;
    int possible_lane[N_CORSIE]={26,29,32,35,38}; //coordinate delle possibili corsie delle macchine

    int speed; //la velocità cambia in base alla difficoltà selezionata

    if(difficolta == 1){
        speed = 60000;
    }
    else if(difficolta == 2){
        speed = 40000;
    }
    else if(difficolta == 3){
        speed = 25000;
    }


    // inizializzazione tipologia del veicolo
    if (1+rand()%6 > 4){
        pthread_mutex_lock(&mutex);
        macchine[identifier].sparato=true; //macchina
        pthread_mutex_unlock(&mutex);
    }
    else{
        pthread_mutex_lock(&mutex);
        macchine[identifier].sparato=false; //camion
        pthread_mutex_unlock(&mutex);
    }

    pthread_mutex_lock(&mutex);
    macchine[identifier].y=possible_lane[(rand()%5)];
    macchine[identifier].x=(BORDER+rand()%MAXX-18);
    pthread_mutex_unlock(&mutex);

    while(flag){ //controllo per la creazione delle macchine senza collisioni
        bandiera = true;
        for (int i = 0; i<N_CARS; i++){
            for (int j = 0; j<N_CARS; j++){
                if (macchine[i].y == macchine[j].y && i != j){
                    if (!(macchine[j].x > macchine[i].x+10 || macchine[j].x+10 < macchine[i].x)){
                        
                        pthread_mutex_lock(&mutex);
                        macchine[identifier].y=possible_lane[(rand()%5)];
                        macchine[identifier].x=(BORDER+rand()%MAXX-18);
                        pthread_mutex_unlock(&mutex);
                        bandiera = false;
                    }
                }
            }
        }
        if (bandiera){
            flag = false;
        }
    }
    //*****************************************************************************************************************************************************

    while(true){

        if(restart == true){ //controllo se si deve restartare la manche
            return 0;
        }

        flag = true;
        if (macchine[identifier].x < BORDER || (macchine[identifier].x+8 > MAXX && macchine[identifier].sparato == false) || (macchine[identifier].sparato == true && macchine[identifier].x+6 > MAXX)){ // verifico se c'è stata una collisione con i bordi dell'area di gioco 
            
            while(flag){
                
                pthread_mutex_lock(&mutex);
                macchine[identifier].y=possible_lane[(rand()%5)]; //decido randomicamente la nuova corsia della macchina
                if((macchine[identifier].y == 29 || macchine[identifier].y == 35) && direzione == 1){ //se la macchina sta nella corsia 2 o 4 il dovrà spownare a ridosso del bordo destro dello schermo 
                        macchine[identifier].x = MAXX-CAMION_LENGTH;
                    }
                    else if((macchine[identifier].y == 29 || macchine[identifier].y == 35) && direzione == -1){
                        macchine[identifier].x = BORDER;
                    }
                    else if(direzione == 1){
                        macchine[identifier].x = BORDER;
                    }
                    else if(direzione == -1){
                        macchine[identifier].x = MAXX-CAMION_LENGTH;
                    }

                for (int i = 0; i < N_CARS; i++){
                    if(macchine[identifier].y == macchine[i].y && identifier != i && !(macchine[identifier].x+10 < macchine[i].x || macchine[identifier].x > macchine[i].x+10)){ //controllo se ci sono collisioni con le macchine che sono già presenti in quella corsia, se ce ne sono la posizione verrà inizializzata nuovamente
                        flag = true;
                        break;
                    }
                    else{
                        flag = false;
                    }
                }
                pthread_mutex_unlock(&mutex);
            }
        }

        else{
            pthread_mutex_lock(&mutex);
            if (macchine[identifier].y == 29 || macchine[identifier].y == 35){// se la macchina sta nella corsia 29 o 35 il movimento sarà da destra verso sinistra
                macchine[identifier].x += (direzione *-1);
            }
            else{
                macchine[identifier].x += direzione;
            }
            pthread_mutex_unlock(&mutex);
                    
            usleep(speed);
        }
    }    
}