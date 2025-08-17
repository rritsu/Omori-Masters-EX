#ifndef UTILITY_H
#define UTILITY_H

#define sys "\n\n\n\t\t"
#define DELAY 750

#include <stdbool.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#include "../visual/UIVisual.h"

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


#endif