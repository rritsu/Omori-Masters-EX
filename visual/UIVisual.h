#ifndef UI_VISUAL_H 
#define UI_VISUAL_H


#include <stdio.h>
#include <string.h>

#include "colors.h"
#include "enemyVisual.h"
#include "playerVisual.h"

#include "../logic/player.h"
#include "../logic/utility.h"

void PrintSeparator() {
    printf("\n\n");
    printf(RESET"\t\t\t\t ═══════════════════════════════════════════════════════════════════════════════════════════════════════\n");
}

void DisplayMenuOptions() {
    printf(HI_YELLOW"\t\t\t\t\t\t\t\t\t     [1] Play Game\n\n");
    printf(HI_BLUE  "\t\t\t\t\t\t\t\t\t     [2] Inventory\n\n");
    printf(HI_GREEN "\t\t\t\t\t\t\t\t\t     [3] Shop\n\n");
    printf(HI_RED   "\t\t\t\t\t\t\t\t\t     [4] Quit\n\n\n\n\n\n" RESET);
}

void DisplayExitConfirmation() {
    printf(HI_CYAN"\t\t\t\t\t\t\t\t\t     Confirm Exit?\n\n");
    printf(HI_RED "\t\t\t\t\t\t\t\t\t        [1] Yes\n\n");
    printf(HI_BLUE"\t\t\t\t\t\t\t\t\t        [2] No \n" RESET);
}

void DisplayMainMenu(bool showExitPrompt) {
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
                  "\t\t\t\t\t  ▓|  |_|  ||   _   ||  _____||_    _||   ____||    _ |  |  _____|   ▓|   ____||  |_|  |\n"
        HI_PURPLE "\t\t\t\t\t  ▓|       ||  |_|  || |_____   |  |  |  |___  |   |_||_ | |_____    ▓|  |____ |       |\n"
                  "\t\t\t\t\t  ▓|       ||       ||_____  |  |  |  |   ___| |    __  ||_____  |   ▓|   ____| |     | \n"
        HI_BLUE   "\t\t\t\t\t  ▓| ||_|| ||   _   | _____| |  |  |  |  |____ |   |  | | _____| |   ▓|  |____ |   _   |\n"
                  "\t\t\t\t\t  ▓|_|   |_||__| |__||_______|  |__|  |_______||___|  |_||_______|   ▓|_______||__| |__|\n");

    PrintSeparator();
    printf("\n\n\n\n\n\n\n\n");

    if(!showExitPrompt) DisplayMenuOptions();
    else {
        DisplayExitConfirmation();
        printf("\n\n\n\n\n\n\n");
    }

}

void BorderCheck() {
    
    printf("╔════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    int r = 42;
    for(int i = 0; i < r; i++) {
        printf("║                                                                                                                                                                        ║\n");
    }

    printf("║\t\t1. Switch to Fullscreen                                                                                                                                  ║\n"
           "║\t\t2. Adjust Screen by zooming out with Ctrl + Scroll Down                                                                                                  ║\n"
           "║\t\t3. Align the borders to the corner of your screen, scroll up                                                                                             ║\n"
           "║\t\t4. Press any key to continue (* ^ ω ^)                                                                                                                   ║\n"
           "╚════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
}

void InvalidInputPrompt() {
    printf(RESET sys);
    printf("[SYSTEM]: Invalid input :(");
}

void RedirectingBack() {
    printf(RESET sys);
    printf("[SYSTEM]: Redirecting back...");
}

void RedirectingPrompt(char c) {
    printf(RESET sys);
    switch(c) {
        case '1': printf("[SYSTEM]: Redirecting to Black Room..."); break;
        case '2': printf("[SYSTEM]: Redirecting to Inventory..."); break;
        case '3': printf("[SYSTEM]: Redirecting to Shop..."); break;
    }
}

void RedirectingToBattlePrompt() {
    printf(RESET sys);
    printf("[SYSTEM]: Redirecting to Battle...");
}

void ExitPrompt() {
    printf(RESET sys);
    printf("[SYSTEM]: Closing game...\n");
}

void PurchasePrompt(char c, bool success) {
    printf(RESET sys);
    if(success) {
        switch(c) {
            case '1': printf("[SYSTEM]: Successfully purchased a " HI_RED "[STRIKE]" RESET " sync pair!"); break;
            case '2': printf("[SYSTEM]: Successfully purchased a " HI_BLUE "[TECH]" RESET " sync pair!"); break;
            case '3': printf("[SYSTEM]: Successfully purchased a " REG_YELLOW "[SUPPORT]" RESET " sync pair!"); break;
        }
    }
    else {
        printf("[SYSTEM]: You don't have enough gems :(");
    }
}

void SampleBattle(Player p) {
    int max = 0;
    printf("\n");
    PrintBasil();
    //DisplaySyncPairs(p);

    PrintSeparator();

    printf("\n");
    DisplayAllSyncs(p, &max, true);
   // DisplayStrikePair(p);
}

void DisplayInventory(Player p) {
    int max = 0;

    printf("\n\n\n\n");
    printf(HI_PURPLE "\t\t\t\t\t\t\t\t  ___                      _                   \n"
                     "\t\t\t\t\t\t\t\t▓|_ _|_ ____   _____ _ __ | |_ ___  _ __ _   _ \n"
                     "\t\t\t\t\t\t\t\t ▓| || '_ \\ \\ / / _ \\ '_ \\| __/ _ \\| '__| | | |\n"
           HI_BLUE   "\t\t\t\t\t\t\t\t ▓| || | | \\ V /  __/ | | | || (_) | |  | |_| |\n"
                     "\t\t\t\t\t\t\t\t▓|___|_| |_|\\_/ \\___|_| |_|\\__\\___/|_|   \\__, |\n"
                     "\t\t\t\t\t\t\t\t                                         |___/ \n");
    printf(RESET "\n\t\t\t\t\t\t\t  ═══════════════════════════════════════════════════════════\n");
    //SampleBattle(p);
    
    printf("\n\n\n\n\n");
    printf(REG_RED"\t\t     [STRIKE] " RESET "Deals 10-20 damage \t\t\t");
    printf(REG_BLUE "[TECH] " RESET "Has a 20%% chance of \t\t\t     ");
    printf(REG_YELLOW "[SUPPORT] " RESET "Heals 8-15 HP\n");

    printf("\t\t\t   to the opponent \t\t\t\tmaking the opponent " HI_PURPLE "FLINCH" RESET "\t\t\t\ton all ally syncs\n\n");
    DisplayAllSyncs(p, &max, true);

    printf(HI_RED "\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t[4] Go back\n" RESET);
}

void DisplayShop(Player p) {
    printf("\n\n\n\n");
    printf(HI_CYAN "\t\t\t\t\t\t\t\t\t    _____  _                 \n"
                   "\t\t\t\t\t\t\t\t\t  ▓|  ___|| |                \n"
                   "\t\t\t\t\t\t\t\t\t  ▓| |___ | |__   ___  _ __  \n"
           HI_BLUE "\t\t\t\t\t\t\t\t\t  ▓|___  || '_ \\ / _ \\| '_ \\ \n"
                   "\t\t\t\t\t\t\t\t\t    ___| || | | | (_) | |_) |\n"
                   "\t\t\t\t\t\t\t\t\t  ▓|_____||_| |_|\\___/| .__/ \n"
                   "\t\t\t\t\t\t\t\t\t                      |_|    \n");
    printf(RESET "\n\t\t\t\t\t\t\t\t ═══════════════════════════════════════════\n");
    printf("\n\n\n\n\n");
    printf(HI_YELLOW "\t\t\t\t\t  ╔════════════════════════════════════════════════════════════════╦═════════════════════════╗\n"
                     "\t\t\t\t\t  ║                                                                ║                         ║\n"
                     "\t\t\t\t\t  ║       " HI_CYAN " [ SYNC PAIRS ]                                          " HI_YELLOW "║      " HI_CYAN "[ INVENTORY ]      " HI_YELLOW "║\n"
                     "\t\t\t\t\t  ║                                                                ║                         ║\n"
                     "\t\t\t\t\t  ║────────────────────────────────────────────────────────────────╬─────────────────────────║\n"
                     "\t\t\t\t\t  ║                                                                ║                         ║\n"
                     "\t\t\t\t\t  ║                                              " RESET " Cost " HI_YELLOW "            ║    " RESET "Current Gems: " HI_GREEN "%-5d  " HI_YELLOW "║\n", p.gems); 
    printf(          "\t\t\t\t\t  ║                                                                ║                         ║\n"
                     "\t\t\t\t\t  ║       " HI_CYAN " [1] " RESET "Buy " HI_RED "[STRIKE]                     " HI_GREEN "200 Gems           " HI_YELLOW "║     " HI_RED " [STRIKE]  " RESET "%2dx      " HI_YELLOW "║\n", p.strikeSync.quantity);
    printf(          "\t\t\t\t\t  ║                                                                ║                         ║\n"
                     "\t\t\t\t\t  ║       " HI_CYAN " [2] " RESET "Buy " HI_BLUE "[TECH]                       " HI_GREEN "100 Gems           " HI_YELLOW "║     " HI_BLUE " [TECH]    " RESET "%2dx      " HI_YELLOW "║\n", p.techSync.quantity);
    printf(          "\t\t\t\t\t  ║                                                                ║                         ║\n"
                     "\t\t\t\t\t  ║       " HI_CYAN " [3] " RESET "Buy " REG_YELLOW "[SUPPORT]                    " HI_GREEN "100 Gems           " HI_YELLOW "║     " REG_YELLOW " [SUPPORT] " RESET "%2dx      " HI_YELLOW "║\n", p.supportSync.quantity);
    printf(          "\t\t\t\t\t  ║                                                                ║                         ║\n"
                     "\t\t\t\t\t  ║                                                                ║                         ║\n"
                     "\t\t\t\t\t  ╚════════════════════════════════════════════════════════════════╩═════════════════════════╝" RESET "\n");
    
    printf(HI_RED "\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t[4] Go back\n" RESET);

}

void DisplayBlackRoom(Player p) {
    printf("\n\n\n\n");
    printf("\t\t\t\t\t\t\t     ____  _            _      ____                       \n"
           "\t\t\t\t\t\t\t    | __ )| | __ _  ___| | __ |  _ \\ ___   ___  _ __ ___  \n"
           "\t\t\t\t\t\t\t    |  _ \\| |/ _` |/ __| |/ / | |_) / _ \\ / _ \\| '_ ` _ \\ \n"
           "\t\t\t\t\t\t\t    | |_) | | (_| | (__|   <  |  _ < (_) | (_) | | | | | |\n"
           "\t\t\t\t\t\t\t    |____/|_|\\__,_|\\___|_|\\_\\ |_| \\_\\___/ \\___/|_| |_| |_|\n");
    //printf("\n\n\n\t\t\t\t\t\t\t\t");
    printf("\n\n\n");
    DisplayOmori();
    printf(BOLD_WHITE "\n\t\t\t\t\t\t\t\t\t      Current Floor: %d\n" RESET, p.floor);
    printf("\n\t\t\t\t\t\t\t\t\t     Proceed to Battle?\n");
    printf("\n\t\t\t\t\t\t\t\t\t        " HI_BLUE "[1] Yes\n");
    printf("\n\t\t\t\t\t\t\t\t\t        " HI_RED  "[2] Go back" RESET);

}


#endif 


