#ifndef PLAYER_VISUAL_H
#define PLAYER_VISUAL_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "../logic/struct.h"

void DisplayHP(int quantity, int HP, char syncHP[]);
void DisplayStrikeSyncGray(Sync sync, char strike[20][150], bool displayInfo, int* max);
void DisplayStrikeSync(Sync sync, char strike[20][150], bool displayInfo, int* max);
void DisplayTechSync(Sync sync, char tech[20][150], bool displayInfo);
void DisplayTechSyncGray(Sync sync, char tech[20][150], bool displayInfo);
void DisplaySupportSync(Sync sync, char support[20][150], bool displayInfo);
void DisplaySupportSyncGray(Sync sync, char support[20][150], bool displayInfo);
void DisplayAllSyncs(const Player* p, int* max, bool displayInfo, bool isPlayerTurn);
void DisplayOmori_();
void DisplayOmori();

#endif