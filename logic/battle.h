#ifndef BATTLE_H
#define BATTLE_H

#include <stdio.h>
#include <conio.h>
#include "utility.h"
//#include "values.h"
#include "struct.h"
//#include "../visual/UIVisual.h"

void InitializePlayer(Player* player);
void ResetPlayerStats(Player* player);
void InitializeEnemy(Enemy* e, char type);
char PrepareEnemyType(int floor);

void UpdateScreenWithLog(Player p, Enemy e, char log[LOG_LENGTH], bool isPlayerTurn);
void UpdateScreen(Player p, Enemy e, bool isPlayerTurn);

void HandleSyncQuantity(Sync* sync, Player* p, Enemy e, int syncNum, char log[LOG_LENGTH]);
void CheckPlayerSyncQuantity(Player* p, Enemy e, int syncNum, char log[LOG_LENGTH]);

void PlayerStrikeMove(Player p, Enemy* e, char log[LOG_LENGTH], int* lastSync);
void PlayerTechMove(Player p, Enemy* e, char log[LOG_LENGTH], int* lastSync);
void EnemyStrikeMove(Enemy* e, Player* p, int lastSync, char log[LOG_LENGTH]);
void EnemyTechMove(Enemy* e, Player* p, int lastSync, char log[LOG_LENGTH]);
int EnemyMoveDecision(Player* p, Enemy* e, int lastSync);
void EnemyMove(Enemy* e, Player* p, char log[LOG_LENGTH], int lastSync);
bool CheckPlayerMove(Player p, int lastSync);
void UpdatePlayerFlinchCounters(Player* p, Enemy* e, char log[LOG_LENGTH]);
void UpdateEnemyFlinchCounter(Player* p, Enemy* e, char log[LOG_LENGTH]);
//void UpdateFlinchCounters(Player* p, Enemy* e, char log[LOG_LENGTH]);
bool IsBattleOver(Player p, Enemy e);
void CheckPlayerStatus(Player* p);

void BattleLoop(Player* player);

#endif