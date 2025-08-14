#include "player.h"

void GoToInventory(Player p) {
    char c;
    do {
        system("cls");
        DisplayInventory(p);
        c = _getch(); 

        switch(c) {
            case '4':
                RedirectingBack();
                Sleep(750);
                break;
        }

    } while (c != '4'); 

}   