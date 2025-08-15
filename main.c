#include "logic/menu.c"
#include "logic/utility.h"

#include "visual/enemyVisual.h"
//#include "visual/UIVisual.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    HideCursor();

    ConfigureScreenSettings();
    MainMenu();
  

    return 0;
}