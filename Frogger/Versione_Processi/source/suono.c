#include "include.h"
#include "extern.h"

void splashSound(int p[2]){
    char command[256];
    #ifdef __linux__
    sprintf(command,"aplay %s","sounds/splash.wav");
    system(strcat(command," 1>/dev/null 2>/dev/null"));
    #endif
    #ifdef __APPLE__ || __MACH__
        sprintf(command,"afplay %s","sounds/splash.wav");
        system(command);
    #endif

    _exit(0);
}

void playSound(int p[2]){
    char command[256];
    #ifdef __linux__
    sprintf(command,"aplay %s","sounds/enemy_hit.wav");
    system(strcat(command," 1>/dev/null 2>/dev/null"));
    #endif
    #ifdef __APPLE__ || __MACH__
        sprintf(command,"afplay %s","sounds/enemy_hit.wav");
        system(command);
    #endif

    _exit(0);
}

void startSound(int p[2]){
    char command[256];
    #ifdef __linux__
    sprintf(command,"aplay %s","sounds/start.wav");
    system(strcat(command," 1>/dev/null 2>/dev/null"));
    #endif
    #ifdef __APPLE__ || __MACH__
        sprintf(command,"afplay %s","sounds/start.wav");
        system(command);
    #endif

    _exit(0);
}

void car_hitSound(int p[2]){
    char command[256];
    #ifdef __linux__
    sprintf(command,"aplay %s","sounds/car_hit.wav");
    system(strcat(command," 1>/dev/null 2>/dev/null"));
    #endif
    #ifdef __APPLE__ || __MACH__
        sprintf(command,"afplay %s","sounds/car_hit.wav");
        system(command);
    #endif

    _exit(0);
}

void pingSound(int p[2]){
    char command[256];
    #ifdef __linux__
    sprintf(command,"aplay %s","sounds/ping.wav");
    system(strcat(command," 1>/dev/null 2>/dev/null"));
    #endif
    #ifdef __APPLE__ || __MACH__
        sprintf(command,"afplay %s","sounds/ping.wav");
        system(command);
    #endif

    _exit(0);
}

void winSound(int p[2]){
    char command[256];
    #ifdef __linux__
    sprintf(command,"aplay %s","sounds/win.wav");
    system(strcat(command," 1>/dev/null 2>/dev/null"));
    #endif
    #ifdef __APPLE__ || __MACH__
        sprintf(command,"afplay %s","sounds/win.wav");
        system(command);
    #endif

    _exit(0);
}

void gameOverSound(int p[2]){
    char command[256];
    #ifdef __linux__
    sprintf(command,"aplay %s","sounds/game_over.wav");
    system(strcat(command," 1>/dev/null 2>/dev/null"));
    #endif
    #ifdef __APPLE__ || __MACH__
        sprintf(command,"afplay %s","sounds/game_over.wav");
        system(command);
    #endif

    _exit(0);
}