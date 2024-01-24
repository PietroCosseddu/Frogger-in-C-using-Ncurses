#include "include.h"

//variabili globali

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
bool macchine_no_collision;
bool line_change_block;
posizione tempo;
posizione proiettile_rana;
posizione rana;
posizione tronchi[N_CORSIE];
posizione proiettili_tronchi[N_CORSIE];
posizione macchine[N_CARS];

int punteggio = 0; 
int vite = 5; 
int loghit[5]={0, 0, 0, 0, 0};
bool tane[5] = {true, true, true, true, true}; //array di booleani che segna quali sono le tane non ancora occupate, quando diventano tutte false il gioco finisce
int tane_riempite = 0;
bool new_manche = false;
char reason[100] = "Motivazione cambio manche";
bool restart = false;

int difficolta = 0;
int n_tempo = 0;
