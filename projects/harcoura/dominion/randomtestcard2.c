/*
Chad Erdwins CS 362
randomtestcard2.c
randomly testing council room
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define MAXTESTS 25

int main() {
	//setting gamestate
	struct gameState *gameOn;
	int i;

	//setting up the kingdom cards
	int kingCards[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy };
	
	//declaring variable to keep track of the number of bugs present
	int bugBads = 0;
	
	for (i = 0; i < MAXTESTS; i++) {
		gameOn = malloc(sizeof(struct gameState));
		//declaring and initializing game variables
		int participants = rand() % 4;
		int rngSeed = rand();
		int currentPlayer = 0;
		int beforeHand;
		int afterHand;

		//initializing the game
		int status = initializeGame(participants, kingCards, rngSeed, gameOn);

		//randomizing deck count
		gameOn->deckCount[currentPlayer] = rand() % MAX_DECK;

		//randomizing discard pile
		gameOn->discardCount[currentPlayer] = rand() % MAX_DECK;

		//randomizing player's hand
		gameOn->handCount[currentPlayer] = rand() % MAX_HAND;

		//capturing the current players hand count before counil room is called
		beforeHand = gameOn->handCount[currentPlayer];

		//calling council room
		cardEffect(council_room, 1, 1, 1, gameOn, 0, 0);

		//capturing the current player's hand count after council room was played
		afterHand = gameOn->handCount[currentPlayer];

		//comparing the hand before and after council room was played
		if ((beforeHand + 4) != afterHand) {
			bugBads++;
			printf("WARNING: Player did not draw 4 cards\n");
		}
		if ((beforeHand + 3) == afterHand) {
			bugBads++;
			printf("The player drew 3 cards instead of 4 cards\n");
		}
		if ((beforeHand + 5) == afterHand) {
			bugBads++;
			printf("The player drew 5 cards instead of 4 cards\n");
		}
		if ((beforeHand + 2) == afterHand) {
			bugBads++;
			printf("The player drew 5 cards instead of 4 cards\n");
		}
		free(gameOn);
	}
	printf("Tests Performed: %d\n", MAXTESTS);
	printf("Bugs Detected: %d\n", bugBads);

	return 0;
}