#ifndef UI_VISUAL_H 
#define UI_VISUAL_H


#include <stdio.h>
#include <string.h>

#include "colors.h"
#include "enemyVisual.h"
#include "playerVisual.h"

#include "../logic/player.h"

void PrintSeparator() {
    printf("\n\n");
    printf(RESET"\t\t\t\t ═══════════════════════════════════════════════════════════════════════════════════════════════════════\n");
}

void DisplayMainMenu() {
    printf(HI_YELLOW "\n\n\n\n");
    printf( "\t\t\t\t\t\t\t    _______     __   __     _______     ______       ___    \n"
            "\t\t\t\t\t\t\t  ▓|       |  ▓|  |_|  |  ▓|       |  ▓|    _ |    ▓|   |   \n"
            "\t\t\t\t\t\t\t  ▓|   _   |  ▓|       |  ▓|   _   |  ▓|   | ||    ▓|   |   \n"
            "\t\t\t\t\t\t\t  ▓|  | |  |  ▓|       |  ▓|  | |  |  ▓|   |_||_   ▓|   |   \n"
            "\t\t\t\t\t\t\t  ▓|  |_|  |  ▓|       |  ▓|  |_|  |  ▓|    __  |  ▓|   |   \n"
            "\t\t\t\t\t\t\t  ▓|       |  ▓| ||_|| |  ▓|       |  ▓|   |  | |  ▓|   |   \n"
            "\t\t\t\t\t\t\t  ▓|_______|  ▓|_|   |_|  ▓|_______|  ▓|___|  |_|  ▓|___|   \n"
            "\n\n\n"
        HI_RED    "\t\t\t\t\t    __   __  _______  _______  ______  _______  ______    _______     _______  __   __ \n"
        HI_RED    "\t\t\t\t\t  ▓|  |_|  ||   _   ||  _____||_    _||   ____||    _ |  |  _____|   ▓|   ____||  |_|  |\n"
        HI_PURPLE "\t\t\t\t\t  ▓|       ||  |_|  || |_____   |  |  |  |___  |   |_||_ | |_____    ▓|  |____ |       |\n"
        HI_PURPLE "\t\t\t\t\t  ▓|       ||       ||_____  |  |  |  |   ___| |    __  ||_____  |   ▓|   ____| |     | \n"
        HI_BLUE   "\t\t\t\t\t  ▓| ||_|| ||   _   | _____| |  |  |  |  |____ |   |  | | _____| |   ▓|  |____ |   _   |\n"
        HI_BLUE   "\t\t\t\t\t  ▓|_|   |_||__| |__||_______|  |__|  |_______||___|  |_||_______|   ▓|_______||__| |__|\n");

    PrintSeparator();
    printf("\n\n\n\n\n\n");
    printf(HI_YELLOW"\t\t\t\t\t\t\t\t\t     [1] Play Game\n\n");
    printf(HI_BLUE  "\t\t\t\t\t\t\t\t\t     [2] Inventory\n\n");
    printf(HI_GREEN "\t\t\t\t\t\t\t\t\t     [3] Shop\n\n");
    printf(HI_RED   "\t\t\t\t\t\t\t\t\t     [4] Quit\n\n\n\n\n\n\n\n\n");
    printf(RESET);

}

void BorderCheck() {
    
    printf("╔════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    int r = 42;
    for(int i = 0; i < r; i++) {
        printf("║                                                                                                                                                                        ║\n");
    }

    printf("║\t\t1. Switch to Fullscreen                                                                                                                                  ║\n");
    printf("║\t\t2. Adjust Screen by zooming out with Ctrl + Scroll Down                                                                                                  ║\n");
    printf("║\t\t3. Align the borders to the corner of your screen, scroll up                                                                                             ║\n");
    printf("║\t\t4. Press any key to continue (* ^ ω ^)                                                                                                                   ║\n");
    printf("╚════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
}

void InvalidInputPrompt() {
    printf(RESET"\n\n\t\t");
    printf("[SYSTEM]: Invalid input :(\n");
}

void RedirectingBack() {
    printf(RESET"\n\n\t\t");
    printf("[SYSTEM]: Redirecting back...\n");
}

void RedirectingPrompt(char c) {
    printf(RESET"\n\n\t\t");
    switch(c) {
        case '1': printf("[SYSTEM]: Redirecting to Battle...\n"); break;
        case '2': printf("[SYSTEM]: Redirecting to Inventory...\n"); break;
        case '3': printf("[SYSTEM]: Redirecting to Shop...\n"); break;
    }
}

void DisplayInventory(Player p) {
    int max = 0;

    printf("\n\n\n\n");
    printf(HI_PURPLE "\t\t\t\t\t\t\t\t  ___                      _                   \n"
           HI_PURPLE "\t\t\t\t\t\t\t\t▓|_ _|_ ____   _____ _ __ | |_ ___  _ __ _   _ \n"
           HI_PURPLE "\t\t\t\t\t\t\t\t ▓| || '_ \\ \\ / / _ \\ '_ \\| __/ _ \\| '__| | | |\n"
           HI_BLUE   "\t\t\t\t\t\t\t\t ▓| || | | \\ V /  __/ | | | || (_) | |  | |_| |\n"
           HI_BLUE   "\t\t\t\t\t\t\t\t▓|___|_| |_|\\_/ \\___|_| |_|\\__\\___/|_|   \\__, |\n"
           HI_BLUE   "\t\t\t\t\t\t\t\t                                         |___/ \n");
    printf(RESET "\n\t\t\t\t\t\t\t  ═══════════════════════════════════════════════════════════\n");
    printf("\n\n\n\n\n");
    printf(REG_RED"\t\t     [STRIKE] " RESET "Deals 10-20 Damage \t\t\t");
    printf(REG_BLUE "[TECH] " RESET "Has a 20%% chance of \t\t\t     ");
    printf(REG_YELLOW "[SUPPORT] " RESET "Heals 8-15 HP\n");

    printf("\t\t\t   to the opponent \t\t\t\t making the oppnent " REG_PURPLE "FLINCH" RESET "\t\t\t\ton all ally syncs\n\n");
    DisplayAllSyncs(p, &max, true);

    printf(HI_RED "\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t[4] Go back\n\n" RESET);
}

void SampleBattle(Player p) {
    printf("\n");
    PrintBasil();
    //DisplaySyncPairs(p);

    PrintSeparator();

    printf("\n\n");
   // DisplayStrikePair(p);
}


#endif 


