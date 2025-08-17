#ifndef STRUCT_H 
#define STRUCT_H

typedef enum {
    F_BUNNY,
    BUNNY2,
    BUNNY3
} Sprite;

typedef struct Sync {
    int HP;
    int quantity;
    bool isFlinched;
} Sync;

typedef struct Player {
    Sync strikeSync;
    Sync techSync;
    Sync supportSync;
    int gems;
    int floor;
} Player;

typedef struct Enemy {
    int HP;
    int dmgRange[2];
    int flinchRate;
    int healRange[2];
    char type;
    int spriteID;
    bool isFlinched;
} Enemy;



#endif 
