#include "menu.h"
#include "utility.h"
#include "battle.h"
#include "values.h"

void ConfigureScreenSettings() {
    BorderCheck();
    _getch();
   // Sleep(500);

}

void GoToInventory(const Player* p) {
    system("cls");
    DisplayInventory(p);
    char c = GetInput(1);
    if(c == '4')
        RedirectingBackNotice();
}

void GoToShop(Player* p) {
    char c;
    do {
        system("cls");
        DisplayShop(p);
        c = GetInput(4);
        switch(c) {
            case '1':
                if(p->gems >= STRIKE_COST) {
                    p->gems -= STRIKE_COST;
                    p->strikeSync.quantity++;
                    PurchaseNotice(c, true);
                }
                else PurchaseNotice(c, false);
                break;
            case '2':
                if(p->gems >= TECH_COST) {
                    p->gems -= TECH_COST;
                    p->techSync.quantity++;
                    PurchaseNotice(c, true);
                }
                else PurchaseNotice(c, false);
                break;
            case '3':
                if(p->gems >= SUPPORT_COST) {
                    p->gems -= SUPPORT_COST;
                    p->supportSync.quantity++;
                    PurchaseNotice(c, true);
                }
                else PurchaseNotice(c, false);
                break;
            case '4':
                RedirectingBackNotice();
                break;
        }

    } while (c != '4'); 
}

void ConfirmExit(bool* exitGame) {
    system("cls");
    DisplayMainMenu(true);
    char c = GetInput(2);
    if(c == '1') {
        *exitGame = true;
        ExitGameNotice();
    }
}

void ChooseSpecialReward(Player* p) {
    system("cls");
    DisplaySpecialRewardOption();
    char c = GetInput(3);
    int reward = 0;
    switch(c) {
        case '1': 
            SyncHeal(&p->strikeSync, 100);
            SyncHeal(&p->techSync, 100);
            SyncHeal(&p->supportSync, 100);
            break;
        case '2':
            reward = 500;
            p->gems += reward;
            break;
        case '3':
            reward = GenerateRandomNum(100, 1000);
            p->gems += reward;
            break;
    }

    system("cls");
    DisplaySpecialRewardOption();
    SpecialRewardNotice(c, reward);
    c = _getch();
}

void RewardPlayer(Player* p) {
    int reward = GetGemsReward(p->floor);
    p->gems += reward;
}

void ConfirmReset(Player* p) {
    system("cls");
    DisplayBlackRoom(p, true);
    char c = GetInput(2);
    if(c == '1') {
        ResetPlayerStats(p);
        ResetProgressNotice();
    }
}

void CongratsScreen() {
    system("cls");
    DisplayCongratsScreen();
    Sleep(LONG_DELAY);
    PressAnyKeyNotice();
    _getch();

    //???????
    system("cls");
    GalingTangina();
    _getch();
}

void GoToBlackRoom(Player* p) {
    char c;
    bool fromBattle = false;
    bool playerWin = false;
    do {
        if(fromBattle) {
            if(IsEliteFloor(p->floor) && playerWin) {
                ChooseSpecialReward(p);
                if(p->floor == 20) CongratsScreen();
            }
            else if(!IsEliteFloor(p->floor) && playerWin){
                RewardPlayer(p);
            }
            CheckPlayerStatus(p);
        }
        system("cls");
        DisplayBlackRoom(p, false);
        c = GetInput(4);

        switch(c) {
        case '1':
            RedirectingToBattleNotice();
            BattleLoop(p, &playerWin);
            fromBattle = true;
            break;
        case '2':
            RedirectingNotice(c);
            GoToInventory(p);
            fromBattle = false;
            break;
        case '3':
            ConfirmReset(p);
            fromBattle = false;
            break;
        case '4':
            RedirectingBackNotice();
            break;
        }
    } while(c != '4');
}

void MainMenu() {
    bool exitGame = 0;
    Player player;
    InitializePlayer(&player);
    do {
        system("cls");
        DisplayMainMenu(false);
        char c = GetInput(4);
        switch (c) {
            case '1':
                RedirectingNotice(c);
                GoToBlackRoom(&player);
                break;
            case '2':
                RedirectingNotice(c);
                GoToInventory(&player);
                break;
            case '3':
                RedirectingNotice(c);
                GoToShop(&player);
                break;
            case '4':
                ConfirmExit(&exitGame);
                break;
        }
    } while (!exitGame); 

}


//to do
// enemy sprites
// elite enemies sprites
// elite choices screen
// congratulations screen
// help screen(?)