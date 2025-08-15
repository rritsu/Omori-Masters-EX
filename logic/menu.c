#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <stdbool.h>

#include "../visual/UIVisual.h"

#include "player.h"
#include "utility.h"

void ConfigureScreenSettings() {
    BorderCheck();
    char c = _getch();
   // Sleep(500);
}

void InitializePlayer(Player* player) {
    player->strikeSync.HP = 100;
    player->strikeSync.quantity = 1;

    player->techSync.HP = 100;
    player->techSync.quantity = 1;

    player->supportSync.HP = 100;
    player->supportSync.quantity = 1;

    player->gems = 0;
}

void GoToInventory(Player p) {
    char c;
    do {
        system("cls");
        DisplayInventory(p);
        c = _getch(); 

        if(c!= '4') {
            InvalidInputPrompt();
            Sleep(800);
        }

        switch(c) {
            case '4':
                RedirectingBack();
                Sleep(750);
                break;
        }

    } while (c != '4'); 
}

void BuySyncPair(Player p, char c) {
    switch(c) {
        case '1':
           
            break;
    }
}

void GoToShop(Player* p) {
    char c;
    do {
        system("cls");
        DisplayShop(*p);
        c = _getch();

        if(c != '1' && c != '2' && c != '3' && c != '4') {
            InvalidInputPrompt();
            Sleep(800);
        }

        switch(c) {
            case '1':
                if(p->gems >= STRIKE_COST) {
                    p->gems -= STRIKE_COST;
                    p->strikeSync.quantity++;
                    PurchasePrompt(c, true);
                }
                else PurchasePrompt(c, false);
                Sleep(750);
                break;
            case '2':
                if(p->gems >= TECH_COST) {
                    p->gems -= TECH_COST;
                    p->techSync.quantity++;
                    PurchasePrompt(c, true);
                }
                else PurchasePrompt(c, false);
                Sleep(750);
                break;
            case '3':
                if(p->gems >= SUPPORT_COST) {
                    p->gems -= SUPPORT_COST;
                    p->supportSync.quantity++;
                    PurchasePrompt(c, true);
                }
                else PurchasePrompt(c, false);
                Sleep(750);
                break;
            case '4':
                RedirectingBack();
                Sleep(750);
                break;
        }

    } while (c != '4'); 
}

void ConfirmExit(bool* exitGame) {
    bool validInput = false;

    char c = '0';
    do {
        system("cls");
        DisplayMainMenu(true);
        c = _getch();

        if(c!= '1' && c!= '2') {
            InvalidInputPrompt();
            Sleep(800);
        }
        else {
            validInput = true;
            if(c == '1') {
                *exitGame = true;
                ExitPrompt();
                Sleep(750);
            }
        }

    } while(!validInput);
}

void MainMenu() {
    bool exitGame = 0;
    Player player;
    char c = '0';
    InitializePlayer(&player);

    do {
        system("cls");
        DisplayMainMenu(false);

        c = _getch(); 

        if(c != '1' && c != '2' && c != '3' && c != '4') {
            InvalidInputPrompt();
            Sleep(800);
        }

        switch (c) {
            case '1':
                printf("Play game (placeholder)\n");
                Sleep(500);
                break;
            case '2':
                RedirectingPrompt(c);
                Sleep(750);
                GoToInventory(player);
                break;
            case '3':
                RedirectingPrompt(c);
                Sleep(750);
                GoToShop(&player);
                break;
            case '4':
                ConfirmExit(&exitGame);
                break;
        }

        // if(!exitGame) {        
        //     system("cls");
        //     DisplayMainMenu(false);
        // }

    } while (!exitGame); 

}