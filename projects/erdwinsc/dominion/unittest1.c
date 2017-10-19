/*
unittest1.c
Chad Erdwins
testing numHandCount() for bugs
CS362
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>

//this variable should remain 0 if the test doesn't find bugs
int failure = 0;

//my personal assertion that accepts 2 parameters, cardsInHand and a error message
void personalAssert(int choya, char* errorMSG) {
	if (choya == 0) {
		printf("Bug Detected: %s\n", errorMSG);
		//set failure = 1, means a bug has been detected
		failure = 1;
	}
}

int reviewAssertions() {
	if (!failure) {
		printf("No bugs detected in  function numHandCount.\n");
		return 0;
	}
	return 1;
}

int main() {
	//need to intiate the game state in order to begin
	struct gameState game1;

	//making an array that represents the cards possible
	int gooArray[10] = { smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,
		outpost,baron,tribute };

	//calling function initializeGame to get things started, passing in the array of cards previously defined
	//2 is the number of players, gooArray is the hand, and 3 is the seed number, game1 is the game state
	initializeGame(2, gooArray, 3, &game1);

	//assigning number of cards to a variable
	int cardsInHand = game1.handCount[whoseTurn(&game1)];

	//
	personalAssert(numHandCards(&game1) == cardsInHand, "There is a bug in numHandCount because the wrong value was returned!");

	return reviewAssertions();
}