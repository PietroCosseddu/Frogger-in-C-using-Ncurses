#include "include.h"
#include "extern.h"

void* f_rana(void *X){
    
    rana.ID='R';
    rana.x = MAXX/2;
    rana.y = MAXY-9;
    sleep(5);

    while(true){

        if(restart == true){
            return 0;
        }

        pthread_mutex_lock(&mutex);
        if(vite > 0 && tane_riempite < 5){
            stampa();
        }
        pthread_mutex_unlock(&mutex);

        restart_manche();
        
        timeout(1);
        int c = getch();
        pthread_mutex_lock(&mutex);

        switch(c){
            case KEY_UP: 
                if(rana.y > 4)
                    rana.y -= RANA_H; 
                    break;
            case KEY_DOWN:
                if(rana.y < MAXY - MARCIAPIEDE)
                    rana.y += RANA_H; 
                    break;
            case KEY_LEFT: 
                if(rana.x > BORDER)
                    rana.x -= 1; 
                break;
            case KEY_RIGHT:
                if(rana.x < MAXX-3)
                    rana.x += 1;
                break;
            case SPACE_BAR:
                proiettile_rana.sparato = true;
                break;
            //movimento WASD
            case UP: 
                if(rana.y > 4)
                    rana.y -= RANA_H; 
                    break;
            case DOWN:
                if(rana.y < MAXY - MARCIAPIEDE)
                    rana.y += RANA_H; 
                    break;
            case LEFT: 
                if(rana.x > BORDER)
                    rana.x -= 1; 
                break;
            case RIGHT:
                if(rana.x < MAXX-RANA_W)
                    rana.x += 1;
                break;
        }

        pthread_mutex_unlock(&mutex);
        usleep(100);
    }
}

void* f_proiettile_rana(void *X){

    while(true){
        
        if(restart == true){
            pthread_exit(&proiettile_rana); //controllo se si deve uscire dalla funzione in caso di fine partita
        }

        if(proiettile_rana.sparato == true){
            
            //inizializzazione delle coordinate del proiettile in base alla rana
            proiettile_rana.y = rana.y;
            proiettile_rana.x = rana.x+1;
            proiettile_rana.ID = 'p';

            while(proiettile_rana.y >= 0){

                pthread_mutex_lock(&mutex);
                proiettile_rana.y--; //movimento del proiettile 
                pthread_mutex_unlock(&mutex);

                usleep(40000);
            }

            pthread_mutex_lock(&mutex);
            proiettile_rana.sparato = false;
            pthread_mutex_unlock(&mutex);
        }
    }
}  