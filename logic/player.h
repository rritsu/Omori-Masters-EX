#ifndef PLAYER_H 
#define PLAYER_H

typedef struct Sync {
    int HP;
    int quantity;
} Sync;

typedef struct Player {
    Sync strikeSync;
    Sync techSync;
    Sync supportSync;
    int gems;
    int floor;
} Player;

#endif 
