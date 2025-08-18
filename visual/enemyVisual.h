#ifndef ENEMY_VISUAL_H
#define ENEMY_VISUAL_H

#include "colors.h"

int GetEnemyMaxHP(char type) {
	switch(type) {
		case 'N': return 100; break;
		case '1': return 100; break;
		case '2': return 150; break;
		case '3': return 200; break;
	}
	return 0;
}

void DisplayEnemyHP(int HP, char type) {
	float h = (float)HP / 5.0f;
	if(h > 0 && h < 1) h = 1.0f;
	int e = 20 - h;
	int maxHP = GetEnemyMaxHP(type);
	printf("HP: ");

	for(int i = 0 ; i < (int)h; i++) {
		if(HP > maxHP * 0.65) {
			printf(HI_GREEN "█" RESET);
		}
		else if(HP > maxHP * 0.30) {
			printf(REG_YELLOW "█" RESET);
		}
		else {
			printf(REG_RED "█" RESET);
		}
	}
	printf(RESET);
	for(int i = 0; i < e; i++) {
		printf(HI_BLACK "▒" RESET);
	}
	printf("\n\n");

}

void PrintBasil() {
	printf(HI_GREEN);
	printf(	"                 ███████████████                 \n"
			"           ██████▓▓▓▓▓▓▓▓▓▓▓▓▓▓██████            \n"
			"      ██ ███▒▒▒▒▒░░░░░░░░░░░░░░▒▒▒▒▒▓▓▓▓         \n"
			"      ████▒▒░░░░░░░░░░░░░░░░░░░░░░▒▓▒▒▒▒▓▓       \n"
			"      ██▒▒░░░░░░░░░░░░░░░░░░░░░░░▓▓▓▒▒▒▒▓▓▓▓     \n"
			"        ██░░░░░░░░░░░░░░░░░░░░░▓▓▒▒▒░░░ ▒▒▒▒▓▓   \n"
			"        ██░░░░░░░░░░░░░░░░░░░░░▓▓▒▒▓▒░░░▓▓▒▒▓▓   \n"
			"      ██░░░░░░░░░░░░░░░░░░░░░░░░░▓▓▒▒▒▓▓▒▒▓▓▓▓██ \n"
			"    ██▒░░░░░░░░░░░░░░░░░░░░▒█▓░░░▓▓▒▒▒▓▓▒▒▓▓██   \n"
			"    ██▒░░░░░░░░░░██░░░░░░▒█▓░▓█▒░░▒▓▓▓▓▓▓▓▓▓     \n"
			"      ██▒▒░░░░░██░▒█▓░░░██░░░░░██░░░▒█▓▓▓▓██     \n"
			"      ██▒▒░░░▓█░░▓▒░▓█▒░██░░░▒▓░░██░▒█▓▓██       \n"
			"        ██░▓█▒░░░▓▒░░░████░░░▒▓░░░▒█▓░██         \n"
			"        ██░▓█▒░░░▓▒░░░░░██░░░▒▓░░░░█▓░██         \n"
			"        ██░▒▒██░░░░░░░░░░░░░░░░░░██▒▒░██         \n"
			"        ██░▓██ ██░░░░░░░░░░░░░░██ ██▓░██         \n"
			"         ███   ██████████████████   ███          \n"
			"             ███▓ ░█▓▓▒░░░▓▓█▒ ▓▓██              \n"
			"           ███▓░ ▒▒▒▓▓████▓▓▒▒▒░ ▓▓██            \n"
			"          ██▓▒░▒▒█▓▒▒▒▓▓▓▓▒▒▒▓█▒▒░░▓▓██          \n");
	printf(RESET);
	
}

void PrintBasilaaa() {
	printf(HI_GREEN);
	printf(	"               ██████████████                \n"
		   	"          █████▓▒▒▒▒▒▒▒▒▒▒▒▒▓█████           \n"
	 	   	"     ███ ██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓        \n"
		   	"     ████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▒▒▒▒▓▓      \n"
			"     ██▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▒▒▒▒▓▓▓     \n"
			"       ██░░░░▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▓▒▒▒▒░░░▒▒▒▓▓   \n"
			"     ██▓▓░░▒░░░░░░░░░▒▒▒▒░░▒▒▒▒▓▒▒░▒▒▒▒▓▓▓██ \n"
			"    ██▒▒▒░░▒░░▒░░▒▒░░▒▒▒▒▓█▒░░▓▓▒▒▒▓▓▒▒▓██   \n"
			"    ██▒▒▒▒▒▒▒▒▒▓█▒▒▒▒▒▒▒█▒░██▒▒▒▓▓▓▓▓▓▓▓     \n"
			"     ██▓▒▒▒▒▒▒█▓░██▒▒▒██░░░░▒█▒▒▒▒█▓▓▓▓█     \n"
			"     ██▓▒▒▒▒██░▒▓░░█▓▒██░░░▓▒░██▒▒█▓▓██      \n"
			"       ██▒▒█▒░░▒▓░░░▒▓██░░░▓▒░░░█▓▒██        \n"
			"       ██▒▒▓▓▓░░▒░░░░░▒▒░░░▒░░▓▓▓▒▒██        \n"
			"       ██▒▒██ █▓░░░░░░░░░░░░▒██ █▓▒██        \n"
			"         ██    ██████████████    ███         \n"
			"              █▓ ██▒░  ░▒██ ▒██              \n"
			"            ██   ▒▒██████▓▒   ██             \n"
			"         ██▓▒░▒▓█▓▒▒▓▓▓▓▒▒▒█▓▒░░▓██          \n");
	printf(RESET);
}

void PrintForestBunny(Enemy e) {
	printf(HI_YELLOW);
	printf("\t\t\t\t\t\t\t\t\t      ▒▒▓         ▒▒▓         \n"
		   "\t\t\t\t\t\t\t\t\t     ▒░░░▓      ▓░░░░▓        \n"
		   "\t\t\t\t\t\t\t\t\t    ▓▒░▒▒░▓     ▒▒▒▓░▓▓       \n"
		   "\t\t\t\t\t\t\t\t\t    ▒▒▒▓▓░▓     ▒▒▓▓░▓▓       \n"
		   "\t\t\t\t\t\t\t\t\t    ▓▒▒▓▓▒░▓    ░░▓▓░▓▓       \n"
		   "\t\t\t\t\t\t\t\t\t     ▒░▓▓▒░█    ▒▒▒▓░▓        \n"
		   "\t\t\t\t\t\t\t\t\t     ▓▒▒▓▓░▒░░░░░░▒▒░▓        \n"
		   "\t\t\t\t\t\t\t\t\t      ▓░░░░░░░░░░░░░░▒▓       \n"
		   "\t\t\t\t\t\t\t\t\t    ▓▒░░░░░░░░░░░░░░░░░▒▓     \n"
		   "\t\t\t\t\t\t\t\t\t   █▒░░░░▒▒░░░░▒░░░░▒░░░░▓    \n"
		   "\t\t\t\t\t\t\t\t\t  ▓▒░░░░░░░░░░░░░░░░░░░░░░▒▓  \n"
		   "\t\t\t\t\t\t\t\t\t ▓▓░░░░░░░░░░░░░░░░░░░░░░░░▒  \n"
		   "\t\t\t\t\t\t\t\t\t ▓▒░░▒░░░░░░░░░░░░░░░░░▒░░░▒▓ \n"
		   "\t\t\t\t\t\t\t\t\t ▓▒░░░░░░░░░░░░░░░░░░░░░░░░▒▓ \n"
		   "\t\t\t\t\t\t\t\t\t ▓▓░░░░░░░░░░░░░░░░░░░░░░░░▒  \n"
		   "\t\t\t\t\t\t\t\t\t   ▓▓▒░░░░░░░░░░░░░░░░░░░▒▓   \n"
		   "\t\t\t\t\t\t\t\t\t      ▓▒▒░░░░░░░░░░░░░░▒      \n"
		   "\t\t\t\t\t\t\t\t\t          ▓▓▓▓▓▓▓▓▓           \n" RESET);
	printf("\n\t\t\t\t\t\t\t\t\t ");
	DisplayEnemyHP(e.HP, e.type);
	printf(RESET"\t\t\t\t ════════════════════════════════════════╣     Forest Bunny     ╠══════════════════════════════════════════\n\n");
}

Sprite SetEnemySprite(char type) {
	Sprite sprite;
	if(type == 'N') {
		//randomize 1-20,

	}else {

	}


	return sprite;
}

// void SetEnemySprite(char type) {
// 	switch(type) {
// 		case 
// 	}
// }

void PrintEnemy(Enemy e) {
	switch(e.spriteID) {
		case 1: PrintForestBunny(e); break;
		case 2: PrintForestBunny(e); break;
		case 20: break;
		default: PrintForestBunny(e); break;
	}
}

#endif

