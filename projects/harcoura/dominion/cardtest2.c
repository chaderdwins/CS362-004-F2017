/*
Chad Erdwins CS 362
cardtest2.c
Unit Test for adventurer card
*/

#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>

int critFail = 0;

int personalAssert(int choya, char* errorMsg) {
	if (choya == 0) {
		printf("Fail: %s\n\n", errorMsg);
		critFail = 1;
	}
}

void reviewAss() {
	if (!critFail) {
		printf("End Testing Adventurer!\n\n");
	}
}

int main()
{
	printf("Commence adventurer testing");
	struct gameState gameOn;
	int tally;
	int cardInDeck[10] = { smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,outpost,baron,tribute };

	initializeGame(2, cardInDeck, 5, &gameOn);
	//I am passing the parameters where I think the bug should be
	tally = cardEffect(adventurer, 1, 1, 1, &gameOn, 1, 0);
	personalAssert(tally == 0, "Bug present!");

	reviewAss();
	return 0;
}