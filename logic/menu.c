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
        RedirectingBackNotice();
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
                    PurchaseNotice(c, true);
                }
                else PurchaseNotice(c, false);
                break;
            case '2':
                if(p->gems >= TECH_COST) {
                    p->gems -= TECH_COST;
                    p->techSync.quantity++;
                    PurchaseNotice(c, true);
                }
                else PurchaseNotice(c, false);
                break;
            case '3':
                if(p->gems >= SUPPORT_COST) {
                    p->gems -= SUPPORT_COST;
                    p->supportSync.quantity++;
                    PurchaseNotice(c, true);
                }
                else PurchaseNotice(c, false);
                break;
            case '4':
                RedirectingBackNotice();
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
        ExitGameNotice();
    }
}

void GoToWhiteRoom(Player* p) {
    char c;
    do {
        CheckPlayerStatus(p);
        system("cls");
        DisplayBlackRoom(*p);
        c = GetInput(3);

        switch(c) {
        case '1':
            RedirectingToBattleNotice();
            BattleLoop(p);
            break;
        case '2':
            RedirectingNotice(c);
            GoToInventory(*p);
            break;
        case '3':
            RedirectingBackNotice();
            break;
        }
    } while(c != '3');
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
                RedirectingNotice(c);
                GoToWhiteRoom(&player);
                break;
            case '2':
                RedirectingNotice(c);
                GoToInventory(player);
                break;
            case '3':
                RedirectingNotice(c);
                GoToShop(&player);
                break;
            case '4':
                ConfirmExit(&exitGame);
                break;
        }
    } while (!exitGame); 

}