/*
Chad Erdwins CS 362
unittest4.c
testing the function whoseTurn() in dominion.c
*/

#include "dominion.h"
#include "stdio.h"

int critFail = 0;

void personalAssert(int choya) {
	if (!choya) {
		printf("FAILED ASSERTION: \n");
		critFail = 1;
	}
}

int main() {
	printf("Now Testing whoseTurn()...");
	//declaring game state
	struct gameState gameOn;

	//declaring number of players
	gameOn.numPlayers = 4;
	//passing whose turn it is
	gameOn.whoseTurn = 2;

	//passing the function saying it is player 2's turn
	personalAssert(whoseTurn(&gameOn) == 2);

	//logic to check if whoseTurn() is bugged
	if (!critFail) {
		printf("Passed Successfully!\n");
	}
	else {
		printf("Failed Test!\n");
	}
	return 0;
}