#include "player.h"

// void displaySyncPairs(Player p) {

// }



// void displayInventory(Player p) {
//     printf("\n\n\n\n\n");
//     printf("\t\t\t\t\t««««««««««««««««««   Inventory   »»»»»»»»»»»»»»»»»»\n");
//     displaySyncPairs(p);
// }



void goToInventory(Player p) {
    char c;
    do {
        system("cls");
        displayInventory(p);
        c = _getch(); 

        switch(c) {
            case '4':
                redirectingBack();
                Sleep(750);
                break;
        }

    } while (c != '4'); 

}   