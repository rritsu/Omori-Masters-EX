#ifndef UI_VISUAL_H 
#define UI_VISUAL_H


#include <stdio.h>
#include "colors.h"
#include "../logic/player.h"

void printSeparator() {
    printf("\n\n");
    printf(RESET"\t\t\t\t ════════════════════════════════════════════════════════════════════════════════════════════\n");
}

void displayMainMenu() {
    
   // printf(HI_BLACK);
   // printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");

    printf(HI_YELLOW "\n\n\n\n");
    printf( "\t\t\t\t\t\t    _______     __   __     _______     ______       ___    \n"
            "\t\t\t\t\t\t  ▓|       |  ▓|  |_|  |  ▓|       |  ▓|    _ |    ▓|   |   \n"
            "\t\t\t\t\t\t  ▓|   _   |  ▓|       |  ▓|   _   |  ▓|   | ||    ▓|   |   \n"
            "\t\t\t\t\t\t  ▓|  | |  |  ▓|       |  ▓|  | |  |  ▓|   |_||_   ▓|   |   \n"
            "\t\t\t\t\t\t  ▓|  |_|  |  ▓|       |  ▓|  |_|  |  ▓|    __  |  ▓|   |   \n"
            "\t\t\t\t\t\t  ▓|       |  ▓| ||_|| |  ▓|       |  ▓|   |  | |  ▓|   |   \n"
            "\t\t\t\t\t\t  ▓|_______|  ▓|_|   |_|  ▓|_______|  ▓|___|  |_|  ▓|___|   \n"
            "\n\n\n"
        HI_RED    "\t\t\t\t      __   __  _______  _______  ______  _______  ______    _______     _______  __   __ \n"
        HI_RED    "\t\t\t\t    ▓|  |_|  ||   _   ||  _____||_    _||   ____||    _ |  |  _____|   ▓|   ____||  |_|  |\n"
        HI_PURPLE "\t\t\t\t    ▓|       ||  |_|  || |_____   |  |  |  |___  |   |_||_ | |_____    ▓|  |____ |       |\n"
        HI_PURPLE "\t\t\t\t    ▓|       ||       ||_____  |  |  |  |   ___| |    __  ||_____  |   ▓|   ____| |     | \n"
        HI_BLUE   "\t\t\t\t    ▓| ||_|| ||   _   | _____| |  |  |  |  |____ |   |  | | _____| |   ▓|  |____ |   _   |\n"
        HI_BLUE   "\t\t\t\t    ▓|_|   |_||__| |__||_______|  |__|  |_______||___|  |_||_______|   ▓|_______||__| |__|\n");

    printSeparator();
    printf("\n\n\n\n\n\n\n");
    printf(HI_YELLOW"\t\t\t\t\t\t\t\t\t[1] Play Game\n");
    printf(HI_GREEN"\t\t\t\t\t\t\t\t\t[2] Inventory\n");
    printf(HI_BLUE"\t\t\t\t\t\t\t\t\t[3] Shop\n");
    printf(HI_RED"\t\t\t\t\t\t\t\t\t[4] Quit\n");
    printf(RESET);

}

void redirectingBack() {
    printf(RESET"\n\n\n\t\t\t\t\t\t\t   ");
    printf("[SYSTEM]: Redirecting back...\n");
}

void redirectingPrompt(char c) {
    printf(RESET"\n\n\n\t\t\t\t\t\t\t   ");
    switch(c) {
        case '1': printf("[SYSTEM]: Redirecting to Battle...\n"); break;
        case '2': printf("[SYSTEM]: Redirecting to Inventory...\n"); break;
        case '3': printf("[SYSTEM]: Redirecting to Shop...\n"); break;
    }
}

void displaySyncPairs(Player p) {

}

void displayInventory(Player p) {
    printf("\n\n\n\n\n");
    printf("\t\t\t\t\t««««««««««««««««««   Inventory   »»»»»»»»»»»»»»»»»»\n");
    displaySyncPairs(p);
}


#endif 


