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



#include <windows.h>

void HideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = FALSE;  
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}


#endif