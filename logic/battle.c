#include "battle.h"
//#include "utility.h"
#include "values.h"
//#include "struct.h"
#include "../visual/UIVisual.h"

void InitializePlayer(Player* player) {
    player->strikeSync.HP = 100;
    player->strikeSync.quantity = 1;
    player->strikeSync.isFlinched = false;
    player->strikeSync.flinchCounter = 0;

    player->techSync.HP = 100;
    player->techSync.quantity = 1;
    player->techSync.isFlinched = false;
    player->techSync.flinchCounter = 0;

    player->supportSync.HP = 100;
    player->supportSync.quantity = 1;
    player->supportSync.isFlinched = false;
    player->supportSync.flinchCounter = 0;

    player->gems = 0;
    player->floor = 1;
}


void ResetPlayerStats(Player* player) {
    player->floor = 1;
    player->strikeSync.HP = 100;
    player->strikeSync.quantity = 1;
    player->strikeSync.isFlinched = false;
    player->strikeSync.flinchCounter = 0;

    if(player->techSync.quantity <= 0) {
        player->techSync.quantity = 1;
    }
    if(player->supportSync.quantity <= 0) {
        player->supportSync.quantity = 1;
    }

    player->techSync.HP = 100;
    player->techSync.isFlinched = false;
    player->techSync.flinchCounter = 0;

    player->supportSync.HP = 100;
    player->supportSync.isFlinched = false;
    player->supportSync.flinchCounter = 0;

}


void UpdateScreenWithLog(Player p, Enemy e, char log[LOG_LENGTH], bool isPlayerTurn) {
    system("cls");
    DisplayBattleUI(p, e, isPlayerTurn);
    DisplayBattleLog(log);
}

void UpdateScreen(Player p, Enemy e, bool isPlayerTurn) {
    system("cls");
    DisplayBattleUI(p, e, isPlayerTurn);
}

void InitializeEnemy(Enemy* e, char type) {
    switch(type) {
        case 'N':
            e->dmgRange[0] = 10; e->dmgRange[1] = 20;
            e->flinchRate = 20;
            e->healRange[0] = 8; e->healRange[1] = 15;
            e->sync.HP = 100;
            e->spriteID = GenerateRandomNum(1, 20);
            break;
        case '1': 
            //initiate other values first
            //function: rng 2 sprite IDS (int) then make player pick 
            // whichever player picks is the spriteID that the enemy will use
            //e->spriteID = chosen by player
            
            break;
    }
    e->type = type;
    e->sync.isFlinched = false;
    e->sync.flinchCounter = 0;
}

char PrepareEnemyType(int floor) {
    char type;
    bool isElite = false;
    if(floor % 5 == 0) isElite = true;

    if(isElite) {
        //randomize type
    }
    else {
        type = 'N';
    }

    return type;
}

//not sure if this is still needed 
// void CheckIfPlayerDown(Player* p, Enemy e, int syncNum) {
//     switch(syncNum) {
//         //case 1: if()
//     }
// }

void HandleSyncQuantity(Sync* sync, Player* p, Enemy e, int syncNum, char log[LOG_LENGTH]) {
    int leftover = sync->quantity -= 1;
    DefeatedSyncLog(log, syncNum);
    UpdateScreenWithLog(*p, e, log, false);
    Sleep(LOG_DELAY);

    if(leftover <= 0) {
        NoSyncsLog(log, 1);
    }
    else {
        p->strikeSync.HP = 100; //revive and make HP full
        RevivedSyncLog(log, syncNum);
    }
    UpdateScreenWithLog(*p, e, log, false);
    Sleep(LONG_DELAY);
    
}

void CheckPlayerSyncQuantity(Player* p, Enemy e, int syncNum, char log[LOG_LENGTH]) {
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

void PlayerStrikeMove(Player p, Enemy* e, char log[LOG_LENGTH], int* lastSync) {
    if(p.strikeSync.HP > 0) {
        if(!p.strikeSync.isFlinched) {
            int damage = GenerateRandomNum(10, 20);
            e->sync.HP -= damage;
            *lastSync = 1;
            PlayerStrikeMoveLog(log, damage);
            UpdateScreenWithLog(p, *e, log, false);        
            Sleep(LONG_DELAY);
        }
        else {
            FlinchedSyncLog(log, 1);
            UpdateScreenWithLog(p, *e, log, true);        //player turn
        }
    }
    else {
        //prompt that its dead, it cannot perform
        SyncIsDownLog(log, 1);
        UpdateScreenWithLog(p, *e, log, true);            //player turn
    }

}


void PlayerTechMove(Player p, Enemy* e, char log[LOG_LENGTH], int* lastSync) {
    if(p.techSync.HP > 0) {
        if(!p.techSync.isFlinched) {
            if(!e->sync.isFlinched) {
                int chance = GenerateRandomNum(1, 10);
                PlayerTechAttemptLog(log);
                UpdateScreenWithLog(p, *e, log, false);
                Sleep(LOG_DELAY);  
                if(chance == 1 || chance == 2) {
                    e->sync.isFlinched = true;
                    e->sync.flinchCounter = 2;
                    PlayerTechMoveLog(log, true);
                }
                else {
                    PlayerTechMoveLog(log, false);
                }
                *lastSync = 2;
                UpdateScreenWithLog(p, *e, log, false);
                Sleep(LONG_DELAY);
            }
            else {
                EnemyAlreadyFlinchedLog(log);
                UpdateScreenWithLog(p, *e, log, false);
                Sleep(LONG_DELAY);
            }
        }
        else {
            FlinchedSyncLog(log, 2);
            UpdateScreenWithLog(p, *e, log, true);
        }
    }
    else {
        SyncIsDownLog(log, 2);
        UpdateScreenWithLog(p, *e, log, true);
    }
}

void EnemyStrikeMove(Enemy* e, Player* p, int lastSync, char log[LOG_LENGTH]) {
    int damage = GenerateRandomNum(e->dmgRange[0], e->dmgRange[1]);
    switch(lastSync) {
        case 1:
            p->strikeSync.HP -= damage;
            break;
        case 2:
            p->techSync.HP -= damage;
            break;
        case 3:
            p->supportSync.HP -= damage;
            break;
    }

    EnemyStrikeMoveLog(log, damage, lastSync);
    UpdateScreenWithLog(*p, *e, log, true);            
    //Sleep(LONG_DELAY);   
    CheckPlayerSyncQuantity(p, *e, lastSync, log);
}

void EnemyTechMove(Enemy* e, Player* p, int lastSync, char log[LOG_LENGTH]) {
    int chance = GenerateRandomNum(1, 100);
    int rate = e->flinchRate;
    EnemyTechAttemptLog(log, lastSync);
    UpdateScreenWithLog(*p, *e, log, false);
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

    UpdateScreenWithLog(*p, *e, log, true);
    //Sleep(LONG_DELAY);
    
}

int EnemyMoveDecision(Player* p, Enemy* e, int lastSync) {
    int move = 1;
    bool valid = false;
    while(!valid) {
        move = GenerateRandomNum(1, 2);
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
    printf("     move: %d", move);
    return move;
}

void EnemyMove(Enemy* e, Player* p, char log[LOG_LENGTH], int lastSync) {
    if(!e->sync.isFlinched) {
        int enemyMove = EnemyMoveDecision(p, e, lastSync);
        //int enemyMove = 1
        switch(enemyMove) {
            case 1: EnemyStrikeMove(e, p, lastSync, log); break;
            case 2: EnemyTechMove(e, p, lastSync, log); break;
        }
    }
    else {
        FlinchedEnemyLog(log);
        UpdateScreenWithLog(*p, *e, log, false);
        Sleep(LONG_DELAY);
    }

}

bool CheckPlayerMove(Player p, int lastSync) {
    bool moveSuccess = false;
    switch(lastSync) {
        case 1: 
            if(!p.strikeSync.isFlinched && p.strikeSync.HP > 0)
                moveSuccess = true;
            break;
        case 2:
            if(!p.techSync.isFlinched && p.techSync.HP > 0)
                moveSuccess = true;
            break;
        case 3:
            if(!p.supportSync.isFlinched && p.supportSync.HP > 0)
                moveSuccess = true;
            break;
    }
    return moveSuccess;
}

void UpdatePlayerFlinchCounters(Player* p, Enemy* e, char log[LOG_LENGTH]) {
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
        UpdateScreenWithLog(*p, *e, log, false);
        Sleep(LOG_DELAY);
    }
}

void UpdateEnemyFlinchCounter(Player* p, Enemy* e, char log[LOG_LENGTH]) {
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
        UpdateScreenWithLog(*p, *e, log, true);
        Sleep(LOG_DELAY);
    };
}

bool IsBattleOver(Player p, Enemy e) {
    bool isOver = false;
    if(p.strikeSync.quantity <= 0 || e.sync.HP <= 0) {
        isOver = true;
    }
    return isOver;
}

void CheckPlayerStatus(Player* p) {
    if(p->strikeSync.quantity <= 0) {
        ResetPlayerStats(p);
    }
}

void BattleLoop(Player* player) {
    Enemy enemy;
    InitializeEnemy(&enemy, PrepareEnemyType(player->floor));
    int lastSync = 1;
    char log[LOG_LENGTH] = "";
    char c = '0';

    UpdateScreenWithLog(*player, enemy, log, true);
    do {
   //     UpdateScreenWithLog(*player, enemy, log);
        c = GetInput(3);
        //UpdateScreen(*player, enemy, log);

        switch(c) {
            case '1':
                PlayerStrikeMove(*player, &enemy, log, &lastSync);
             //   lastSync = 1;
                break;
            case '2':
                PlayerTechMove(*player, &enemy, log, &lastSync);
             //   lastSync = 2;
                break;
            case '3':
                break;
        }


        //UpdateScreenWithLog(*player, enemy, log);
        if(CheckPlayerMove(*player, lastSync) && enemy.sync.HP > 0) {
            UpdatePlayerFlinchCounters(player, &enemy, log);
            EnemyMove(&enemy, player, log, lastSync);
          //  CheckPlayerSyncQuantity(player, enemy, 1, log);
            if(!IsBattleOver(*player, enemy)) {
                UpdateEnemyFlinchCounter(player, &enemy, log);
               // UpdateFlinchCounters(player, &enemy, log); //update flinch counters  
             //   UpdateScreenWithLog(*player, enemy, log, true);
              //  Sleep(LOG_DELAY);
            }
        }
        else if(enemy.sync.HP <= 0) {
            DefeatedEnemyLog(log);
            UpdateScreenWithLog(*player, enemy, log, false);       
            Sleep(LONG_DELAY);
        }

    } while (!IsBattleOver(*player, enemy));

    if(player->strikeSync.quantity <= 0) {
        PlayerLossesLog(log);
        UpdateScreenWithLog(*player, enemy, log, false);
      //  ResetPlayerStats(player);  //check na lang stats sa pagbalik sa black room

    }
    else if(enemy.sync.HP <= 0) {
        PlayerWinsLog(log);
        UpdateScreenWithLog(*player, enemy, log, false);   
    }
    
    Sleep(LOG_DELAY);
    c = _getch(); //continue/confirm prompt
    UpdateScreen(*player, enemy, false);
    ReturnToRoomNotice();

}
