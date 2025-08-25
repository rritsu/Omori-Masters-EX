#include "battle.h"
//#include "utility.h"
#include "values.h"
//#include "struct.h"
#include "../visual/UIVisual.h"

void UpdateScreenWithLog(const Player* p, const Enemy* e, char log[LOG_LENGTH], bool isPlayerTurn) {
    system("cls");
    DisplayBattleUI(p, e, isPlayerTurn);
    DisplayBattleLog(log);
}

void UpdateScreen(const Player* p, const Enemy* e, bool isPlayerTurn) {
    system("cls");
    DisplayBattleUI(p, e, isPlayerTurn);
}

void SetChoices(int floor, char first[], char second[], char third[]) {
    switch(floor) {
        case 5:
            strcpy(first, "Kanade");
            strcpy(second, "Aubrey"); 
            strcpy(third, "Turbo Granny"); 
            break;
        case 10:
            strcpy(first, "Mizuki");
            strcpy(second, "Usagi"); 
            strcpy(third, "Kel"); 
            break;
        case 15:
            strcpy(first, "Hero");
            strcpy(second, "Ena"); 
            strcpy(third, "Hachiware"); 
            break;
        case 20: 
            strcpy(first, "Chiikawa");
            strcpy(second, "Basil"); 
            strcpy(third, "Mafuyu"); 
            break;
    }
}

char GetEliteType(int floor) {
    char type;
    char c = GetInput(3);
    switch(floor) {
        case 5:
            if(c == '1') type = '2';
            else if(c == '2') type = '1';
            else if(c == '3') type = '3';
            break;
        case 10:
            if(c == '1') type = '1';
            else if(c == '2') type = '3';
            else if(c == '3') type = '2';
            break;
        case 15:
            if(c == '1') type = '3';
            else if(c == '2') type = '2';
            else if(c == '3') type = '1';
            break;
        case 20:
            if(c == '1') type = '2';
            else if(c == '2') type = '3';
            else if(c == '3') type = '1';
            break;
    }
    return type;
}


int GetEliteSprite(int floor, char type) {
    int id = 0;
    switch(floor) {
        case 5:
            if(type == '2') id = 21;
            else if(type == '1') id = 22;
            else if(type == '3') id = 23;   
            break;
        case 10:
            if(type == '1') id = 24;
            else if(type == '3') id = 25;
            else if(type == '2') id = 26; 
            break;
        case 15:
            if(type == '3') id = 27;
            else if(type == '2') id = 28;
            else if(type == '1') id = 29; 
            break;
        case 20:
            if(type == '2') id = 30;
            else if(type == '3') id = 31;
            else if(type == '1') id = 32; 
            break;

    }
    return id;
}


void InitializeEnemy(Enemy* e, char type, int floor) {
    switch(type) {
        case 'N':
            e->dmgRange[0] = 10; e->dmgRange[1] = 20;
            e->flinchRate = 20;
            e->healRange[0] = 8; e->healRange[1] = 15;
            e->sync.HP = 100;
            e->spriteID = GenerateRandomNum(1, 20);
            break;
        case '1': 
            e->dmgRange[0] = 20; e->dmgRange[1] = 40;
            e->flinchRate = 15;
            e->healRange[0] = 8; e->healRange[1] = 15;
            e->sync.HP = 100;
            e->spriteID = GetEliteSprite(floor, type);
            break;
        case '2':
            e->dmgRange[0] = 15; e->dmgRange[1] = 25;
            e->flinchRate = 40;
            e->healRange[0] = 8; e->healRange[1] = 15;
            e->sync.HP = 150;
            e->spriteID = GetEliteSprite(floor, type);
            break;
        case '3':
            e->dmgRange[0] = 10; e->dmgRange[1] = 20;
            e->flinchRate = 25;
            e->healRange[0] = 8; e->healRange[1] = 15;
            e->sync.HP = 200;
            e->spriteID = GetEliteSprite(floor, type);
            break;
    }
    e->type = type;
    e->sync.isFlinched = false;
    e->sync.flinchCounter = 0;
}


char PrepareEnemyType(int floor) {
    char type;
    if(IsEliteFloor(floor)) {
        char first[15], second[15], third[15];
        SetChoices(floor, first, second, third);
        DisplayEliteOptions(floor, first, second, third);
        type = GetEliteType(floor);
        GoodluckNotice();
        //Sleep(DELAY);
    }
    else {
        type = 'N';
    }

    return type;
}

bool IsBattleOver(const Player* p, const Enemy* e) {
    bool isOver = false;
    if(p->strikeSync.quantity <= 0 || e->sync.HP <= 0) {
        isOver = true;
    }
    return isOver;
}


void HandleSyncQuantity(Sync* sync, const Player* p, const Enemy* e, int syncNum, char log[LOG_LENGTH]) {
    int leftover = sync->quantity -= 1;
    DefeatedSyncLog(log, syncNum);
    UpdateScreenWithLog(p, e, log, false);
    Sleep(LONG_DELAY);

    if(leftover <= 0) {
        NoSyncsLog(log, syncNum);
    }
    else {
        sync->HP = 100; //revive and make HP full
        RevivedSyncLog(log, syncNum);
    }
    UpdateScreenWithLog(p, e, log, false);
    Sleep(LONG_DELAY);
    
}

void CheckPlayerSyncQuantity(Player* p, const Enemy* e, int syncNum, char log[LOG_LENGTH]) {
    Sync* sync = NULL;
    switch(syncNum) {
        case 1: sync = &p->strikeSync; break;
        case 2: sync = &p->techSync; break;
        case 3: sync = &p->supportSync; break;
    }
    if(sync && sync->HP <= 0) {
        HandleSyncQuantity(sync, p, e, syncNum, log);
    }
}

void PlayerStrikeMove(const Player* p, Enemy* e, char log[LOG_LENGTH], int* lastSync) {
    *lastSync = 1;
    if(p->strikeSync.HP > 0) {
        if(!p->strikeSync.isFlinched) {
            int damage = GenerateRandomNum(10, 20);
            e->sync.HP -= damage;
            PlayerStrikeMoveLog(log, damage);
            UpdateScreenWithLog(p, e, log, false);        
            Sleep(LONG_DELAY);
        }
        else {
            FlinchedSyncLog(log, 1);
            UpdateScreenWithLog(p, e, log, true);        //player turn
        }
    }
    else {
        SyncIsDownLog(log, 1);
        UpdateScreenWithLog(p, e, log, true);            //player turn
    }

}


void PlayerTechMove(const Player* p, Enemy* e, char log[LOG_LENGTH], int* lastSync) {
    *lastSync = 2;
    if(p->techSync.HP > 0) {
        if(!p->techSync.isFlinched) {
            if(!e->sync.isFlinched) {
                int chance = GenerateRandomNum(1, 2);
                PlayerTechAttemptLog(log);
                UpdateScreenWithLog(p, e, log, false);
                Sleep(LOG_DELAY);  
                if(chance == 1 || chance == 2) {
                    e->sync.isFlinched = true;
                    e->sync.flinchCounter = 2;
                    PlayerTechMoveLog(log, true);
                }
                else {
                    PlayerTechMoveLog(log, false);
                }
                UpdateScreenWithLog(p, e, log, false);
                Sleep(LONG_DELAY);
            }
            else {
                EnemyAlreadyFlinchedLog(log);
                UpdateScreenWithLog(p, e, log, false);
                Sleep(LONG_DELAY);
            }
        }
        else {
            FlinchedSyncLog(log, 2);
            UpdateScreenWithLog(p, e, log, true);
        }
    }
    else {
        SyncIsDownLog(log, 2);
        UpdateScreenWithLog(p, e, log, true);
    }
}

void SyncHeal(Sync* sync, int heal) {
    sync->HP += heal;
    if(sync->HP > 100)
        sync->HP = 100;
}

void PlayerSupportMove(Player* p, Enemy* e, char log[LOG_LENGTH], int* lastSync) {
    *lastSync = 3;
    if(p->supportSync.HP > 0) {
        if(!p->supportSync.isFlinched) {
            int heal = GenerateRandomNum(8, 15);

            if(p->strikeSync.HP >= 100 && p->techSync.HP >= 100 && p->supportSync.HP >= 100 ) {
                PlayerSupportMoveLog(log, heal, false);
            }
            else {
                SyncHeal(&p->strikeSync, heal);
                SyncHeal(&p->techSync, heal);
                SyncHeal(&p->supportSync, heal);
                PlayerSupportMoveLog(log, heal, true);
            }
            //*lastSync = 3;
            UpdateScreenWithLog(p, e, log, false);        
            Sleep(LONG_DELAY);
        }
        else {
            FlinchedSyncLog(log, 3);
            UpdateScreenWithLog(p, e, log, true);
        }
    }
    else {
        SyncIsDownLog(log, 3);
        UpdateScreenWithLog(p, e, log, true);
    }
}

void PlayerEndTurn(Player* p, Enemy* e,char log[LOG_LENGTH]) {
    PlayerEndTurnLog(log);
    UpdateScreenWithLog(p, e, log, false);        
    Sleep(LONG_DELAY);
}

void EnemyStrikeMove(const Enemy* e, Player* p, int lastSync, char log[LOG_LENGTH]) {
    int damage = GenerateRandomNum(e->dmgRange[0], e->dmgRange[1]);
    switch(lastSync) {
        case 1: p->strikeSync.HP -= damage; break;
        case 2: p->techSync.HP -= damage; break;
        case 3: p->supportSync.HP -= damage; break;
    }

    EnemyStrikeMoveLog(log, damage, lastSync);
    UpdateScreenWithLog(p, e, log, false);            
    Sleep(LOG_DELAY); 
    CheckPlayerSyncQuantity(p, e, lastSync, log);
    if(!IsBattleOver(p, e)) {
        UpdateScreenWithLog(p, e, log, true);
    }
}

void EnemyTechMove(const Enemy* e, Player* p, int lastSync, char log[LOG_LENGTH]) {
    int chance = GenerateRandomNum(1, 100);
    int rate = e->flinchRate;
    EnemyTechAttemptLog(log, lastSync);
    UpdateScreenWithLog(p, e, log, false);
    Sleep(LOG_DELAY); 

    if(chance <= rate) {
        switch(lastSync) {
            case 1: 
                p->strikeSync.isFlinched = true;
                p->strikeSync.flinchCounter = 2;
                break;
            case 2:
                p->techSync.isFlinched = true;
                p->techSync.flinchCounter = 2;
                break;
            case 3:
                p->supportSync.isFlinched = true;
                p->supportSync.flinchCounter = 2;
                break;
        }
        EnemyTechMoveLog(log, lastSync, true);
    }
    else {
        EnemyTechMoveLog(log, lastSync, false);
    }

    UpdateScreenWithLog(p, e, log, false);
    Sleep(LOG_DELAY);
    UpdateScreenWithLog(p, e, log, true);
    
}

void EnemySupportMove(Enemy* e, const Player* p, char log[LOG_LENGTH]) {
    int heal = GenerateRandomNum(e->healRange[0], e->healRange[1]);
    SyncHeal(&e->sync, heal);
    EnemySupportMoveLog(log, heal);
    UpdateScreenWithLog(p, e, log, false);
    Sleep(LOG_DELAY);
    UpdateScreenWithLog(p, e, log, true);  
}

int EnemyMoveDecision(const Player* p, const Enemy* e, int lastSync) {
    int move = 1;
    bool valid = false;
    while(!valid) {
        move = GenerateRandomNum(1, 3);
        if(move == 2) {
            switch(lastSync) {
                case 1: if(!p->strikeSync.isFlinched) valid = true; break; 
                case 2: if(!p->techSync.isFlinched) valid = true; break; 
                case 3: if(!p->supportSync.isFlinched) valid = true; break; 
            }
        }
        else if(move == 3) {
            if(e->sync.HP < GetEnemyMaxHP(e->type))
                valid = true;
        }
        else {
            valid = true;
        }
    }
   // printf("     move: %d", move);
    return move;
}

void EnemyMove(Enemy* e, Player* p, char log[LOG_LENGTH], int lastSync) {
    if(!e->sync.isFlinched) {
        int enemyMove = EnemyMoveDecision(p, e, lastSync);
        switch(enemyMove) {
            case 1: EnemyStrikeMove(e, p, lastSync, log); break;
            case 2: EnemyTechMove(e, p, lastSync, log); break;
            case 3: EnemySupportMove(e, p, log);
        }
    }
    else {
        FlinchedEnemyLog(log);
        UpdateScreenWithLog(p, e, log, false);
        Sleep(LONG_DELAY);
    }

}

bool CheckPlayerMove(const Player* p, int lastSync) {
    bool moveSuccess = false;
    switch(lastSync) {
        case 1: 
            if(!p->strikeSync.isFlinched && p->strikeSync.HP > 0)
                moveSuccess = true;
            break;
        case 2:
            if(!p->techSync.isFlinched && p->techSync.HP > 0)
                moveSuccess = true;
            break;
        case 3:
            if(!p->supportSync.isFlinched && p->supportSync.HP > 0)
                moveSuccess = true;
            break;
    }
    return moveSuccess;
}

void UpdatePlayerFlinchCounters(Player* p, const Enemy* e, char log[LOG_LENGTH]) {
    bool update = false;
    if(p->strikeSync.isFlinched) {
        p->strikeSync.flinchCounter -= 1;
        update = true;
        if(p->strikeSync.flinchCounter == 0){ 
            p->strikeSync.isFlinched = false;
            ResetFlinchCounterLog(log, 1);
        }
    }

    if(p->techSync.isFlinched) {
        p->techSync.flinchCounter -= 1;
        update = true;
        if(p->techSync.flinchCounter == 0){ 
            p->techSync.isFlinched = false;
            ResetFlinchCounterLog(log, 2);
        }
    }

    if(p->supportSync.isFlinched) {
        p->supportSync.flinchCounter -= 1;
        update = true;
        if(p->supportSync.flinchCounter == 0) {
            p->supportSync.isFlinched = false;
            ResetFlinchCounterLog(log, 3);
        }
    }

    if(update) {
        UpdateScreenWithLog(p, e, log, false);
        Sleep(LOG_DELAY);
    }
}

void UpdateEnemyFlinchCounter(const Player* p, Enemy* e, char log[LOG_LENGTH]) {
    bool update = false;
    if(e->sync.isFlinched) {
        e->sync.flinchCounter -= 1;
        update = true;
        if(e->sync.flinchCounter == 0) { 
            e->sync.isFlinched = false;
            ResetFlinchCounterLog(log, 0);
        }
    }

    if(update) {
        UpdateScreenWithLog(p, e, log, true);
        Sleep(LOG_DELAY);
    };
}


void CheckPlayerStatus(Player* p) {
    if(p->strikeSync.quantity <= 0) {
        ResetPlayerStats(p);
    }
    else {
        p->floor += 1;
        if(p->floor > 20)
            p->floor = 20;
        ResetFlinchCounter(p);
    }
}

void BattleLoop(Player* player, bool* playerWin) {
    Enemy enemy;
    InitializeEnemy(&enemy, PrepareEnemyType(player->floor), player->floor);
    int lastSync = 1;
    char log[LOG_LENGTH] = "";
    char c = '0';

    UpdateScreenWithLog(player, &enemy, log, true);
    do {
   //     UpdateScreenWithLog(*player, enemy, log);
        c = GetInput(4);
        //UpdateScreen(*player, enemy, log);

        switch(c) {
            case '1': PlayerStrikeMove(player, &enemy, log, &lastSync); break;
            case '2': PlayerTechMove(player, &enemy, log, &lastSync); break;
            case '3': PlayerSupportMove(player, &enemy, log, &lastSync); break;
            case '4': PlayerEndTurn(player, &enemy, log); break;
        }


        //UpdateScreenWithLog(*player, enemy, log);
        if(CheckPlayerMove(player, lastSync) && enemy.sync.HP > 0) {
            UpdatePlayerFlinchCounters(player, &enemy, log);
            EnemyMove(&enemy, player, log, lastSync);
          //  CheckPlayerSyncQuantity(player, enemy, 1, log);
            if(!IsBattleOver(player, &enemy)) {
                UpdateEnemyFlinchCounter(player, &enemy, log);
               // UpdateFlinchCounters(player, &enemy, log); //update flinch counters  
             //   UpdateScreenWithLog(*player, enemy, log, true);
              //  Sleep(LOG_DELAY);
            }
        }
        else if(enemy.sync.HP <= 0) {
            DefeatedEnemyLog(log);
            UpdateScreenWithLog(player, &enemy, log, false);       
            Sleep(LONG_DELAY);
        }

    } while (!IsBattleOver(player, &enemy));

    if(player->strikeSync.quantity <= 0) {
        *playerWin = false;
        PlayerLossesLog(log);
        UpdateScreenWithLog(player, &enemy, log, false);
       
      //  ResetPlayerStats(player);  //check na lang stats sa pagbalik sa black room
    }
    else if(enemy.sync.HP <= 0) {
        *playerWin = true;
        PlayerWinsLog(log, GetGemsReward(player->floor));
        UpdateScreenWithLog(player, &enemy, log, false);
        Sleep(LONG_DELAY);
        NextFloorLog(log);
        UpdateScreenWithLog(player, &enemy, log, false);
    }
    
   // Sleep(LOG_DELAY);
    c = _getch(); //continue/confirm prompt
    UpdateScreen(player, &enemy, false);
    ReturnToRoomNotice();

}
