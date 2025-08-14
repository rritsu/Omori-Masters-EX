#ifndef UI_VISUAL_H 
#define UI_VISUAL_H


#include <stdio.h>
#include <string.h>

#include "colors.h"
#include "enemyVisual.h"
#include "../logic/player.h"

void PrintSeparator() {
    printf("\n\n");
    printf(RESET"\t\t\t\t ════════════════════════════════════════════════════════════════════════════════════════════════════\n");
}

void DisplayMainMenu() {
    printf(HI_YELLOW "\n\n\n\n");
    printf( "\t\t\t\t\t\t\t  _______     __   __     _______     ______       ___    \n"
            "\t\t\t\t\t\t\t▓|       |  ▓|  |_|  |  ▓|       |  ▓|    _ |    ▓|   |   \n"
            "\t\t\t\t\t\t\t▓|   _   |  ▓|       |  ▓|   _   |  ▓|   | ||    ▓|   |   \n"
            "\t\t\t\t\t\t\t▓|  | |  |  ▓|       |  ▓|  | |  |  ▓|   |_||_   ▓|   |   \n"
            "\t\t\t\t\t\t\t▓|  |_|  |  ▓|       |  ▓|  |_|  |  ▓|    __  |  ▓|   |   \n"
            "\t\t\t\t\t\t\t▓|       |  ▓| ||_|| |  ▓|       |  ▓|   |  | |  ▓|   |   \n"
            "\t\t\t\t\t\t\t▓|_______|  ▓|_|   |_|  ▓|_______|  ▓|___|  |_|  ▓|___|   \n"
            "\n\n\n"
        HI_RED    "\t\t\t\t\t  __   __  _______  _______  ______  _______  ______    _______     _______  __   __ \n"
        HI_RED    "\t\t\t\t\t▓|  |_|  ||   _   ||  _____||_    _||   ____||    _ |  |  _____|   ▓|   ____||  |_|  |\n"
        HI_PURPLE "\t\t\t\t\t▓|       ||  |_|  || |_____   |  |  |  |___  |   |_||_ | |_____    ▓|  |____ |       |\n"
        HI_PURPLE "\t\t\t\t\t▓|       ||       ||_____  |  |  |  |   ___| |    __  ||_____  |   ▓|   ____| |     | \n"
        HI_BLUE   "\t\t\t\t\t▓| ||_|| ||   _   | _____| |  |  |  |  |____ |   |  | | _____| |   ▓|  |____ |   _   |\n"
        HI_BLUE   "\t\t\t\t\t▓|_|   |_||__| |__||_______|  |__|  |_______||___|  |_||_______|   ▓|_______||__| |__|\n");

    PrintSeparator();
    printf("\n\n\n\n\n\n");
    printf(HI_YELLOW"\t\t\t\t\t\t\t\t\t[1] Play Game\n\n");
    printf(HI_GREEN"\t\t\t\t\t\t\t\t\t[2] Inventory\n\n");
    printf(HI_BLUE"\t\t\t\t\t\t\t\t\t[3] Shop\n\n");
    printf(HI_RED"\t\t\t\t\t\t\t\t\t[4] Quit\n\n");
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
    printf(RESET"\n\n\n\t\t\t\t\t\t\t   ");
    printf("[SYSTEM]: Invalid input :(\n");
}

void RedirectingBack() {
    printf(RESET"\n\n\t\t\t\t\t\t\t   ");
    printf("[SYSTEM]: Redirecting back...\n");
}

void RedirectingPrompt(char c) {
    printf(RESET"\n\n\n\t\t\t\t\t\t\t   ");
    switch(c) {
        case '1': printf("[SYSTEM]: Redirecting to Battle...\n"); break;
        case '2': printf("[SYSTEM]: Redirecting to Inventory...\n"); break;
        case '3': printf("[SYSTEM]: Redirecting to Shop...\n"); break;
    }
}


void DisplayStrikePairRe(Player p) {
    printf(HI_BLACK);
    char strike[20][100];
    char r0[100] =  "╔═════───────  1  ───────═════╗\n";
    char r1[100] =  "║                             ║\n";
    char r2[100] =  "║      ▒▒░                    ║\n";
    char r3[100] =  "│      ░░▒▒░                  │\n";
    char r4[100] =  "│      ░▓▒▒▒░                 │\n";
    char r5[100] =  "│       ░░▒▒░▒░               │\n";
    char r6[100] =  "│        ░▒▒▒░░░              │\n";
    char r7[100] =  "│         ▒░░▒░░░░            │\n";
    char r8[100] =  "│          ░░▒▒░░░▒░          │\n";
    char r9[100] =  "│          ░▒▒░▒░░▓█▓░        │\n";
    char r10[100] = "│            ░▓░▒▒  ▓▒▒       │\n";
    char r11[100] = "│             ░░     ░▓█▒     │\n";
    char r12[100] = "║                      ░░     ║\n";
    char r13[100] = "║                             ║\n";
    char r14[200] = "╚═════───────────────────═════╝\n";

    strcpy(strike[0], r0);
    strcpy(strike[1], r1);
    strcpy(strike[2], r2);
    strcpy(strike[3], r3);
    strcpy(strike[4], r4);
    strcpy(strike[5], r5);
    strcpy(strike[6], r6);
    strcpy(strike[7], r7);
    strcpy(strike[8], r8);
    strcpy(strike[9], r9);
    strcpy(strike[10], r10);
    strcpy(strike[11], r11);
    strcpy(strike[12], r12);
    strcpy(strike[13], r13);
    strcpy(strike[14], r14);
    // strcpy(strike[15], r15);
    // strcpy(strike[16], r16);
    // strcpy(strike[17], r17);

    for (int i = 0; i < 15; i++) {
        printf("%s", strike[i]); 
    }

    printf("\n");
    printf("Q: 1 | HP: ██████████████████");
} 


void DisplaySyncPairs(Player p) {
//    printf("\n\n\n\n\n\n\n\n\n\n\n\n");
        //test with basil
        //printf("\n\n");
        PrintSeparator();

    printf("\n\n");
    DisplayStrikePairRe(p);
}


void DisplayInventory(Player p) {
    // printf("\n\n\n\n");
    // printf(HI_PURPLE "\t\t\t\t\t\t\t  ___                      _                   \n"
    //        HI_PURPLE "\t\t\t\t\t\t\t▓|_ _|_ ____   _____ _ __ | |_ ___  _ __ _   _ \n"
    //        HI_PURPLE "\t\t\t\t\t\t\t ▓| || '_ \\ \\ / / _ \\ '_ \\| __/ _ \\| '__| | | |\n"
    //        HI_BLUE   "\t\t\t\t\t\t\t ▓| || | | \\ V /  __/ | | | || (_) | |  | |_| |\n"
    //        HI_BLUE   "\t\t\t\t\t\t\t▓|___|_| |_|\\_/ \\___|_| |_|\\__\\___/|_|   \\__, |\n"
    //        HI_BLUE   "\t\t\t\t\t\t\t                                         |___/ \n");
    // printf(RESET "\n\t\t\t\t\t\t  ═══════════════════════════════════════════════════════════\n");

    printf("\n");
    PrintBasil();
    DisplaySyncPairs(p);
}


#endif 


