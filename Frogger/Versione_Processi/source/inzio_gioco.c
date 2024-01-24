#include "include.h"
#include "extern.h"


int inizio_gioco(){

    //inizializzazione del seed
    srand(getpid());

    //inizializzazione della libreria
    initscr();

    //imposta la modalità della tastiera
    noecho();

    //inizializza lo schermo con i colori 
    start_color();

    //inizializzazione della tastiers
    keypad(stdscr,1);
    curs_set(0); 

    //inizializzazione delle diverse pipes....
    int p[2]; //pipe principale
    pipe(p);
    
    int pc[2];//pipe non bloccante per gestire la comunicazione tra la funzione controllo e la funzione rana nel caso si verifichino delle collisioni con la rana
    pipe(pc);
    fcntl(pc[0], F_SETFL, fcntl(pc[0], F_GETFL) | O_NONBLOCK);

    int pt[2];//pipe non bloccante per comunicare alla funzione che gestisce il timer che la manche è terminata e il tempo deve essere resettato
    pipe(pt);
    fcntl(pt[0], F_SETFL, fcntl(pt[0], F_GETFL) | O_NONBLOCK);

    int pg[2];//pipe non bloccante che comunica alla funzione tronco dalla funzione controllo che ma manche è terminata e i proiettili devono "resettarsi"
    pipe(pg);
    fcntl(pg[0], F_SETFL, fcntl(pg[0], F_GETFL) | O_NONBLOCK);

    int p_2[2];//pipe che serve per comunicare alla funzione macchina di rigenerare tutte le macchine dato che c'è stata una collisione in generazione
    pipe(p_2);
    fcntl(p_2[0], F_SETFL, O_NONBLOCK);

    int p_3[2];//pipe che serve per comunicare alle altre macchine che già una macchina sta cambiando corsia e in caso lo voglia fare un'altra macchina essa deve aspettare
    pipe(p_3);
    fcntl(p_3[0], F_SETFL, O_NONBLOCK);

    
    //creazione di tutti i processi con le rispettive pipes
    pid_t rana = fork();
    if (rana == 0){
        f_rana(p, pc);
        
    }
    else{
        pid_t tempo = fork();
        if(tempo == 0){
            f_tempo(p, pt);
           
        }
        pid_t macchina1 = fork();
        if (macchina1 == 0){
            f_macchina(p,1, p_2, p_3);
            
        }
        else{
            pid_t macchina2 = fork();
            if(macchina2 == 0){
                f_macchina(p,2, p_2, p_3);
                
            }
            else{
                pid_t macchina3 = fork();
                if(macchina3 == 0){
                    f_macchina(p,3, p_2, p_3);
                    
                }
                else{
                    pid_t macchina4 = fork();
                    if (macchina4 == 0){
                        f_macchina(p,4, p_2, p_3);
                       
                    }
                    else{
                        pid_t macchina5 = fork();
                        if(macchina5 == 0){
                            f_macchina(p,5, p_2, p_3);
                            
                        }
                        else{
                            pid_t macchina6 = fork();
                            if (macchina6 == 0){
                                f_macchina(p,6, p_2, p_3);
                                
                            }
                            else{
                                pid_t macchina7 = fork();
                                if(macchina7 == 0){
                                    f_macchina(p,7, p_2, p_3);
                                    
                                }
                                else{
                                    pid_t macchina8 = fork();
                                    if(macchina8 == 0){
                                        f_macchina(p,8, p_2, p_3);
                                        
                                    }
                                    else{
                                        pid_t macchina9 = fork();
                                        if (macchina9 == 0){
                                            f_macchina(p,9, p_2, p_3);
                                            
                                        }
                                        else{
                                            pid_t macchina0 = fork();
                                            if(macchina0 == 0){
                                                f_macchina(p,0, p_2, p_3);
                                                
                                            }
                                            else{
                                                pid_t tronco0 = fork();
                                                if (tronco0 == 0){
                                                    f_tronco(p,20, pg);
                                                    
                                                }
                                                else{
                                                    pid_t tronco1 = fork();
                                                    if (tronco1 == 0){
                                                        f_tronco(p,21, pg);
                                                        
                                                    }
                                                    else{
                                                        pid_t tronco2 = fork();
                                                        if(tronco2 == 0){
                                                            f_tronco(p,22, pg);
                                                           
                                                        }
                                                        else{
                                                            pid_t tronco3 = fork();
                                                            if(tronco3 == 0){
                                                                f_tronco(p,23, pg);
                                                                
                                                            }
                                                            else{
                                                                pid_t tronco4 = fork();
                                                                if (tronco4 == 0){
                                                                    f_tronco(p,24, pg);
                                                                    
                                                                }
                                                                else{
                                                                    f_controllo(p, pc, pt, p_2, p_3);
                                                                    kill(rana,1);
                                                                    kill(tempo,1);
                                                                    kill(macchina1,1);
                                                                    kill(macchina2,1);
                                                                    kill(macchina3,1);
                                                                    kill(macchina4,1);
                                                                    kill(macchina5,1);
                                                                    kill(macchina6,1);
                                                                    kill(macchina7,1);
                                                                    kill(macchina8,1);
                                                                    kill(macchina9,1);
                                                                    kill(macchina0,1);
                                                                    kill(tronco0,1);
                                                                    kill(tronco1,1);
                                                                    kill(tronco2,1);
                                                                    kill(tronco3,1);
                                                                    kill(tronco4,1);
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    menu();
    return 0;
}