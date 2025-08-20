#ifndef UTILITY_H
#define UTILITY_H

#define sys "\n\n\t\t"
#define DELAY 750
#define LOG_DELAY 1200
#define LONG_DELAY 1800
#define LOG_LENGTH 400

#include <stdbool.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

//#include "../visual/UIVisual.h"


void HideCursor();
void InitializeRNG();
int GenerateRandomNum(int min, int max);
char GetInput(int numInputs);
void SetBufferLog(char log[LOG_LENGTH], const char* msg);
int GetEnemyMaxHP(char type);


#endif