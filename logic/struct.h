#ifndef STRUCT_H 
#define STRUCT_H

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

typedef struct Enemy {
    Sync syncPair;
    char type;
} Enemy;

#endif 
