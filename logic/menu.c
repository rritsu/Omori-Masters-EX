#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <stdbool.h>

#include "struct.h"
#include "utility.h"
#include "battle.c"
#include "values.h"

void ConfigureScreenSettings() {
    BorderCheck();
    char c = _getch();
   // Sleep(500);
}



void GoToInventory(Player p) {
    system("cls");
    DisplayInventory(p);
    char c = GetInput(1);
    if(c == '4')
        RedirectingBackPrompt();
}

void GoToShop(Player* p) {
    char c;
    do {
        system("cls");
        DisplayShop(*p);
        c = GetInput(4);
        switch(c) {
            case '1':
                if(p->gems >= STRIKE_COST) {
                    p->gems -= STRIKE_COST;
                    p->strikeSync.quantity++;
                    PurchasePrompt(c, true);
                }
                else PurchasePrompt(c, false);
                break;
            case '2':
                if(p->gems >= TECH_COST) {
                    p->gems -= TECH_COST;
                    p->techSync.quantity++;
                    PurchasePrompt(c, true);
                }
                else PurchasePrompt(c, false);
                break;
            case '3':
                if(p->gems >= SUPPORT_COST) {
                    p->gems -= SUPPORT_COST;
                    p->supportSync.quantity++;
                    PurchasePrompt(c, true);
                }
                else PurchasePrompt(c, false);
                break;
            case '4':
                RedirectingBackPrompt();
                break;
        }

    } while (c != '4'); 
}

void ConfirmExit(bool* exitGame) {
    system("cls");
    DisplayMainMenu(true);
    char c = GetInput(2);
    if(c == '1') {
        *exitGame = true;
        ExitPrompt();
    }
}

void GoToWhiteRoom(Player* p) {
    system("cls");
    DisplayBlackRoom(*p);
    char c = GetInput(2);
    switch(c) {
        case '1':
            RedirectingToBattlePrompt();
            BattleLoop(p);
            break;
        case '2':
            RedirectingBackPrompt();
            break;
    }
    //might have to make a do-while loop later, so that player stays in the room after battle
}

void MainMenu() {
    bool exitGame = 0;
    Player player;
    InitializePlayer(&player);
    do {
        system("cls");
        DisplayMainMenu(false);
        char c = GetInput(4);
        switch (c) {
            case '1':
                RedirectingPrompt(c);
                GoToWhiteRoom(&player);
                break;
            case '2':
                RedirectingPrompt(c);
                GoToInventory(player);
                break;
            case '3':
                RedirectingPrompt(c);
                GoToShop(&player);
                break;
            case '4':
                ConfirmExit(&exitGame);
                break;
        }
    } while (!exitGame); 

}