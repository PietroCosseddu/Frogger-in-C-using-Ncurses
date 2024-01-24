#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h> 
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h> 
#include <ncurses.h>
#include <pthread.h> 
#include <wchar.h>
#include <locale.h>
#include <stdio.h>
#include <ncurses.h>

#define SPACE_BAR 32
#define RANA_H 3
#define RANA_W 3
#define MARCIAPIEDE_PRATO 3
#define N_CORSIE 5
#define BORDER 10
#define MAXX 100
#define MAXY 50
#define CAMION_LENGTH 8
#define CAR_LENGTH 6
#define N_CARS 10
#define LOG_LEN 10
#define MARCIAPIEDE 10
#define EASY 1
#define MEDIUM 2
#define HARD 3
#define PRATO 23
#define N_TRONCHI 5
#define SEZIONE_TANE 5
#define N_TANE 5
#define UP 119
#define LEFT 97
#define DOWN 115
#define RIGHT 100

typedef struct{
    int x;
    int y;
    int ID;
    bool flag;
}posizione;

void f_rana(int p[2], int pc[2]);
void f_controllo(int p[2], int pc[2], int pt[2], int p_2[2], int p_3[2]);
void f_proiettile(int p[2], posizione frog);
void f_macchina(int p[2], int ID, int p_2[2], int p_3[2]);
void controllo_macchine_in_generazione(int p[2], int p_2[2]);
void colorazione_background();
void f_tempo(int p[2], int pt[2]);
void f_tronco(int p[2], int ID, int pg[2]);
void f_enemy_bullet(int p[2], posizione tronco);
void stampa_tronco(posizione tronco, posizione proiettile);
void stampa_macchina(posizione macchina);
void print_start_screen();
void print_rectangular_frame(int width, int height);
void print_screen_frame();
void print_frogger();
void print_frog(int start_y, int start_x);
void print_play(int start_y, int start_x);
void print_exit(int start_y, int start_x);
void print_arrow(int start_y, int start_x);
void colorazione_tane(bool flags[N_TANE]);
void stampa_timer(int tempo);
void scelta_difficolta();
void print_easy(int start_y, int start_x);
void print_medium(int start_y, int start_x);
void print_hard(int start_y, int start_x);
void menu();
int inizio_gioco();
void playSound(int p[2]);
void startSound(int p[2]);
void splashSound(int p[2]);
void car_hitSound(int p[2]);
void pingSound(int p[2]);
void gameOverSound(int p[2]);
void winSound(int p[2]);


