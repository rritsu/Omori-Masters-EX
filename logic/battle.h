#ifndef BATTLE_H
#define BATTLE_H

#include <stdio.h>
#include <conio.h>
#include "utility.h"
//#include "values.h"
#include "struct.h"
//#include "../visual/UIVisual.h"


void InitializeEnemy(Enemy* e, char type);
char PrepareEnemyType(int floor);

bool IsBattleOver(const Player* p, const Enemy* e);

void UpdateScreenWithLog(const Player* p, const Enemy* e, char log[LOG_LENGTH], bool isPlayerTurn);
void UpdateScreen(const Player* p, const Enemy* e, bool isPlayerTurn);

void HandleSyncQuantity(Sync* sync, const Player* p, const Enemy* e, int syncNum, char log[LOG_LENGTH]);
void CheckPlayerSyncQuantity(Player* p, const Enemy* e, int syncNum, char log[LOG_LENGTH]);

void PlayerStrikeMove(const Player* p, Enemy* e, char log[LOG_LENGTH], int* lastSync);
void PlayerTechMove(const Player* p, Enemy* e, char log[LOG_LENGTH], int* lastSync);
void SyncHeal(Sync* sync, int heal);
void PlayerSupportMove(Player* p, Enemy* e, char log[LOG_LENGTH], int* lastSync);
void PlayerEndTurn(Player* p, Enemy* e,char log[LOG_LENGTH]);

void EnemyStrikeMove(const Enemy* e, Player* p, int lastSync, char log[LOG_LENGTH]);
void EnemyTechMove(const Enemy* e, Player* p, int lastSync, char log[LOG_LENGTH]);
void EnemySupportMove(Enemy* e,const Player* p, char log[LOG_LENGTH]);
int EnemyMoveDecision(const Player* p, const Enemy* e, int lastSync);
void EnemyMove(Enemy* e, Player* p, char log[LOG_LENGTH], int lastSync);

bool CheckPlayerMove(const Player* p, int lastSync);
void UpdatePlayerFlinchCounters(Player* p, const Enemy* e, char log[LOG_LENGTH]);
void UpdateEnemyFlinchCounter(const Player* p, Enemy* e, char log[LOG_LENGTH]);


void CheckPlayerStatus(Player* p);

void BattleLoop(Player* player, bool* playerWin);

#endif