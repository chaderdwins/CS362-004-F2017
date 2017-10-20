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
	echo "GCOV AFTER UNITTEST1" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./playdom 3 >> unittestresults.out
	echo "RESULTS AFTER A GAME" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	./unittest2 >> unittestresults.out
	echo "GCOV AFTER UNITTEST2" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./playdom 3 >> unittestresults.out
	echo "RESULTS AFTER A GAME" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	./unittest3 >> unittestresults.out
	echo "GCOV AFTER UNITTEST3" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./playdom 3 >> unittestresults.out
	echo "RESULTS AFTER A GAME" >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	./unittest4 >> unittestresults.out
	echo "GCOV AFTER UNITTEST4" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./playdom 3 >> unittestresults.out
	echo "RESULTS AFTER A GAME" >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	./cardtest1 >> unittestresults.out
	echo "GCOV AFTER CARDTEST1" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./playdom 3 >> unittestresults.out
	echo "RESULTS AFTER A GAME" >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	./cardtest2 >> unittestresults.out
	echo "GCOV AFTER CARDTEST2" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./playdom 3 >> unittestresults.out
	echo "RESULTS AFTER A GAME" >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	./cardtest3 >> unittestresults.out
	echo "GCOV AFTER CARDTEST3" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./playdom 3 >> unittestresults.out
	echo "RESULTS AFTER A GAME" >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	./cardtest4 >> unittestresults.out
	echo "GCOV AFTER CARDTEST4" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./playdom 3 >> unittestresults.out
	echo "RESULTS AFTER A GAME" >> unittestresults.out
	gcov dominion.c >> unittestresults.out	


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

all: playdom player testDrawCard testBuyCard badTestDrawCard tests unittestresults.out

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
