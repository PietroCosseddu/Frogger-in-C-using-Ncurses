#include "include.h"
#include "extern.h"

int inizio_gioco(){

    // inizializzazione dell'id delle macchine
    int carId[N_CARS];
    for (int i = 0;i<N_CARS; i++){
        carId[i] = i;
    }

    int logID[N_CORSIE];
    int bull_logID[N_CORSIE];

    //inizializzazione dell'id dei tronchi e dei nemici dei tronchi
    for (int i = 0; i<N_CORSIE; i++){
        logID[i] = i;
        bull_logID[i] = i;
    }

    pthread_t tempo;
    pthread_t proiettile_rana;
    pthread_t rana;
    pthread_t tronchi[N_CARS];
    pthread_t proiettili_tronchi[N_CARS];
    pthread_t macchine[N_CARS];
    pthread_t startSound;

    if(restart == true){
        restart = false;
    }
    
    // creazione dei thread
    pthread_create(&rana, NULL, &f_rana, NULL);
    pthread_create(&proiettile_rana, NULL, &f_proiettile_rana, NULL);
    pthread_create(&tempo, NULL, &f_tempo, NULL);

    for (int i = 0; i<N_CORSIE; i++){
        pthread_create(&tronchi[i], NULL, &f_tronco,(void*)&logID[i]);
    }

    for (int i = 0; i<N_CORSIE; i++){
        pthread_create(&proiettili_tronchi[i], NULL, &f_proiettile_tronco, (void*)&bull_logID[i]);
    }
    
    for (int i = 0; i<N_CARS; i++){
        pthread_create(&macchine[i], NULL, &f_macchina,(void*)&carId[i]);
    }

    pthread_create(&startSound, NULL, &playStart, NULL);
    sleep(2);
    f_controllo();

    //una volta uscito dalle funzioni thread si fa la cancel di tutti thread chiudendoli prima di chiamare nuovamente la funzione menu
    pthread_cancel(rana);
    pthread_cancel(proiettile_rana);
    pthread_cancel(tempo);
    for (int i = 0; i<N_CORSIE; i++){
        pthread_cancel(tronchi[i]);
    }

    for (int i = 0; i<N_CORSIE; i++){
        pthread_cancel(proiettili_tronchi[i]);
    }
    
    for (int i = 0; i<N_CARS; i++){
        pthread_cancel(macchine[i]);
    }

    pthread_cancel(startSound);

    menu();

    wait(NULL);
    return 0;
}


