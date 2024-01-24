#include "include.h"
#include "extern.h"

void* playSound(void* X){
    char command[256];
    #ifdef __linux__
    sprintf(command,"aplay %s","sounds/enemy_hit.wav");
    system(strcat(command," 1>/dev/null 2>/dev/null"));
    #endif
    #ifdef __APPLE__ || __MACH__
        sprintf(command,"afplay %s","sounds/enemy_hit.wav");
        system(command);
    #endif

    pthread_exit(0);
}

void* playSplash(void* X){
    char command[256];
    #ifdef __linux__
    sprintf(command,"aplay %s","sounds/splash.wav");
    system(strcat(command," 1>/dev/null 2>/dev/null"));
    #endif
    #ifdef __APPLE__ || __MACH__
        sprintf(command,"afplay %s","sounds/splash.wav");
        system(command);
    #endif

    pthread_exit(0);
}

void* playStart(void* X){
    char command[256];
    #ifdef __linux__
    sprintf(command,"aplay %s","sounds/start.wav");
    system(strcat(command," 1>/dev/null 2>/dev/null"));
    #endif
    #ifdef __APPLE__ || __MACH__
        sprintf(command,"afplay %s","sounds/start.wav");
        system(command);
    #endif

    pthread_exit(0);
}

void* playCrash(void* X){
    char command[256];
    #ifdef __linux__
    sprintf(command,"aplay %s","sounds/car_hit.wav");
    system(strcat(command," 1>/dev/null 2>/dev/null"));
    #endif
    #ifdef __APPLE__ || __MACH__
        sprintf(command,"afplay %s","sounds/car_hit.wav");
        system(command);
    #endif

    pthread_exit(0);
}

void* playPing(void* X){
    char command[256];
    #ifdef __linux__
    sprintf(command,"aplay %s","sounds/ping.wav");
    system(strcat(command," 1>/dev/null 2>/dev/null"));
    #endif
    #ifdef __APPLE__ || __MACH__
        sprintf(command,"afplay %s","sounds/ping.wav");
        system(command);
    #endif

    pthread_exit(0);
}

void* playWin(void* X){
    char command[256];
    #ifdef __linux__
    sprintf(command,"aplay %s","sounds/win.wav");
    system(strcat(command," 1>/dev/null 2>/dev/null"));
    #endif
    #ifdef __APPLE__ || __MACH__
        sprintf(command,"afplay %s","sounds/win.wav");
        system(command);
    #endif

    pthread_exit(0);
}

void* playGameOver(void* X){
    char command[256];
    #ifdef __linux__
    sprintf(command,"aplay %s","sounds/game_over.wav");
    system(strcat(command," 1>/dev/null 2>/dev/null"));
    #endif
    #ifdef __APPLE__ || __MACH__
        sprintf(command,"afplay %s","sounds/game_over.wav");
        system(command);
    #endif

    pthread_exit(0);
}

