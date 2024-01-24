#include "include.h"
#include "extern.h"


void f_tronco(int p[2], int ID, int pg[2]){

    //inizializzazione del seed in base al pid del processo in modo da avere sempre risultati random
    srand(getpid());

    posizione tronco; //definizione degli oggetti struct che verranno utilizzati

    pid_t proiettile; //definisco il processo del proiettile del nemico, ogni tronco creerà a sua volta un processo ciascuno che rappresenta il proiettile flag dal nemico 

    int arr_direzione[] = {-1,1}; //array che contiene le direzioni possibili, da destra verso sinistra o viceversa
    int arr_flusso[] = {20,17,14,11,8}; //array che contiene la y dei 5 flussi attraversati dai 5 tronchi
    int direzione = arr_direzione[rand()%2]; // la direzione viene scelta randomicamente

    //inizializzazione del tronco
    tronco.y = arr_flusso[ID-20]; //la corsia viene decisa in base all'ID
    tronco.x = BORDER+1+rand()%70;
    tronco.ID = ID;
    tronco.flag = false; //flag settata a false

    //timers per lo spawn dei nemici
    int lim_timer = 60+rand()%250; //quando lim_timer è > spawn_timer allora il nemico non può spawnare
    int spawn_timer = 0; //quando spawn_timer è > lim_timer allora questo spawna al centro del tronco

    //timers per lo sparo dei proiettili quando i nemici sono spawnati nel tronco 
    int lim_shoot = 30+rand()%90;
    int shoot_timer = 0;

    //variabili che cambiano in base alla decisione della difficoltà
    int bull_timer; //timer che si deve aspettare perché il nemico possa risparare un proiettile
    int speed; //velocità dei tronchi

    if (difficolta == EASY){
        bull_timer = 300;
        speed = 65000;
    } 
    else if(difficolta == MEDIUM){
        bull_timer = 150;
        speed = 50000;
    }
    else if(difficolta == HARD){
        bull_timer = 0;
        speed = 40000;
    }

    while(true){
        
        //il tronco cambia direzione ogni volta che tocca uno dei bordi dell'area di gioco
        if (tronco.x >= MAXX-LOG_LEN || tronco.x <= BORDER){
            direzione *= -1;
        }

        if(spawn_timer > lim_timer && tronco.flag == false){ //controllo che il timer per lo spawn sia maggiore di lim_timer e che il flag sia false
            tronco.flag = true; //flag viene settata a true e il nemico spawna nel tronco

            //i timer vengono ripristinati
            spawn_timer += 250+rand()%200; 
            lim_timer = 60+rand()%300;
        }

        else if(spawn_timer < 0){ // se il timer dello spawn diventa < 0 la flag viene messa a false, quindi il nemico despowna dal tronco 
            tronco.flag = false;
        }
        
        if(tronco.flag == false){
            spawn_timer++; // una volta despownato il nemico perché lo spawn_timer è arrivato a < 0 si rincomincia ad incrementare finché non supera il lim_timer e quindi respawna il nemico sul tronco 
        }

        if(tronco.flag == true){ //il nemico è sul tronco

            if (shoot_timer >= lim_shoot){
                shoot_timer = 0;
                lim_shoot = 1+rand()%bull_timer; //viene ricalcolato il timer per sparare un nuovo proiettile

                if(waitpid(-1, NULL, WNOHANG) != 0){//controllo se il processo del proiettile flag in precedenza è stato terminato, 
                                                    //-1 indica che attende qualsiasi processo figlio, 
                                                    //NULL indica che non desidera ottenere lo stato di terminazione del processo figlio, 
                                                    //WNOHANG indica che non deve bloccare l'esecuzione se il processo figlio non è terminato
                    proiettile = fork(); //creo un nuovo proiettile
                    if(proiettile == 0){
                        f_enemy_bullet(p, tronco); //chiamo la funzione che si occupa di muovere il proiettile
                    }
                }
            }

            shoot_timer++; //il timer per sparare aumenta ad ogni iterazione fino ad essere maggiore del lim_shoot e poter sparare il proiettile.
            spawn_timer--; //viene decrementato anche lo spawn_timer fino ad arrivare < 0, quando succede il nemico despowna
        }

        tronco.x += direzione; //movimento del tronco 

        write(p[1],&tronco,sizeof(posizione)); //scrittura nella pipe del tronco 
        usleep(speed); //delay espresso in millisecondi
    }
}

void f_enemy_bullet(int p[2], posizione tronco){

    posizione enemy_bullet;

    int speed;
    //in base alla difficoltà selezionata prima dell'inizio della partita cambia la velocità di movimento dei proiettili
    if(difficolta == EASY){
        speed = 60000;
    }
    else if(difficolta == MEDIUM){
        speed = 45000;
    }
    else if(difficolta == HARD){
        speed = 20000;
    }

    //il proiettile avrà come posizione di partenza le coordinate del nemico che sta sul tronco 
    enemy_bullet.x = tronco.x+4;
    enemy_bullet.y = tronco.y+2;
    enemy_bullet.ID = tronco.ID * 10;

    write(p[1], &enemy_bullet, sizeof(posizione));

    while(enemy_bullet.y <= MAXY-7){ //il proiettile si ferma quando supera il bordo 

        enemy_bullet.y++; //incremento della y del proiettile 
        write(p[1], &enemy_bullet, sizeof(posizione)); //scrivo il cambiamento nella pipe principale

        usleep(speed);
    }
    _exit(0); //killo il processo per poterne creare uno nuovo quando si spara un altro proiettile
}
