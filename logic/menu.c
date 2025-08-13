#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <stdbool.h>

#include "../visual/colors.h"
#include "../visual/UIVisual.h"

#include "inventory.c"
#include "player.h"



void mainMenu() {
    Player player = {1, 1, 1, 0};
    char c = '0';

    do {
        system("cls");
        displayMainMenu();
        c = _getch(); 

        switch (c) {
            case '1':
                printf("Play game (placeholder)\n");
                Sleep(500);
                break;
            case '2':
                redirectingPrompt(c);
                Sleep(750);
                goToInventory(player);
                break;
            case '3':
                printf("Shop (placeholder)\n");
                Sleep(500);
                break;
        }
    } while (c != '4'); 

}