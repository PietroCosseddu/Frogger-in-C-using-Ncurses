#include "include.h"


int main(){
    initscr(); // Inizializza ncursed
    cbreak(); // Disabilita il buffering delle linee
    noecho(); // Disabilita l'echoing delle tastiere
    keypad(stdscr, 1); // Abilita i tasti speciali (come le frecce)
    curs_set(0); 
    start_color(); //inizializza i colori

    menu();

    endwin();
    return 0;
}

void menu(){

    int flag = 0;

    int highlight = 0; // Indice dell'opzione evidenziata
    const char *choices[] = {"PLAY", "EXIT"};
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
        print_play(13,BORDER+42);
        print_exit(25,BORDER+42);

        if(flag == 0){
            print_arrow(17, BORDER+75);
        }
        else{
            print_arrow(29, BORDER+75);
        }
        refresh();
        
        int c = getch(); // Legge un carattere dalla tastiera
        switch (c) {
            case KEY_UP: // Freccia su: sposta l'evidenziazione sull'opzione precedente
                    highlight = (highlight - 1 + n_choices) % n_choices;

                    if (flag == 0){
                        flag = 1; 
                    }
                    else{
                        flag = 0;
                    }

                    break;
            case KEY_DOWN: // Freccia giù: sposta l'evidenziazione sull'opzione successiva
                    highlight = (highlight + 1) % n_choices;

                    if (flag == 0){
                        flag = 1; 
                    }
                    else{
                        flag = 0;
                    }

                    break;
            case '\n': // Invio: scegli l'opzione evidenziata
                if (strcmp(choices[highlight], "EXIT") == 0) {
                    // Esci dal programma
                    endwin();
                    exit(0);
                    return ;
                } else {
                // Inizia il programma
                    erase();
                    mvprintw(MAXY/2, MAXX/2-18, "IL GIOCO INIZIERA' TRA QUALCHE SECONDO...");
                    refresh();
                    scelta_difficolta();
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

