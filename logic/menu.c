#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <stdbool.h>

#include "../visual/UIVisual.h"

#include "inventory.c"
#include "player.h"



void ConfigureScreenSettings() {
    BorderCheck();
    char c = _getch();
   // Sleep(500);
}

void InitializePlayer(Player* player) {
    player->strikeSync.HP = 40;
    player->strikeSync.quantity = 1;

    player->techSync.HP = 20;
    player->techSync.quantity = 1;

    player->supportSync.HP = 100;
    player->supportSync.quantity = 1;

    player->gems = 0;
}

void MainMenu() {
    Player player;
    char c = '0';

    system("cls");
    DisplayMainMenu();
    InitializePlayer(&player);

    do {
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
                printf("Shop (placeholder)\n");
                Sleep(500);
                break;
        }

        

        system("cls");
        DisplayMainMenu();

    } while (c != '4'); 

}