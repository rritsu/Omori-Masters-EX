#include <stdio.h>

#include "utility.h"
#include "values.h"
//#include "struct.h"
#include "../visual/UIVisual.h"

void InitializePlayer(Player* player) {
    player->strikeSync.HP = 4;
    player->strikeSync.quantity = 2;
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


void UpdateScreenWithLog(Player p, Enemy e, char log[LOG_LENGTH]) {
    system("cls");
    DisplayBattleUI(p, e);
    DisplayBattleLog(log);
}

void UpdateScreen(Player p, Enemy e) {
    system("cls");
    DisplayBattleUI(p, e);
}

void InitializeEnemy(Enemy* e, char type) {
    switch(type) {
        case 'N':
            e->dmgRange[0] = 10; e->dmgRange[1] = 20;
            e->flinchRate = 20;
            e->healRange[0] = 8; e->healRange[1] = 15;
            e->HP = 40;
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
    e->isFlinched = false;
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

void CheckPlayerSyncQuantity(Player* p, Enemy e, int syncNum, char log[LOG_LENGTH]) {
    switch(syncNum) {
        case 1: 
            if(p->strikeSync.HP <= 0) {
                int leftover = p->strikeSync.quantity -= 1;
                DefeatedSyncLog(log, syncNum); //prompt it died
                UpdateScreenWithLog(*p, e, log);
                Sleep(LOG_DELAY);
                if(leftover <= 0) {
                    NoStrikeSyncsLog(log);
                }
                else {
                    p->strikeSync.HP = 100; //revive and make HP full
                    RevivedSyncLog(log, syncNum);
                }
                UpdateScreenWithLog(*p, e, log);
                Sleep(LONG_DELAY);
            }
            break;
    }
}

void PlayerStrikeMove(Player p, Enemy* e, char log[LOG_LENGTH]) {
    if(p.strikeSync.HP > 0) {
        if(!p.strikeSync.isFlinched) {
            int damage = GenerateRandomNum(10, 20);
            e->HP -= damage;
            PlayerStrikeMoveLog(log, damage);
            UpdateScreenWithLog(p, *e, log);
            Sleep(LOG_DELAY);
        }
        else {
            FlinchedSyncLog(log, 1);
        }
    }
    else {
        //prompt that its dead, it cannot perform
        SyncIsDownLog(log, 1);
    }
}

void EnemyStrikeMove(Enemy e, Player* p, int lastSync, char log[LOG_LENGTH]) {
    int damage = GenerateRandomNum(e.dmgRange[0], e.dmgRange[1]);
    switch(lastSync) {
        case 1:
            p->strikeSync.HP -= damage;
            EnemyStrikeMoveLog(log, damage, lastSync);
            UpdateScreenWithLog(*p, e, log);
            Sleep(LOG_DELAY);   
            CheckPlayerSyncQuantity(p, e, 1, log);
            break;
    }


}

void EnemyMove(Enemy e, Player* p, char log[LOG_LENGTH], int lastSync) {
    if(!e.isFlinched) {
        //int enemyMove = GenerateRandomNum(1, 3);
        int enemyMove = 1;
        switch(enemyMove) {
            case 1:
                EnemyStrikeMove(e, p, lastSync, log);
                //damage prompt
            break;
        }
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

void BattleLoop(Player* player) {
    Enemy enemy;
    InitializeEnemy(&enemy, PrepareEnemyType(player->floor));
    int lastSync = 0;
    char log[LOG_LENGTH] = "";

    UpdateScreenWithLog(*player, enemy, log);
    do {
   //     UpdateScreenWithLog(*player, enemy, log);
        char c = GetInput(3);
        //UpdateScreen(*player, enemy, log);

        switch(c) {
            case '1':
                PlayerStrikeMove(*player, &enemy, log);
                lastSync = 1;
                break;
            case '2':
                break;
            case '3':
                break;
        }
        //UpdateScreenWithLog(*player, enemy, log);
        if(CheckPlayerMove(*player, lastSync) && enemy.HP > 0) {
            EnemyMove(enemy, player, log, lastSync);
          //  CheckPlayerSyncQuantity(player, enemy, 1, log);
        }
        else if(enemy.HP <= 0) {
            DefeatedEnemyLog(log);
            UpdateScreenWithLog(*player, enemy, log);
            Sleep(LONG_DELAY);
        }

    } while (player->strikeSync.quantity > 0 && enemy.HP > 0);

    if(player->strikeSync.quantity <= 0) {
        PlayerLossesLog(log);
        UpdateScreenWithLog(*player, enemy, log);
        ResetPlayerStats(player);

    }
    else if(enemy.HP <= 0) {
        PlayerWinsLog(log);
        UpdateScreenWithLog(*player, enemy, log);   
    }
    
    Sleep(LOG_DELAY);
    char c = _getch(); //continue/confirm prompt
    UpdateScreen(*player, enemy);
    ReturnToRoomNotice();

}
