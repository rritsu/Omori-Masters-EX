#ifndef PLAYER_VISUAL_H
#define PLAYER_VISUAL_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "colors.h"
#include "UIVisual.h"

#include "../logic/player.h"


void DisplayHP(int quantity, int HP, char syncHP[]) {
    int h = HP / 5;
    int e = 20 - h;

    char temp[30];
    sprintf(temp, HI_CYAN "%2d" RESET " | DU: ",  quantity);
    strcpy(syncHP, temp);
   // strcpy(syncHP, "   DU: ");

    for(int i = 0; i < h; i++) {
        if(HP > 65) {
            strcat(syncHP, HI_GREEN "█" RESET);
        }
        else if (HP > 30) {
            strcat(syncHP, REG_YELLOW "█" RESET);
        }
        else {
            strcat(syncHP, REG_RED "█" RESET);
        }
    }

    for(int i = 0; i < e; i++) {
        strcat(syncHP, HI_BLACK "▒" RESET);
    }

    strcat(syncHP, "  ");
}

void DisplayStrikePair(Player p, char strike[20][150], bool displayInfo, int* max) {
    char r0[100] =  HI_RED "╔═════───────  1  ───────═════╗" RESET;
    char r1[100] =  HI_RED "║                             " REG_PURPLE "║" RESET;
    char r2[100] =  HI_RED "║" HI_BLACK "     ▒▒░                     " REG_PURPLE "║" RESET;
    char r3[100] =  HI_RED "│" HI_BLACK "      ░░▒▒░                  " REG_PURPLE "│" RESET;
    char r4[100] =  HI_RED "│" HI_BLACK "      ░▓▒▒▒░                 " REG_PURPLE "│" RESET;
    char r5[100] =  HI_RED "│" HI_BLACK "       ░░▒▒░▒░               " REG_PURPLE "│" RESET;
    char r6[100] =  HI_RED "│" HI_BLACK "        ░▒▒▒░░░              " REG_PURPLE "│" RESET;
    char r7[100] =  HI_RED "│" HI_BLACK "         ▒░░▒░░░░            " REG_PURPLE "│" RESET;
    char r8[100] =  HI_RED "│" HI_BLACK "          ░░▒▒░░░▒░          " REG_PURPLE "│" RESET;
    char r9[100] =  HI_RED "│" HI_BLACK "          ░▒▒░▒░░▓█▓░        " REG_PURPLE "│" RESET;
    char r10[100] = HI_RED "│" HI_BLACK "            ░▓░▒▒  ▓▒▒       " REG_PURPLE "│" RESET;
    char r11[100] = HI_RED "│" HI_BLACK "             ░░     ░▓█▒     " REG_PURPLE "│" RESET;
    char r12[100] = HI_RED "║" HI_BLACK "                      ░░     " REG_PURPLE "║" RESET;
    char r13[100] = HI_RED "║" HI_BLACK "                             " REG_PURPLE "║" RESET;
    char r14[150] = REG_PURPLE "╚═════────── " HI_RED "STRIKE" REG_PURPLE " ─────═════╝" RESET;

    strcpy(strike[0], r0);   strcpy(strike[1], r1);
    strcpy(strike[2], r2);   strcpy(strike[3], r3);
    strcpy(strike[4], r4);   strcpy(strike[5], r5);
    strcpy(strike[6], r6);   strcpy(strike[7], r7);
    strcpy(strike[8], r8);   strcpy(strike[9], r9);
    strcpy(strike[10], r10); strcpy(strike[11], r11);
    strcpy(strike[12], r12); strcpy(strike[13], r13);
    strcpy(strike[14], r14);
    *max = 14 + 1;
    
    if(displayInfo) {
        char r15[40]  =      "                               ";
        char r16[300];
        DisplayHP(p.strikeSync.quantity, p.strikeSync.HP, r16);
        strcpy(strike[15], r15);
        strcpy(strike[16], r16);
        *max = 16 + 1;
    }
}

void DisplayTechPair(Player p, char tech[20][150], bool displayInfo) {
    char r0[100] =  HI_BLUE "╔═════───────  2  ───────═════╗" RESET;
    char r1[100] =  HI_BLUE "║                             " REG_PURPLE "║" RESET;
    char r2[100] =  HI_BLUE "║" HI_BLACK "         ▒▓██▓▓▓▓░           " REG_PURPLE "║" RESET;
    char r3[100] =  HI_BLUE "│" HI_BLACK "       ░▓▒▓▓▓▒▒█▒▒▒          " REG_PURPLE "│" RESET;
    char r4[100] =  HI_BLUE "│" HI_BLACK "       ░█▒░▓░█▓▒▓▒▓▓         " REG_PURPLE "│" RESET;
    char r5[100] =  HI_BLUE "│" HI_BLACK "       ░█░░░▓▒▓▓█▓▒▒▓░       " REG_PURPLE "│" RESET;
    char r6[100] =  HI_BLUE "│" HI_BLACK "        ▓▒░░▓▒░█▓▒░▒▒        " REG_PURPLE "│" RESET;
    char r7[100] =  HI_BLUE "│" HI_BLACK "         ▒▓▓▒░▒▓░▒▓▒░        " REG_PURPLE "│" RESET;
    char r8[100] =  HI_BLUE "│" HI_BLACK "            ▒▓░░▓░▒▒         " REG_PURPLE "│" RESET;
    char r9[100] =  HI_BLUE "│" HI_BLACK "                ░█░▒▓░       " REG_PURPLE "│" RESET;
    char r10[100] = HI_BLUE "│" HI_BLACK "                 ░▓░░▒       " REG_PURPLE "│" RESET;
    char r11[100] = HI_BLUE "│" HI_BLACK "                  ▒▒░▒▓      " REG_PURPLE "│" RESET;
    char r12[100] = HI_BLUE "║" HI_BLACK "                   ▓▓▒       " REG_PURPLE "║" RESET;
    char r13[100] = HI_BLUE "║" HI_BLACK "                             " REG_PURPLE "║" RESET;
    char r14[150] = REG_PURPLE "╚═════─────── " HI_BLUE "TECH" REG_PURPLE " ──────═════╝" RESET;

    strcpy(tech[0], r0);   strcpy(tech[1], r1);
    strcpy(tech[2], r2);   strcpy(tech[3], r3);
    strcpy(tech[4], r4);   strcpy(tech[5], r5);
    strcpy(tech[6], r6);   strcpy(tech[7], r7);
    strcpy(tech[8], r8);   strcpy(tech[9], r9);
    strcpy(tech[10], r10); strcpy(tech[11], r11);
    strcpy(tech[12], r12); strcpy(tech[13], r13);
    strcpy(tech[14], r14); 

    if(displayInfo) {
        char r15[40]  =      "                               ";
        char r16[300];
        DisplayHP(p.techSync.quantity, p.techSync.HP, r16);
        strcpy(tech[15], r15);
        strcpy(tech[16], r16);
    }
}

void DisplaySupportPair(Player p, char support[20][150], bool displayInfo) {
    char r0[100] =  REG_YELLOW "╔═════───────  3  ───────═════╗" RESET;
    char r1[100] =  REG_YELLOW "║                             " REG_PURPLE "║" RESET ;
    char r2[100] =  REG_YELLOW "║" HI_BLACK "               ░▓▒           " REG_PURPLE "║" RESET;
    char r3[100] =  REG_YELLOW "│" HI_BLACK "       ░▒▒░░▓▒░░▓▒           " REG_PURPLE "│" RESET;
    char r4[100] =  REG_YELLOW "│" HI_BLACK "      █░░▒▒░▒▓▓██▒           " REG_PURPLE "│" RESET;
    char r5[100] =  REG_YELLOW "│" HI_BLACK "    ░▒▓░▓▓▒▓▓▓▒▒▓▓░▒▒░       " REG_PURPLE "│" RESET;
    char r6[100] =  REG_YELLOW "│" HI_BLACK "         ░▒▓▒▒░▓▒▓▒░░░▓▒     " REG_PURPLE "│" RESET;
    char r7[100] =  REG_YELLOW "│" HI_BLACK "        ░▓▒▒▒░░░░░░░░░░▒▒    " REG_PURPLE "│" RESET;
    char r8[100] =  REG_YELLOW "│" HI_BLACK "        ▒▓▒▒▒░░░░░░░░░░░▓    " REG_PURPLE "│" RESET;
    char r9[100] =  REG_YELLOW "│" HI_BLACK "       ░▓▒▒░░░░░░░░░░░░░▒    " REG_PURPLE "│" RESET;
    char r10[100] = REG_YELLOW "│" HI_BLACK "       ░▓▒▒░░░░░░░░░░░░▓░    " REG_PURPLE "│" RESET;
    char r11[100] = REG_YELLOW "│" HI_BLACK "          ░▒▒▒░░░░░░░░░▓░    " REG_PURPLE "│" RESET;
    char r12[100] = REG_YELLOW "║" HI_BLACK "          ░▒▓▓▒▒▒▓▓▓▒░       " REG_PURPLE "║" RESET;
    char r13[100] = REG_YELLOW "║" HI_BLACK "                             " REG_PURPLE "║" RESET;
    char r14[150] = REG_PURPLE "╚═════───── " REG_YELLOW "SUPPORT" REG_PURPLE " ─────═════╝" RESET;

    strcpy(support[0], r0);   strcpy(support[1], r1);
    strcpy(support[2], r2);   strcpy(support[3], r3);
    strcpy(support[4], r4);   strcpy(support[5], r5);
    strcpy(support[6], r6);   strcpy(support[7], r7);
    strcpy(support[8], r8);   strcpy(support[9], r9);
    strcpy(support[10], r10); strcpy(support[11], r11);
    strcpy(support[12], r12); strcpy(support[13], r13);
    strcpy(support[14], r14);

    if(displayInfo) {
        char r15[40]  =      "                               ";
        char r16[300];
        DisplayHP(p.supportSync.quantity, p.supportSync.HP, r16);
        strcpy(support[15], r15);
        strcpy(support[16], r16);
    }
}


void DisplayAllSyncs(Player p, int* max, bool displayInfo) {
   // char syncPairs[20][1000];
    char strike[20][150];
    char tech[20][150];
    char support[20][150];
    char padding[21] = "                    ";

    DisplayStrikePair(p, strike, displayInfo, max);
    DisplayTechPair(p, tech, displayInfo);
    DisplaySupportPair(p, support, displayInfo);

    // for(int i = 0; i < *max; i++) {
    //     char temp[700];
    //     strcpy(temp, strike[i]);
    //     strcat(temp, padding);
    //     strcat(temp, tech[i]);
    //     strcat(temp, padding);
    //     strcat(temp, support[i]);

    //     strcpy(syncPairs[i], temp);
    //     printf(syncPairs[i]);
    // }

    for(int i = 0; i < *max; i++) {
        printf("\t\t   ");
        printf(strike[i]);
        printf(padding);
        printf(tech[i]);
        printf(padding);
        printf(support[i]);
        printf("\n");
    }
}

void DisplayOmori() {
    printf(HI_BLACK);
    printf("\t\t\t\t\t\t\t\t                █████████████  ███             \n"
           "\t\t\t\t\t\t\t\t             ████████████████████████          \n"
           "\t\t\t\t\t\t\t\t           ███████████████████████             \n"
           "\t\t\t\t\t\t\t\t          █████████████████████████            \n"
           "\t\t\t\t\t\t\t\t          █████████████████████████            \n"
           "\t\t\t\t\t\t\t\t        █████████████████████████████          \n"
           "\t\t\t\t\t\t\t\t        █████████████████████████████          \n"
           "\t\t\t\t\t\t\t\t        █████████████████████████████          \n"
           "\t\t\t\t\t\t\t\t       ██ ██████████████   ████████ ██         \n"
           "\t\t\t\t\t\t\t\t       ██ ▓▓██████▓▓▓      ▒▒▓███▓▓ ██         \n"
           "\t\t\t\t\t\t\t\t       ███░░█▒▒▒▓█         █▓ ░▒█░░███         \n"
           "\t\t\t\t\t\t\t\t          ███▒  ▓█         █▓  ▒███            \n"
           "\t\t\t\t\t\t\t\t             ██               ██               \n"
           "\t\t\t\t\t\t\t\t               ███░░░░░░░░░███                 \n"
           "\t\t\t\t\t\t\t\t               █▓▒███▒▒▒███▒▓█                 \n"
           "\t\t\t\t\t\t\t\t             ██   █████████   ██               \n"
           "\t\t\t\t\t\t\t\t           ██▒  ▓███████████▓  ▒██             \n"
           "\t\t\t\t\t\t\t\t          ██   ███████████████░  ██            \n"
           "\t\t\t\t\t\t\t\t          ██▓▓▓█▓▓█████████▓▓█▓▓▓██            \n"
           "\t\t\t\t\t\t\t\t               █▒ █▒░███░▒█ ▒██                \n"
           "\t\t\t\t\t\t\t\t               ███████████████                 \n"
           "\t\t\t\t\t\t\t\t               █▒  ▓█   █▓  ▒█                 \n"
           "\t\t\t\t\t\t\t\t               ██████   ██████                 \n"
           "\t\t\t\t\t\t\t\t               ██████   ██████                 \n");
    printf(RESET);
           
}


#endif