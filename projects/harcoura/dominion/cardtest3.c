/*
Chad Erdwins CS 362
cardtest3.c
Unit Test for gardens
*/

#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>

int personalAssert(int choya, char* Z) {
  if (!choya) {
    printf ("ASSERTION FAILURE: %s\n", Z);
  }
}

int main () {
	//declare and initialize variables here
	struct gameState G;
	int gerome[10] = {minion, smithy, gardens, tribute, baron, adventurer, cutpurse, mine, embargo, outpost};
	int rngSeed = 498;
	int playerCount = 2;
	initializeGame(playerCount, gerome, rngSeed, &G);
	int payLoad;
	int count;


	count = G.handCount[0];
	printf("Query Gardens for bugs:\n");
	//passing gardens to the hand to make sure it is going to be played
	G.hand[0][0] = gardens;
	 payLoad = playCard(0, 1, 0, 0, &G);
	//using my personal asserts to check if a bug is present
	personalAssert(payLoad == -1, "There is a bug present");
	personalAssert(count == G.handCount[0], "A bug has been found!");

	 printf("Testing Complete.\n");
 
	return 0; 
}