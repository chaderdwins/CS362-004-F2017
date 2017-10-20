/*
Chad Erdwins CS 362
unittest2.c
testing the function initializeGame() in dominion.c
*/

#include "dominion.h"
#include <stdio.h>

//this variable should remain 0 if all goes smoothly
int critFail = 0;

void verifyAssert() {
	if (!critFail) {
		printf("NO BUGS DETECTED!\n");
	}
	else {
		printf("WARNING! BUGS ARE PRESENT!\n");
	}
}

void personalAssertion(int choya, const char *errorMsg) {
	if (!choya) {
		printf("Failure: %s\n", errorMsg);
		//bugs are present
		critFail = 1;
	}
}

int main() {
	printf("Now Testing initializeGame()...");
	// Declaring variables so game will begin
	int cardsAvailable[] = { smithy,adventurer,gardens,embargo,cutpurse,mine,
		ambassador,outpost,baron,tribute };
	struct gameState gameOn;
	//number of players available
	int participants = 2;
	//random seed number
	int rngSeed = 4975;
	

	//calling initializeGame from dominion.c and passing the necessary parameters
	int payLoad = initializeGame(participants, cardsAvailable, rngSeed, &gameOn);

	//calling my assertion to debug and verify
	personalAssertion((payLoad == 0), "Initializing Game Failure");

	// declaring a deck with many duplicates to test and see if it detects bug
	int duplicateDeck[] = { smithy,smithy,adventurer,adventurer,gardens,gardens,
		embargo,embargo,cutpurse,cutpurse };

	//passing everything to initializeGame function and the duplicate array
	payLoad = initializeGame(participants, duplicateDeck, rngSeed, &gameOn);

	//I expect this message to return because of the multiple duplicates
	personalAssertion((payLoad != 0), "Multiple Duplicates Detected!!!");

	verifyAssert();

	return 0;
}