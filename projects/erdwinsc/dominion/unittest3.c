/*
Chad Erdwins CS 362
unittest3.c
testing the function supplyCount()in dominion.c
*/

#include "dominion.h"
#include <stdio.h>

int critFail = 0;

void personalAssertion(int choya, const char *errorMsg) {
	if (!choya) {
		printf("FAIL: %s\n", errorMsg);
		critFail = 1;
	}
}

void verifyAssert() {
	if (!critFail) {
		printf("NO BUGS DETECTED!\n");
	}
	else {
		printf("WARNING! BUGS ARE PRESENT!\n");
	}
}

int main() {
	printf("Now testing supplyCount()...");
	struct gameState gameOn;
	struct gameState *firstG = &gameOn;
	int participants = 2;
	int cardsAvailable[] = { smithy,adventurer,gardens,embargo,cutpurse,mine,
		ambassador,outpost,baron,tribute };
	int rngSeed = 3465;


	//call to initializeGame passing in the relevant information
	initializeGame(participants, cardsAvailable, rngSeed, firstG);

	//using payLoad to keep track of the supply amount for copper, silver, and gold
	int payLoad = supplyCount(copper, firstG);

	//46 is the amount of copper cards in a 2 player game
	personalAssertion((payLoad == 46), "Amount of Copper Present");

	payLoad = supplyCount(silver, firstG);
	//40 is the amount of silver in a game
	personalAssertion((payLoad == 40), "Amount of Silver Present");

	payLoad = supplyCount(gold, firstG);
	//30 is the amount of gold in a game
	personalAssertion((payLoad == 30), "Amount of Gold Present");

	verifyAssert();

	return 0;
}