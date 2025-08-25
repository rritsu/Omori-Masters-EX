#ifndef MENU_H
#define MENU_H

#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <stdbool.h>

#include "struct.h"
#include "../visual/UIVisual.h"

void ConfigureScreenSettings();

void GoToInventory(const Player* p);

void GoToShop(Player* p);

void ConfirmExit(bool* exitGame);
void ChooseSpecialReward(Player* p);
void ConfirmReset(Player* p);
void CongratsScreen();
void GoToBlackRoom(Player* p);


void MainMenu();

#endif