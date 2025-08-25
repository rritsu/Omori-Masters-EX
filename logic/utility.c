
#include "utility.h"
#include "../visual/UIVisual.h"
#include "values.h"

void HideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = FALSE;  
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void InitializeRNG() {
    srand(time(NULL));
}

int GenerateRandomNum(int min, int max) {
    int rng = (rand() % (max- min + 1) + min);
    return rng;
}


char GetInput(int numInputs) {
    char c = '0';
    bool validInput = false;

    do {
        c = _getch();
        switch(numInputs) {
            case 1: 
                if(c == '4') validInput = true;
                else InvalidInputNotice();
                break;
            case 2: 
                if(c == '1' || c == '2') validInput = true;
                else InvalidInputNotice();
                break;
            case 3: 
                if(c == '1' || c == '2' || c == '3') validInput = true;
                else InvalidInputNotice();
                break;
            case 4: 
                if(c == '1' || c == '2' || c == '3' || c == '4') validInput = true;
                else InvalidInputNotice();
                break;
            
        }

    } while(!validInput);   
    return c;
}

void SetBufferLog(char log[LOG_LENGTH], const char* msg) {
    strncpy(log, msg, LOG_LENGTH - 1);
    log[LOG_LENGTH - 1] = '\0';
}

int GetEnemyMaxHP(char type) {
	switch(type) {
		case 'N': return 100; break;
		case '1': return 100; break;
		case '2': return 150; break;
		case '3': return 200; break;
	}
	return 0;
}

void ResetPlayerHP(Player* p) {
    p->strikeSync.HP = 100;
    p->techSync.HP = 100;
    p->supportSync.HP = 100;
}

void ResetFlinchCounter(Player* p) {
    p->strikeSync.isFlinched = false;
    p->strikeSync.flinchCounter = 0;

    p->techSync.isFlinched = false;
    p->techSync.flinchCounter = 0;

    p->supportSync.isFlinched = false;
    p->supportSync.flinchCounter = 0;
}

void InitializePlayer(Player* player) {
    ResetPlayerHP(player);
    ResetFlinchCounter(player);
    player->strikeSync.quantity = 1;
    player->techSync.quantity = 1;
    player->supportSync.quantity = 1;
    player->gems = 0;
    player->floor = 20;
}


void ResetPlayerStats(Player* player) {
    ResetPlayerHP(player);
    ResetFlinchCounter(player);

    if(player->strikeSync.quantity <= 0) {
        player->strikeSync.quantity = 1;
    }
    if(player->techSync.quantity <= 0) {
        player->techSync.quantity = 1;
    }
    if(player->supportSync.quantity <= 0) {
        player->supportSync.quantity = 1;
    }
    player->floor = 1;
}

bool IsEliteFloor(int floor) {
    if(floor % 5 == 0)
        return true;
    else 
        return false;
}

int GetGemsReward(int floor) {
    int gems;
    if(floor >= 1 && floor <= 10) gems = 50;
    else if(floor >= 11 && floor <= 15) gems = 80;
    else if(floor >= 16 && floor <= 19) gems = 100;
    else gems = 500;

    return gems;
}




// void StrikeMovePrompt(bool isPlayerMove, int damage) {
//     printf(RESET sys);
//     if(isPlayerMove) printf("[SYSTEM]: Player dealt %d damage to the opponent!", damage);
//     else printf("[SYSTEM]: Enemy dealth %d damage to the player!", damage);
//     Sleep(DELAY);
// }
