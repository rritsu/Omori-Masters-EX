#ifndef UTILITY_H
#define UTILITY_H

#define sys "\n\n\t\t"
#define DELAY 750
#define LOG_DELAY 1200

#include <stdbool.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#include "../visual/UIVisual.h"
#include "values.h"

void HideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = FALSE;  
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void InitializeRNG() {
    srand(time(NULL));
}

int GenerateRandomNum(int min, int max) {
    int rng = (rand() % (max- min + 1) + min);
    return rng;
}


char GetInput(int numInputs) {
    char c = '0';
    bool validInput = false;

    do {
        c = _getch();
        switch(numInputs) {
            case 1: 
                if(c == '4') validInput = true;
                else InvalidInputPrompt();
                break;
            case 2: 
                if(c == '1' || c == '2') validInput = true;
                else InvalidInputPrompt();
                break;
            case 3: 
                if(c == '1' || c == '2' || c == '3') validInput = true;
                else InvalidInputPrompt();
                break;
            case 4: 
                if(c == '1' || c == '2' || c == '3' || c == '4') validInput = true;
                else InvalidInputPrompt();
                break;
            
        }

    } while(!validInput);   
    return c;
}

void SetBufferLog(char log[LOG_LENGTH], const char* msg) {
    strncpy(log, msg, LOG_LENGTH - 1);
    log[LOG_LENGTH - 1] = '\0';
}




// void StrikeMovePrompt(bool isPlayerMove, int damage) {
//     printf(RESET sys);
//     if(isPlayerMove) printf("[SYSTEM]: Player dealt %d damage to the opponent!", damage);
//     else printf("[SYSTEM]: Enemy dealth %d damage to the player!", damage);
//     Sleep(DELAY);
// }



#endif