#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <stdbool.h>

#include "../visual/colors.h"
#include "../visual/UIVisual.h"

#include "inventory.c"
#include "player.h"

void ConfigureScreenSettings() {
    BorderCheck();
    char c = _getch();
   // Sleep(500);
}

void MainMenu() {
    Player player = {1, 1, 1, 0};
    char c = '0';

    system("cls");
    DisplayMainMenu();

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