/*
Chad Erdwins CS 362
randomtestcard1.c
randomly testing smithy card
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define MAXIMUSTESTIMUS 25

int main() {
	//setting the initial deck
	int kingdomDeck[10] = { adventurer, gardens, village, smithy, sea_hag, mine, minion, great_hall, embargo, cutpurse };

	//seeding
	int rngSeed = rand();
	
	struct gameState gameOn;

	int i,
		z;
	for (i = 0; i<MAXIMUSTESTIMUS; i++) {
		
		int participants = (rand() % MAX_PLAYERS);
		if (participants < 2) {
			participants = participants + 2;
		}
		//starting game
		initializeGame(participants, kingdomDeck, rngSeed, &gameOn);

		//nested for loop gives players a hand and deck
		for (z = 0; z < participants; z++) {

			//intializing the deck
			gameOn.deckCount[z] = rand() % MAX_DECK;
			//initializing the hand
			gameOn.handCount[z] = rand() % MAX_HAND;
			//initializing the discard pile
			gameOn.discardCount[z] = rand() % MAX_DECK;

			//inserting smithy into hand
			gameOn.hand[z][0] = smithy;

			//capturing the deck and hand size before smithy is played
			int beforeHand = numHandCards(&gameOn);
			int beforeDeck = gameOn.deckCount[z] + gameOn.discardCount[z];

			//play the smithy card
			int difference = playCard(0, 0, 0, 0, &gameOn);

			//check if player drew any cards
			if (numHandCards(&gameOn) != beforeHand + 3 && beforeDeck >= 3) {
				printf("Test: %d Player: %d did not draw 3 cards\n", i, z);
			}
			//check if player drew less than 3 cards
			if (numHandCards(&gameOn) != beforeHand + 2 && beforeDeck >= 2) {
				printf("Test: %d Player: %d drew 2 cards instead of 3 cards\n", i, z);
			}

			endTurn(&gameOn);

		}


	}
	return 0;
}