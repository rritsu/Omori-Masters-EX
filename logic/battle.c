#include <stdio.h>

#include "utility.h"
#include "values.h"
//#include "struct.h"
#include "../visual/UIVisual.h"

void InitializeEnemy(Enemy* e, char type) {
    switch(type) {
        case 'N':
            e->dmgRange[0] = 10; e->dmgRange[1] = 20;
            e->flinchRate = 20;
            e->healRange[0] = 8; e->healRange[1] = 15;
            e->HP = 100;
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

void PlayerStrikeMove(Player player, Enemy* enemy) {
    if(!player.strikeSync.isFlinched) {
        int damage = GenerateRandomNum(10, 20);
        enemy->HP -= damage;
        StrikeMovePrompt(true, damage);
    }
    else {
        FlinchedSyncPrompt(1);
    }
}

//void EnemyMove()

void BattleLoop(Player* player) {
    Enemy enemy;
    InitializeEnemy(&enemy, PrepareEnemyType(player->floor));
    int lastMove = 0;

    do {
        system("cls");
        DisplayBattleUI(*player, enemy);

        char c = GetInput(3);
        switch(c) {
            case '1':
                PlayerStrikeMove(*player, &enemy);
                lastMove = 1;
                break;
            case '2':
                break;
            case '3':
                break;
        }



    } while (player->strikeSync.quantity > 0 || enemy.HP > 0);
}
