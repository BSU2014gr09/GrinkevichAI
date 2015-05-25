#include "Functions.h"
#include <time.h>
#include <iostream>

using namespace std;

void initDeck(Deck *deck)
{
	deck->size = SuitCount * ValueCount;
	deck->cards = new Card[deck->size];

	for (int i = 0; i < SuitCount; ++i)
	{
		Suit suit = (Suit)i;

		for (int j = 0; j < ValueCount; ++j)
		{
			Value val = (Value)j;

			Card *card = &deck->cards[j + ValueCount*i];
			card->suit = suit;
			card->val = val;
		}
	}

	for (int i = 0; i < deck->size; ++i)
	{
		Card *card = &deck->cards[i];

		if (i < deck->size - 1)
			card->nextCard = &deck->cards[i + 1];
		else
			card->nextCard = &deck->cards[0];
	}
}

void freeDeck(Deck *deck)
{
	delete[] deck->cards;
	deck->cards = NULL;
	deck->size = 0;
}

void shuffleDeck(Deck *deck)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 100; ++i)
	{
		int i1 = rand() % (deck->size);
		int i2 = rand() % (deck->size);

		Card tmp = deck->cards[i1];
		deck->cards[i1] = deck->cards[i2];
		deck->cards[i2] = tmp;
	}

	for (int i = 0; i < deck->size; ++i)
	{
		Card *card = &deck->cards[i];

		if (i < deck->size - 1)
			card->nextCard = &deck->cards[i + 1];
		else
			card->nextCard = &deck->cards[0];
	}
}

void getCardText(const Card *card, char *buffer)
{
	switch (card->suit)
	{
	case (Hearts) :
	case (Diamonds) :
	case (Clubs) :
	case (Spades) :
				  buffer[0] = (char)(3 + (int)card->suit);
		break;

	default:
		break;
	}

	switch (card->val)
	{
	case (Six) :
	case (Seven) :
	case (Eight) :
	case (Nine) :
				buffer[1] = (char)card->val + '6';
		break;

	case (Ten) :
		buffer[1] = '1';
		buffer[2] = '0';
		break;

	case (Jack) :
		buffer[1] = 'J';
		break;

	case (Queen) :
		buffer[1] = 'Q';
		break;

	case (King) :
		buffer[1] = 'K';
		break;

	case (Ace) :
		buffer[1] = 'A';
		break;

	default:
		break;
	}
}

void printDeck(const Deck *deck)
{
	char buffer[4] = { 0 };

	for (int i = 0; i < deck->size; ++i)
	{
		Card *card = &deck->cards[i];

		memset(buffer, 0, 4);
		getCardText(card, buffer);

		cout << buffer;

		if (i == deck->size / 2)
			cout << " <-----------";

		cout << endl;
	}
}

int compareCard(const Card* firstCard, const Card* secondCard)
{
	char buffer1[4] = { 0 };
	getCardText(firstCard, buffer1);

	char buffer2[4] = { 0 };
	getCardText(secondCard, buffer2);

	if (firstCard->val > secondCard->val)
	{
		cout << buffer1 << " beats " << buffer2 << endl;
		return 1;
	}
	else if (firstCard->val < secondCard->val)
	{
		cout << buffer1 << " was beaten by " << buffer2 << endl;
		return -1;
	}
	else
	{
		cout << buffer1 << " equals to " << buffer2 << endl;
		return 0;
	}
}

