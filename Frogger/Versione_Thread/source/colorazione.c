#include "include.h"
#include "extern.h"

void print_screen_frame(){

    init_pair(12, COLOR_MAGENTA, COLOR_MAGENTA); // Crea una coppia di colori verde su nero


    //stampa bordo superiore
    attron(COLOR_PAIR(12));
    mvhline(3, BORDER,' ',MAXX-BORDER+1); //funzione che colora un'intera riga 
    attroff(COLOR_PAIR(12));



    //stampa bordo inferiore
    attron(COLOR_PAIR(12));
    mvhline(49, BORDER,' ',MAXX-BORDER); //funzione che colora un'intera riga 
    attroff(COLOR_PAIR(12));


    //stampa bordi destro e sinistro
    for (int i = 3 + 1; i < 50; i++) {
        attron(COLOR_PAIR(12));
        mvaddch(i, BORDER , ' ');
        mvaddch(i, MAXX, ' ');
        attroff(COLOR_PAIR(12));    

    }

}

void print_exit(int start_y, int start_x){

    init_pair(20, COLOR_BLACK, COLOR_BLACK);
    init_pair(21, COLOR_RED, COLOR_RED);

    attron(COLOR_PAIR(20));

    mvaddch(start_y, start_x+2, ' ');
    mvaddch(start_y, start_x+3, ' ');
    mvaddch(start_y, start_x+4, ' ');
    mvaddch(start_y, start_x+5, ' ');
    mvaddch(start_y, start_x+6, ' ');
    mvaddch(start_y, start_x+7, ' ');
    mvaddch(start_y, start_x+8, ' ');
    mvaddch(start_y, start_x+9, ' ');
    mvaddch(start_y, start_x+10, ' ');
    mvaddch(start_y, start_x+11, ' ');
    mvaddch(start_y, start_x+12, ' ');
    mvaddch(start_y, start_x+13, ' ');
    mvaddch(start_y, start_x+14, ' ');
    mvaddch(start_y, start_x+15, ' ');
    mvaddch(start_y, start_x+16, ' ');
    mvaddch(start_y, start_x+17, ' ');
    mvaddch(start_y, start_x+18, ' ');
    mvaddch(start_y, start_x+19, ' ');
    mvaddch(start_y, start_x+20, ' ');
    mvaddch(start_y, start_x+21, ' ');
    mvaddch(start_y, start_x+22, ' ');
    mvaddch(start_y, start_x+23, ' ');

    mvaddch(start_y+1, start_x+1, ' ');
    mvaddch(start_y+1, start_x+24, ' ');

    mvaddch(start_y+2, start_x, ' ');
    mvaddch(start_y+2, start_x+4, ' ');
    mvaddch(start_y+2, start_x+5, ' ');
    mvaddch(start_y+2, start_x+6, ' ');
    mvaddch(start_y+2, start_x+7, ' ');
    mvaddch(start_y+2, start_x+9, ' ');
    mvaddch(start_y+2, start_x+13, ' ');
    mvaddch(start_y+2, start_x+15, ' ');
    mvaddch(start_y+2, start_x+17, ' ');
    mvaddch(start_y+2, start_x+18, ' ');
    mvaddch(start_y+2, start_x+19, ' ');
    mvaddch(start_y+2, start_x+20, ' ');
    mvaddch(start_y+2, start_x+21, ' ');
    mvaddch(start_y+2, start_x+25, ' ');

    mvaddch(start_y+3, start_x, ' ');
    mvaddch(start_y+3, start_x+4, ' ');
    mvaddch(start_y+3, start_x+10, ' ');
    mvaddch(start_y+3, start_x+12, ' ');
    mvaddch(start_y+3, start_x+15, ' ');
    mvaddch(start_y+3, start_x+19, ' ');
    mvaddch(start_y+3, start_x+25, ' ');

    mvaddch(start_y+4, start_x, ' ');
    mvaddch(start_y+4, start_x+4, ' ');
    mvaddch(start_y+4, start_x+5, ' ');
    mvaddch(start_y+4, start_x+11, ' ');
    mvaddch(start_y+4, start_x+15, ' ');
    mvaddch(start_y+4, start_x+19, ' ');
    mvaddch(start_y+4, start_x+25, ' ');

    mvaddch(start_y+5, start_x, ' ');
    mvaddch(start_y+5, start_x+4, ' ');
    mvaddch(start_y+5, start_x+10, ' ');
    mvaddch(start_y+5, start_x+12, ' ');
    mvaddch(start_y+5, start_x+15, ' ');
    mvaddch(start_y+5, start_x+19, ' ');
    mvaddch(start_y+5, start_x+25, ' ');

    mvaddch(start_y+6, start_x, ' ');
    mvaddch(start_y+6, start_x+4, ' ');
    mvaddch(start_y+6, start_x+5, ' ');
    mvaddch(start_y+6, start_x+6, ' ');
    mvaddch(start_y+6, start_x+7, ' ');
    mvaddch(start_y+6, start_x+9, ' ');
    mvaddch(start_y+6, start_x+13, ' ');
    mvaddch(start_y+6, start_x+15, ' ');
    mvaddch(start_y+6, start_x+19, ' ');
    mvaddch(start_y+6, start_x+25, ' ');

    mvaddch(start_y+7, start_x+1, ' ');
    mvaddch(start_y+7, start_x+24, ' ');    

    mvaddch(start_y+8, start_x+2, ' ');
    mvaddch(start_y+8, start_x+3, ' ');
    mvaddch(start_y+8, start_x+4, ' ');
    mvaddch(start_y+8, start_x+5, ' ');
    mvaddch(start_y+8, start_x+6, ' ');
    mvaddch(start_y+8, start_x+7, ' ');
    mvaddch(start_y+8, start_x+8, ' ');
    mvaddch(start_y+8, start_x+9, ' ');
    mvaddch(start_y+8, start_x+10, ' ');
    mvaddch(start_y+8, start_x+11, ' ');
    mvaddch(start_y+8, start_x+12, ' ');
    mvaddch(start_y+8, start_x+13, ' ');
    mvaddch(start_y+8, start_x+14, ' ');
    mvaddch(start_y+8, start_x+15, ' ');
    mvaddch(start_y+8, start_x+16, ' ');
    mvaddch(start_y+8, start_x+17, ' ');
    mvaddch(start_y+8, start_x+18, ' ');
    mvaddch(start_y+8, start_x+19, ' ');
    mvaddch(start_y+8, start_x+20, ' ');
    mvaddch(start_y+8, start_x+21, ' ');
    mvaddch(start_y+8, start_x+22, ' ');
    mvaddch(start_y+8, start_x+23, ' ');


    attroff(COLOR_PAIR(20));

    attron(COLOR_PAIR(21));

    mvaddch(start_y+1, start_x+2, ' ');
    mvaddch(start_y+1, start_x+3, ' ');
    mvaddch(start_y+1, start_x+4, ' ');
    mvaddch(start_y+1, start_x+5, ' ');
    mvaddch(start_y+1, start_x+6, ' ');
    mvaddch(start_y+1, start_x+7, ' ');
    mvaddch(start_y+1, start_x+8, ' ');
    mvaddch(start_y+1, start_x+9, ' ');
    mvaddch(start_y+1, start_x+10, ' ');
    mvaddch(start_y+1, start_x+11, ' ');
    mvaddch(start_y+1, start_x+12, ' ');
    mvaddch(start_y+1, start_x+13, ' ');
    mvaddch(start_y+1, start_x+14, ' ');
    mvaddch(start_y+1, start_x+15, ' ');
    mvaddch(start_y+1, start_x+16, ' ');
    mvaddch(start_y+1, start_x+17, ' ');
    mvaddch(start_y+1, start_x+18, ' ');
    mvaddch(start_y+1, start_x+19, ' ');
    mvaddch(start_y+1, start_x+20, ' ');
    mvaddch(start_y+1, start_x+21, ' ');
    mvaddch(start_y+1, start_x+22, ' ');
    mvaddch(start_y+1, start_x+23, ' ');

    mvaddch(start_y+2, start_x+1, ' ');
    mvaddch(start_y+2, start_x+2, ' ');
    mvaddch(start_y+2, start_x+3, ' ');
    mvaddch(start_y+2, start_x+8, ' ');
    mvaddch(start_y+2, start_x+10, ' ');
    mvaddch(start_y+2, start_x+11, ' ');
    mvaddch(start_y+2, start_x+12, ' ');
    mvaddch(start_y+2, start_x+14, ' ');
    mvaddch(start_y+2, start_x+16, ' ');
    mvaddch(start_y+2, start_x+22, ' ');
    mvaddch(start_y+2, start_x+23, ' ');
    mvaddch(start_y+2, start_x+24, ' ');

    mvaddch(start_y+3, start_x+1, ' ');
    mvaddch(start_y+3, start_x+2, ' ');
    mvaddch(start_y+3, start_x+3, ' ');
    mvaddch(start_y+3, start_x+5, ' ');
    mvaddch(start_y+3, start_x+6, ' ');
    mvaddch(start_y+3, start_x+7, ' ');
    mvaddch(start_y+3, start_x+8, ' ');
    mvaddch(start_y+3, start_x+9, ' ');
    mvaddch(start_y+3, start_x+11, ' ');
    mvaddch(start_y+3, start_x+13, ' ');
    mvaddch(start_y+3, start_x+14, ' ');
    mvaddch(start_y+3, start_x+16, ' ');
    mvaddch(start_y+3, start_x+17, ' ');
    mvaddch(start_y+3, start_x+18, ' ');
    mvaddch(start_y+3, start_x+20, ' ');
    mvaddch(start_y+3, start_x+21, ' ');
    mvaddch(start_y+3, start_x+22, ' ');
    mvaddch(start_y+3, start_x+23, ' ');
    mvaddch(start_y+3, start_x+24, ' ');

    mvaddch(start_y+4, start_x+1, ' ');
    mvaddch(start_y+4, start_x+2, ' ');
    mvaddch(start_y+4, start_x+3, ' ');
    mvaddch(start_y+4, start_x+6, ' ');
    mvaddch(start_y+4, start_x+7, ' ');
    mvaddch(start_y+4, start_x+8, ' ');
    mvaddch(start_y+4, start_x+9, ' ');
    mvaddch(start_y+4, start_x+10, ' ');
    mvaddch(start_y+4, start_x+12, ' ');
    mvaddch(start_y+4, start_x+13, ' ');
    mvaddch(start_y+4, start_x+14, ' ');
    mvaddch(start_y+4, start_x+16, ' ');
    mvaddch(start_y+4, start_x+17, ' ');
    mvaddch(start_y+4, start_x+18, ' ');
    mvaddch(start_y+4, start_x+20, ' ');
    mvaddch(start_y+4, start_x+21, ' ');
    mvaddch(start_y+4, start_x+22, ' ');
    mvaddch(start_y+4, start_x+23, ' ');
    mvaddch(start_y+4, start_x+24, ' ');

    mvaddch(start_y+5, start_x+1, ' ');
    mvaddch(start_y+5, start_x+2, ' ');
    mvaddch(start_y+5, start_x+3, ' ');
    mvaddch(start_y+5, start_x+5, ' ');
    mvaddch(start_y+5, start_x+6, ' ');
    mvaddch(start_y+5, start_x+7, ' ');
    mvaddch(start_y+5, start_x+8, ' ');
    mvaddch(start_y+5, start_x+9, ' ');
    mvaddch(start_y+5, start_x+11, ' ');
    mvaddch(start_y+5, start_x+13, ' ');
    mvaddch(start_y+5, start_x+14, ' ');
    mvaddch(start_y+5, start_x+16, ' ');
    mvaddch(start_y+5, start_x+17, ' ');
    mvaddch(start_y+5, start_x+18, ' ');
    mvaddch(start_y+5, start_x+20, ' ');
    mvaddch(start_y+5, start_x+21, ' ');
    mvaddch(start_y+5, start_x+22, ' ');
    mvaddch(start_y+5, start_x+23, ' ');
    mvaddch(start_y+5, start_x+24, ' ');

    mvaddch(start_y+6, start_x+1, ' ');
    mvaddch(start_y+6, start_x+2, ' ');
    mvaddch(start_y+6, start_x+3, ' ');
    mvaddch(start_y+6, start_x+8, ' ');
    mvaddch(start_y+6, start_x+10, ' ');
    mvaddch(start_y+6, start_x+11, ' ');
    mvaddch(start_y+6, start_x+12, ' ');
    mvaddch(start_y+6, start_x+14, ' ');
    mvaddch(start_y+6, start_x+16, ' ');
    mvaddch(start_y+6, start_x+17, ' ');
    mvaddch(start_y+6, start_x+18, ' ');
    mvaddch(start_y+6, start_x+20, ' ');
    mvaddch(start_y+6, start_x+21, ' ');
    mvaddch(start_y+6, start_x+22, ' ');
    mvaddch(start_y+6, start_x+23, ' ');
    mvaddch(start_y+6, start_x+24, ' ');


    mvaddch(start_y+7, start_x+2, ' ');
    mvaddch(start_y+7, start_x+3, ' ');
    mvaddch(start_y+7, start_x+4, ' ');
    mvaddch(start_y+7, start_x+5, ' ');
    mvaddch(start_y+7, start_x+6, ' ');
    mvaddch(start_y+7, start_x+7, ' ');
    mvaddch(start_y+7, start_x+8, ' ');
    mvaddch(start_y+7, start_x+9, ' ');
    mvaddch(start_y+7, start_x+10, ' ');
    mvaddch(start_y+7, start_x+11, ' ');
    mvaddch(start_y+7, start_x+12, ' ');
    mvaddch(start_y+7, start_x+13, ' ');
    mvaddch(start_y+7, start_x+14, ' ');
    mvaddch(start_y+7, start_x+15, ' ');
    mvaddch(start_y+7, start_x+16, ' ');
    mvaddch(start_y+7, start_x+17, ' ');
    mvaddch(start_y+7, start_x+18, ' ');
    mvaddch(start_y+7, start_x+19, ' ');
    mvaddch(start_y+7, start_x+20, ' ');
    mvaddch(start_y+7, start_x+21, ' ');
    mvaddch(start_y+7, start_x+22, ' ');
    mvaddch(start_y+7, start_x+23, ' ');

    attroff(COLOR_PAIR(21));


}

void print_arrow(int start_y, int start_x){

    init_pair(18, COLOR_BLACK, COLOR_BLACK);

    attron(COLOR_PAIR(18));

    mvaddch(start_y, start_x, ' ');
    mvaddch(start_y, start_x+1, ' ');
    mvaddch(start_y, start_x+2, ' ');
    mvaddch(start_y, start_x+3, ' ');
    mvaddch(start_y, start_x+4, ' ');
    mvaddch(start_y, start_x+5, ' ');
    mvaddch(start_y, start_x+6, ' ');


    attroff(COLOR_PAIR(18));
}

void print_play(int start_y, int start_x){


    
    init_pair(17, COLOR_BLACK, COLOR_BLACK);
    init_pair(19, COLOR_GREEN, COLOR_GREEN);

    attron(COLOR_PAIR(17));

    mvaddch(start_y, start_x+2, ' ');
    mvaddch(start_y, start_x+3, ' ');
    mvaddch(start_y, start_x+4, ' ');
    mvaddch(start_y, start_x+5, ' ');
    mvaddch(start_y, start_x+6, ' ');
    mvaddch(start_y, start_x+7, ' ');
    mvaddch(start_y, start_x+8, ' ');
    mvaddch(start_y, start_x+9, ' ');
    mvaddch(start_y, start_x+10, ' ');
    mvaddch(start_y, start_x+11, ' ');
    mvaddch(start_y, start_x+12, ' ');
    mvaddch(start_y, start_x+13, ' ');
    mvaddch(start_y, start_x+14, ' ');
    mvaddch(start_y, start_x+15, ' ');
    mvaddch(start_y, start_x+16, ' ');
    mvaddch(start_y, start_x+17, ' ');
    mvaddch(start_y, start_x+18, ' ');
    mvaddch(start_y, start_x+19, ' ');
    mvaddch(start_y, start_x+20, ' ');
    mvaddch(start_y, start_x+21, ' ');
    mvaddch(start_y, start_x+22, ' ');
    mvaddch(start_y, start_x+23, ' ');

    mvaddch(start_y+1, start_x+1, ' ');
    mvaddch(start_y+1, start_x+24, ' ');

    mvaddch(start_y+2, start_x, ' ');
    mvaddch(start_y+2, start_x+3, ' ');
    mvaddch(start_y+2, start_x+4, ' ');
    mvaddch(start_y+2, start_x+5, ' ');
    mvaddch(start_y+2, start_x+8, ' ');
    mvaddch(start_y+2, start_x+14, ' ');
    mvaddch(start_y+2, start_x+15, ' ');
    mvaddch(start_y+2, start_x+18, ' ');
    mvaddch(start_y+2, start_x+22, ' ');
    mvaddch(start_y+2, start_x+25, ' ');

    mvaddch(start_y+3, start_x, ' ');
    mvaddch(start_y+3, start_x+3, ' ');
    mvaddch(start_y+3, start_x+6, ' ');
    mvaddch(start_y+3, start_x+8, ' ');
    mvaddch(start_y+3, start_x+13, ' ');
    mvaddch(start_y+3, start_x+16, ' ');
    mvaddch(start_y+3, start_x+18, ' ');
    mvaddch(start_y+3, start_x+22, ' ');
    mvaddch(start_y+3, start_x+25, ' ');

    mvaddch(start_y+4, start_x, ' ');
    mvaddch(start_y+4, start_x+3, ' ');
    mvaddch(start_y+4, start_x+4, ' ');
    mvaddch(start_y+4, start_x+5, ' ');
    mvaddch(start_y+4, start_x+8, ' ');
    mvaddch(start_y+4, start_x+13, ' ');
    mvaddch(start_y+4, start_x+14, ' ');
    mvaddch(start_y+4, start_x+15, ' ');
    mvaddch(start_y+4, start_x+16, ' ');
    mvaddch(start_y+4, start_x+19, ' ');
    mvaddch(start_y+4, start_x+20, ' ');
    mvaddch(start_y+4, start_x+21, ' ');
    mvaddch(start_y+4, start_x+25, ' ');

    
    mvaddch(start_y+5, start_x, ' ');
    mvaddch(start_y+5, start_x+3, ' ');
    mvaddch(start_y+5, start_x+8, ' ');
    mvaddch(start_y+5, start_x+13, ' ');
    mvaddch(start_y+5, start_x+16, ' ');
    mvaddch(start_y+5, start_x+20, ' ');
    mvaddch(start_y+5, start_x+25, ' ');

    mvaddch(start_y+6, start_x, ' ');
    mvaddch(start_y+6, start_x+3, ' ');
    mvaddch(start_y+6, start_x+8, ' ');
    mvaddch(start_y+6, start_x+9, ' ');
    mvaddch(start_y+6, start_x+10, ' ');
    mvaddch(start_y+6, start_x+11, ' ');
    mvaddch(start_y+6, start_x+13, ' ');
    mvaddch(start_y+6, start_x+16, ' ');
    mvaddch(start_y+6, start_x+20, ' ');
    mvaddch(start_y+6, start_x+25, ' ');

    mvaddch(start_y+7, start_x+1, ' ');
    mvaddch(start_y+7, start_x+24, ' ');

    mvaddch(start_y+8, start_x+2, ' ');
    mvaddch(start_y+8, start_x+3, ' ');
    mvaddch(start_y+8, start_x+4, ' ');
    mvaddch(start_y+8, start_x+5, ' ');
    mvaddch(start_y+8, start_x+6, ' ');
    mvaddch(start_y+8, start_x+7, ' ');
    mvaddch(start_y+8, start_x+8, ' ');
    mvaddch(start_y+8, start_x+9, ' ');
    mvaddch(start_y+8, start_x+10, ' ');
    mvaddch(start_y+8, start_x+11, ' ');
    mvaddch(start_y+8, start_x+12, ' ');
    mvaddch(start_y+8, start_x+13, ' ');
    mvaddch(start_y+8, start_x+14, ' ');
    mvaddch(start_y+8, start_x+15, ' ');
    mvaddch(start_y+8, start_x+16, ' ');
    mvaddch(start_y+8, start_x+17, ' ');
    mvaddch(start_y+8, start_x+18, ' ');
    mvaddch(start_y+8, start_x+19, ' ');
    mvaddch(start_y+8, start_x+20, ' ');
    mvaddch(start_y+8, start_x+21, ' ');
    mvaddch(start_y+8, start_x+22, ' ');
    mvaddch(start_y+8, start_x+23, ' ');


    attroff(COLOR_PAIR(17));
    
    

    attron(COLOR_PAIR(19));

    mvaddch(start_y+1, start_x+2, ' ');
    mvaddch(start_y+1, start_x+3, ' ');
    mvaddch(start_y+1, start_x+4, ' ');
    mvaddch(start_y+1, start_x+5, ' ');
    mvaddch(start_y+1, start_x+6, ' ');
    mvaddch(start_y+1, start_x+7, ' ');
    mvaddch(start_y+1, start_x+8, ' ');
    mvaddch(start_y+1, start_x+9, ' ');
    mvaddch(start_y+1, start_x+10, ' ');
    mvaddch(start_y+1, start_x+11, ' ');
    mvaddch(start_y+1, start_x+12, ' ');
    mvaddch(start_y+1, start_x+13, ' ');
    mvaddch(start_y+1, start_x+14, ' ');
    mvaddch(start_y+1, start_x+15, ' ');
    mvaddch(start_y+1, start_x+16, ' ');
    mvaddch(start_y+1, start_x+17, ' ');
    mvaddch(start_y+1, start_x+18, ' ');
    mvaddch(start_y+1, start_x+19, ' ');
    mvaddch(start_y+1, start_x+20, ' ');
    mvaddch(start_y+1, start_x+21, ' ');
    mvaddch(start_y+1, start_x+22, ' ');
    mvaddch(start_y+1, start_x+23, ' ');

    
    mvaddch(start_y+2, start_x+1, ' ');
    mvaddch(start_y+2, start_x+2, ' ');
    mvaddch(start_y+2, start_x+6, ' ');
    mvaddch(start_y+2, start_x+7, ' ');
    mvaddch(start_y+2, start_x+9, ' ');
    mvaddch(start_y+2, start_x+10, ' ');
    mvaddch(start_y+2, start_x+11, ' ');
    mvaddch(start_y+2, start_x+12, ' ');
    mvaddch(start_y+2, start_x+13, ' ');
    mvaddch(start_y+2, start_x+16, ' ');
    mvaddch(start_y+2, start_x+17, ' ');
    mvaddch(start_y+2, start_x+19, ' ');
    mvaddch(start_y+2, start_x+20, ' ');
    mvaddch(start_y+2, start_x+21, ' ');
    mvaddch(start_y+2, start_x+23, ' ');
    mvaddch(start_y+2, start_x+24, ' ');



    mvaddch(start_y+3, start_x+1, ' ');
    mvaddch(start_y+3, start_x+2, ' ');
    mvaddch(start_y+3, start_x+4, ' ');
    mvaddch(start_y+3, start_x+5, ' ');
    mvaddch(start_y+3, start_x+7, ' ');
    mvaddch(start_y+3, start_x+9, ' ');
    mvaddch(start_y+3, start_x+10, ' ');
    mvaddch(start_y+3, start_x+11, ' ');
    mvaddch(start_y+3, start_x+12, ' ');
    mvaddch(start_y+3, start_x+14, ' ');
    mvaddch(start_y+3, start_x+15, ' ');
    mvaddch(start_y+3, start_x+17, ' ');
    mvaddch(start_y+3, start_x+19, ' ');
    mvaddch(start_y+3, start_x+20, ' ');
    mvaddch(start_y+3, start_x+21, ' ');
    mvaddch(start_y+3, start_x+23, ' ');   
    mvaddch(start_y+3, start_x+24, ' ');   


    mvaddch(start_y+4, start_x+1, ' ');
    mvaddch(start_y+4, start_x+2, ' '); 
    mvaddch(start_y+4, start_x+6, ' '); 
    mvaddch(start_y+4, start_x+7, ' '); 
    mvaddch(start_y+4, start_x+9, ' '); 
    mvaddch(start_y+4, start_x+10, ' '); 
    mvaddch(start_y+4, start_x+11, ' '); 
    mvaddch(start_y+4, start_x+12, ' '); 
    mvaddch(start_y+4, start_x+17, ' '); 
    mvaddch(start_y+4, start_x+18, ' '); 
    mvaddch(start_y+4, start_x+22, ' '); 
    mvaddch(start_y+4, start_x+23, ' '); 
    mvaddch(start_y+4, start_x+24, ' '); 

    mvaddch(start_y+5, start_x+1, ' ');
    mvaddch(start_y+5, start_x+2, ' '); 
    mvaddch(start_y+5, start_x+4, ' '); 
    mvaddch(start_y+5, start_x+5, ' '); 
    mvaddch(start_y+5, start_x+6, ' '); 
    mvaddch(start_y+5, start_x+7, ' '); 
    mvaddch(start_y+5, start_x+9, ' '); 
    mvaddch(start_y+5, start_x+10, ' '); 
    mvaddch(start_y+5, start_x+11, ' '); 
    mvaddch(start_y+5, start_x+12, ' '); 
    mvaddch(start_y+5, start_x+14, ' '); 
    mvaddch(start_y+5, start_x+15, ' '); 
    mvaddch(start_y+5, start_x+17, ' '); 
    mvaddch(start_y+5, start_x+18, ' '); 
    mvaddch(start_y+5, start_x+19, ' '); 
    mvaddch(start_y+5, start_x+21, ' '); 
    mvaddch(start_y+5, start_x+22, ' '); 
    mvaddch(start_y+5, start_x+23, ' '); 
    mvaddch(start_y+5, start_x+24, ' '); 

    mvaddch(start_y+6, start_x+1, ' ');
    mvaddch(start_y+6, start_x+2, ' '); 
    mvaddch(start_y+6, start_x+4, ' '); 
    mvaddch(start_y+6, start_x+5, ' '); 
    mvaddch(start_y+6, start_x+6, ' '); 
    mvaddch(start_y+6, start_x+7, ' ');
    mvaddch(start_y+6, start_x+12, ' '); 
    mvaddch(start_y+6, start_x+14, ' '); 
    mvaddch(start_y+6, start_x+15, ' '); 
    mvaddch(start_y+6, start_x+17, ' '); 
    mvaddch(start_y+6, start_x+18, ' '); 
    mvaddch(start_y+6, start_x+19, ' '); 
    mvaddch(start_y+6, start_x+21, ' '); 
    mvaddch(start_y+6, start_x+22, ' '); 
    mvaddch(start_y+6, start_x+23, ' '); 
    mvaddch(start_y+6, start_x+24, ' '); 

     

    mvaddch(start_y+7, start_x+2, ' ');
    mvaddch(start_y+7, start_x+3, ' ');
    mvaddch(start_y+7, start_x+4, ' ');
    mvaddch(start_y+7, start_x+5, ' ');
    mvaddch(start_y+7, start_x+6, ' ');
    mvaddch(start_y+7, start_x+7, ' ');
    mvaddch(start_y+7, start_x+8, ' ');
    mvaddch(start_y+7, start_x+9, ' ');
    mvaddch(start_y+7, start_x+10, ' ');
    mvaddch(start_y+7, start_x+11, ' ');
    mvaddch(start_y+7, start_x+12, ' ');
    mvaddch(start_y+7, start_x+13, ' ');
    mvaddch(start_y+7, start_x+14, ' ');
    mvaddch(start_y+7, start_x+15, ' ');
    mvaddch(start_y+7, start_x+16, ' ');
    mvaddch(start_y+7, start_x+17, ' ');
    mvaddch(start_y+7, start_x+18, ' ');
    mvaddch(start_y+7, start_x+19, ' ');
    mvaddch(start_y+7, start_x+20, ' ');
    mvaddch(start_y+7, start_x+21, ' ');
    mvaddch(start_y+7, start_x+22, ' ');
    mvaddch(start_y+7, start_x+23, ' ');

    attroff(COLOR_PAIR(19));

}

void print_frog(int start_y, int start_x){


    init_pair(14, COLOR_BLACK, COLOR_BLACK);
    init_pair(15, COLOR_WHITE, COLOR_WHITE);
    init_pair(16, COLOR_GREEN, COLOR_GREEN);

    attron(COLOR_PAIR(14));

    mvaddch(start_y, start_x+3, ' ');
    mvaddch(start_y, start_x+4, ' ');
    mvaddch(start_y, start_x+5, ' ');

    mvaddch(start_y, start_x+11, ' ');
    mvaddch(start_y, start_x+12, ' ');
    mvaddch(start_y, start_x+13, ' ');


    mvaddch(start_y+1, start_x+2, ' ');
    mvaddch(start_y+1, start_x+6, ' ');
    mvaddch(start_y+1, start_x+10, ' ');
    mvaddch(start_y+1, start_x+14, ' ');

    mvaddch(start_y+2, start_x+1, ' ');    
    mvaddch(start_y+2, start_x+3, ' ');
    mvaddch(start_y+2, start_x+4, ' ');
    mvaddch(start_y+2, start_x+7, ' ');
    mvaddch(start_y+2, start_x+8, ' ');
    mvaddch(start_y+2, start_x+9, ' ');
    mvaddch(start_y+2, start_x+12, ' ');
    mvaddch(start_y+2, start_x+13, ' ');
    mvaddch(start_y+2, start_x+15, ' ');

    mvaddch(start_y+3, start_x+1, ' ');    
    mvaddch(start_y+3, start_x+3, ' ');
    mvaddch(start_y+3, start_x+4, ' ');
    mvaddch(start_y+3, start_x+12, ' ');
    mvaddch(start_y+3, start_x+13, ' ');
    mvaddch(start_y+3, start_x+15, ' ');

    mvaddch(start_y+4, start_x+1, ' ');    
    mvaddch(start_y+4, start_x+15, ' ');    

    mvaddch(start_y+5, start_x+2, ' ');    
    mvaddch(start_y+5, start_x+14, ' ');    

    mvaddch(start_y+6, start_x+1, ' ');    
    mvaddch(start_y+6, start_x+15, ' '); 

    mvaddch(start_y+7, start_x, ' ');
    mvaddch(start_y+7, start_x+3, ' ');
    mvaddch(start_y+7, start_x+13, ' ');
    mvaddch(start_y+7, start_x+16, ' ');

    mvaddch(start_y+8, start_x, ' ');
    mvaddch(start_y+8, start_x+4, ' ');
    mvaddch(start_y+8, start_x+5, ' ');
    mvaddch(start_y+8, start_x+6, ' ');
    mvaddch(start_y+8, start_x+7, ' ');
    mvaddch(start_y+8, start_x+8, ' ');
    mvaddch(start_y+8, start_x+9, ' ');
    mvaddch(start_y+8, start_x+10, ' ');
    mvaddch(start_y+8, start_x+11, ' ');
    mvaddch(start_y+8, start_x+12, ' ');
    mvaddch(start_y+8, start_x+16, ' ');

    mvaddch(start_y+9, start_x+1, ' ');    
    mvaddch(start_y+9, start_x+15, ' '); 

    mvaddch(start_y+10, start_x+2, ' ');
    mvaddch(start_y+10, start_x+3, ' ');
    mvaddch(start_y+10, start_x+4, ' ');
    mvaddch(start_y+10, start_x+12, ' ');
    mvaddch(start_y+10, start_x+13, ' ');
    mvaddch(start_y+10, start_x+14, ' ');

    mvaddch(start_y+11, start_x+3,' ');
    mvaddch(start_y+11, start_x +13, ' ');

    mvaddch(start_y+12, start_x +1, ' ');
    mvaddch(start_y+12, start_x +2, ' ');
    mvaddch(start_y+12, start_x +14, ' ');
    mvaddch(start_y+12, start_x +15, ' ');

    mvaddch(start_y+13, start_x, ' ');
    mvaddch(start_y+13, start_x+2, ' ');
    mvaddch(start_y+13, start_x+14, ' ');
    mvaddch(start_y+13, start_x+16, ' ');

    mvaddch(start_y+14, start_x, ' ');
    mvaddch(start_y+14, start_x+4, ' ');
    mvaddch(start_y+14, start_x+6, ' ');
    mvaddch(start_y+14, start_x+10, ' ');
    mvaddch(start_y+14, start_x+12, ' ');
    mvaddch(start_y+14, start_x+16, ' ');

    mvaddch(start_y+15, start_x+1, ' ');
    mvaddch(start_y+15, start_x+2, ' ');
    mvaddch(start_y+15, start_x+3, ' ');
    mvaddch(start_y+15, start_x+5, ' ');
    mvaddch(start_y+15, start_x+7, ' ');
    mvaddch(start_y+15, start_x+8, ' ');
    mvaddch(start_y+15, start_x+9, ' ');
    mvaddch(start_y+15, start_x+11, ' ');
    mvaddch(start_y+15, start_x+13, ' ');
    mvaddch(start_y+15, start_x+14, ' ');
    mvaddch(start_y+15, start_x+15, ' ');


    attroff(COLOR_PAIR(14));


    attron(COLOR_PAIR(15));

    mvaddch(start_y+1, start_x+3, ' ');
    mvaddch(start_y+1, start_x+4, ' ');
    mvaddch(start_y+1, start_x+5, ' ');
    mvaddch(start_y+1, start_x+11, ' ');
    mvaddch(start_y+1, start_x+12, ' ');
    mvaddch(start_y+1, start_x+13, ' ');

    mvaddch(start_y+2, start_x+2, ' ');
    mvaddch(start_y+2, start_x+5, ' ');
    mvaddch(start_y+2, start_x+6, ' ');
    mvaddch(start_y+2, start_x+10, ' ');
    mvaddch(start_y+2, start_x+11, ' ');
    mvaddch(start_y+2, start_x+14, ' ');

    mvaddch(start_y+3, start_x+2, ' ');
    mvaddch(start_y+3, start_x+5, ' ');
    mvaddch(start_y+3, start_x+6, ' ');
    mvaddch(start_y+3, start_x+10, ' ');
    mvaddch(start_y+3, start_x+11, ' ');
    mvaddch(start_y+3, start_x+14, ' ');

    mvaddch(start_y+4, start_x+2, ' ');
    mvaddch(start_y+4, start_x+3, ' ');
    mvaddch(start_y+4, start_x+4, ' ');
    mvaddch(start_y+4, start_x+5, ' ');
    mvaddch(start_y+4, start_x+6, ' ');
    mvaddch(start_y+4, start_x+10, ' ');
    mvaddch(start_y+4, start_x+11, ' ');
    mvaddch(start_y+4, start_x+12, ' ');
    mvaddch(start_y+4, start_x+13, ' ');
    mvaddch(start_y+4, start_x+14, ' ');

    mvaddch(start_y+5, start_x+3, ' ');
    mvaddch(start_y+5, start_x+4, ' ');
    mvaddch(start_y+5, start_x+5, ' ');
    mvaddch(start_y+5, start_x+11, ' ');
    mvaddch(start_y+5, start_x+12, ' ');
    mvaddch(start_y+5, start_x+13, ' ');

    mvaddch(start_y+12, start_x+8, ' ');

    mvaddch(start_y+13, start_x+7, ' ');
    mvaddch(start_y+13, start_x+8, ' ');
    mvaddch(start_y+13, start_x+9, ' ');

    mvaddch(start_y+14, start_x+7, ' ');
    mvaddch(start_y+14, start_x+8, ' ');
    mvaddch(start_y+14, start_x+9, ' ');    

    attroff(COLOR_PAIR(15));


    attron(COLOR_PAIR(16));

    mvaddch(start_y+3, start_x+7, ' ');    
    mvaddch(start_y+3, start_x+8, ' ');
    mvaddch(start_y+3, start_x+9, ' ');

    mvaddch(start_y+4, start_x+7, ' ');    
    mvaddch(start_y+4, start_x+8, ' ');
    mvaddch(start_y+4, start_x+9, ' ');  

    mvaddch(start_y+5, start_x+6,' ');
    mvaddch(start_y+5, start_x+7, ' ');
    mvaddch(start_y+5, start_x+8, ' ');    
    mvaddch(start_y+5, start_x+9, ' ');
    mvaddch(start_y+5, start_x+10, ' ');   

    mvaddch(start_y+6, start_x+2, ' ');    
    mvaddch(start_y+6, start_x+3, ' ');    
    mvaddch(start_y+6, start_x+4, ' ');    
    mvaddch(start_y+6, start_x+5, ' ');    
    mvaddch(start_y+6, start_x+6, ' ');    
    mvaddch(start_y+6, start_x+7, ' ');    
    mvaddch(start_y+6, start_x+8, ' ');    
    mvaddch(start_y+6, start_x+9, ' ');    
    mvaddch(start_y+6, start_x+10, ' ');    
    mvaddch(start_y+6, start_x+11, ' ');    
    mvaddch(start_y+6, start_x+12, ' ');    
    mvaddch(start_y+6, start_x+13, ' ');    
    mvaddch(start_y+6, start_x+14, ' ');    


    mvaddch(start_y+7, start_x+1, ' ');
    mvaddch(start_y+7, start_x+2, ' ');
    mvaddch(start_y+7, start_x+4, ' ');
    mvaddch(start_y+7, start_x+5, ' ');
    mvaddch(start_y+7, start_x+6, ' ');
    mvaddch(start_y+7, start_x+7, ' ');
    mvaddch(start_y+7, start_x+8, ' ');
    mvaddch(start_y+7, start_x+9, ' ');
    mvaddch(start_y+7, start_x+10, ' ');
    mvaddch(start_y+7, start_x+11, ' ');
    mvaddch(start_y+7, start_x+12, ' ');
    mvaddch(start_y+7, start_x+14, ' ');
    mvaddch(start_y+7, start_x+15, ' ');


    mvaddch(start_y+8, start_x+1, ' ');
    mvaddch(start_y+8, start_x+2, ' ');
    mvaddch(start_y+8, start_x+3, ' ');
    mvaddch(start_y+8, start_x+13, ' ');
    mvaddch(start_y+8, start_x+14, ' ');
    mvaddch(start_y+8, start_x+15, ' ');
    
    mvaddch(start_y+9, start_x+2, ' ');    
    mvaddch(start_y+9, start_x+3, ' ');    
    mvaddch(start_y+9, start_x+4, ' ');    
    mvaddch(start_y+9, start_x+5, ' ');    
    mvaddch(start_y+9, start_x+6, ' ');    
    mvaddch(start_y+9, start_x+7, ' ');    
    mvaddch(start_y+9, start_x+8, ' ');    
    mvaddch(start_y+9, start_x+9, ' ');    
    mvaddch(start_y+9, start_x+10, ' ');    
    mvaddch(start_y+9, start_x+11, ' ');    
    mvaddch(start_y+9, start_x+12, ' ');    
    mvaddch(start_y+9, start_x+13, ' ');    
    mvaddch(start_y+9, start_x+14, ' ');

    mvaddch(start_y+10, start_x+5, ' ');
    mvaddch(start_y+10, start_x+6, ' ');
    mvaddch(start_y+10, start_x+7, ' ');
    mvaddch(start_y+10, start_x+8, ' ');
    mvaddch(start_y+10, start_x+9, ' ');
    mvaddch(start_y+10, start_x+10, ' ');
    mvaddch(start_y+10, start_x+11, ' ');

    mvaddch(start_y+11, start_x+4, ' ');
    mvaddch(start_y+11, start_x+5, ' ');
    mvaddch(start_y+11, start_x+6, ' ');
    mvaddch(start_y+11, start_x+7, ' ');
    mvaddch(start_y+11, start_x+8, ' ');
    mvaddch(start_y+11, start_x+9, ' ');
    mvaddch(start_y+11, start_x+10, ' ');
    mvaddch(start_y+11, start_x+11, ' ');
    mvaddch(start_y+11, start_x+12, ' ');

    mvaddch(start_y+12, start_x+3, ' ');
    mvaddch(start_y+12, start_x+4, ' ');
    mvaddch(start_y+12, start_x+5, ' ');
    mvaddch(start_y+12, start_x+6, ' ');
    mvaddch(start_y+12, start_x+7, ' ');
    mvaddch(start_y+12, start_x+9, ' ');
    mvaddch(start_y+12, start_x+10, ' ');
    mvaddch(start_y+12, start_x+11, ' ');
    mvaddch(start_y+12, start_x+12, ' ');
    mvaddch(start_y+12, start_x+13, ' ');

    mvaddch(start_y+13, start_x+1, ' ');
    mvaddch(start_y+13, start_x+3, ' ');
    mvaddch(start_y+13, start_x+4, ' ');
    mvaddch(start_y+13, start_x+5, ' ');
    mvaddch(start_y+13, start_x+6, ' ');
    mvaddch(start_y+13, start_x+10, ' ');
    mvaddch(start_y+13, start_x+11, ' ');
    mvaddch(start_y+13, start_x+12, ' ');
    mvaddch(start_y+13, start_x+13, ' ');
    mvaddch(start_y+13, start_x+15, ' ');

    mvaddch(start_y+14, start_x+1, ' ');
    mvaddch(start_y+14, start_x+2, ' ');
    mvaddch(start_y+14, start_x+3, ' ');
    mvaddch(start_y+14, start_x+5, ' ');
    mvaddch(start_y+14, start_x+6, ' ');
    mvaddch(start_y+14, start_x+11, ' ');
    mvaddch(start_y+14, start_x+13, ' ');
    mvaddch(start_y+14, start_x+14, ' ');
    mvaddch(start_y+14, start_x+15, ' ');

    attroff(COLOR_PAIR(16));
}

void print_frogger(){

    //stampa la F

    int start_y = 40;
    int start_x = BORDER+25;

    init_pair(13, COLOR_WHITE,COLOR_WHITE );

    //stampa la F
    attron(COLOR_PAIR(13));
    mvaddch(start_y,start_x,' ');
        mvaddch(start_y,start_x+1,' ');
        mvaddch(start_y,start_x+2,' ');
        mvaddch(start_y,start_x+3,' ');

    mvaddch(start_y+1,start_x,' ');
    mvaddch(start_y+2,start_x,' ');
        mvaddch(start_y+2,start_x+1,' ');
        mvaddch(start_y+2,start_x+2,' ');

    mvaddch(start_y+3,start_x,' ');
    mvaddch(start_y+4,start_x,' ');
    mvaddch(start_y+5,start_x,' ');
    mvaddch(start_y+6,start_x,' ');

    start_x += 6; 

    //stampo la lettera R

    mvaddch(start_y, start_x, ' ');
        mvaddch(start_y, start_x+1, ' ');
        mvaddch(start_y, start_x+2, ' ');
        mvaddch(start_y, start_x+3, ' ');
    
    mvaddch(start_y+1, start_x, ' ');
        mvaddch(start_y+1, start_x+3, ' ');

    mvaddch(start_y+2, start_x, ' ');
        mvaddch(start_y+2, start_x+3, ' ');

    mvaddch(start_y+3, start_x, ' ');
        mvaddch(start_y+3, start_x+1, ' ');
        mvaddch(start_y+3, start_x+2, ' ');
        mvaddch(start_y+3, start_x+3, ' ');
    
    mvaddch(start_y+4, start_x, ' ');
        mvaddch(start_y+4, start_x+2, ' ');

    mvaddch(start_y+5, start_x, ' ');
        mvaddch(start_y+5, start_x+3, ' ');

    mvaddch(start_y+6, start_x, ' ');
        mvaddch(start_y+6, start_x+3, ' ');

    start_x += 6; 

    //stampo la lettera o


    mvaddch(start_y, start_x+1, ' ');
        mvaddch(start_y, start_x+2, ' ');
    
    mvaddch(start_y+1, start_x, ' ');
        mvaddch(start_y+1, start_x+3, ' '); 
    mvaddch(start_y+2, start_x, ' ');
        mvaddch(start_y+2, start_x+3, ' ');
    mvaddch(start_y+3, start_x, ' ');
        mvaddch(start_y+3, start_x+3, ' ');
    mvaddch(start_y+4, start_x, ' ');
        mvaddch(start_y+4, start_x+3, ' ');
    mvaddch(start_y+5, start_x, ' ');
        mvaddch(start_y+5, start_x+3, ' ');

    mvaddch(start_y+6, start_x+1, ' ');
        mvaddch(start_y+6, start_x+2, ' ');

    start_x += 6; 


    //stampo la lettera G

    mvaddch(start_y, start_x+1, ' ');
        mvaddch(start_y, start_x+2, ' ');   
    
    mvaddch(start_y+1, start_x, ' ');
        mvaddch(start_y+1, start_x+3, ' ');

    mvaddch(start_y+2, start_x, ' ');
    mvaddch(start_y+3, start_x, ' ');

    mvaddch(start_y+4, start_x, ' ');
        mvaddch(start_y+4, start_x+2, ' ');
        mvaddch(start_y+4, start_x+3, ' ');

    mvaddch(start_y+5, start_x, ' ');
        mvaddch(start_y+5, start_x+3, ' ');

    mvaddch(start_y+6, start_x+1, ' ');
        mvaddch(start_y+6, start_x+2, ' ');  



    start_x += 6; 


    //stampo la lettera G

    mvaddch(start_y, start_x+1, ' ');
        mvaddch(start_y, start_x+2, ' ');   
    
    mvaddch(start_y+1, start_x, ' ');
        mvaddch(start_y+1, start_x+3, ' ');

    mvaddch(start_y+2, start_x, ' ');
    mvaddch(start_y+3, start_x, ' ');

    mvaddch(start_y+4, start_x, ' ');
        mvaddch(start_y+4, start_x+2, ' ');
        mvaddch(start_y+4, start_x+3, ' ');

    mvaddch(start_y+5, start_x, ' ');
        mvaddch(start_y+5, start_x+3, ' ');

    mvaddch(start_y+6, start_x+1, ' ');
        mvaddch(start_y+6, start_x+2, ' ');  



    start_x += 6; 

    //stampo la lettera E

    mvaddch(start_y, start_x, ' ');
        mvaddch(start_y, start_x+1, ' ');
        mvaddch(start_y, start_x+2, ' ');
        mvaddch(start_y, start_x+3, ' ');
    
    mvaddch(start_y+1, start_x, ' ');
    mvaddch(start_y+2, start_x, ' ');

    mvaddch(start_y+3, start_x, ' ');
        mvaddch(start_y+3, start_x+1, ' ');
        mvaddch(start_y+3, start_x+2, ' ');
    
    mvaddch(start_y+4, start_x, ' ');
    mvaddch(start_y+5, start_x, ' ');

    mvaddch(start_y+6, start_x, ' ');
        mvaddch(start_y+6, start_x+1, ' ');
        mvaddch(start_y+6, start_x+2, ' ');
        mvaddch(start_y+6, start_x+3, ' ');

    start_x += 6;

    //stampo la lettera R

    mvaddch(start_y, start_x, ' ');
        mvaddch(start_y, start_x+1, ' ');
        mvaddch(start_y, start_x+2, ' ');
        mvaddch(start_y, start_x+3, ' ');
    
    mvaddch(start_y+1, start_x, ' ');
        mvaddch(start_y+1, start_x+3, ' ');

    mvaddch(start_y+2, start_x, ' ');
        mvaddch(start_y+2, start_x+3, ' ');

    mvaddch(start_y+3, start_x, ' ');
        mvaddch(start_y+3, start_x+1, ' ');
        mvaddch(start_y+3, start_x+2, ' ');
        mvaddch(start_y+3, start_x+3, ' ');
    
    mvaddch(start_y+4, start_x, ' ');
        mvaddch(start_y+4, start_x+2, ' ');

    mvaddch(start_y+5, start_x, ' ');
        mvaddch(start_y+5, start_x+3, ' ');

    mvaddch(start_y+6, start_x, ' ');
        mvaddch(start_y+6, start_x+3, ' ');


    attroff(COLOR_PAIR(13));


}

void print_start_screen() {

  start_color(); // Abilita i colori

  init_pair(10, COLOR_CYAN, COLOR_CYAN); // Crea una coppia di colori verde su nero
  for(int i = 3; i < MAXY; i++){
        attron(COLOR_PAIR(10));
        mvhline(i, BORDER,' ',MAXX-BORDER); //funzione che colora un'intera riga 
        attroff(COLOR_PAIR(10));    
    }
}

void print_background_screen() {

    start_color(); // Abilita i colori

    int maxx, maxy;
    getmaxyx(stdscr, maxy, maxx);

    init_pair(40, COLOR_BLACK, COLOR_BLACK); // Crea una coppia di colori verde su nero
    for(int i = 0; i < maxy; i++){
            attron(COLOR_PAIR(40));
            mvhline(i, 0,' ',maxx); //funzione che colora un'intera riga 
            attroff(COLOR_PAIR(40));    
        }
}

void print_rectangular_frame(int width, int height) {
    // Calcola la posizione di inizio e fine del frame
    int start_x = ((MAXX+BORDER) - width) / 2;
    int end_x = start_x + width - 1;
    int start_y = (MAXY - height) / 2;
    int end_y = start_y + height - 1;

    init_pair(11, COLOR_BLACK, COLOR_BLACK); // Crea una coppia di colori verde su nero


    // Stampa la prima riga del frame
    for (int i = start_x; i <= end_x; i++) {
        attron(COLOR_PAIR(11));
        mvaddch(start_y, i, '*');
        attroff(COLOR_PAIR(11));    

    }

    // Stampa le colonne laterali del frame
    for (int i = start_y + 1; i < end_y; i++) {
        attron(COLOR_PAIR(11));
        mvaddch(i, start_x, '*');
        mvaddch(i, end_x, '*');
        attroff(COLOR_PAIR(11));    

    }

    // Stampa l'ultima riga del frame
    for (int i = start_x; i <= end_x; i++) {
        attron(COLOR_PAIR(11));
        mvaddch(end_y, i, '*');
        attroff(COLOR_PAIR(11));    

    }
    }

void colorazione_background(){

    int offset = 1;

    init_pair(1, COLOR_GREEN, COLOR_GREEN);
    init_pair(2, COLOR_BLUE, COLOR_BLUE);
    init_pair(3, COLOR_CYAN, COLOR_CYAN);
    init_pair(4, COLOR_RED, COLOR_RED);
    init_pair(5, COLOR_BLACK, COLOR_BLACK);

    //coloro in rosso per la parte in cui ci dovrebbe essere il tempo e il punteggio
    for(int i = 1; i <= RANA_H; i++){
        attron(COLOR_PAIR(5));
        mvhline(i, BORDER,' ',MAXX-BORDER); //funzione che colora un'intera riga 
        attroff(COLOR_PAIR(5));
        offset += 1;
    }
    int tmp = offset;

    //colorazione della parte dove ci dovrebbero essere le tane
    for(int i = offset; i <= RANA_H+tmp; i++){
        attron(COLOR_PAIR(4));
        mvhline(i, BORDER,' ',MAXX-BORDER); //funzione che colora un'intera riga 
        attroff(COLOR_PAIR(4));
        offset += 1;
    }
    tmp = offset;

    //colorazione della parte del fiume
    for(int i = offset; i <= RANA_H*N_CORSIE+tmp-1; i++){
        attron(COLOR_PAIR(3));
        mvhline(i, BORDER,' ',MAXX-BORDER); //funzione che colora un'intera riga 
        attroff(COLOR_PAIR(3));    
        offset += 1;
    }
    tmp = offset;

    //colorazione della parte del prato
    for(int i = offset; i <= MARCIAPIEDE_PRATO+tmp-1; i++){
        attron(COLOR_PAIR(1));
        mvhline(i, BORDER,' ',MAXX-BORDER); //funzione che colora un'intera riga 
        attroff(COLOR_PAIR(1));
        offset += 1;
    }
    tmp = offset;
    
    //colorazione della parte dell'autostrada
    for(int i = offset; i <= RANA_H*N_CORSIE+tmp-1; i++){
        attron(COLOR_PAIR(2));
        mvhline(i, BORDER,' ',MAXX-BORDER); //funzione che colora un'intera riga 
        attroff(COLOR_PAIR(2));
        offset += 1;
    }
    tmp = offset;

    //colorazione del marciapiede
    for(int i = offset; i <= MARCIAPIEDE_PRATO+tmp-1; i++){
        attron(COLOR_PAIR(1));
        mvhline(i, BORDER,' ',MAXX-BORDER); //funzione che colora un'intera riga 
        attroff(COLOR_PAIR(1));
        offset += 1;
    }
}


void stampa_tronco(posizione tronco, posizione proiettile){

    init_pair(30, COLOR_BLACK, COLOR_RED);

    if (tronco.sparato == true){
        mvprintw(tronco.y, tronco.x, " --");
        mvprintw(tronco.y+1, tronco.x, "|--");
        mvprintw(tronco.y+2, tronco.x, " --");

        attron(COLOR_PAIR(30));
        mvprintw(tronco.y,tronco.x+3, "[oo]");
        mvprintw(tronco.y+1,tronco.x+3, "[==]");
        mvprintw(tronco.y+2,tronco.x+3, "[/\\]");
        attroff(COLOR_PAIR(30));

        mvprintw(tronco.y, tronco.x+7, "-- ");
        mvprintw(tronco.y+1, tronco.x+7, "--|");
        mvprintw(tronco.y+2, tronco.x+7, "-- ");

        if(proiettile.sparato == true && proiettile.y < MAXY-8){
            attron(COLOR_PAIR(30));
            mvprintw(proiettile.y, proiettile.x, "*");
            attroff(COLOR_PAIR(30));
        }
    }
    
    else if (tronco.sparato == false){
        mvprintw(tronco.y, tronco.x, " -------- ");
        mvprintw(tronco.y+1, tronco.x, "|--------|");
        mvprintw(tronco.y+2, tronco.x, " -------- ");
    }
}


void stampa_timer(int tempo){

    //definisco le coppie di colori che verranno usate in ogni stage dello scorrere del tempo
    init_pair(6, COLOR_BLACK, COLOR_GREEN);
    init_pair(7, COLOR_BLACK, COLOR_YELLOW);
    init_pair(8, COLOR_BLACK, COLOR_RED);

    int time_frame = n_tempo/3; //viene calcolato un terzo del tempo totale per gestire il cambio di colore allo scorrere del tempo
   
    mvprintw(MAXY-3, BORDER, "TIME:");
    
    if (tempo >= time_frame*2){ //il tempo è maggiore dei 2 terzi, colore verde
        attron(COLOR_PAIR(6));
        mvhline(MAXY-2,BORDER,' ', tempo);
        attroff(COLOR_PAIR(6));
    }
    else if(tempo >= time_frame){ //il tempo si avvicina alla metà, colore diventa giallo
        attron(COLOR_PAIR(7));
        mvhline(MAXY-2,BORDER,' ', tempo);
        attroff(COLOR_PAIR(7));
    }
    else{
        attron(COLOR_PAIR(8)); //il tempo sta per scadere, colore diventa rosso
        mvhline(MAXY-2,BORDER,' ', tempo);
        attroff(COLOR_PAIR(8));
    }   
}

void stampa_macchina(posizione macchina){

    if(macchina.sparato==false){ //stampa del camion
        mvprintw(macchina.y,macchina.x,"/------\\");
        mvprintw(macchina.y+1,macchina.x,"|------|");
        mvprintw(macchina.y+2,macchina.x,"O------O");
    }
    else{ //stampa della macchina
        mvprintw(macchina.y,macchina.x,"/----\\");
        mvprintw(macchina.y+1,macchina.x,"|----|");
        mvprintw(macchina.y+2,macchina.x,"O----O");
    }

}

void colorazione_tane(_Bool flags[5]){
    init_pair(23, COLOR_WHITE, COLOR_WHITE);
    init_pair(4, COLOR_BLACK, COLOR_RED);
    init_pair(5, COLOR_BLACK, COLOR_BLACK);

    for(int i = 5; i <= 7; i++){
        
        attron(COLOR_PAIR(4));
        mvhline(i, BORDER,' ',5);  
        attroff(COLOR_PAIR(4));

        if(flags[0] == true){
            attron(COLOR_PAIR(23));
            mvhline(i,14, ' ',23);
            attroff(COLOR_PAIR(23));
        }
        else{
            attron(COLOR_PAIR(4));
            mvhline(i,14,'/',23); 
            attroff(COLOR_PAIR(4));
        }

        attron(COLOR_PAIR(4));
        mvhline(i, 23,' ',32);  
        attroff(COLOR_PAIR(4));

        if(flags[1] == true){
            attron(COLOR_PAIR(23));
            mvhline(i,32, ' ',41);
            attroff(COLOR_PAIR(23));
        }
        else{
            attron(COLOR_PAIR(4));
            mvhline(i, 32,'/',41); 
            attroff(COLOR_PAIR(4));
        }

        attron(COLOR_PAIR(4));
        mvhline(i, 41,' ',50);  
        attroff(COLOR_PAIR(4));

        if(flags[2] == true){
            attron(COLOR_PAIR(23));
            mvhline(i,50, ' ',59);
            attroff(COLOR_PAIR(23));
        }
        else{
            attron(COLOR_PAIR(4));
            mvhline(i, 50,'/',59); 
            attroff(COLOR_PAIR(4));
        }


        attron(COLOR_PAIR(4));
        mvhline(i, 59,' ',68);  
        attroff(COLOR_PAIR(4));

        if(flags[3] == true){
            attron(COLOR_PAIR(23));
            mvhline(i,68, ' ',77);
            attroff(COLOR_PAIR(23));
        }
        else{
            attron(COLOR_PAIR(4));
            mvhline(i, 68,'/',77); 
            attroff(COLOR_PAIR(4));
        }

        attron(COLOR_PAIR(4));
        mvhline(i, 77,' ',86);  
        attroff(COLOR_PAIR(4));

        if(flags[4] == true){
            attron(COLOR_PAIR(23));
            mvhline(i,86, ' ',95);
            attroff(COLOR_PAIR(23));
        }
        else{
            attron(COLOR_PAIR(4));
            mvhline(i, 86,'/',95); 
            attroff(COLOR_PAIR(4));
        }
        attron(COLOR_PAIR(4));
        mvhline(i, 95, ' ', 100-BORDER);
        attroff(COLOR_PAIR(4));

        attron(COLOR_PAIR(5));
        mvhline(i,100 , ' ', MAXX+10);
        attroff(COLOR_PAIR(5));
    
    }
}

void print_hard(int start_y, int start_x){

    init_pair(20, COLOR_BLACK, COLOR_BLACK);
    init_pair(21, COLOR_RED, COLOR_RED);

    attron(COLOR_PAIR(20));

    mvaddch(start_y, start_x+2, ' ');
    mvaddch(start_y, start_x+3, ' ');
    mvaddch(start_y, start_x+4, ' ');
    mvaddch(start_y, start_x+5, ' ');
    mvaddch(start_y, start_x+6, ' ');
    mvaddch(start_y, start_x+7, ' ');
    mvaddch(start_y, start_x+8, ' ');
    mvaddch(start_y, start_x+9, ' ');
    mvaddch(start_y, start_x+10, ' ');
    mvaddch(start_y, start_x+11, ' ');
    mvaddch(start_y, start_x+12, ' ');
    mvaddch(start_y, start_x+13, ' ');
    mvaddch(start_y, start_x+14, ' ');
    mvaddch(start_y, start_x+15, ' ');
    mvaddch(start_y, start_x+16, ' ');
    mvaddch(start_y, start_x+17, ' ');
    mvaddch(start_y, start_x+18, ' ');
    mvaddch(start_y, start_x+19, ' ');
    mvaddch(start_y, start_x+20, ' ');
    mvaddch(start_y, start_x+21, ' ');
    mvaddch(start_y, start_x+22, ' ');
    mvaddch(start_y, start_x+23, ' ');

    mvaddch(start_y+1, start_x+1, ' ');
    mvaddch(start_y+1, start_x+24, ' ');

    mvaddch(start_y+2, start_x, ' ');
    mvaddch(start_y+2, start_x+25, ' ');

    mvaddch(start_y+3, start_x, ' ');
    mvaddch(start_y+3, start_x+25, ' ');

    mvaddch(start_y+4, start_x, ' ');
    mvaddch(start_y+4, start_x+25, ' ');

    mvaddch(start_y+5, start_x, ' ');
    mvaddch(start_y+5, start_x+25, ' ');

    mvaddch(start_y+6, start_x, ' ');
    mvaddch(start_y+6, start_x+25, ' ');

    mvaddch(start_y+7, start_x+1, ' ');
    mvaddch(start_y+7, start_x+24, ' ');    

    mvaddch(start_y+8, start_x+2, ' ');
    mvaddch(start_y+8, start_x+3, ' ');
    mvaddch(start_y+8, start_x+4, ' ');
    mvaddch(start_y+8, start_x+5, ' ');
    mvaddch(start_y+8, start_x+6, ' ');
    mvaddch(start_y+8, start_x+7, ' ');
    mvaddch(start_y+8, start_x+8, ' ');
    mvaddch(start_y+8, start_x+9, ' ');
    mvaddch(start_y+8, start_x+10, ' ');
    mvaddch(start_y+8, start_x+11, ' ');
    mvaddch(start_y+8, start_x+12, ' ');
    mvaddch(start_y+8, start_x+13, ' ');
    mvaddch(start_y+8, start_x+14, ' ');
    mvaddch(start_y+8, start_x+15, ' ');
    mvaddch(start_y+8, start_x+16, ' ');
    mvaddch(start_y+8, start_x+17, ' ');
    mvaddch(start_y+8, start_x+18, ' ');
    mvaddch(start_y+8, start_x+19, ' ');
    mvaddch(start_y+8, start_x+20, ' ');
    mvaddch(start_y+8, start_x+21, ' ');
    mvaddch(start_y+8, start_x+22, ' ');
    mvaddch(start_y+8, start_x+23, ' ');


    attroff(COLOR_PAIR(20));

    attron(COLOR_PAIR(21));

    mvaddch(start_y+1, start_x+2, ' ');
    mvaddch(start_y+1, start_x+3, ' ');
    mvaddch(start_y+1, start_x+4, ' ');
    mvaddch(start_y+1, start_x+5, ' ');
    mvaddch(start_y+1, start_x+6, ' ');
    mvaddch(start_y+1, start_x+7, ' ');
    mvaddch(start_y+1, start_x+8, ' ');
    mvaddch(start_y+1, start_x+9, ' ');
    mvaddch(start_y+1, start_x+10, ' ');
    mvaddch(start_y+1, start_x+11, ' ');
    mvaddch(start_y+1, start_x+12, ' ');
    mvaddch(start_y+1, start_x+13, ' ');
    mvaddch(start_y+1, start_x+14, ' ');
    mvaddch(start_y+1, start_x+15, ' ');
    mvaddch(start_y+1, start_x+16, ' ');
    mvaddch(start_y+1, start_x+17, ' ');
    mvaddch(start_y+1, start_x+18, ' ');
    mvaddch(start_y+1, start_x+19, ' ');
    mvaddch(start_y+1, start_x+20, ' ');
    mvaddch(start_y+1, start_x+21, ' ');
    mvaddch(start_y+1, start_x+22, ' ');
    mvaddch(start_y+1, start_x+23, ' ');

    mvaddch(start_y+2, start_x+1, ' ');
    mvaddch(start_y+2, start_x+2, ' ');
    mvaddch(start_y+2, start_x+3, ' ');
    mvaddch(start_y+2, start_x+8, ' ');
    mvaddch(start_y+2, start_x+10, ' ');
    mvaddch(start_y+2, start_x+11, ' ');
    mvaddch(start_y+2, start_x+12, ' ');
    mvaddch(start_y+2, start_x+14, ' ');
    mvaddch(start_y+2, start_x+16, ' ');
    mvaddch(start_y+2, start_x+22, ' ');
    mvaddch(start_y+2, start_x+23, ' ');
    mvaddch(start_y+2, start_x+24, ' ');
    mvaddch(start_y+2, start_x+4, ' ');
    mvaddch(start_y+2, start_x+5, ' ');
    mvaddch(start_y+2, start_x+6, ' ');
    mvaddch(start_y+2, start_x+7, ' ');
    mvaddch(start_y+2, start_x+9, ' ');
    mvaddch(start_y+2, start_x+13, ' ');
    mvaddch(start_y+2, start_x+15, ' ');
    mvaddch(start_y+2, start_x+17, ' ');
    mvaddch(start_y+2, start_x+18, ' ');
    mvaddch(start_y+2, start_x+19, ' ');
    mvaddch(start_y+2, start_x+20, ' ');
    mvaddch(start_y+2, start_x+21, ' ');

    mvaddch(start_y+3, start_x+1, ' ');
    mvaddch(start_y+3, start_x+2, ' ');
    mvaddch(start_y+3, start_x+3, ' ');
    mvaddch(start_y+3, start_x+5, ' ');
    mvaddch(start_y+3, start_x+6, ' ');
    mvaddch(start_y+3, start_x+7, ' ');
    mvaddch(start_y+3, start_x+8, ' ');
    mvaddch(start_y+3, start_x+9, ' ');
    mvaddch(start_y+3, start_x+11, ' ');
    mvaddch(start_y+3, start_x+13, ' ');
    mvaddch(start_y+3, start_x+14, ' ');
    mvaddch(start_y+3, start_x+16, ' ');
    mvaddch(start_y+3, start_x+17, ' ');
    mvaddch(start_y+3, start_x+18, ' ');
    mvaddch(start_y+3, start_x+20, ' ');
    mvaddch(start_y+3, start_x+21, ' ');
    mvaddch(start_y+3, start_x+22, ' ');
    mvaddch(start_y+3, start_x+23, ' ');
    mvaddch(start_y+3, start_x+24, ' ');
    mvaddch(start_y+3, start_x+4, ' ');
    mvaddch(start_y+3, start_x+10, ' ');
    mvaddch(start_y+3, start_x+12, ' ');
    mvaddch(start_y+3, start_x+15, ' ');
    mvaddch(start_y+3, start_x+19, ' ');

    mvaddch(start_y+4, start_x+1, ' ');
    mvaddch(start_y+4, start_x+2, ' ');
    mvaddch(start_y+4, start_x+3, ' ');
    mvaddch(start_y+4, start_x+6, ' ');
    mvaddch(start_y+4, start_x+7, ' ');
    mvaddch(start_y+4, start_x+8, ' ');
    mvaddch(start_y+4, start_x+9, ' ');
    mvaddch(start_y+4, start_x+10, ' ');
    mvaddch(start_y+4, start_x+12, ' ');
    mvaddch(start_y+4, start_x+13, ' ');
    mvaddch(start_y+4, start_x+14, ' ');
    mvaddch(start_y+4, start_x+16, ' ');
    mvaddch(start_y+4, start_x+17, ' ');
    mvaddch(start_y+4, start_x+18, ' ');
    mvaddch(start_y+4, start_x+20, ' ');
    mvaddch(start_y+4, start_x+21, ' ');
    mvaddch(start_y+4, start_x+22, ' ');
    mvaddch(start_y+4, start_x+23, ' ');
    mvaddch(start_y+4, start_x+24, ' ');
    mvaddch(start_y+4, start_x+4, ' ');
    mvaddch(start_y+4, start_x+5, ' ');
    mvaddch(start_y+4, start_x+11, ' ');
    mvaddch(start_y+4, start_x+15, ' ');
    mvaddch(start_y+4, start_x+19, ' ');

    mvaddch(start_y+5, start_x+1, ' ');
    mvaddch(start_y+5, start_x+2, ' ');
    mvaddch(start_y+5, start_x+3, ' ');
    mvaddch(start_y+5, start_x+5, ' ');
    mvaddch(start_y+5, start_x+6, ' ');
    mvaddch(start_y+5, start_x+7, ' ');
    mvaddch(start_y+5, start_x+8, ' ');
    mvaddch(start_y+5, start_x+9, ' ');
    mvaddch(start_y+5, start_x+11, ' ');
    mvaddch(start_y+5, start_x+13, ' ');
    mvaddch(start_y+5, start_x+14, ' ');
    mvaddch(start_y+5, start_x+16, ' ');
    mvaddch(start_y+5, start_x+17, ' ');
    mvaddch(start_y+5, start_x+18, ' ');
    mvaddch(start_y+5, start_x+20, ' ');
    mvaddch(start_y+5, start_x+21, ' ');
    mvaddch(start_y+5, start_x+22, ' ');
    mvaddch(start_y+5, start_x+23, ' ');
    mvaddch(start_y+5, start_x+24, ' ');
    mvaddch(start_y+5, start_x+4, ' ');
    mvaddch(start_y+5, start_x+10, ' ');
    mvaddch(start_y+5, start_x+12, ' ');
    mvaddch(start_y+5, start_x+15, ' ');
    mvaddch(start_y+5, start_x+19, ' ');

    mvaddch(start_y+6, start_x+1, ' ');
    mvaddch(start_y+6, start_x+2, ' ');
    mvaddch(start_y+6, start_x+3, ' ');
    mvaddch(start_y+6, start_x+8, ' ');
    mvaddch(start_y+6, start_x+10, ' ');
    mvaddch(start_y+6, start_x+11, ' ');
    mvaddch(start_y+6, start_x+12, ' ');
    mvaddch(start_y+6, start_x+14, ' ');
    mvaddch(start_y+6, start_x+16, ' ');
    mvaddch(start_y+6, start_x+17, ' ');
    mvaddch(start_y+6, start_x+18, ' ');
    mvaddch(start_y+6, start_x+20, ' ');
    mvaddch(start_y+6, start_x+21, ' ');
    mvaddch(start_y+6, start_x+22, ' ');
    mvaddch(start_y+6, start_x+23, ' ');
    mvaddch(start_y+6, start_x+24, ' ');
    mvaddch(start_y+6, start_x+4, ' ');
    mvaddch(start_y+6, start_x+5, ' ');
    mvaddch(start_y+6, start_x+6, ' ');
    mvaddch(start_y+6, start_x+7, ' ');
    mvaddch(start_y+6, start_x+9, ' ');
    mvaddch(start_y+6, start_x+13, ' ');
    mvaddch(start_y+6, start_x+15, ' ');
    mvaddch(start_y+6, start_x+19, ' ');


    mvaddch(start_y+7, start_x+2, ' ');
    mvaddch(start_y+7, start_x+3, ' ');
    mvaddch(start_y+7, start_x+4, ' ');
    mvaddch(start_y+7, start_x+5, ' ');
    mvaddch(start_y+7, start_x+6, ' ');
    mvaddch(start_y+7, start_x+7, ' ');
    mvaddch(start_y+7, start_x+8, ' ');
    mvaddch(start_y+7, start_x+9, ' ');
    mvaddch(start_y+7, start_x+10, ' ');
    mvaddch(start_y+7, start_x+11, ' ');
    mvaddch(start_y+7, start_x+12, ' ');
    mvaddch(start_y+7, start_x+13, ' ');
    mvaddch(start_y+7, start_x+14, ' ');
    mvaddch(start_y+7, start_x+15, ' ');
    mvaddch(start_y+7, start_x+16, ' ');
    mvaddch(start_y+7, start_x+17, ' ');
    mvaddch(start_y+7, start_x+18, ' ');
    mvaddch(start_y+7, start_x+19, ' ');
    mvaddch(start_y+7, start_x+20, ' ');
    mvaddch(start_y+7, start_x+21, ' ');
    mvaddch(start_y+7, start_x+22, ' ');
    mvaddch(start_y+7, start_x+23, ' ');

    attroff(COLOR_PAIR(21));


}

void print_medium(int start_y, int start_x){

    init_pair(20, COLOR_BLACK, COLOR_BLACK);
    init_pair(25, COLOR_YELLOW, COLOR_YELLOW);

    attron(COLOR_PAIR(20));

    mvaddch(start_y, start_x+2, ' ');
    mvaddch(start_y, start_x+3, ' ');
    mvaddch(start_y, start_x+4, ' ');
    mvaddch(start_y, start_x+5, ' ');
    mvaddch(start_y, start_x+6, ' ');
    mvaddch(start_y, start_x+7, ' ');
    mvaddch(start_y, start_x+8, ' ');
    mvaddch(start_y, start_x+9, ' ');
    mvaddch(start_y, start_x+10, ' ');
    mvaddch(start_y, start_x+11, ' ');
    mvaddch(start_y, start_x+12, ' ');
    mvaddch(start_y, start_x+13, ' ');
    mvaddch(start_y, start_x+14, ' ');
    mvaddch(start_y, start_x+15, ' ');
    mvaddch(start_y, start_x+16, ' ');
    mvaddch(start_y, start_x+17, ' ');
    mvaddch(start_y, start_x+18, ' ');
    mvaddch(start_y, start_x+19, ' ');
    mvaddch(start_y, start_x+20, ' ');
    mvaddch(start_y, start_x+21, ' ');
    mvaddch(start_y, start_x+22, ' ');
    mvaddch(start_y, start_x+23, ' ');

    mvaddch(start_y+1, start_x+1, ' ');
    mvaddch(start_y+1, start_x+24, ' ');

    mvaddch(start_y+2, start_x, ' ');
    mvaddch(start_y+2, start_x+25, ' ');

    mvaddch(start_y+3, start_x, ' ');
    mvaddch(start_y+3, start_x+25, ' ');

    mvaddch(start_y+4, start_x, ' ');
    mvaddch(start_y+4, start_x+25, ' ');

    mvaddch(start_y+5, start_x, ' ');
    mvaddch(start_y+5, start_x+25, ' ');

    mvaddch(start_y+6, start_x, ' ');
    mvaddch(start_y+6, start_x+25, ' ');

    mvaddch(start_y+7, start_x+1, ' ');
    mvaddch(start_y+7, start_x+24, ' ');    

    mvaddch(start_y+8, start_x+2, ' ');
    mvaddch(start_y+8, start_x+3, ' ');
    mvaddch(start_y+8, start_x+4, ' ');
    mvaddch(start_y+8, start_x+5, ' ');
    mvaddch(start_y+8, start_x+6, ' ');
    mvaddch(start_y+8, start_x+7, ' ');
    mvaddch(start_y+8, start_x+8, ' ');
    mvaddch(start_y+8, start_x+9, ' ');
    mvaddch(start_y+8, start_x+10, ' ');
    mvaddch(start_y+8, start_x+11, ' ');
    mvaddch(start_y+8, start_x+12, ' ');
    mvaddch(start_y+8, start_x+13, ' ');
    mvaddch(start_y+8, start_x+14, ' ');
    mvaddch(start_y+8, start_x+15, ' ');
    mvaddch(start_y+8, start_x+16, ' ');
    mvaddch(start_y+8, start_x+17, ' ');
    mvaddch(start_y+8, start_x+18, ' ');
    mvaddch(start_y+8, start_x+19, ' ');
    mvaddch(start_y+8, start_x+20, ' ');
    mvaddch(start_y+8, start_x+21, ' ');
    mvaddch(start_y+8, start_x+22, ' ');
    mvaddch(start_y+8, start_x+23, ' ');


    attroff(COLOR_PAIR(20));

    attron(COLOR_PAIR(25));

    mvaddch(start_y+1, start_x+2, ' ');
    mvaddch(start_y+1, start_x+3, ' ');
    mvaddch(start_y+1, start_x+4, ' ');
    mvaddch(start_y+1, start_x+5, ' ');
    mvaddch(start_y+1, start_x+6, ' ');
    mvaddch(start_y+1, start_x+7, ' ');
    mvaddch(start_y+1, start_x+8, ' ');
    mvaddch(start_y+1, start_x+9, ' ');
    mvaddch(start_y+1, start_x+10, ' ');
    mvaddch(start_y+1, start_x+11, ' ');
    mvaddch(start_y+1, start_x+12, ' ');
    mvaddch(start_y+1, start_x+13, ' ');
    mvaddch(start_y+1, start_x+14, ' ');
    mvaddch(start_y+1, start_x+15, ' ');
    mvaddch(start_y+1, start_x+16, ' ');
    mvaddch(start_y+1, start_x+17, ' ');
    mvaddch(start_y+1, start_x+18, ' ');
    mvaddch(start_y+1, start_x+19, ' ');
    mvaddch(start_y+1, start_x+20, ' ');
    mvaddch(start_y+1, start_x+21, ' ');
    mvaddch(start_y+1, start_x+22, ' ');
    mvaddch(start_y+1, start_x+23, ' ');

    mvaddch(start_y+2, start_x+1, ' ');
    mvaddch(start_y+2, start_x+2, ' ');
    mvaddch(start_y+2, start_x+3, ' ');
    mvaddch(start_y+2, start_x+8, ' ');
    mvaddch(start_y+2, start_x+10, ' ');
    mvaddch(start_y+2, start_x+11, ' ');
    mvaddch(start_y+2, start_x+12, ' ');
    mvaddch(start_y+2, start_x+14, ' ');
    mvaddch(start_y+2, start_x+16, ' ');
    mvaddch(start_y+2, start_x+22, ' ');
    mvaddch(start_y+2, start_x+23, ' ');
    mvaddch(start_y+2, start_x+24, ' ');
    mvaddch(start_y+2, start_x+4, ' ');
    mvaddch(start_y+2, start_x+5, ' ');
    mvaddch(start_y+2, start_x+6, ' ');
    mvaddch(start_y+2, start_x+7, ' ');
    mvaddch(start_y+2, start_x+9, ' ');
    mvaddch(start_y+2, start_x+13, ' ');
    mvaddch(start_y+2, start_x+15, ' ');
    mvaddch(start_y+2, start_x+17, ' ');
    mvaddch(start_y+2, start_x+18, ' ');
    mvaddch(start_y+2, start_x+19, ' ');
    mvaddch(start_y+2, start_x+20, ' ');
    mvaddch(start_y+2, start_x+21, ' ');

    mvaddch(start_y+3, start_x+1, ' ');
    mvaddch(start_y+3, start_x+2, ' ');
    mvaddch(start_y+3, start_x+3, ' ');
    mvaddch(start_y+3, start_x+5, ' ');
    mvaddch(start_y+3, start_x+6, ' ');
    mvaddch(start_y+3, start_x+7, ' ');
    mvaddch(start_y+3, start_x+8, ' ');
    mvaddch(start_y+3, start_x+9, ' ');
    mvaddch(start_y+3, start_x+11, ' ');
    mvaddch(start_y+3, start_x+13, ' ');
    mvaddch(start_y+3, start_x+14, ' ');
    mvaddch(start_y+3, start_x+16, ' ');
    mvaddch(start_y+3, start_x+17, ' ');
    mvaddch(start_y+3, start_x+18, ' ');
    mvaddch(start_y+3, start_x+20, ' ');
    mvaddch(start_y+3, start_x+21, ' ');
    mvaddch(start_y+3, start_x+22, ' ');
    mvaddch(start_y+3, start_x+23, ' ');
    mvaddch(start_y+3, start_x+24, ' ');
    mvaddch(start_y+3, start_x+4, ' ');
    mvaddch(start_y+3, start_x+10, ' ');
    mvaddch(start_y+3, start_x+12, ' ');
    mvaddch(start_y+3, start_x+15, ' ');
    mvaddch(start_y+3, start_x+19, ' ');

    mvaddch(start_y+4, start_x+1, ' ');
    mvaddch(start_y+4, start_x+2, ' ');
    mvaddch(start_y+4, start_x+3, ' ');
    mvaddch(start_y+4, start_x+6, ' ');
    mvaddch(start_y+4, start_x+7, ' ');
    mvaddch(start_y+4, start_x+8, ' ');
    mvaddch(start_y+4, start_x+9, ' ');
    mvaddch(start_y+4, start_x+10, ' ');
    mvaddch(start_y+4, start_x+12, ' ');
    mvaddch(start_y+4, start_x+13, ' ');
    mvaddch(start_y+4, start_x+14, ' ');
    mvaddch(start_y+4, start_x+16, ' ');
    mvaddch(start_y+4, start_x+17, ' ');
    mvaddch(start_y+4, start_x+18, ' ');
    mvaddch(start_y+4, start_x+20, ' ');
    mvaddch(start_y+4, start_x+21, ' ');
    mvaddch(start_y+4, start_x+22, ' ');
    mvaddch(start_y+4, start_x+23, ' ');
    mvaddch(start_y+4, start_x+24, ' ');
    mvaddch(start_y+4, start_x+4, ' ');
    mvaddch(start_y+4, start_x+5, ' ');
    mvaddch(start_y+4, start_x+11, ' ');
    mvaddch(start_y+4, start_x+15, ' ');
    mvaddch(start_y+4, start_x+19, ' ');

    mvaddch(start_y+5, start_x+1, ' ');
    mvaddch(start_y+5, start_x+2, ' ');
    mvaddch(start_y+5, start_x+3, ' ');
    mvaddch(start_y+5, start_x+5, ' ');
    mvaddch(start_y+5, start_x+6, ' ');
    mvaddch(start_y+5, start_x+7, ' ');
    mvaddch(start_y+5, start_x+8, ' ');
    mvaddch(start_y+5, start_x+9, ' ');
    mvaddch(start_y+5, start_x+11, ' ');
    mvaddch(start_y+5, start_x+13, ' ');
    mvaddch(start_y+5, start_x+14, ' ');
    mvaddch(start_y+5, start_x+16, ' ');
    mvaddch(start_y+5, start_x+17, ' ');
    mvaddch(start_y+5, start_x+18, ' ');
    mvaddch(start_y+5, start_x+20, ' ');
    mvaddch(start_y+5, start_x+21, ' ');
    mvaddch(start_y+5, start_x+22, ' ');
    mvaddch(start_y+5, start_x+23, ' ');
    mvaddch(start_y+5, start_x+24, ' ');
    mvaddch(start_y+5, start_x+4, ' ');
    mvaddch(start_y+5, start_x+10, ' ');
    mvaddch(start_y+5, start_x+12, ' ');
    mvaddch(start_y+5, start_x+15, ' ');
    mvaddch(start_y+5, start_x+19, ' ');

    mvaddch(start_y+6, start_x+1, ' ');
    mvaddch(start_y+6, start_x+2, ' ');
    mvaddch(start_y+6, start_x+3, ' ');
    mvaddch(start_y+6, start_x+8, ' ');
    mvaddch(start_y+6, start_x+10, ' ');
    mvaddch(start_y+6, start_x+11, ' ');
    mvaddch(start_y+6, start_x+12, ' ');
    mvaddch(start_y+6, start_x+14, ' ');
    mvaddch(start_y+6, start_x+16, ' ');
    mvaddch(start_y+6, start_x+17, ' ');
    mvaddch(start_y+6, start_x+18, ' ');
    mvaddch(start_y+6, start_x+20, ' ');
    mvaddch(start_y+6, start_x+21, ' ');
    mvaddch(start_y+6, start_x+22, ' ');
    mvaddch(start_y+6, start_x+23, ' ');
    mvaddch(start_y+6, start_x+24, ' ');
    mvaddch(start_y+6, start_x+4, ' ');
    mvaddch(start_y+6, start_x+5, ' ');
    mvaddch(start_y+6, start_x+6, ' ');
    mvaddch(start_y+6, start_x+7, ' ');
    mvaddch(start_y+6, start_x+9, ' ');
    mvaddch(start_y+6, start_x+13, ' ');
    mvaddch(start_y+6, start_x+15, ' ');
    mvaddch(start_y+6, start_x+19, ' ');


    mvaddch(start_y+7, start_x+2, ' ');
    mvaddch(start_y+7, start_x+3, ' ');
    mvaddch(start_y+7, start_x+4, ' ');
    mvaddch(start_y+7, start_x+5, ' ');
    mvaddch(start_y+7, start_x+6, ' ');
    mvaddch(start_y+7, start_x+7, ' ');
    mvaddch(start_y+7, start_x+8, ' ');
    mvaddch(start_y+7, start_x+9, ' ');
    mvaddch(start_y+7, start_x+10, ' ');
    mvaddch(start_y+7, start_x+11, ' ');
    mvaddch(start_y+7, start_x+12, ' ');
    mvaddch(start_y+7, start_x+13, ' ');
    mvaddch(start_y+7, start_x+14, ' ');
    mvaddch(start_y+7, start_x+15, ' ');
    mvaddch(start_y+7, start_x+16, ' ');
    mvaddch(start_y+7, start_x+17, ' ');
    mvaddch(start_y+7, start_x+18, ' ');
    mvaddch(start_y+7, start_x+19, ' ');
    mvaddch(start_y+7, start_x+20, ' ');
    mvaddch(start_y+7, start_x+21, ' ');
    mvaddch(start_y+7, start_x+22, ' ');
    mvaddch(start_y+7, start_x+23, ' ');

    attroff(COLOR_PAIR(25));


}



void print_easy(int start_y, int start_x){
    
    init_pair(17, COLOR_BLACK, COLOR_BLACK);
    init_pair(19, COLOR_GREEN, COLOR_GREEN);

    

    attron(COLOR_PAIR(17));

    mvaddch(start_y, start_x+2, ' ');
    mvaddch(start_y, start_x+3, ' ');
    mvaddch(start_y, start_x+4, ' ');
    mvaddch(start_y, start_x+5, ' ');
    mvaddch(start_y, start_x+6, ' ');
    mvaddch(start_y, start_x+7, ' ');
    mvaddch(start_y, start_x+8, ' ');
    mvaddch(start_y, start_x+9, ' ');
    mvaddch(start_y, start_x+10, ' ');
    mvaddch(start_y, start_x+11, ' ');
    mvaddch(start_y, start_x+12, ' ');
    mvaddch(start_y, start_x+13, ' ');
    mvaddch(start_y, start_x+14, ' ');
    mvaddch(start_y, start_x+15, ' ');
    mvaddch(start_y, start_x+16, ' ');
    mvaddch(start_y, start_x+17, ' ');
    mvaddch(start_y, start_x+18, ' ');
    mvaddch(start_y, start_x+19, ' ');
    mvaddch(start_y, start_x+20, ' ');
    mvaddch(start_y, start_x+21, ' ');
    mvaddch(start_y, start_x+22, ' ');
    mvaddch(start_y, start_x+23, ' ');

    mvaddch(start_y+1, start_x+1, ' ');
    mvaddch(start_y+1, start_x+24, ' ');

    mvaddch(start_y+2, start_x, ' ');
    mvaddch(start_y+2, start_x+25, ' ');

    mvaddch(start_y+3, start_x, ' ');
    mvaddch(start_y+3, start_x+25, ' ');

    mvaddch(start_y+4, start_x, ' ');
    mvaddch(start_y+4, start_x+25, ' ');

    mvaddch(start_y+5, start_x, ' ');
    mvaddch(start_y+5, start_x+25, ' ');

    mvaddch(start_y+6, start_x, ' ');
    mvaddch(start_y+6, start_x+25, ' ');

    mvaddch(start_y+7, start_x+1, ' ');
    mvaddch(start_y+7, start_x+24, ' ');    

    mvaddch(start_y+8, start_x+2, ' ');
    mvaddch(start_y+8, start_x+3, ' ');
    mvaddch(start_y+8, start_x+4, ' ');
    mvaddch(start_y+8, start_x+5, ' ');
    mvaddch(start_y+8, start_x+6, ' ');
    mvaddch(start_y+8, start_x+7, ' ');
    mvaddch(start_y+8, start_x+8, ' ');
    mvaddch(start_y+8, start_x+9, ' ');
    mvaddch(start_y+8, start_x+10, ' ');
    mvaddch(start_y+8, start_x+11, ' ');
    mvaddch(start_y+8, start_x+12, ' ');
    mvaddch(start_y+8, start_x+13, ' ');
    mvaddch(start_y+8, start_x+14, ' ');
    mvaddch(start_y+8, start_x+15, ' ');
    mvaddch(start_y+8, start_x+16, ' ');
    mvaddch(start_y+8, start_x+17, ' ');
    mvaddch(start_y+8, start_x+18, ' ');
    mvaddch(start_y+8, start_x+19, ' ');
    mvaddch(start_y+8, start_x+20, ' ');
    mvaddch(start_y+8, start_x+21, ' ');
    mvaddch(start_y+8, start_x+22, ' ');
    mvaddch(start_y+8, start_x+23, ' ');


    attroff(COLOR_PAIR(17));

    attron(COLOR_PAIR(19));

    mvaddch(start_y+1, start_x+2, ' ');
    mvaddch(start_y+1, start_x+3, ' ');
    mvaddch(start_y+1, start_x+4, ' ');
    mvaddch(start_y+1, start_x+5, ' ');
    mvaddch(start_y+1, start_x+6, ' ');
    mvaddch(start_y+1, start_x+7, ' ');
    mvaddch(start_y+1, start_x+8, ' ');
    mvaddch(start_y+1, start_x+9, ' ');
    mvaddch(start_y+1, start_x+10, ' ');
    mvaddch(start_y+1, start_x+11, ' ');
    mvaddch(start_y+1, start_x+12, ' ');
    mvaddch(start_y+1, start_x+13, ' ');
    mvaddch(start_y+1, start_x+14, ' ');
    mvaddch(start_y+1, start_x+15, ' ');
    mvaddch(start_y+1, start_x+16, ' ');
    mvaddch(start_y+1, start_x+17, ' ');
    mvaddch(start_y+1, start_x+18, ' ');
    mvaddch(start_y+1, start_x+19, ' ');
    mvaddch(start_y+1, start_x+20, ' ');
    mvaddch(start_y+1, start_x+21, ' ');
    mvaddch(start_y+1, start_x+22, ' ');
    mvaddch(start_y+1, start_x+23, ' ');

    mvaddch(start_y+2, start_x+1, ' ');
    mvaddch(start_y+2, start_x+2, ' ');
    mvaddch(start_y+2, start_x+3, ' ');
    mvaddch(start_y+2, start_x+8, ' ');
    mvaddch(start_y+2, start_x+10, ' ');
    mvaddch(start_y+2, start_x+11, ' ');
    mvaddch(start_y+2, start_x+12, ' ');
    mvaddch(start_y+2, start_x+14, ' ');
    mvaddch(start_y+2, start_x+16, ' ');
    mvaddch(start_y+2, start_x+22, ' ');
    mvaddch(start_y+2, start_x+23, ' ');
    mvaddch(start_y+2, start_x+24, ' ');
    mvaddch(start_y+2, start_x+4, ' ');
    mvaddch(start_y+2, start_x+5, ' ');
    mvaddch(start_y+2, start_x+6, ' ');
    mvaddch(start_y+2, start_x+7, ' ');
    mvaddch(start_y+2, start_x+9, ' ');
    mvaddch(start_y+2, start_x+13, ' ');
    mvaddch(start_y+2, start_x+15, ' ');
    mvaddch(start_y+2, start_x+17, ' ');
    mvaddch(start_y+2, start_x+18, ' ');
    mvaddch(start_y+2, start_x+19, ' ');
    mvaddch(start_y+2, start_x+20, ' ');
    mvaddch(start_y+2, start_x+21, ' ');

    mvaddch(start_y+3, start_x+1, ' ');
    mvaddch(start_y+3, start_x+2, ' ');
    mvaddch(start_y+3, start_x+3, ' ');
    mvaddch(start_y+3, start_x+5, ' ');
    mvaddch(start_y+3, start_x+6, ' ');
    mvaddch(start_y+3, start_x+7, ' ');
    mvaddch(start_y+3, start_x+8, ' ');
    mvaddch(start_y+3, start_x+9, ' ');
    mvaddch(start_y+3, start_x+11, ' ');
    mvaddch(start_y+3, start_x+13, ' ');
    mvaddch(start_y+3, start_x+14, ' ');
    mvaddch(start_y+3, start_x+16, ' ');
    mvaddch(start_y+3, start_x+17, ' ');
    mvaddch(start_y+3, start_x+18, ' ');
    mvaddch(start_y+3, start_x+20, ' ');
    mvaddch(start_y+3, start_x+21, ' ');
    mvaddch(start_y+3, start_x+22, ' ');
    mvaddch(start_y+3, start_x+23, ' ');
    mvaddch(start_y+3, start_x+24, ' ');
    mvaddch(start_y+3, start_x+4, ' ');
    mvaddch(start_y+3, start_x+10, ' ');
    mvaddch(start_y+3, start_x+12, ' ');
    mvaddch(start_y+3, start_x+15, ' ');
    mvaddch(start_y+3, start_x+19, ' ');

    mvaddch(start_y+4, start_x+1, ' ');
    mvaddch(start_y+4, start_x+2, ' ');
    mvaddch(start_y+4, start_x+3, ' ');
    mvaddch(start_y+4, start_x+6, ' ');
    mvaddch(start_y+4, start_x+7, ' ');
    mvaddch(start_y+4, start_x+8, ' ');
    mvaddch(start_y+4, start_x+9, ' ');
    mvaddch(start_y+4, start_x+10, ' ');
    mvaddch(start_y+4, start_x+12, ' ');
    mvaddch(start_y+4, start_x+13, ' ');
    mvaddch(start_y+4, start_x+14, ' ');
    mvaddch(start_y+4, start_x+16, ' ');
    mvaddch(start_y+4, start_x+17, ' ');
    mvaddch(start_y+4, start_x+18, ' ');
    mvaddch(start_y+4, start_x+20, ' ');
    mvaddch(start_y+4, start_x+21, ' ');
    mvaddch(start_y+4, start_x+22, ' ');
    mvaddch(start_y+4, start_x+23, ' ');
    mvaddch(start_y+4, start_x+24, ' ');
    mvaddch(start_y+4, start_x+4, ' ');
    mvaddch(start_y+4, start_x+5, ' ');
    mvaddch(start_y+4, start_x+11, ' ');
    mvaddch(start_y+4, start_x+15, ' ');
    mvaddch(start_y+4, start_x+19, ' ');

    mvaddch(start_y+5, start_x+1, ' ');
    mvaddch(start_y+5, start_x+2, ' ');
    mvaddch(start_y+5, start_x+3, ' ');
    mvaddch(start_y+5, start_x+5, ' ');
    mvaddch(start_y+5, start_x+6, ' ');
    mvaddch(start_y+5, start_x+7, ' ');
    mvaddch(start_y+5, start_x+8, ' ');
    mvaddch(start_y+5, start_x+9, ' ');
    mvaddch(start_y+5, start_x+11, ' ');
    mvaddch(start_y+5, start_x+13, ' ');
    mvaddch(start_y+5, start_x+14, ' ');
    mvaddch(start_y+5, start_x+16, ' ');
    mvaddch(start_y+5, start_x+17, ' ');
    mvaddch(start_y+5, start_x+18, ' ');
    mvaddch(start_y+5, start_x+20, ' ');
    mvaddch(start_y+5, start_x+21, ' ');
    mvaddch(start_y+5, start_x+22, ' ');
    mvaddch(start_y+5, start_x+23, ' ');
    mvaddch(start_y+5, start_x+24, ' ');
    mvaddch(start_y+5, start_x+4, ' ');
    mvaddch(start_y+5, start_x+10, ' ');
    mvaddch(start_y+5, start_x+12, ' ');
    mvaddch(start_y+5, start_x+15, ' ');
    mvaddch(start_y+5, start_x+19, ' ');

    mvaddch(start_y+6, start_x+1, ' ');
    mvaddch(start_y+6, start_x+2, ' ');
    mvaddch(start_y+6, start_x+3, ' ');
    mvaddch(start_y+6, start_x+8, ' ');
    mvaddch(start_y+6, start_x+10, ' ');
    mvaddch(start_y+6, start_x+11, ' ');
    mvaddch(start_y+6, start_x+12, ' ');
    mvaddch(start_y+6, start_x+14, ' ');
    mvaddch(start_y+6, start_x+16, ' ');
    mvaddch(start_y+6, start_x+17, ' ');
    mvaddch(start_y+6, start_x+18, ' ');
    mvaddch(start_y+6, start_x+20, ' ');
    mvaddch(start_y+6, start_x+21, ' ');
    mvaddch(start_y+6, start_x+22, ' ');
    mvaddch(start_y+6, start_x+23, ' ');
    mvaddch(start_y+6, start_x+24, ' ');
    mvaddch(start_y+6, start_x+4, ' ');
    mvaddch(start_y+6, start_x+5, ' ');
    mvaddch(start_y+6, start_x+6, ' ');
    mvaddch(start_y+6, start_x+7, ' ');
    mvaddch(start_y+6, start_x+9, ' ');
    mvaddch(start_y+6, start_x+13, ' ');
    mvaddch(start_y+6, start_x+15, ' ');
    mvaddch(start_y+6, start_x+19, ' ');


    mvaddch(start_y+7, start_x+2, ' ');
    mvaddch(start_y+7, start_x+3, ' ');
    mvaddch(start_y+7, start_x+4, ' ');
    mvaddch(start_y+7, start_x+5, ' ');
    mvaddch(start_y+7, start_x+6, ' ');
    mvaddch(start_y+7, start_x+7, ' ');
    mvaddch(start_y+7, start_x+8, ' ');
    mvaddch(start_y+7, start_x+9, ' ');
    mvaddch(start_y+7, start_x+10, ' ');
    mvaddch(start_y+7, start_x+11, ' ');
    mvaddch(start_y+7, start_x+12, ' ');
    mvaddch(start_y+7, start_x+13, ' ');
    mvaddch(start_y+7, start_x+14, ' ');
    mvaddch(start_y+7, start_x+15, ' ');
    mvaddch(start_y+7, start_x+16, ' ');
    mvaddch(start_y+7, start_x+17, ' ');
    mvaddch(start_y+7, start_x+18, ' ');
    mvaddch(start_y+7, start_x+19, ' ');
    mvaddch(start_y+7, start_x+20, ' ');
    mvaddch(start_y+7, start_x+21, ' ');
    mvaddch(start_y+7, start_x+22, ' ');
    mvaddch(start_y+7, start_x+23, ' ');

    attroff(COLOR_PAIR(19));

}

