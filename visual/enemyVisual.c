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
void PrintForestBunny(const Enemy* e) {
	printf(REG_GREEN);
	printf(	"\t\t\t\t\t\t\t\t\t     ▒▒▓         ▒▒▓         \n"
		   	"\t\t\t\t\t\t\t\t\t    ▒░░░▓      ▓░░░░▓        \n"
			"\t\t\t\t\t\t\t\t\t   ▓▒░▒▒░▓     ▒▒▒▓░▓▓       \n"
			"\t\t\t\t\t\t\t\t\t   ▒▒▒▓▓░▓     ▒▒▓▓░▓▓       \n"
			"\t\t\t\t\t\t\t\t\t   ▓▒▒▓▓▒░▓    ░░▓▓░▓▓       \n"
			"\t\t\t\t\t\t\t\t\t    ▒░▓▓▒░█    ▒▒▒▓░▓        \n"
			"\t\t\t\t\t\t\t\t\t    ▓▒▒▓▓░▒░░░░░░▒▒░▓        \n"
			"\t\t\t\t\t\t\t\t\t     ▓░░░░░░░░░░░░░░▒▓       \n"
			"\t\t\t\t\t\t\t\t\t   ▓▒░░░░░░░░░░░░░░░░░▒▓     \n"
			"\t\t\t\t\t\t\t\t\t  █▒░░░░▒▒░░░░▒░░░░▒░░░░▓    \n"
			"\t\t\t\t\t\t\t\t\t ▓▒░░░░░░░░░░░░░░░░░░░░░░▒▓  \n"
			"\t\t\t\t\t\t\t\t\t▓▓░░░░░░░░░░░░░░░░░░░░░░░░▒  \n"
			"\t\t\t\t\t\t\t\t\t▓▒░░▒░░░░░░░░░░░░░░░░░▒░░░▒▓ \n");
	if(!e->sync.isFlinched) {
		printf("\t\t\t\t\t\t\t\t\t▓▒░░░░░░░░░░░░░░░░░░░░░░░░▒▓ \n"
		       "\t\t\t\t\t\t\t\t\t▓▓░░░░░░░░░░░░░░░░░░░░░░░░▒  \n"
			   "\t\t\t\t\t\t\t\t\t  ▓▓▒░░░░░░░░░░░░░░░░░░░▒▓   \n");
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t" HI_PURPLE "═════════════════════════════" RESET "\n");
		printf("\t\t\t\t\t\t\t\t\t" BOLD_WHITE "         FLINCHED: %d        " RESET "\n", e->sync.flinchCounter);
		printf("\t\t\t\t\t\t\t\t\t" HI_PURPLE "═════════════════════════════" RESET "\n");
	}
	printf(REG_GREEN "\t\t\t\t\t\t\t\t\t     ▓▒▒░░░░░░░░░░░░░░▒      \n"
	       "\t\t\t\t\t\t\t\t\t         ▓▓▓▓▓▓▓▓▓           \n"  RESET);
	printf("\n\t\t\t\t\t\t\t\t\t " RESET);
	DisplayEnemyHP(e->sync.HP, e->type);
	printf(RESET"\t\t\t\t ════════════════════════════════════════╣" BHI_YELLOW "     FOREST BUNNY     " RESET "╠══════════════════════════════════════════\n\n");
}

void PrintDustBunny(const Enemy* e) {
	printf(HI_YELLOW);
	printf(	"\t\t\t\t\t\t\t\t                       █▓▒▓            \n"
		   	"\t\t\t\t\t\t\t\t                     ▓▒░░░░▓           \n"
			"\t\t\t\t\t\t\t\t                   ▓▓▓▒░░▒▒▓  █▓▒▓█    \n"
			"\t\t\t\t\t\t\t\t                  ▓▒▒▒░░▒▓▓ ▓▓▒░░░▒█   \n"
			"\t\t\t\t\t\t\t\t               ███▒▒▓░▒▒█  █▒▒▒▒▒▒▓█   \n"
			"\t\t\t\t\t\t\t\t          █▓▓▓▒▒░░▒▒▒▒▒▓▓  ▓░░░░░▒▓    \n"
			"\t\t\t\t\t\t\t\t         ▓▒░░░░░░▒░░░░░░░░▒░▒▓▒▓▓▓▓    \n"
			"\t\t\t\t\t\t\t\t        ▓▒░░▒▓░░░░░░░░░░░░░░░░░▓▓▓     \n"
			"\t\t\t\t\t\t\t\t       ▓▒▒░░░░░░░█▒░░░░▒█▒░░░░░░▒▓▓    \n"
			"\t\t\t\t\t\t\t\t      ▓▓▒░░░░░░░░░░░░░░░░░░░░░░░▒▓     \n"
			"\t\t\t\t\t\t\t\t      ▓▓▒▒▒▒░░░░░░░░░░░░░░░░░░░░░▒▓█   \n"
			"\t\t\t\t\t\t\t\t      █▓▒▒▒▒░░░░░░░░░░░░░░░░░░░░░░▒██  \n"
			"\t\t\t\t\t\t\t\t      ▓▓▓▒▒▒▒░░░░░░░░░░░░░░░░░░░░▒▒▓   \n");
	if(!e->sync.isFlinched) {
		printf("\t\t\t\t\t\t\t\t       ▓▒▒▓▓▒▒░░░░░░░░░░░░░░░░░░░▒▒▓█  \n"
		       "\t\t\t\t\t\t\t\t        █▓▓▓▓▒▒▒▒▒▒░░▒▒▒▒░░░░▓▒▒▒▒▓█▓█ \n"
			   "\t\t\t\t\t\t\t\t         █▓▓▒▒▓▒▒▒▒▒▒▒▒▒░░░▒▒▒▓▒▓▓▓    \n");
	}
	else {
		printf("\t\t\t\t\t\t\t\t     " HI_PURPLE "════════════════════════════════" RESET "\n");
		printf("\t\t\t\t\t\t\t\t     " BOLD_WHITE "           FLINCHED: %d       " RESET "\n", e->sync.flinchCounter);
		printf("\t\t\t\t\t\t\t\t     " HI_PURPLE "════════════════════════════════" RESET "\n");
	}
	printf(HI_YELLOW "\t\t\t\t\t\t\t\t           ▓▓▒▓▒▓▓▓▓▒▒▒▓▒▒▒▒▒▒▒███     \n"
	       "\t\t\t\t\t\t\t\t               █▓▓▓▓▓▓▓▒▒▓▓▓▓▓█        \n"  RESET);
	printf("\n\t\t\t\t\t\t\t\t\t " RESET);
	DisplayEnemyHP(e->sync.HP, e->type);
	printf(RESET"\t\t\t\t ════════════════════════════════════════╣" BHI_YELLOW "      DUST BUNNY      " RESET "╠══════════════════════════════════════════\n\n");
	//name: 22
}

void PrintGhostBunny(const Enemy* e) {
	printf(REG_PURPLE);
	printf(	"\t\t\t\t\t\t\t\t               ░░░     ░░░            \n"
		   	"\t\t\t\t\t\t\t\t              ▒▒▒▒░   ░▒▒▒░           \n"
			"\t\t\t\t\t\t\t\t             ░▒▒░▒░  ░░░░▒░           \n"
			"\t\t\t\t\t\t\t\t            ░▒░░▒▒░  ▒░░░░░           \n"
			"\t\t\t\t\t\t\t\t            ░▒▒░▒▒░  ░▒░▒░▒           \n"
			"\t\t\t\t\t\t\t\t            ░░▒▒░░░  ▒░░▒░░           \n"
			"\t\t\t\t\t\t\t\t            ░▒▒░▒░▒░░░░░░░░░          \n"
			"\t\t\t\t\t\t\t\t             ░▒░▒▒▒▒▒░▒▒░░░▒░░░       \n"
			"\t\t\t\t\t\t\t\t          ░▒▒░░░░░░░░░░░░░░░▒▒░▒░░░   \n"
			"\t\t\t\t\t\t\t\t         ░░░░░▒▓░░░░▒░░▒▒▒░▒▒▒▒░░░░░  \n"
			"\t\t\t\t\t\t\t\t        ░▒▒▒░░░░░░▒░░▒░░▒░░▒░░▒░░░░░░ \n"
			"\t\t\t\t\t\t\t\t       ░░░░░░░░░░░░▒░░░░░▓░░░░░░▒▒░▒░ \n"
			"\t\t\t\t\t\t\t\t       ░░░░░░░░░░░░░░░░░░░░░░▒▒░░▒░░░ \n");
	if(!e->sync.isFlinched) {
		printf("\t\t\t\t\t\t\t\t       ░░░▒░░░░░░░░░▒▒░░░▒░░░░▒▒░░░░░ \n"
		       "\t\t\t\t\t\t\t\t        ░░░░░░░░░░░▒░▒░▒░░▒░░░░░░░░░  \n"
			   "\t\t\t\t\t\t\t\t         ░░░░░░▒▒░░░▒░░░░░▒░░░▒░░░░   \n");
	}
	else {
		printf("\t\t\t\t\t\t\t\t      " HI_PURPLE "════════════════════════════════" RESET "\n");
		printf("\t\t\t\t\t\t\t\t      " BOLD_WHITE "          FLINCHED: %d       " RESET "\n", e->sync.flinchCounter);
		printf("\t\t\t\t\t\t\t\t      " HI_PURPLE "════════════════════════════════" RESET "\n");
	}
	printf(REG_PURPLE "\t\t\t\t\t\t\t\t           ░▒░░░░▒░░▒▒░▒░░░▒▒░░░░     \n"
	       "\t\t\t\t\t\t\t\t              ░▒▒░░░░░░▒░░░░░         \n"  RESET);
	printf("\n\t\t\t\t\t\t\t\t\t " RESET);
	DisplayEnemyHP(e->sync.HP, e->type);
	printf(RESET"\t\t\t\t ════════════════════════════════════════╣" BHI_YELLOW "      GHOST BUNNY     " RESET "╠══════════════════════════════════════════\n\n");
	//name: 22
}

void PrintSourdough(const Enemy* e) {
	printf(REG_YELLOW);
	printf(	"\t\t\t\t\t\t\t\t                 ██████████              \n"
		   	"\t\t\t\t\t\t\t\t           █▓▓▓▓▓▓▓▓▓▓▒▓▓▓▓▓▓▓██         \n"
			"\t\t\t\t\t\t\t\t         █▓▒▒▒▓▓▓▓▓▓▓▒▒▒░░▒░░░▒▒▒▓█      \n"
			"\t\t\t\t\t\t\t\t       █▓▓▓▒▒▒▒▒▓▓▓▒░░░░░░░░░░░░░░▒▓█    \n"
			"\t\t\t\t\t\t\t\t      █▓▓▓▓▓▓▓▓▓▒▒░░░░░░░░▒▒░░░░▒░░░▓▓   \n"
			"\t\t\t\t\t\t\t\t     █▓▓▓▓▓▓▒▓▓▒░░░░░░░░░░░░░░░░░░░░░▓▓  \n"
			"\t\t\t\t\t\t\t\t    ██▓▓▓▓▓▓▓▓▓▒░░░▒▒▒░░░░░░░░░░░▒▒▒░░▓█ \n"
			"\t\t\t\t\t\t\t\t    ███▓▓▓▓▓▓▓▒░░░░░██▒░░░░░░░░▒██▒░░░▒▓ \n"
			"\t\t\t\t\t\t\t\t    ███▓▒▓▓▓▓▓▒░░░░░░░░▒░░░░░░░░▒░░░░░▒▓ \n"
			"\t\t\t\t\t\t\t\t     █▓██▓▓▓█▓▒░░░▒░░░░░░░░▒█▓▒░░░░░░░░█ \n"
			"\t\t\t\t\t\t\t\t       ███▓▓▓▓▒░▒▒░▒▒░░░░░░░▒▒░░░░░░░░▒█ \n"
			"\t\t\t\t\t\t\t\t          █████▓▒▒░░░░░░░░░░░░░░░▒▒░░▒▓  \n"
			"\t\t\t\t\t\t\t\t             ▓▒▒▒▒▒▒▓▒▒▒▒▓▓▓▓▓▓▒▒▒▒▒▒    \n");
	if(!e->sync.isFlinched) {
		printf("\t\t\t\t\t\t\t\t            ▓▒▓▓▓▓▒▓▒░░░░▒▓▒▒▒▒▓         \n"
		       "\t\t\t\t\t\t\t\t               ▓▒▒▒▓▒░░░▒▓▒▒▓▓▓▓         \n"
			   "\t\t\t\t\t\t\t\t               ▓▓▒▒▒▒▒▓▓▓▒▒▒█            \n");
	}
	else {
		printf("\t\t\t\t\t\t\t\t      " HI_PURPLE "════════════════════════════════" RESET "\n");
		printf( "\t\t\t\t\t\t\t\t      " BOLD_WHITE "           FLINCHED: %d       " RESET "\n", e->sync.flinchCounter);
		printf("\t\t\t\t\t\t\t\t      " HI_PURPLE "════════════════════════════════" RESET "\n");
	}
	printf(REG_YELLOW "\t\t\t\t\t\t\t\t              █▓▒▒▒▓▓▓▓▓▓▒▒▒█            \n"
	       "\t\t\t\t\t\t\t\t              █▓▓▓       ▓▓▓█            \n"  RESET);
	printf("\n\t\t\t\t\t\t\t\t\t " RESET);
	DisplayEnemyHP(e->sync.HP, e->type);
	printf(RESET"\t\t\t\t ════════════════════════════════════════╣" BHI_YELLOW "       SOURDOUGH      " RESET "╠══════════════════════════════════════════\n\n");
	//name: 22
}

void PrintSlice(const Enemy* e) {
	printf(REG_YELLOW);
	printf(	"\t\t\t\t\t\t\t\t\t                ▒▒▒▒▒      \n"
		   	"\t\t\t\t\t\t\t\t\t  ▓▒▒░░░░░▓  ▒▒░░░░░░░▒█   \n"
			"\t\t\t\t\t\t\t\t\t ▒▒░░░░░░░░░░░░░░░░░░░░▓█  \n"
			"\t\t\t\t\t\t\t\t\t█▓░░░░░░░▒░░░░░░░░░░░░░▓▓█ \n"
			"\t\t\t\t\t\t\t\t\t █▓▒░░░░░░░░▒░░░░░░░░░▓██  \n"
			"\t\t\t\t\t\t\t\t\t  ██▓░░░░░░░░░░░░░▒▒░▒██   \n"
			"\t\t\t\t\t\t\t\t\t    █░▒▓▒▒░░░░░░░▒▓░░▒█    \n"
			"\t\t\t\t\t\t\t\t\t    █░░░▒▓▒░░░░░▒▓░▒░▒█    \n"
			"\t\t\t\t\t\t\t\t\t    █░░▒▓▒░░░░░░░░▒▓▒▒█    \n"
			"\t\t\t\t\t\t\t\t\t    █▓░░░░░▒▒▒▒▒▒░░░░▒█    \n"
			"\t\t\t\t\t\t\t\t\t     █▓▓▒▒▒▒▒▒▒▒▒▓▓▓▓██    \n"
			"\t\t\t\t\t\t\t\t\t        █████▓▓▓▓▓▓██      \n"
			"\t\t\t\t\t\t\t\t\t      ▓▒▒▒▒▒▓▒▒▒▒▒▒▒▒▒▓    \n");
	if(!e->sync.isFlinched) {
		printf("\t\t\t\t\t\t\t\t\t      ▓▓▓█▒▓▒░░░░▒▓▒▓ ▓█   \n"
		       "\t\t\t\t\t\t\t\t\t         █▓▓▒░░░░▒▓▒▓      \n"
			   "\t\t\t\t\t\t\t\t\t         █▓▓▓▓▒▒▓▓▒▒▓▓     \n");
	}
	else {
		printf("\t\t\t\t\t\t\t\t      " HI_PURPLE "═══════════════════════════════" RESET "\n");
		printf("\t\t\t\t\t\t\t\t      " BOLD_WHITE "           FLINCHED: %d       " RESET "\n", e->sync.flinchCounter);
		printf("\t\t\t\t\t\t\t\t      " HI_PURPLE "═══════════════════════════════" RESET "\n");
	}
	printf(REG_YELLOW "\t\t\t\t\t\t\t\t\t         █▓▓██▓▓███▓▓▓     \n"
	       "\t\t\t\t\t\t\t\t\t          ▓█       ██      \n"  RESET);
	printf("\n\t\t\t\t\t\t\t\t\t " RESET);
	DisplayEnemyHP(e->sync.HP, e->type);
	printf(RESET"\t\t\t\t ════════════════════════════════════════╣" BHI_YELLOW "         SLICE        " RESET "╠══════════════════════════════════════════\n\n");
	//name: 22
}

void PrintLivingBread(const Enemy* e) {
	printf(BHI_RED);
	printf(	"\t\t\t\t\t\t\t\t         ▓▓▓▓               ▓▓▓▓           \n"
		   	"\t\t\t\t\t\t\t\t       ▓▓▓▓▓                ▓▓▓▓▓▓         \n"
			"\t\t\t\t\t\t\t\t       ▓▓▓▓▓                 ▓▓▓▓▓         \n"
			"\t\t\t\t\t\t\t\t      ▓▓▓▓▓▓                 ▓▓▓▓▓▓        \n"
			"\t\t\t\t\t\t\t\t      ▓▓▓▓▓▓▓               ▓▓▓▓▓▓▓        \n"
			"\t\t\t\t\t\t\t\t      ▓▓▓▒▒▒▒▒▒▒▓▓▒     ▓▓▒▒▓▒▓▓▓▓▓        \n"
			"\t\t\t\t\t\t\t\t    ▓▓▒▒░░░░░░░░▒▒▓▓▓▓▓▒▒▒▒░░░░░░░▒▓▓      \n"
			"\t\t\t\t\t\t\t\t    ▓▒▓░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▓      \n"
			"\t\t\t\t\t\t\t\t    ▓▒▒░░░░▒▓▓▓░░░░░░░░░░░░░░░░░░░░▓▓      \n"
			"\t\t\t\t\t\t\t\t    ▓▓▒░░░░▒▓▓▓░░░░▒▒▒░░░░░▓▓▓▓░░░▒▓▓      \n"
			"\t\t\t\t\t\t\t\t     ▓▓▒░▒░░░░░░▒░▓▓▓▓▓░▓░░░▒▒░░░▒▒▒▓      \n"
			"\t\t\t\t\t\t\t\t      ▓▒▓▒░░░░░░▓▓▓▓▓▓▓▓▓▒░░░░▒▒░▒▓▓       \n"
			"\t\t\t\t\t\t\t\t       ▓▓▒░░░░░░▓▓▓▓▓▓▓▓▓▓▒░░░▒▒▒▓▓▓       \n");
	if(!e->sync.isFlinched) {
		printf("\t\t\t\t\t\t\t\t       ▓▓▒▒▒▒░▒▓▓▒▓▒▒▒▒▓▓▒▒▒▒░▒▒▒▓▓        \n"
		       "\t\t\t\t\t\t\t\t       ▓▓▒▒▒▒▒▒▓▒▒▒▒▒░▒▒▒▒▒▒▒▒▒▒▒▓▓ ▓      \n"
			   "\t\t\t\t\t\t\t\t        ▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓       \n");
	}
	else {
		printf("\t\t\t\t\t\t\t\t      " HI_PURPLE "═══════════════════════════════" RESET "\n");
		printf("\t\t\t\t\t\t\t\t      " BOLD_WHITE "          FLINCHED: %d       " RESET "\n", e->sync.flinchCounter);
		printf("\t\t\t\t\t\t\t\t      " HI_PURPLE "═══════════════════════════════" RESET "\n");
	}
	printf(BHI_RED "\t\t\t\t\t\t\t\t   ▒░▒  ▓▓▒▒▒▒▒▒▓▓▓▓▓▓▒▓▓▒▒▒▒▒▒▒▒▓▓▓  ░    \n"
	       "\t\t\t\t\t\t\t\t     ░  ▓▓▓▒▓▓▓             ▒▒▓▓▓▓▓▓▓▒     \n"  RESET);
	printf("\n\t\t\t\t\t\t\t\t\t " RESET);
	DisplayEnemyHP(e->sync.HP, e->type);
	printf(RESET"\t\t\t\t ════════════════════════════════════════╣" BHI_YELLOW "     LIVING BREAD     " RESET "╠══════════════════════════════════════════\n\n");
	//name: 22
}

void PrintToastGhost(const Enemy* e) {
	printf(BHI_BLUE);
	printf(	"\t\t\t\t\t\t\t\t           ▒▒▒▒▒▒▒▒▒▒▓   ▒▒▒▒▒▒▒▒▒    \n"
		   	"\t\t\t\t\t\t\t\t        ▓▒▒▒▒▒▒░▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒░▒▒▒  \n"
			"\t\t\t\t\t\t\t\t       ▓▒▒░░░░░░░░░░░░░░░░░░░▒▒▒▒▒▒▒▒ \n"
			"\t\t\t\t\t\t\t\t       ▒▓▒▒▒▒░░░░░░░░░░░░░░░░░▒▒▒▒▒▒▓ \n"
			"\t\t\t\t\t\t\t\t       █▒▒▒▒▒▒░░░░░░░░░░░░░░░░▒▒▒▒▒▒▓ \n"
			"\t\t\t\t\t\t\t\t         ▓▒▒▒▒░▒░░░░░░░░░░░░░░▒▒▒▒▒▒▒ \n"
			"\t\t\t\t\t\t\t\t          ▒▒▒▒░░░░░░░░░░░░░░░░▒▒▒▒▒   \n"
			"\t\t\t\t\t\t\t\t          ▒▒░░░░░░░░░░░░░░░░░░░░░▒▒   \n"
			"\t\t\t\t\t\t\t\t          ▒▒▒▒▒▒▒▒▒░░░░░░░▒▒░▒▒▒▒▒▒   \n"
			"\t\t\t\t\t\t\t\t          ▒▒▒██▒▒▒░░░░░░▒▒▒██▒▒▒▒▒▒   \n"
			"\t\t\t\t\t\t\t\t          ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒   \n"
			"\t\t\t\t\t\t\t\t          ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓   \n"
			"\t\t\t\t\t\t\t\t          ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒    \n");
	if(!e->sync.isFlinched) {
		printf("\t\t\t\t\t\t\t\t            ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒      \n"
		       "\t\t\t\t\t\t\t\t                   ▓▒▒▒▒▒▒▒           \n"
			   "\t\t\t\t\t\t\t\t                    ▒▒▒▒              \n");
	}
	else {
		printf("\t\t\t\t\t\t\t\t      " HI_PURPLE "═══════════════════════════════" RESET "\n");
		printf("\t\t\t\t\t\t\t\t      " BOLD_WHITE "          FLINCHED: %d       " RESET "\n", e->sync.flinchCounter);
		printf("\t\t\t\t\t\t\t\t      " HI_PURPLE "═══════════════════════════════" RESET "\n");
	}
	printf(BHI_BLUE "\t\t\t\t\t\t\t\t                     ▒▒▒▓             \n"
	       "\t\t\t\t\t\t\t\t                      ▒▓              \n"  RESET);
	printf("\n\t\t\t\t\t\t\t\t\t " RESET);
	DisplayEnemyHP(e->sync.HP, e->type);
	printf(RESET"\t\t\t\t ════════════════════════════════════════╣" BHI_YELLOW "      TOAST GHOST     " RESET "╠══════════════════════════════════════════\n\n");
	//name: 22
}

void PrintSnowBunny(const Enemy* e) {
	printf(BOLD_WHITE);
	printf(	"\t\t\t\t\t\t\t\t                ▓▓                              \n"
		   	"\t\t\t\t\t\t\t\t              ▓░░░░░        █▒░░                \n"
			"\t\t\t\t\t\t\t\t            ▓░░░░░░░      ░░░░░░░░              \n"
			"\t\t\t\t\t\t\t\t           ▓░░░░░░░▓    ▒░░░░░░░░░              \n"
			"\t\t\t\t\t\t\t\t          ▓░░░░░░░▓     ░░░░░░░░░▒              \n"
			"\t\t\t\t\t\t\t\t          █░░░░░░▒▓▒▓▓ ░░░░░░░░░▓               \n"
			"\t\t\t\t\t\t\t\t          ▒░░░░░░░░░░░▓░░░░░░░▒▓▓               \n"
			"\t\t\t\t\t\t\t\t         ▓░░░░░░░░░░░░░░░░░░░░▒▒▒▒░▒            \n"
			"\t\t\t\t\t\t\t\t        ▒░░░░░░░░░░░░░░░░░░░░▒▒░░░░░░           \n"
			"\t\t\t\t\t\t\t\t       ░░░░░▒▓░░░░░▓▒░░░░░░░░░░░░░░░░░          \n"
			"\t\t\t\t\t\t\t\t      ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▓         \n"
			"\t\t\t\t\t\t\t\t     ▓░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░         \n"
			"\t\t\t\t\t\t\t\t     ▓░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒░         \n");
	if(!e->sync.isFlinched) {
		printf("\t\t\t\t\t\t\t\t     █░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒░░░         \n"
		       "\t\t\t\t\t\t\t\t     █░▒░░░░░░░░░░░░░░░░░░░░░░░░░░░▒░░░▓        \n"
			   "\t\t\t\t\t\t\t\t     ▓▓▒▓░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▓       \n");
	}
	else {
		printf("\t\t\t\t\t\t\t\t    " HI_PURPLE "═════════════════════════════════════" RESET "\n");
		printf("\t\t\t\t\t\t\t\t    " BOLD_WHITE "            FLINCHED: %d       " RESET "\n", e->sync.flinchCounter);
		printf("\t\t\t\t\t\t\t\t    " HI_PURPLE "═════════════════════════════════════" RESET "\n");
	}
	printf(BOLD_WHITE "\t\t\t\t\t\t\t\t▒░▒ ▓░▓░▒░▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▓       \n"
	       "\t\t\t\t\t\t\t\t █ ▓ ▒▒░▒░░░░░░░░░░░░░░░░▒▓░░░░░░▒▒▒▒▓   ▓▒▓▒░▒ \n"  RESET);
	printf("\n\t\t\t\t\t\t\t\t\t " RESET);
	DisplayEnemyHP(e->sync.HP, e->type);
	printf(RESET"\t\t\t\t ════════════════════════════════════════╣" BHI_YELLOW "      SNOW BUNNY      " RESET "╠══════════════════════════════════════════\n\n");
	//name: 22
}

void PrintSnowPile(const Enemy* e) {
	printf(BOLD_WHITE);
	printf(	"\t\t\t\t\t\t                                ▓▓▒▓▒▒▒▒▒▒▒▒▓▓▓▓                                \n"
		   	"\t\t\t\t\t\t                            ▓▓▒▒░░░░░░░░░░░░▒░░▒▒▓▓                             \n"
			"\t\t\t\t\t\t                          ▓▒▒░░░░░░░░░░░░░░▒▓▓▓░░░░▒▓                           \n"
			"\t\t\t\t\t\t                       ▓▓▒░░░░░░░░░░░░░░░▒▒░░▓▓░░░░░░▒▓                         \n"
			"\t\t\t\t\t\t                     ▓▓▒▒▒▒▓▓░░░░▒▒▒▓▓▓▓▓▓▓▒░░░░░░░░░░░▒▓                       \n"
			"\t\t\t\t\t\t                    ▓▒▒░░░▓▓▒░░░▒▓▓▓▓▓▓▓▓▓▓▓░░░░░░░░░░░▒▒▓                      \n"
			"\t\t\t\t\t\t                   ▓▒▒▒░░░░░░░░░▒▓▓▓▓▓▓▓█▓▓█▓░░░░░░░░░░░▒▓▓                     \n"
			"\t\t\t\t\t\t                  ▓▒▒░░░░░░░░░░░▒▓▓▓▓▓▒░░░░░░░░░░░░░░░░░░▒▓▓                    \n"
			"\t\t\t\t\t\t                 ▓▒▒▒░░░░░░░░░░░▒▒░░░░░░░░░░░░░░░░░░░░░░▒▒▒▓▓                   \n"
			"\t\t\t\t\t\t                ▓▒▒▒▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▒▒▓▓                  \n"
			"\t\t\t\t\t\t      ▓▓█  ▓█  █▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒░▒░▒▒▒▒▓▓▓               \n"
			"\t\t\t\t\t\t      ▒▒▓  ▓▓▓▓▒▒▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▒░░▒▒▒▒▒▒▒▒▒▓▓         \n"
			"\t\t\t\t\t\t         ▓█▓▒▒░▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒░░▒░░▒▒░▒▒▒░░▒▓▓▒         \n");
	if(!e->sync.isFlinched) {
		printf("\t\t\t\t\t\t           ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▒░▒▒▒▒▒▒▒░▒▒▒░░░░░▒            \n"
		       "\t\t\t\t\t\t             ░░░░▒▒░░▒▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▓▒░               \n"
			   "\t\t\t\t\t\t            ▓▒▓ ▒▒▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒░░   ▒▓▓                \n");
	}
	else {
		printf("\t\t\t\t\t\t      " HI_PURPLE "═════════════════════════════════════════════════════════════════" RESET "\n");
		printf("\t\t\t\t\t\t      " BOLD_WHITE "                           FLINCHED: %d       " RESET "\n", e->sync.flinchCounter);
		printf("\t\t\t\t\t\t      " HI_PURPLE "═════════════════════════════════════════════════════════════════" RESET "\n");
	}
	printf(BOLD_WHITE "\t\t\t\t\t\t             ▒          ▒░░░░░░░░░░░░░░░░░░░░░░░░░      ░                       \n"
	       "\t\t\t\t\t\t                                     ░░                                         \n"  RESET);
	printf("\n\t\t\t\t\t\t\t\t\t " RESET);
	DisplayEnemyHP(e->sync.HP, e->type);
	printf(RESET"\t\t\t\t ════════════════════════════════════════╣" BHI_YELLOW "       SNOW PILE      " RESET "╠══════════════════════════════════════════\n\n");
	//name: 22
}

void PrintLili(const Enemy* e) {
	printf(HI_BLACK);
	printf(	"\t\t\t\t\t\t\t\t                    ▒▒▓▒                 \n"
		   	"\t\t\t\t\t\t\t\t              ░░░ ▒▒█████▓   ░░▒░        \n"
			"\t\t\t\t\t\t\t\t            ▒▓██▒░░░█████▓░░░▓███▒░      \n"
			"\t\t\t\t\t\t\t\t           ░░███░░░░░░░░░░░░░████▓░░     \n"
			"\t\t\t\t\t\t\t\t     ▒▒▒▒▓▓▒░░░░░░░░    ░░░░░░▓█▒░░      \n"
			"\t\t\t\t\t\t\t\t    ▒▒▒▓▓░░░░░░▓██▒▒░░░░▒████░░░░▒▒▒▒    \n"
			"\t\t\t\t\t\t\t\t    ░█████░░░░░████░░░░░░▒███░░░░░███▓   \n"
			"\t\t\t\t\t\t\t\t    ░▒███░░░░░░▒██▓░░ ░░░░░░░░░░░░███░   \n"
			"\t\t\t\t\t\t\t\t      ░░░░░▒▒▒░░  ░░▒▒▒░░░░▒░░░░▒░░░░    \n"
			"\t\t\t\t\t\t\t\t        ░▒▓███▒▒░░▒████░░░░░▓███▓░░▒▒▒░  \n"
			"\t\t\t\t\t\t\t\t        ░░████▒░░░░░██▒░░ ░░▒███▓░░▒▓▒░░ \n"
			"\t\t\t\t\t\t\t\t     ▒▒░░░░░░░░ ░ ░░░ ░░▒▒░░  ░░ ░████░░ \n"
			"\t\t\t\t\t\t\t\t    ▒▒▓█▓░░░░ ░░▒▒░░░░░████░░    ░███▒░░ \n");
	if(!e->sync.isFlinched) {
		printf("\t\t\t\t\t\t\t\t    ░▒████░░░▒▒████▒░░░▓███░░░░░░░░░░░░  \n"
		       "\t\t\t\t\t\t\t\t    ▒░░▒▒░░░░░░███▓░░░░░  ░░░▒███░░░     \n"
			   "\t\t\t\t\t\t\t\t       ░░░░░ ░░░░░░ ░░▓▓▒░░ ░▒██▒░       \n");
	}
	else {
		printf("\t\t\t\t\t\t\t\t    " HI_PURPLE "════════════════════════════════════" RESET "\n");
		printf("\t\t\t\t\t\t\t\t    " BOLD_WHITE "            FLINCHED: %d       " RESET "\n", e->sync.flinchCounter);
		printf("\t\t\t\t\t\t\t\t    " HI_PURPLE "════════════════════════════════════" RESET "\n");
	}
	printf(HI_BLACK "\t\t\t\t\t\t\t\t                ░  ░░████░░░░░░░░        \n"
	       "\t\t\t\t\t\t\t\t                   ░░░▒░░░░░             \n"  RESET);
	printf("\n\t\t\t\t\t\t\t\t\t " RESET);
	DisplayEnemyHP(e->sync.HP, e->type);
	printf(RESET"\t\t\t\t ════════════════════════════════════════╣" BHI_YELLOW "         LILI         " RESET "╠══════════════════════════════════════════\n\n");
}

void PrintDorothi(const Enemy* e) {
	printf(HI_BLACK);
	printf(	"\t\t\t\t\t\t\t\t\t        ░░          ░░▒▒░   \n"
		   	"\t\t\t\t\t\t\t\t\t   ░  ░░░         ░▒░░░░░░░ \n"
			"\t\t\t\t\t\t\t\t\t  ░░░░ ░        ░░░░░░░░░░░ \n"
			"\t\t\t\t\t\t\t\t\t  ░░░░         ░░░░░░░   ░░ \n"
			"\t\t\t\t\t\t\t\t\t ░░█▒░░    ░░░░ ░░░    ░░░░ \n"
			"\t\t\t\t\t\t\t\t\t  ░▒░░░▒░░░▒░░░░░    ░░░░░░ \n"
			"\t\t\t\t\t\t\t\t\t  ░░  ░░░░░░░░░░░░░ ░░░░░░  \n"
			"\t\t\t\t\t\t\t\t\t  ░   ░░     ░░     ░░ ░░   \n"
			"\t\t\t\t\t\t\t\t\t     ░░    ░░       ░ ░░░   \n"
			"\t\t\t\t\t\t\t\t\t    ░░   ░░        ░░░░░░   \n"
			"\t\t\t\t\t\t\t\t\t   ░░░░░░░░       ░░░░░░░░  \n"
			"\t\t\t\t\t\t\t\t\t   ░░░ ░░░░      ░░░░  ░░░  \n"
			"\t\t\t\t\t\t\t\t\t  ░░░  ░░░░     ░░░░    ░░  \n");
	if(!e->sync.isFlinched) {
		printf("\t\t\t\t\t\t\t\t\t  ░░    ░░░     ░░      ░░░ \n"
		       "\t\t\t\t\t\t\t\t\t ░░░     ░░    ░░░       ░░ \n"
			   "\t\t\t\t\t\t\t\t\t ░░      ░░    ░░░       ░░ \n");
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t" HI_PURPLE "════════════════════════════" RESET "\n");
		printf("\t\t\t\t\t\t\t\t\t " BOLD_WHITE "        FLINCHED: %d       " RESET "\n", e->sync.flinchCounter);
		printf("\t\t\t\t\t\t\t\t\t" HI_PURPLE "════════════════════════════" RESET "\n");
	}
	printf(HI_BLACK "\t\t\t\t\t\t\t\t\t         ░     ░░        ░░ \n"
	       "\t\t\t\t\t\t\t\t\t               ░          ░ \n"  RESET);
	printf("\n\t\t\t\t\t\t\t\t\t " RESET);
	DisplayEnemyHP(e->sync.HP, e->type);
	printf(RESET"\t\t\t\t ════════════════════════════════════════╣" BHI_YELLOW "        DOROTHI       " RESET "╠══════════════════════════════════════════\n\n");
}

void PrintNanci(const Enemy* e) {
	printf(HI_BLACK);
	printf(	"\t\t\t\t\t\t\t\t                 ▒                     \n"
		   	"\t\t\t\t\t\t\t\t                ▒░         ▓           \n"
			"\t\t\t\t\t\t\t\t               ▒▒▒▒░░░░▒▒▒▒▒           \n"
			"\t\t\t\t\t\t\t\t               ▒░░░░░█░░░░░▒           \n"
			"\t\t\t\t\t\t\t\t               ▒░░░░██▒░░░░░           \n"
			"\t\t\t\t\t\t\t\t               ▒▒░░░▒█░░░░░▒           \n"
			"\t\t\t\t\t\t\t\t               ▒▒░░░░▒░░░░▒▒           \n"
			"\t\t\t\t\t\t\t\t               ▒░░░░░░░░░░░▒           \n"
			"\t\t\t\t\t\t\t\t                ░░░░░░░░░░░░▒          \n"
			"\t\t\t\t\t\t\t\t                ▒░░░░░░░░░░▒▒          \n"
			"\t\t\t\t\t\t\t\t                ▒░░▒ ░░░ ▓▒▒▓          \n"
			"\t\t\t\t\t\t\t\t                ▒░░░▒ ░░ ░▒░▓          \n"
			"\t\t\t\t\t\t\t\t          ▒▒▒▓   ░░░░░▒ ▒▒░░░  ▒▒▓▓    \n");
	if(!e->sync.isFlinched) {
		printf("\t\t\t\t\t\t\t\t         ▒░░░▒▒▓▒░▒▒░░▒▓▒░░░▒▒░░░░░▒▓  \n"
		       "\t\t\t\t\t\t\t\t         ▒░ ▓▒░░░░░░░ ░░░░▒▒▒░  ░▒▒░▒▓ \n"
			   "\t\t\t\t\t\t\t\t        ▓▒▒▒░░░                  ░▒░░▓ \n");
	}
	else {
		printf("\t\t\t\t\t\t\t\t       " HI_PURPLE "═══════════════════════════════" RESET "\n");
		printf("\t\t\t\t\t\t\t\t        " BOLD_WHITE "         FLINCHED: %d       " RESET "\n", e->sync.flinchCounter);
		printf("\t\t\t\t\t\t\t\t       " HI_PURPLE "═══════════════════════════════" RESET "\n");
	}
	printf(HI_BLACK "\t\t\t\t\t\t\t\t        ▒▒▒░░                     ░░░▒ \n"
	       "\t\t\t\t\t\t\t\t       ▓▒ ▓░                        ░▓ \n"  RESET);
	printf("\n\t\t\t\t\t\t\t\t\t " RESET);
	DisplayEnemyHP(e->sync.HP, e->type);
	printf(RESET"\t\t\t\t ════════════════════════════════════════╣" BHI_YELLOW "         NANCI        " RESET "╠══════════════════════════════════════════\n\n");
}

void PrintCreepypasta(const Enemy* e) {
	printf(HI_RED "\n");
	printf(	"\t\t\t\t\t\t\t\t\t         ▒▓▓▒▒▒▒▒▒▒▓▓          \n"
		   	"\t\t\t\t\t\t\t\t\t        ▒▒▓▒▒▓▓▓▓▓▓▒▒          \n"
			"\t\t\t\t\t\t\t\t\t       ▒▒▒▒▒▒▒▒▓▓▓▓░▓          \n"
			"\t\t\t\t\t\t\t\t\t      ▒░▓░░▓▒▒▓▒▒▒░▓           \n"
			"\t\t\t\t\t\t\t\t\t     ▒▓▓▒░▓▒▒▒▓▒▒▒▒▓           \n"
			"\t\t\t\t\t\t\t\t\t     ▒▒▓▒░▓▒▒▓▓▒▒▓▒            \n"
			"\t\t\t\t\t\t\t\t\t     ▓▒▓░▓▒▒░▓▒▒░▓▓            \n"
			"\t\t\t\t\t\t\t\t\t     ▒▒▒░▓▒▒▒▓▒▒▒▒▒            \n"
			"\t\t\t\t\t\t\t\t\t    ▒▓▓▒░▓▒▒▒░░▒▒▒▓            \n"
			"\t\t\t\t\t\t\t\t\t    ▒▓▓▒░▓▒▒▒▓▒▒▒▓             \n"
			"\t\t\t\t\t\t\t\t\t     ▒▓▒▒▓▒▒▓▓▒▒▓▓             \n"
			"\t\t\t\t\t\t\t\t\t     ▒▓▒░▒▒▒▒▒▓▓▒▓▓            \n");
	if(!e->sync.isFlinched) {
		printf("\t\t\t\t\t\t\t\t\t     ▒▓▒▒▒▒▒▒▒▒▒▒▒▒▓           \n"
		       "\t\t\t\t\t\t\t\t\t     ▒▓▒░▓▒▒▓▒▒▒▒▒▒           \n"
			   "\t\t\t\t\t\t\t\t\t       ▓▓▒▒▓▒▓▒▒░▒▓▒▓          \n");
	}
	else {
		printf("\t\t\t\t\t\t\t\t       " HI_PURPLE "══════════════════════════════" RESET "\n");
		printf("\t\t\t\t\t\t\t\t        " BOLD_WHITE "         FLINCHED: %d       " RESET "\n", e->sync.flinchCounter);
		printf("\t\t\t\t\t\t\t\t       " HI_PURPLE "══════════════════════════════" RESET "\n");
	}
	printf(HI_RED "\t\t\t\t\t\t\t\t\t        ▓▓░▒▓▒▓▒▒▒░▓▓          \n"
	       "\t\t\t\t\t\t\t\t\t          ▒▓▓▓▓▓▓▓▓            \n"  RESET);
	printf("\n\t\t\t\t\t\t\t\t\t " RESET);
	DisplayEnemyHP(e->sync.HP, e->type);
	printf(RESET"\t\t\t\t ════════════════════════════════════════╣" BHI_YELLOW "      CREEPYPASTA     " RESET "╠══════════════════════════════════════════\n\n");
}

void PrintCopypasta(const Enemy* e) {
	printf(HI_YELLOW);
	printf(	"\t\t\t\t\t\t\t\t\t         ██▓░▒▓▓▒░▒▓██     \n"
		   	"\t\t\t\t\t\t\t\t\t        █▒▓▓▒██▓██▓▓▒▒█    \n"
			"\t\t\t\t\t\t\t\t\t       ▓▒█░▒█▓░▓███▓█▒▓█   \n"
			"\t\t\t\t\t\t\t\t\t     ██░▓░░▒░░▒▒░░▒░░▒█    \n"
			"\t\t\t\t\t\t\t\t\t    █▓▒▓░░▓░░░▒░░▒░░░██    \n"
			"\t\t\t\t\t\t\t\t\t    █▓▓▒░▓░░░▒░░▒▒░░▒█     \n"
			"\t\t\t\t\t\t\t\t\t    █▒▓░▒▒░░░░░░░░░░█      \n"
			"\t\t\t\t\t\t\t\t\t    █▓▒░▒░▒██▒░░▓█░▒█      \n"
			"\t\t\t\t\t\t\t\t\t   █▓▓▒░▓░░░░░░░░░░▒█      \n"
			"\t\t\t\t\t\t\t\t\t   █▓▓▓░▓░░░▓█▓▓░░░▓       \n"
			"\t\t\t\t\t\t\t\t\t   ██▓▓░▓░░░░░░░░░░█       \n"
			"\t\t\t\t\t\t\t\t\t   ██▓▓░▓░░▒▓░░▒▒░░█       \n"
			"\t\t\t\t\t\t\t\t\t    █▓▓▒▒▒░▒▒░░▒▓░░▓       \n");
	if(!e->sync.isFlinched) {
		printf("\t\t\t\t\t\t\t\t\t    ██▒▓▒▓░▒▓░░░▓░░▒█      \n"
		       "\t\t\t\t\t\t\t\t\t     ██▓▒▓░░▓░░░░▓░░▓█     \n"
			   "\t\t\t\t\t\t\t\t\t      █▓▓░▓░▒▓░░▒▒▒░░██    \n");
	}
	else {
		printf("\t\t\t\t\t\t\t\t       " HI_PURPLE "══════════════════════════════" RESET "\n");
		printf("\t\t\t\t\t\t\t\t        " BOLD_WHITE "        FLINCHED: %d       " RESET "\n", e->sync.flinchCounter);
		printf("\t\t\t\t\t\t\t\t       " HI_PURPLE "══════════════════════════════" RESET "\n");
	}
	printf(HI_YELLOW "\t\t\t\t\t\t\t\t\t       ███░▒░▒▓░▒▒▓░▓█    \n"
	       "\t\t\t\t\t\t\t\t\t        █▓▓███░▒▒▒█      \n"  RESET);
	printf("\n\t\t\t\t\t\t\t\t\t " RESET);
	DisplayEnemyHP(e->sync.HP, e->type);
	printf(RESET"\t\t\t\t ════════════════════════════════════════╣" BHI_YELLOW "       COPYPASTA      " RESET "╠══════════════════════════════════════════\n\n");
}

void PrintSesame(const Enemy* e) {
	printf(REG_YELLOW);
	printf(	"\t\t\t\t\t\t\t\t\t         ▓▓▓▒▒▓▓▒▒▓▓          \n"
		   	"\t\t\t\t\t\t\t\t\t     ▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓       \n"
			"\t\t\t\t\t\t\t\t\t   ▓▒▒▒▒▒▒▓▒▒▒▒▒▒▒▓▒▒▒▒▒▓▓    \n"
			"\t\t\t\t\t\t\t\t\t  ▓▒▒▒▓▒▒▒▒▒▒▒▓▓▒▒▒▒▒▓▒▒▒▒▓   \n"
			"\t\t\t\t\t\t\t\t\t █▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓  \n"
			"\t\t\t\t\t\t\t\t\t█▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓ \n"
			"\t\t\t\t\t\t\t\t\t█▒▒▒▒▒▒▒▒▓▒▒▒▒▒▒▒▒▒▒▒▓▒▒▒▒▒▒▓ \n"
			"\t\t\t\t\t\t\t\t\t█▓▒▒▒▒▒▒▒▒▓█▒▒▒▒▒▒▒█▓▒▒▒▒▒▒▒▓ \n"
			"\t\t\t\t\t\t\t\t\t ▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓ \n"
			"\t\t\t\t\t\t\t\t\t   ▓▓▓▒▒▒▒▒▒▒▒▓▓▓▒▒▒▒▒▒▒▒▒▓▓  \n"
			"\t\t\t\t\t\t\t\t\t    ████▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓    \n"
			"\t\t\t\t\t\t\t\t\t  ▓▓▓▒▒▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓      \n"
			"\t\t\t\t\t\t\t\t\t      ███▓▓▓▓▒▒▒▓▓▒▓▓▓▓▓▓▓    \n");
	if(!e->sync.isFlinched) {
		printf("\t\t\t\t\t\t\t\t\t       █▓▓▓▒░░░░░▓▓▒▒         \n"
		       "\t\t\t\t\t\t\t\t\t       ▓▓▓▓░░░░░▒▓▓▒▓▓        \n"
			   "\t\t\t\t\t\t\t\t\t       █▓▓▓▓▒▒▒▒▓▓▒▓▓         \n");
	}
	else {
		printf("\t\t\t\t\t\t\t\t\t" HI_PURPLE "══════════════════════════════" RESET "\n");
		printf("\t\t\t\t\t\t\t\t\t" BOLD_WHITE "         FLINCHED: %d       " RESET "\n", e->sync.flinchCounter);
		printf("\t\t\t\t\t\t\t\t\t" HI_PURPLE "══════════════════════════════" RESET "\n");
	}
	printf(REG_YELLOW "\t\t\t\t\t\t\t\t\t      ▓▓▓▓▓▓▒▓▓▓▓▓▒▓▓         \n"
	       "\t\t\t\t\t\t\t\t\t      ▓▓▓         ▓▓▓█        \n"  RESET);
	printf("\n\t\t\t\t\t\t\t\t\t " RESET);
	DisplayEnemyHP(e->sync.HP, e->type);
	printf(RESET"\t\t\t\t ════════════════════════════════════════╣" BHI_YELLOW "         SESAME         " RESET "╠══════════════════════════════════════════\n\n");
}

void PrintMixtape(const Enemy* e) {
	printf(REG_PURPLE);
	printf(	"\t\t\t\t\t\t\t\t                                ▓▓              \n"
		   	"\t\t\t\t\t\t\t\t                  ░░           ░░▓              \n"
			"\t\t\t\t\t\t\t\t                  ░░            ░░░░▓▓          \n"
			"\t\t\t\t\t\t\t\t    ░░▓▓▓░░░░░▓░░░░                  ▓░▓        \n"
			"\t\t\t\t\t\t\t\t  ░░░░                               ▓▓░        \n"
			"\t\t\t\t\t\t\t\t ▓░░░                               ░▓▓         \n"
			"\t\t\t\t\t\t\t\t ▓░▓▓                               ▓▓          \n"
			"\t\t\t\t\t\t\t\t  ▓░░                               ░█▓         \n"
			"\t\t\t\t\t\t\t\t   ▓░░    ▓▓▓░░░░░░░░░░░░░░░░░░░▒     ▓▓▓░▓     \n"
			"\t\t\t\t\t\t\t\t   ▓░▓    ▓▒▒░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░▒        ░░░░   \n"
			"\t\t\t\t\t\t\t\t    ░░    ▓▒▒░▒███▒▒▒▒░░░▒▒▓▓▓▒░▒         ░▓░   \n"
			"\t\t\t\t\t\t\t\t    ░░    ▓▒▒░▒███▒▒▒▒▒▒▒▒▒▓▓▓▒░▓          ░░   \n"
			"\t\t\t\t\t\t\t\t  ▓░▓░    ▓░░░▒▒▒▒▒░░▒▒▒░▒▒░░░░░▒          ░░   \n");
	if(!e->sync.isFlinched) {
		printf("\t\t\t\t\t\t\t\t ▓▓▓░     ▓▓▒▒▒▒▒▒▒▒▒░░░▒▒▒▒▒▒▒▒▒         ▓▓▓   \n"
		       "\t\t\t\t\t\t\t\t ▓▓░      ▓▓░░░░░▒▒▒▒▒▒▒▒▒▒▒░░░░▒        ▓░█    \n"
			   "\t\t\t\t\t\t\t\t ▓░▓░     ▓▓▒▒▓▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓      ░░░      \n");
	}
	else {
		printf("\t\t\t\t\t\t\t\t  " HI_PURPLE "═══════════════════════════════════════════" RESET "\n");
		printf("\t\t\t\t\t\t\t\t\t" BOLD_WHITE "         FLINCHED: %d       " RESET "\n", e->sync.flinchCounter);
		printf("\t\t\t\t\t\t\t\t  " HI_PURPLE "═══════════════════════════════════════════" RESET "\n");
	}
	printf(REG_PURPLE "\t\t\t\t\t\t\t\t   ▓█▓▓▓▒▓▓▓▓█                ▓▓▓▓▓▓▓▓▓█▓       \n"
	       "\t\t\t\t\t\t\t\t                                  ███           \n"  RESET);
	printf("\n\t\t\t\t\t\t\t\t\t " RESET);
	DisplayEnemyHP(e->sync.HP, e->type);
	printf(RESET"\t\t\t\t ════════════════════════════════════════╣" BHI_YELLOW "        MIXTAPE       " RESET "╠══════════════════════════════════════════\n\n");
}

void PrintFishBunny(const Enemy* e) {
	printf(BHI_CYAN);
	printf(	"\t\t\t\t\t\t\t\t                    ▒▒▓                  \n"
		   	"\t\t\t\t\t\t\t\t                  ▓░░░░▒▓    ▓▒░░▒       \n"
			"\t\t\t\t\t\t\t\t                  ▒▒▒▒▒░▒▓  ▒▒▒▒▒░▓      \n"
			"\t\t\t\t\t\t\t\t                  ▒▒▒▒▒▒▒▒  ▓▒▒▒▒▒▒      \n"
			"\t\t\t\t\t\t\t\t                  ▓▒▒▒▒▒▒▒  ▓▒▒▒▒▒▒      \n"
			"\t\t\t\t\t\t\t\t                  ▓▒▒▒▒▒▒▒  ▓▒▒▒▒░▒      \n"
			"\t\t\t\t\t\t\t\t                 ▓▒▓▒▒▒▒▒░░▒▒▒▒▒▒▒▓      \n"
			"\t\t\t\t\t\t\t\t              ▒░░░░░▒░░░░░░░░░░░░▒▓      \n"
			"\t\t\t\t\t\t\t\t ▒▒░▒▒      ▓░░░░░░░░░░░░░░░░░░░░░░▒     \n"
			"\t\t\t\t\t\t\t\t  ▒▒░░░▒▓ ▒░░░░░░░░░░░░░░░░░░░░░░░░░▒▓   \n"
			"\t\t\t\t\t\t\t\t  ▓▒░░░░░▒░░░░░░░░░░░░░▓▓░░░░░░░░▓▓░░▒   \n"
			"\t\t\t\t\t\t\t\t   ▓▒░▒▒▒░░░░▒▒░░░▒░░░░░░░░░░▒▒░░░░░░▒▓  \n"
			"\t\t\t\t\t\t\t\t     ▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░░▒▓  \n");
	if(!e->sync.isFlinched) {
		printf("\t\t\t\t\t\t\t\t     ▓▒▒▒▒▒▒▒▒▓▒▒▒░░░░░░░░░░░░░░░░▒▒▒▒   \n"
		       "\t\t\t\t\t\t\t\t      ▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░▒▒▒▒▒▒▓    \n"
			   "\t\t\t\t\t\t\t\t      ▓▓▓   ▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓     \n");
	}
	else {
		printf("\t\t\t\t\t\t\t\t    " HI_PURPLE "═════════════════════════════════════" RESET "\n");
		printf("\t\t\t\t\t\t\t\t    " BOLD_WHITE "            FLINCHED: %d       " RESET "\n", e->sync.flinchCounter);
		printf("\t\t\t\t\t\t\t\t    " HI_PURPLE "═════════════════════════════════════" RESET "\n");
	}
	printf(BHI_CYAN "\t\t\t\t\t\t\t\t              ▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓        \n"
	       "\t\t\t\t\t\t\t\t                    ▓▓▓▓█▓▒              \n"  RESET);
	printf("\n\t\t\t\t\t\t\t\t\t " RESET);
	DisplayEnemyHP(e->sync.HP, e->type);
	printf(RESET"\t\t\t\t ════════════════════════════════════════╣" BHI_YELLOW "      FISH BUNNY      " RESET "╠══════════════════════════════════════════\n\n");
}

void PrintSlimeBunny(const Enemy* e) {
	printf(BHI_GREEN);
	printf(	"\t\t\t\t\t\t\t                                     █▓▓         \n"
		   	"\t\t\t\t\t\t\t                            ▒░░░▓   ▒░░░▒        \n"
			"\t\t\t\t\t\t\t                           ▓░░░░▓  ▒░░░░▒▓       \n"
			"\t\t\t\t\t\t\t                          █▒░░░░▓  ▓▒░░░▒▒       \n"
			"\t\t\t\t\t\t\t                          █▒░░░░█   ▒░░░▒▓       \n"
			"\t\t\t\t\t\t\t                          █░░░░░▓   ▓▒░░▒▓       \n"
			"\t\t\t\t\t\t\t                         ░▓░░░░░░▒▒▒░▒▒░▒▓       \n"
			"\t\t\t\t\t\t\t                    ▓▒▒░░░░░░░░░░░░░░░░░▒▓▓      \n"
			"\t\t\t\t\t\t\t                   ▒▒░░░░░░░░░▒▒░░░▒▒░░▒░░▒▓     \n"
			"\t\t\t\t\t\t\t                 █▒▒▒░░░░░░░░░░░░░░░░░░░░░░░▒▓   \n"
			"\t\t\t\t\t\t\t                 ▓▒▒▒▒░░░░░░░░░░░░░░░░░░░░░░▒▓   \n"
			"\t\t\t\t\t\t\t                █▓▒▒▒▒░░░░░░░░░░░░░░░░░░░░░▒▒▓   \n"
			"\t\t\t\t\t\t\t                 ▓▒▒▒▒▒▒▒░░░░░░░░░░░░░░▒▒▒░▒▒▓   \n");
	if(!e->sync.isFlinched) {
		printf("\t\t\t\t\t\t\t                 █▓▒▒▒▒▒▒▒▒▒▒▒▒░▒▒▒▒▒▒▒▒▒▒▒▒▓█   \n"
		       "\t\t\t\t\t\t\t       ▓▓  ▒▒▒▒▓▓▒▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓█   \n"
			   "\t\t\t\t\t\t\t       ▓  ▓▒░░░░░░▒▒▓▒▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▒▒▒▒██ \n");
	}
	else {
		printf("\t\t\t\t\t\t\t\t    " HI_PURPLE "═════════════════════════════════════" RESET "\n");
		printf("\t\t\t\t\t\t\t\t    " BOLD_WHITE "            FLINCHED: %d       " RESET "\n", e->sync.flinchCounter);
		printf("\t\t\t\t\t\t\t\t    " HI_PURPLE "═════════════════════════════════════" RESET "\n");
	}
	printf(BHI_GREEN "\t\t\t\t\t\t\t     ▓▒▒█  ▓▒▒▒░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▒▒▒▒▒▒▒▒▒▒░▒▓ \n"
	       "\t\t\t\t\t\t\t               ▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒   \n"  RESET);
	printf("\n\t\t\t\t\t\t\t\t\t " RESET);
	DisplayEnemyHP(e->sync.HP, e->type);
	printf(RESET"\t\t\t\t ════════════════════════════════════════╣" BHI_YELLOW "      SLIME BUNNY     " RESET "╠══════════════════════════════════════════\n\n");
}

void PrintSnotBubble(const Enemy* e) {
	printf(REG_WHITE "\n");
	printf(	"\t\t\t\t\t\t\t\t                   ▓█▓▓▓▓▓▓▓▓           \n"
		   	"\t\t\t\t\t\t\t\t               ▓▓▒░░░░░░░░░░░▒▓         \n"
			"\t\t\t\t\t\t\t\t            ▓▓░░░▒▒▓▒░░▒░░▒▒▒░░▓▓       \n"
			"\t\t\t\t\t\t\t\t          ▓▒░░▒▒▓▓▒▒▒▒░░░░░░░▒░░▒▓      \n"
			"\t\t\t\t\t\t\t\t         ▓▒░▒▒▓▓▓▒▓▒▒░░░░░░░░░▒░░▒▓     \n"
			"\t\t\t\t\t\t\t\t        ▓▒░▒░░░▓▓▓▓░░░▒▓▒░░░░░▒▒░░▒▓    \n"
			"\t\t\t\t\t\t\t\t       ▓▒░▒▓▒░░░░░░░░▒▓▓▓▒░░░▓▓▓▒░▒▓    \n"
			"\t\t\t\t\t\t\t\t       ▓▒▒░░░░░░░░▓▓▒▓▓▓▒▒░░▓▓▓▓▒░░▓    \n"
			"\t\t\t\t\t\t\t\t       ▓▓▓▒▒▓▓░░░░░░░▓▓▓▓▓▒░▓▒▓▓░░░▓▒   \n"
			"\t\t\t\t\t\t\t\t       ▓▓▒░▒░░░▒░░▒▓▓▓▓▓▓░░░░▓▓▓▒░░▓    \n"
			"\t\t\t\t\t\t\t\t       ▓▒▒▒▒░░▒▓▓░░░▓▓▓░░░░░░░▓░░░▒▓    \n"
			"\t\t\t\t\t\t\t\t       ▓▒░▒▒▒░░░▒▒░░░░░▓░░░░░░░░░░▒     \n");
	if(!e->sync.isFlinched) {
		printf("\t\t\t\t\t\t\t\t        ▓░░▒▒░░░▓░░░▓▒░░░░░▒▒▒░░░▓▓     \n"
		       "\t\t\t\t\t\t\t\t        ▓▒░░▒░░░▒▓▓░░▒▒▓░▒░▒▒░░▒▓       \n"
			   "\t\t\t\t\t\t\t\t         ▓▒░▒░░░░░░░░▒░░▒▒░░░▒▓         \n");
	}
	else {
		printf("\t\t\t\t\t\t\t\t       " HI_PURPLE "══════════════════════════════" RESET "\n");
		printf("\t\t\t\t\t\t\t\t        " BOLD_WHITE "         FLINCHED: %d       " RESET "\n", e->sync.flinchCounter);
		printf("\t\t\t\t\t\t\t\t       " HI_PURPLE "══════════════════════════════" RESET "\n");
	}
	printf(REG_WHITE "\t\t\t\t\t\t\t\t          ▓▓▓▒░░░░░░░░░░▒▒▓▓▓           \n"
	       "\t\t\t\t\t\t\t\t             ▓▓▓▓▓▓▓▓▓                  \n"  RESET);
	printf("\n\t\t\t\t\t\t\t\t\t " RESET);
	DisplayEnemyHP(e->sync.HP, e->type);
	printf(RESET"\t\t\t\t ════════════════════════════════════════╣" BHI_YELLOW "      SNOT BUBBLE     " RESET "╠══════════════════════════════════════════\n\n");
}

void PrintAngi(const Enemy* e) {
printf(HI_BLACK);
	printf(	"\t\t\t\t\t\t\t\t                ██                      \n"
		   	"\t\t\t\t\t\t\t\t          ▒░▒▒░   ███                   \n"
			"\t\t\t\t\t\t\t\t          ░▒▓▓░▒    ▓█                  \n"
			"\t\t\t\t\t\t\t\t            ▒        ▓█                 \n"
			"\t\t\t\t\t\t\t\t            ▓███████████                \n"
			"\t\t\t\t\t\t\t\t          ▓▓░░▓██████░▓▓▓█              \n"
			"\t\t\t\t\t\t\t\t         ▓██████▓███▓▒ ▓▓▓▒▓            \n"
			"\t\t\t\t\t\t\t\t        ██▒▓█▓▒░▒▓▓▒▒▓▓▒▓▓▓▒▓           \n"
			"\t\t\t\t\t\t\t\t        █▓░░█▒░░▒▒▒░░▓▓▓▓▓▓▓▒▓          \n"
			"\t\t\t\t\t\t\t\t       ▓█▒▒░▒░░░▒░▓░▒░▒▓▓▓▓▓▓▓          \n"
			"\t\t\t\t\t\t\t\t       ██▒█▓░▒░░▒░▒░▒▒░▓▓▓▒▓▒▓          \n"
			"\t\t\t\t\t\t\t\t       ▓▓▒█▓▒▓░▒▒░▒░▓▓░▒▓▓▓▓▓▓▓         \n"
			"\t\t\t\t\t\t\t\t       ██▒██▒▓░▒▓▓▒▓▓▓▒▒▓▓▓▓▒▓▒▓     ██ \n");
	if(!e->sync.isFlinched) {
		printf("\t\t\t\t\t\t\t\t       ▓█▒██▓▓▓▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓█   ███ \n"
		       "\t\t\t\t\t\t\t\t        ▓▓▓███▓▓▓▓▓▓▓▓▓▓▓▓▒▓█▓▓▓▓█ ▓██  \n"
			   "\t\t\t\t\t\t\t\t        ██▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓█▓▓▓▓██  \n");
	}
	else {
		printf("\t\t\t\t\t\t\t\t     " HI_PURPLE "═══════════════════════════════════" RESET "\n");
		printf("\t\t\t\t\t\t\t\t     " BOLD_WHITE "            FLINCHED: %d       " RESET "\n", e->sync.flinchCounter);
		printf("\t\t\t\t\t\t\t\t     " HI_PURPLE "═══════════════════════════════════" RESET "\n");
	}
	printf(HI_BLACK "\t\t\t\t\t\t\t\t        ▓▓▓▓█████▓██▓▒▓▓▓▓▓▓▓███▓███▓█  \n"
	       "\t\t\t\t\t\t\t\t                      ▓▓██▒▓██▓▓▓▓█▓    \n"  RESET);
	printf("\n\t\t\t\t\t\t\t\t\t " RESET);
	DisplayEnemyHP(e->sync.HP, e->type);
	printf(RESET"\t\t\t\t ════════════════════════════════════════╣" BHI_YELLOW "         ANGI         " RESET "╠══════════════════════════════════════════\n\n");
}

void PrintHarold(const Enemy* e) {
	printf(BHI_BLUE);
	printf(	"\t\t\t\t\t\t\t\t                   ▒█▓▒▓                    \n"
		   	"\t\t\t\t\t\t\t\t                   ▒▓▒░▓░                   \n"
			"\t\t\t\t\t\t\t\t                 ░▓▓██▓▓▓▓░                 \n"
			"\t\t\t\t\t\t\t\t               ▒▓▓▓████▓▓▓█▓▒               \n"
			"\t\t\t\t\t\t\t\t            ▒░▓▓▓█▓█████▓▓▓▒█▓░             \n"
			"\t\t\t\t\t\t\t\t           ▒▒▓▓▓█▓███████▓▓▒▓▓██▒           \n"
			"\t\t\t\t\t\t\t\t         ░▒▓▓▓▓██▓████████▓▓▒▒▒██▓          \n"
			"\t\t\t\t\t\t\t\t        ░▓▒▒▓███▓█████████▓▓▓▒░░██▓▒        \n"
			"\t\t\t\t\t\t\t\t       ▒▒▓▓▒░▒░░░░░░░░░░░░░▒░░▒░▓██▒        \n"
			"\t\t\t\t\t\t\t\t       ▒▓▓▓▒░░▒██▒▒░░░▒░░██░░░░░▓▓██▒       \n"
			"\t\t\t\t\t\t\t\t      ▒▒▓▒▒▒░░░██░░░░░░░░██░░░░░▒▓█▓▓▓      \n"
			"\t\t\t\t\t\t\t\t      ▒▓▓▓▓▓▓▒▒░░░░░░░░░░░░▒▓▓▓▓▓▓███▒      \n"
			"\t\t\t\t\t\t\t\t      ░▓▓░▓▓░▓█▓▒██▓██▒██▓▒██▒░▓▓░▓█▓▒      \n");
	if(!e->sync.isFlinched) {
		printf("\t\t\t\t\t\t\t\t       ▒▒▓▒█▒▒█▓░██▒██░▓█▒▒█▓▒░▓▓▒▓█▒       \n"
		       "\t\t\t\t\t\t\t\t        ▒▒▓▓▓▓▓▓▓███████████▓▓▓▓▓▓▒▒▓███▒   \n"
			   "\t\t\t\t\t\t\t\t     ▒▒▓▓▓▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒░▒▓█▓▓███▒  \n");
	}
	else {
		printf("\t\t\t\t\t\t\t\t    " HI_PURPLE "═════════════════════════════════════" RESET "\n");
		printf("\t\t\t\t\t\t\t\t    " BOLD_WHITE "             FLINCHED: %d       " RESET "\n", e->sync.flinchCounter);
		printf("\t\t\t\t\t\t\t\t    " HI_PURPLE "═════════════════════════════════════" RESET "\n");
	}
	printf(BHI_BLUE "\t\t\t\t\t\t\t\t    ▒▓▓▓██▓▓▓▓▒▓▒▒▒░░▒▒▒▒▓   ▒▓▓▒▓▓▓▓▓▓▓▓▒  \n"
	       "\t\t\t\t\t\t\t\t     ▒▒▒░▒░▒█▓▒              ▒▒▓▒▓▒▒▒░     \n"  RESET);
	printf("\n\t\t\t\t\t\t\t\t\t " RESET);
	DisplayEnemyHP(e->sync.HP, e->type);
	printf(RESET"\t\t\t\t ════════════════════════════════════════╣" BHI_YELLOW "         HAROLD         " RESET "╠══════════════════════════════════════════\n\n");
} 

void PrintEnemy(const Enemy* e) {
	switch(e->spriteID) {
		case 1: PrintForestBunny(e); break;
		case 2: PrintDustBunny(e); break;
		case 3: PrintGhostBunny(e); break;
		case 4: PrintSourdough(e); break;
		case 5: PrintSlice(e); break;
		case 6: PrintLivingBread(e); break;
		case 7: PrintToastGhost(e); break;
		case 8: PrintSnowBunny(e); break;
		case 9: PrintSnowPile(e); break;
		case 10: PrintLili(e); break;
		case 11: PrintDorothi(e); break;
		case 12: PrintNanci(e); break;
		case 13: PrintCreepypasta(e); break;
		case 14: PrintCopypasta(e); break;
		case 15: PrintSesame(e); break;
		case 16: PrintMixtape(e); break;
		case 17: PrintSlimeBunny(e); break;
		case 18: PrintSnotBubble(e); break;
		case 19: PrintAngi(e); break;
		case 20: PrintHarold(e); break;
		//default: PrintHarold(e); break;
	}
}