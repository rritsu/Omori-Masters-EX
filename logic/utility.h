#ifndef UTILITY_H
#define UTILITY_H

#define NUMBER_OF_FLOORS 20
#define REWARD_A 50
#define REWARD_B 80
#define REWARD_C 100
#define REWARD_D 500

#define STRIKE_COST 200
#define TECH_COST 100
#define SUPPORT_COST 100

#define sys "\n\n\n\t\t"
#define DELAY 750

#include <stdbool.h>
#include <windows.h>

#include "../visual/UIVisual.h"

void HideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = FALSE;  
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

char GetInput(int numInputs) {
    char c = '0';
    bool validInput = false;

    do {
        c = _getch();
        switch(numInputs) {
            case 1: {
                if(c == '4') validInput = true;
                else InvalidInputPrompt();
                break;
            }
            case 2: {
                if(c == '1' || c == '2') validInput = true;
                else InvalidInputPrompt();
                break;
            }
            case 4: {
                if(c == '1' || c == '2' || c == '3' || c == '4') validInput = true;
                else InvalidInputPrompt();
                break;
            }
        }

    } while(!validInput);   
    return c;
}

#endif