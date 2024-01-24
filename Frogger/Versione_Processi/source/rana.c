#include "include.h"
#include "extern.h"


void f_rana(int p[2], int pc[2]){

    //dichiarazione delle variabili che verranno utilizzate
    posizione rana, data, oldfrog;

    //l'oggetto rana viene inizializzato per la prima volta e viene posizionata al centro del marciapiede
    rana.ID='R';
    rana.y=MAXY-9;
    rana.x=MAXX/2; 
    rana.flag=false;

    //la flag della variabile utilizzata per il controllo delle collisioni viene settata a false,
    data.flag=false; // se è true significa che si è verificata una collisione e bisogna resettarne la posizione

    pid_t bullet; //viene dichiarato il processo proiettile che verrà creato all'interno della funzione della rana quando viene premuta la barra spaziatrice
    
    write(p[1],&rana, sizeof(posizione));

    while(true){

        timeout(1); 
        int c = getch(); //getch per lo spostamento della rana o lo sparo di un proiettile

        //read non bloccante che aspetta ci sia una collisione con la rana
        read(pc[0], &data, sizeof(posizione));
        if(data.flag==true){ //se c'è stata una collisione bisogna riportare la rana sul marciapiede
            rana.x=data.x;
            rana.y=data.y;
            data.flag = false; //la flag viene risettata a false
        }
        
        switch(c) {
            case SPACE_BAR: //se viene premuta la barra spaziatrice la flag della rana viene settata a true il proiettile deve essere flag
                if(waitpid(-1, NULL, WNOHANG) != 0){ //controllo se il processo del proiettile flag in precedenza è stato terminato, 
                                                    //-1 indica che attende qualsiasi processo figlio, 
                                                    //NULL indica che non desidera ottenere lo stato di terminazione del processo figlio, 
                                                    //WNOHANG indica che non deve bloccare l'esecuzione se il processo figlio non è terminato
                    bullet = fork(); //creo il un nuovo proiettile ogni volta che questo viene flag
                    if(bullet == 0){
                        f_proiettile(p, rana); //chiamo la funzione che si occupa di muovere il proiettile e stamparlo nella pipe
                    }
                    break;
                }
                break;
            // gestione del movimento con le frecce della tastiera, con rispettivi controlli per non uscire dal bordo di gioco
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
                if(rana.x < MAXX-RANA_W)
                    rana.x += 1;
                break;

            //Movimento WASD
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
        
        //se la rana ha cambiato posizione o è stata premuta la spacebar allora viene scritta nella pipe,
        //altrimeni se non è stata fatta alcuna azione essa non viene scritta in modo da non riempire la pipe con un oggetto idendico a quello scritto in precedenza
        if (oldfrog.x != rana.x || oldfrog.y != rana.y || rana.flag == true){
            write(p[1],&rana, sizeof(posizione));
        }
        oldfrog = rana; //i dati della rana vengono salvati per svolgere il controllo nel ciclo successivo e scrivere nella pipe solo in caso uno di questi cambi
        usleep(15000); //delay della rana espresso in millisecondi
    }
}

void f_proiettile(int p[2], posizione frog){

    posizione bullet; //inizializzo l'oggetto proiettile

    //il proiettile prende le posizioni della rana che è stata passata come parametro alla funzione
    bullet.y = frog.y;  
    bullet.x = frog.x+1;

    bullet.ID = 'P';

    write(p[1], &bullet, sizeof(posizione));

    while(bullet.y >= 0){ //il proiettile si ferma quando supera il bordo 
        bullet.y --; //il proiettile si muove dal basso verso l'alto, la y va decrementata fino ad arrivare a 0
        write(p[1], &bullet, sizeof(posizione));
        usleep(40000);
    }
    _exit(0); //killo il processo per poterne creare uno nuovo quando si spara un altro proiettile
} 

