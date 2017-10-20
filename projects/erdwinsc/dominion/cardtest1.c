/*
Chad Erdwins
cardtest1.c
Unit Test for smithy
CS362
*/

#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>

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

	//initializing game and passing parameters
	initializeGame(participants, cardHand, rngSeed, &gameOn);

	//passing parameters to check and see if the smithy card behaves accordingly
	payLoad = cardEffect(smithy, 1, 1, 1, &gameOn, 1, 0);
	personalAssertion(payLoad == 0, "Smithy Return");

	verifyAss();
	return 0;
}