#include "include.h"
#include "extern.h"


void f_tempo(int p[2], int pt[2]){

    //inizializzazione delle variabili
    posizione time, reset_time;
    
    reset_time.flag = false; //la flag dell'oggetto che viene letto per resettare il tempo alla fine di ogni manche viene settata di default a false

    //inizializzazione del tempo
    time.ID = 't';
    time.x = n_tempo + 5; //come prima inizializzazione del tempo vengono aggiunti 5 secondi bonus in quanto passano un paio di secondi dall'avvio prima che il gioco inizi


    while(time.x >= 0){
        //il tempo viene scritto nella pipe 
        write(p[1], &time, sizeof(posizione));
        time.x--; //decremento di 1 alla volta
        sleep(1); 

        read(pt[0], &reset_time, sizeof(posizione)); //read non bloccante che serve per resettare il tempo alla fine di una manche, se la flag è true la manche è finita e il tempo va resettato
        if(reset_time.flag==true){
            time.x = n_tempo;
            sleep(2);
        }
        reset_time.flag = false; //la flag viene risettata a false
        
    }
}