CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

randomTests: randomtestcard1.c randomtestcard2.c randomtestadventurer.c interface.o dominion.o rngs.o
	gcc -o randomtestcard1 randomtestcard1.c -g dominion.o rngs.o interface.o $(CFLAGS)
	gcc -o randomtestcard2 randomtestcard2.c -g dominion.o rngs.o interface.o $(CFLAGS)
	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o interface.o $(CFLAGS)

randomtestcard1.out: randomtestcard1 playdom
	./randomtestcard1 >> randomtestcard1.out
	gcov randomtestcard1.c >> randomtestcard1.out
	gcov dominion.c >> 	randomtestcard1.out
	./playdom 345 >> randomtestcard1.out
	./randomtestcard1 >> randomtestcard1.out
	gcov randomtestcard1.c >> randomtestcard1.out
	gcov dominion.c >> randomtestcard1.out

randomtestcard2.out: randomtestcard2 playdom
	./randomtestcard2 >> randomtestcard2.out
	gcov randomtestcard2.c >> randomtestcard2.out
	gcov dominion.c >> randomtestcard2.out
	./playdom 345 >> randomtestcard2.out
	./randomtestcard2 >> randomtestcard2.out
	gcov dominion.c >> randomtestcard2.out
	gcov randomtestcard2.c >> randomtestcard2.out

randomtestadventurer.out: randomtestadventurer  playdom
	./randomtestadventurer >> randomtestadventurer.out
	gcov randomtestadventurer.c >> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out
	./playdom 345 >> randomtestadventurer.out
	./randomtestadventurer >> randomtestadventurer.out
	gcov randomtestadventurer.c >> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out

tests: unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c interface.o dominion.o rngs.o
	gcc -o unittest1 unittest1.c -g dominion.o rngs.o interface.o $(CFLAGS)
	gcc -o unittest2 unittest2.c -g dominion.o rngs.o interface.o $(CFLAGS)
	gcc -o unittest3 unittest3.c -g dominion.o rngs.o interface.o $(CFLAGS)
	gcc -o unittest4 unittest4.c -g dominion.o rngs.o interface.o $(CFLAGS)
	gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o interface.o $(CFLAGS)
	gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o interface.o $(CFLAGS)
	gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o interface.o $(CFLAGS)
	gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o interface.o $(CFLAGS)

unittestresults.out: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 playdom
	./unittest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./playdom 234 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	gcov unittest1.c >> unittestresults.out
	
	./unittest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./playdom 234 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	gcov unittest2.c >> unittestresults.out

	./unittest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./playdom 234 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	gcov unittest3.c >> unittestresults.out

	./unittest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./playdom 234 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	gcov unittest4.c >> unittestresults.out

	./cardtest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./playdom 234 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	gcov cardtest1.c >> unittestresults.out

	./cardtest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./playdom 234 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	gcov cardtest2.c >> unittestresults.out

	./cardtest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./playdom 234 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	gcov cardtest3.c >> unittestresults.out

	./cardtest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./playdom 234 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	gcov cardtest4.c >> unittestresults.out	


testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard tests unittestresults.out randomTests 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
