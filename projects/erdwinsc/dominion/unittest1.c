/*
Chad Erdwins CS 362
unittest1.c
testing the function isGameOver() in dominion.c
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int critFail = 0;

void personalAssert(int choya, char *errorMsg)
{
	if (choya == 0) {
		printf("Warning: %s\n\n", errorMsg);
		critFail = 1;
	}
}

void reviewAss()
{
	if (!critFail) {
		printf("Testing Done. Congratulations!\n\n");
	}
}

int main()
{
	printf("Testing isGameOver()...\n\n");
	int gameHold;
	int i;
	struct gameState *gameOn = calloc(1, sizeof(struct gameState));

	for (i = 0; i < treasure_map; i++) {
		gameOn->supplyCount[i] = 10;
	}

	gameHold = isGameOver(gameOn);
	personalAssert(gameHold == 0, "supplyCount is set!");

	//I am forcing game over here
	gameOn->supplyCount[province] = 0;
	gameHold = isGameOver(gameOn);
	personalAssert(gameHold == 1, "You should see this message if province is set to zero and it is game over!");

	//another parameter that should force game over.
	gameOn->supplyCount[province] = 10;
	gameOn->supplyCount[duchy] = 0;
	gameHold = isGameOver(gameOn);
	personalAssert(gameHold == 1, "Duchy supply is zero, should result in game over!");

	reviewAss();
	return 0;
}