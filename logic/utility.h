#ifndef UTILITY_H
#define UTILITY_H

#include <windows.h>

void HideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = FALSE;  
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}


#endif