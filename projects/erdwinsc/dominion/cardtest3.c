
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>

//testing gardens
int personalAssert(int choya, char* Z) {
  if (!choya) {
    printf ("ASSERTION FAILURE: %s\n", Z);
  }
}

int main () {
  struct gameState G;
  int gerome[10] = {minion, smithy, gardens, tribute, baron, adventurer, cutpurse, mine, embargo,
	       outpost};
  int rngSeed = 498;
  int playerCount = 2;
  initializeGame(playerCount, gerome, rngSeed, &G);
  int payLoad;
  int count = G.handCount[0];
  printf("Query Gardens for bugs:\n");
  G.hand[0][0] = gardens;
  payLoad = playCard(0, 1, 0, 0, &G);
  personalAssert(payLoad == -1, "There is a bug present");
  personalAssert(count == G.handCount[0], "A bug has been found!");
  printf("Testing Complete.\n");
 
 return 0; 
}