#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int critFail = 0;

void reviewAss() {
	if (!critFail) {
		printf("Testing Complete!\n");
	}
}

int personalAssert(int choya, char* errorMsg) {
	if (choya == 0) {
		printf("Attention: %s\n", errorMsg);
		critFail = 1;
	}
}

int main()
{
	struct gameState gamma;
	int tally;
	int rngSeed = 124;
	int playerCount = 2;

	int kingdomCards[10] = { smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,outpost,baron,tribute };

	initializeGame(playerCount, kingdomCards, rngSeed, &gamma);

	tally = drawCard(1, &gamma);
	personalAssert(tally == 0, "Bug Detected!");

	reviewAss();
	return 0;
}