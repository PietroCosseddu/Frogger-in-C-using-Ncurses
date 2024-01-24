#include "include.h"
#include "extern.h"


void scelta_difficolta(){

    int highlight = 0; // Indice dell'opzione evidenziata
    const char *choices[] = {"EASY", "MEDIUM", "HARD"};
    const int n_choices = sizeof(choices) / sizeof(char *);

    // Stampa il menu finché l'utente non sceglie un'opzione o premendo 'q'
    while (TRUE) {

        //grafica del menu di inizio gioco
        erase();
        print_start_screen();  
        print_screen_frame();
        refresh();
        print_frogger();
        print_frog(15, BORDER+12);
        print_easy(6,BORDER+42);
        print_medium(17, BORDER+42);
        print_hard(28,BORDER+42);

        //in base alla scelta possibile cambia anche la posizione della barra di scelta
        if (strcmp(choices[highlight], "EASY") == 0){
            print_arrow(10, BORDER+75);
        }
        else if (strcmp(choices[highlight], "MEDIUM") == 0){
            print_arrow(21, BORDER+75);
        }
        else if (strcmp(choices[highlight], "HARD") == 0){
            print_arrow(32, BORDER+75);
        }
        refresh();
        
        int c = getch(); 
        switch (c) {
            case KEY_UP: // Freccia su: sposta l'evidenziazione sull'opzione precedente
                    highlight = (highlight - 1 + n_choices) % n_choices;
                    break;

            case KEY_DOWN: // Freccia giù: sposta l'evidenziazione sull'opzione successiva
                    highlight = (highlight + 1) % n_choices;
                    break;

            case '\n': // Invio: scegli l'opzione evidenziata
                if (strcmp(choices[highlight], "EASY") == 0) {
                    
                    n_tempo = 60; //nel caso della modalità di gioco facile il tempo per manche è 60 secondi
                    difficolta = EASY;

                    erase();
                    mvprintw(MAXY/2, MAXX/2-26, "IL GIOCO INIZIERA' TRA QUALCHE SECONDO... MODALITA' FACILE");
                    refresh();
                    inizio_gioco();//viene chiamata la funzione inizio_gioco che fa partire il gioco inizializzando pipe e processi
                    

                } else if(strcmp(choices[highlight], "MEDIUM") == 0){
                    
                    n_tempo = 45; //nel caso della modalità di gioco facile il tempo per manche è 45 secondi
                    difficolta = MEDIUM;
                    

                    erase();
                    mvprintw(MAXY/2, MAXX/2-26, "IL GIOCO INIZIERA' TRA QUALCHE SECONDO... MODALITA' MEDIA");
                    refresh();
                    inizio_gioco();//viene chiamata la funzione inizio_gioco che fa partire il gioco inizializzando pipe e processi
                    

                }else if(strcmp(choices[highlight], "HARD") == 0){

                    n_tempo = 30; //nel caso della modalità di gioco facile il tempo per manche è 30 secondi
                    difficolta = HARD;

                    erase();
                    mvprintw(MAXY/2, MAXX/2-28, "IL GIOCO INIZIERA' TRA QUALCHE SECONDO... MODALITA' DIFFICILE");
                    refresh();
                    inizio_gioco(); //viene chiamata la funzione inizio_gioco che fa partire il gioco inizializzando pipe e processi

                }
                break;

            case 'q': // Esci dal programma
                endwin();
                return ;
                break;
        }
        
        usleep(2000);
    }
}