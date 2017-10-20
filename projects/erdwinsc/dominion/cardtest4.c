/*
Chad Erdwins CS 362
cardtest4.c
Unit Test for village
*/

#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>

int personalAssert(int choya, char* Zee) {
  if (!choya) {
    printf ("Message: %s\n", Zee);
  }
}

int main () {
	//initialization variables
	struct gameState G;
	int kingdomHand[10] = {minion, smithy, gardens, tribute, baron, adventurer, cutpurse, mine, embargo,
         outpost};
	int playerCount = 2;
	int rngSeed = 22;
	int challenge;
	int tally;

	//passing parameters to start game
	initializeGame(playerCount, kingdomHand, rngSeed, &G);
	//letting user know what is going on
	 printf("Testing Village Card Now...\n");
	 tally = G.handCount[0];
	 //passing village card to make sure it gets played
	 G.hand[0][0] = village;
	 challenge = playCard(0, 1, 0, 0, &G);

	 //using my asserts to see if there is a bug
	 personalAssert(challenge == 0, "Warning! Bug Detected!");
	personalAssert(tally == G.handCount[0], "I found a bug!");
 
	 printf("Testing Complete.\n\n");
  
	 return 0; 
}