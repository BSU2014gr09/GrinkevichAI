#ifndef FUNCTIONS_H
#define FUNCTIONS_H

enum Suit
{
	Hearts = 0, // червы
	Diamonds, // бубны
	Clubs, // трефы
	Spades, // пики

	SuitCount
};

enum Value
{
	Six = 0,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King,
	Ace,

	ValueCount
};

struct Card
{
	Suit suit;
	Value val;

	Card *nextCard;
};

struct Deck
{
	Card *cards;
	int size;
};

void initDeck(Deck *deck);
void shuffleDeck(Deck *deck);
void getCardText(const Card *card, char *buffer);
void printDeck(const Deck *deck);
int compareCard(const Card* firstCard, const Card* secondCard);
void freeDeck(Deck *deck);

#endif