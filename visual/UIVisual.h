#ifndef UI_VISUAL_H 
#define UI_VISUAL_H

#include <stdio.h>
#include <string.h>
#include "../logic/struct.h"
#include "../logic/utility.h"

void PrintSeparator();
void DisplayMenuOptions();
void DisplayBlackRoomOptions();
void DisplayExitConfirmation();
void DisplayResetConfirmation();
void DisplayMainMenu(bool showExitPrompt);
void BorderCheck();

void InvalidInputNotice();
void RedirectingBackNotice();
void RedirectingNotice(char c);
void RedirectingToBattleNotice();
void ExitGameNotice();
void ResetProgressNotice();
void PurchaseNotice(char c, bool success);
void ReturnToRoomNotice();
void ReturnToMenuNotice();
void SpecialRewardNotice(char c, int gems);
void GoodluckNotice();
void PressAnyKeyNotice();

void DisplayBattleLog(char log[LOG_LENGTH]);
void FlinchedSyncLog(char log[LOG_LENGTH], int syncNum);
void SyncIsDownLog(char log[LOG_LENGTH], int syncNum);
void FlinchedEnemyLog(char log[LOG_LENGTH]);
void EnemyAlreadyFlinchedLog(char log[LOG_LENGTH]);
void ResetFlinchCounterLog(char log[LOG_LENGTH], int syncNum);

void PlayerStrikeMoveLog(char log[LOG_LENGTH], int damage);
void PlayerTechAttemptLog(char log[LOG_LENGTH]);
void PlayerTechMoveLog(char log[LOG_LENGTH], bool success);
void PlayerSupportMoveLog(char log[LOG_LENGTH], int heal, bool success);
void PlayerEndTurnLog(char log[LOG_LENGTH]);

void EnemyStrikeMoveLog(char log[LOG_LENGTH], int damage, int syncNum);
void EnemyTechAttemptLog(char log[LOG_LENGTH], int syncNum);
void EnemyTechMoveLog(char log[LOG_LENGTH], int syncNum, bool success);
void EnemySupportMoveLog(char log[LOG_LENGTH], int heal);

void DefeatedEnemyLog(char log[LOG_LENGTH]);
void PlayerWinsLog(char log[LOG_LENGTH], int gems);
void NextFloorLog(char log[LOG_LENGTH]);
void PlayerLossesLog(char log[LOG_LENGTH]);
void DefeatedSyncLog(char log[LOG_LENGTH], int syncNum);
void RevivedSyncLog(char log[LOG_LENGTH], int syncNum);
void NoSyncsLog(char log[LOG_LENGTH], int syncNum);

void DisplayInventory(const Player* p);
void DisplayShop(const Player* p);
void DisplayBlackRoom(const Player* p, bool showResetPrompt);
void DisplayEliteOptions(int floor, char first[], char second[], char third[]);
void DisplayBattleUI(const Player* p, const Enemy* e, bool isPlayerTurn);
void DisplaySpecialRewardOption();
void DisplayCongratsScreen();
void GalingTangina();
//void PressAnyKeyNotice();

#endif 


