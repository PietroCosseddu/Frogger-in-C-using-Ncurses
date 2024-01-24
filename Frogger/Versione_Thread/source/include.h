#include <ncurses.h>
#include <pthread.h> 
#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h> 
#include <time.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <signal.h> //per kill
#include <time.h>
#include <string.h>

// inclusione dei file esterni
#define SPACE_BAR 32
#define RANA_H 3
#define MARCIAPIEDE_PRATO 3
#define N_CORSIE 5
#define BORDER 10
#define MAXX 100
#define MAXY 50
#define CAR_LENGTH 8
#define N_CARS 10
#define CAMION_LENGTH 8
#define MARCIAPIEDE 10
#define UP 119
#define LEFT 97
#define DOWN 115
#define RIGHT 100
#define RANA_W 3
#define N_TRONCHI 5

typedef struct{
    int x;
    int y;
    int ID;
    bool sparato;
}posizione;


// prototipi funzioni
void print_start_screen();
void print_rectangular_frame(int width, int height);
void print_screen_frame();
void print_frogger();
void print_frog(int start_y, int start_x);
void print_play(int start_y, int start_x);
void print_exit(int start_y, int start_x);
void print_arrow(int start_y, int start_x);
void colorazione_background();
void print_background_screen();
void scelta_difficolta();
void menu();
void colorazione_tane(bool flags[5]);
int inizio_gioco();
void stampa_timer(int tempo);
void stampa_tronco(posizione tronco, posizione proiettile);
void stampa_macchina(posizione macchina);
void stampa();
void restart_manche();
void f_controllo();
void print_easy();
void print_medium();
void print_hard();

// funzioni thread
void* f_rana(void*);
void* f_proiettile_rana(void*);
void* f_tronco(void*);
void* f_proiettile_tronco(void*);
void* f_tempo(void*);
void* f_macchina(void*);
void* playSound(void*);
void* playSplash(void*);
void* playStart(void*);
void* playCrash(void*);
void* playGameOver(void*);
void* playWin(void*);
void* playPing(void*);





