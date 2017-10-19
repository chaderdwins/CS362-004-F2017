#include<stdio.h>

main()
{
	printf("Hello World");

}


void playSmithy() {
	//+3 Cards
	for (i = 0; i < 5; i++)//introduced bug where 5 cards are drawn instead of 3
	{
		drawCard(currentPlayer, state);
	}

	//discard card from hand
	discardCard(handPos, currentPlayer, state, 0);
	return 0;
}