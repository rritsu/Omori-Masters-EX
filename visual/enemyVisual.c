#include "enemyVisual.h"
#include "colors.h"
#include "../logic./utility.h"

void DisplayEnemyHP(int HP, char type) {
	float h = (float)HP / 5.0f;
	if(h > 0 && h < 1) h = 1.0f;
	else if(h < 0) h = 0.0f;
	
	int e = 20 - (int)h;

	int maxHP = GetEnemyMaxHP(type);
	printf("HP: ");

	for(int i = 0 ; i < (int)h; i++) {
		// printf("[DEBUG] Raw HP = %d\n", HP);
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


//18 lines
// void PrintForestBunny_(Enemy e) {
// 	printf(HI_YELLOW);
// 	printf("\t\t\t\t\t\t\t\t\t      ▒▒▓         ▒▒▓         \n"
// 		   "\t\t\t\t\t\t\t\t\t     ▒░░░▓      ▓░░░░▓        \n"
// 		   "\t\t\t\t\t\t\t\t\t    ▓▒░▒▒░▓     ▒▒▒▓░▓▓       \n"
// 		   "\t\t\t\t\t\t\t\t\t    ▒▒▒▓▓░▓     ▒▒▓▓░▓▓       \n"
// 		   "\t\t\t\t\t\t\t\t\t    ▓▒▒▓▓▒░▓    ░░▓▓░▓▓       \n"
// 		   "\t\t\t\t\t\t\t\t\t     ▒░▓▓▒░█    ▒▒▒▓░▓        \n"
// 		   "\t\t\t\t\t\t\t\t\t     ▓▒▒▓▓░▒░░░░░░▒▒░▓        \n"
// 		   "\t\t\t\t\t\t\t\t\t      ▓░░░░░░░░░░░░░░▒▓       \n"
// 		   "\t\t\t\t\t\t\t\t\t    ▓▒░░░░░░░░░░░░░░░░░▒▓     \n"
// 		   "\t\t\t\t\t\t\t\t\t   █▒░░░░▒▒░░░░▒░░░░▒░░░░▓    \n"
// 		   "\t\t\t\t\t\t\t\t\t  ▓▒░░░░░░░░░░░░░░░░░░░░░░▒▓  \n"
// 		   "\t\t\t\t\t\t\t\t\t ▓▓░░░░░░░░░░░░░░░░░░░░░░░░▒  \n"
// 		   "\t\t\t\t\t\t\t\t\t ▓▒░░▒░░░░░░░░░░░░░░░░░▒░░░▒▓ \n"
// 		   "\t\t\t\t\t\t\t\t\t ▓▒░░░░░░░░░░░░░░░░░░░░░░░░▒▓ \n"
// 		   "\t\t\t\t\t\t\t\t\t ▓▓░░░░░░░░░░░░░░░░░░░░░░░░▒  \n"
// 		   "\t\t\t\t\t\t\t\t\t   ▓▓▒░░░░░░░░░░░░░░░░░░░▒▓   \n"
// 		   "\t\t\t\t\t\t\t\t\t      ▓▒▒░░░░░░░░░░░░░░▒      \n"
// 		   "\t\t\t\t\t\t\t\t\t          ▓▓▓▓▓▓▓▓▓           \n" RESET);
// 	printf("\n\t\t\t\t\t\t\t\t\t ");
// 	DisplayEnemyHP(e.sync.HP, e.type);
// 	printf(RESET"\t\t\t\t ════════════════════════════════════════╣     Forest Bunny     ╠══════════════════════════════════════════\n\n");
// }

void PrintForestBunny(const Enemy* e) {
	printf(HI_YELLOW);
	printf(	"\t\t\t\t\t\t\t\t\t      ▒▒▓         ▒▒▓         \n"
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
			"\t\t\t\t\t\t\t\t\t ▓▒░░▒░░░░░░░░░░░░░░░░░▒░░░▒▓ \n");

	if(!e->sync.isFlinched) {
		printf("\t\t\t\t\t\t\t\t\t ▓▒░░░░░░░░░░░░░░░░░░░░░░░░▒▓ \n"
		       "\t\t\t\t\t\t\t\t\t ▓▓░░░░░░░░░░░░░░░░░░░░░░░░▒  \n"
			   "\t\t\t\t\t\t\t\t\t   ▓▓▒░░░░░░░░░░░░░░░░░░░▒▓   \n");
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t" HI_PURPLE "═════════════════════════════" RESET "\n");
		printf(HI_YELLOW "\t\t\t\t\t\t\t\t\t" BOLD_WHITE "         Flinched: %d         " RESET "\n", e->sync.flinchCounter);
		printf(HI_YELLOW"\t\t\t\t\t\t\t\t\t" HI_PURPLE "═════════════════════════════" RESET "\n");
	}

	printf(HI_YELLOW "\t\t\t\t\t\t\t\t\t      ▓▒▒░░░░░░░░░░░░░░▒      \n"
	       "\t\t\t\t\t\t\t\t\t          ▓▓▓▓▓▓▓▓▓           \n"  RESET);
	printf("\n\t\t\t\t\t\t\t\t\t " RESET);
	DisplayEnemyHP(e->sync.HP, e->type);
	printf(RESET"\t\t\t\t ════════════════════════════════════════╣     Forest Bunny     ╠══════════════════════════════════════════\n\n");
}

void PrintEnemy(const Enemy* e) {
	// switch(e.spriteID) {
	// 	case 1: PrintForestBunny(e); break;
	// 	case 2: PrintForestBunny(e); break;
	// 	case 20: break;
	// 	default: PrintForestBunny(e); break;
	// }
	PrintForestBunny(e);
}


// Sprite SetEnemySprite(char type) {
// 	Sprite sprite;
// 	if(type == 'N') {
// 		//randomize 1-20,

// 	}else {

// 	}


// 	return sprite;
// }

// void SetEnemySprite(char type) {
// 	switch(type) {
// 		case 
// 	}
// }
