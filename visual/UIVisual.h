#ifndef UI_VISUAL_H 
#define UI_VISUAL_H

#include <stdio.h>
#include <string.h>
#include "../logic/struct.h"
#include "../logic/utility.h"

void PrintSeparator();
void DisplayMenuOptions();
void DisplayExitConfirmation();
void DisplayMainMenu(bool showExitPrompt);
void BorderCheck();

void InvalidInputNotice();
void RedirectingBackNotice();
void RedirectingNotice(char c);
void RedirectingToBattleNotice();
void ExitGameNotice();
void PurchaseNotice(char c, bool success);
void ReturnToRoomNotice();
void ReturnToMenuNotice();

void DisplayBattleLog(char log[LOG_LENGTH]);
void FlinchedSyncLog(char log[LOG_LENGTH], int syncNum);
void SyncIsDownLog(char log[LOG_LENGTH], int syncNum);
void FlinchedEnemyLog(char log[LOG_LENGTH]);
void EnemyAlreadyFlinchedLog(char log[LOG_LENGTH]);
void ResetFlinchCounterLog(char log[LOG_LENGTH], int syncNum);
void PlayerStrikeMoveLog(char log[LOG_LENGTH], int damage);
void PlayerTechAttemptLog(char log[LOG_LENGTH]);
void PlayerTechMoveLog(char log[LOG_LENGTH], bool success);
void EnemyStrikeMoveLog(char log[LOG_LENGTH], int damage, int syncNum);
void EnemyTechAttemptLog(char log[LOG_LENGTH], int syncNum);
void EnemyTechMoveLog(char log[LOG_LENGTH], int syncNum, bool success);
void DefeatedEnemyLog(char log[LOG_LENGTH]);
void PlayerWinsLog(char log[LOG_LENGTH]);
void PlayerLossesLog(char log[LOG_LENGTH]);
void DefeatedSyncLog(char log[LOG_LENGTH], int syncNum);
void RevivedSyncLog(char log[LOG_LENGTH], int syncNum);
void NoSyncsLog(char log[LOG_LENGTH], int syncNum);

void DisplayInventory(Player p);
void DisplayShop(Player p);
void DisplayBlackRoom(Player p);
void DisplayBattleUI(Player p, Enemy e, bool isPlayerTurn);

#endif 


