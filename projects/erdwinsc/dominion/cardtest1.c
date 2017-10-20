/*
cardtest1.c
Chad Erdwins
Unit Test for smithy
CS362
*/

#include "dominion.h"
#include <stdio.h>

//this variable should remain 0 if all goes smoothly
int critFail = 0;

int personalAssertion(int choya, char* errorMSG) {
	if (choya == 0) {
		printf("Smithy Card is Bugged: %s\n", errorMSG);
		//update to store bug
		critFail = 1;
	}
}

void verifyAss() {
	if (!critFail) {
		printf("Smithy Card Test Successful.\n");
	}
}

int main()
{
	struct gameState gameOn;
	int payLoad;
	int rngSeed = 333;
	int participants = 2;


	int cardHand[10] = { smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,outpost,baron,tribute };

	//started game
	initializeGame(participants, cardHand, rngSeed, &gameOn);

	payLoad = cardEffect(smithy, 1, 1, 1, &gameOn, 1, 0);
	personalAssertion(payLoad == 0, "Smithy Return");

	verifyAss();
	return 0;
}