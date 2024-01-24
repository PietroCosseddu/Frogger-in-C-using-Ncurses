#include "include.h"
#include "extern.h"

void* f_tempo(void*X){

    //inizializzazione del tempo
    tempo.x = n_tempo; //tempo cambia in base alla difficoltà

    while(tempo.x > -1){
        
        if(restart == true){ //controllo se si deve rincominciare la manche e quindi si deve uscire dalla funzione
            return 0;
        }

        pthread_mutex_lock(&mutex);
        tempo.x--; //decremento di 1 alla volta
        pthread_mutex_unlock(&mutex);

        sleep(1); 
    }
    return 0;
}


//****************************************************************************************************************************************
