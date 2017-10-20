/*
Chad Erdwins CS 362
cardtest2.c
Unit Test for adventurer card
*/

#include "dominion.h"
#include <stdio.h>

int failed = 0;

int myassert(int b, char* msg) {
	if (b == 0) {
		printf("adventurer Test Failure: %s\n", msg);
		failed = 1;
	}
}

void checkasserts() {
	if (!failed) {
		printf("adventurer Successful\n");
	}
}

int main()
{
	struct gameState g;
	int r;

	int k[10] = { smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,outpost,baron,tribute };

	initializeGame(2, k, 5, &g);

	r = cardEffect(adventurer, 1, 1, 1, &g, 1, 0);
	myassert(r == 0, "Bug present!");

	checkasserts();
	return 0;
}