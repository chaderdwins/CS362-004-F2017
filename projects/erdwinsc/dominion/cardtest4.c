#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>

//testing village

int personalAssert(int choya, char* Zee) {
  if (!choya) {
    printf ("Message: %s\n", Zee);
  }
}

int main () {
  struct gameState G;
  int kingdomHand[10] = {minion, smithy, gardens, tribute, baron, adventurer, cutpurse, mine, embargo,
         outpost};
  int playerCount = 2;
  int rngSeed = 22;
  
  initializeGame(playerCount, kingdomHand, rngSeed, &G);
  printf("Testing Village Card Now...\n");
  int challenge;
  int tally = G.handCount[0];
  G.hand[0][0] = village;
  challenge = playCard(0, 1, 0, 0, &G);
  personalAssert(challenge == 0, "Warning! Bug Detected!");
  personalAssert(tally == G.handCount[0], "I found a bug!");
 
  printf("Testing Complete.\n");
  
 return 0; 
  
}