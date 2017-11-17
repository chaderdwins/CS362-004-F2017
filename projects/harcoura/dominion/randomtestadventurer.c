/*
Chad Erdwins CS 362
randomtestadventurer.c
randomly testing adventurer card
*/

#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

//declaring this constant to limit the maximum tests
#define MAXIMUSTESTIMUS 25

int personalAssert(int choya, char* errorMsg) {
  if (!choya) {
    printf ("personalAssert has failed: %s\n", errorMsg);
  }
}

int postAdventure(struct gameState*status, int participant, int previousHand){
	//checking to see if the player drew at least two treasure cards
	int i = 2;
	if(status->hand[participant][status->handCount[participant] - i] != gold && status->hand[participant][status->handCount[participant] - i] != copper && status->hand[participant][status->handCount[participant] - i] != silver){
		printf("The player has not drawn at least two treasure cards. Please advise.\n\n");
		 return 0;	
	}
	//checking to see if the player drew more than 2 treasure cards
	i = 3;
	if(status->hand[participant][status->handCount[participant] - i] == silver || status->hand[participant][status->handCount[participant] - i] == gold || status->hand[participant][status->handCount[participant] - i] == copper){
		printf("The player has drawn more than 2 treasure cards. Please advise.\n\n");
		 return 0;	
	}
		
		return 1; //should return if things run as expected
}

int main() {
	//variable declaration that will be used to initialize the game
	int i;
	int rngSeed;
	int gameCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int numberInHand; 
	int numberInDeck; 
	int numberPlayers;
	int currentPlayer;

	struct gameState gameOn;
	printf("Commence random adventurer testing:\n\n");

	//testing 25 times
	for (i = 1; i <= MAXIMUSTESTIMUS; i++) {
		//seeding RNG
		rngSeed = rand();
		//assigning a random number of player to numberPlayers, minimum is 2 and maximum is 4
		numberPlayers = rand() % (MAX_PLAYERS - 1) + 2;//MAX_PLAYERS is defined in dominion.h
		//setting up the game
		initializeGame(numberPlayers, gameCards, rngSeed, &gameOn);

		currentPlayer = 0;
		//using rand() to assign a randomized deck size
		gameOn.deckCount[currentPlayer] = rand() % MAX_DECK;//MAX-DECK is defined in dominion.h
		//assigning a value to the discard pile using MAX_DECK
		gameOn.discardCount[currentPlayer] = rand() % MAX_DECK;
		//assigning a random amount of cards to the current players hand
		gameOn.handCount[currentPlayer] = rand() % MAX_HAND;//MAX_HAND is defined in dominion.h

		//after assigning random values, we pass those values on to our variables 
		numberInHand = gameOn.handCount[currentPlayer];
		numberInDeck = gameOn.deckCount[currentPlayer];

		//playing adventurer card
		cardEffect(adventurer, 1, 1, 1, &gameOn, 1, 1);
		//after all of the setup, we test the card that was played for bugs using out personalAssert
		personalAssert(postAdventure(&gameOn, currentPlayer, numberInHand) == 1, "WARNING: BUG DETECTED.\n");	  
	}
	  

	  printf("CONGRATULATIONS TESTING IS FINISHED ON ADVENTURER.\n\n\n");

	  return 0;
}