extern pthread_mutex_t mutex;
extern bool macchine_no_collision;
extern bool line_change_block;
extern posizione tempo;
extern posizione proiettile_rana;
extern posizione rana;
extern posizione tronchi[N_CORSIE];
extern posizione proiettili_tronchi[N_CORSIE];
extern posizione macchine[N_CARS];

extern int punteggio;
extern int vite; 
extern int loghit[5];
extern bool tane[5]; //array di booleani che segna quali sono le tane non ancora occupate, quando diventano tutte false il gioco finisce
extern int tane_riempite;
extern bool new_manche;
extern char reason[100];
extern bool restart;

extern int difficolta;
extern int n_tempo;