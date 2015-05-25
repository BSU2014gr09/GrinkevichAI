#include <iostream>
#include <cstring>
#include <time.h>
#include "Functions.h"

using namespace std;

int main()
{
	Deck deck;
	initDeck(&deck);

	shuffleDeck(&deck);

	cout << "Deck" << endl;

	printDeck(&deck);

	cout << "------------------------------------\n";
	cout << "Game" << endl;
	
	Card* head1 = &deck.cards[0];
	Card* tail1 = &deck.cards[(deck.size / 2) - 1];
	Card* head2 = &deck.cards[(deck.size / 2)];
	Card* tail2 = &deck.cards[deck.size - 1];

	bool isGameRunning = true;

	while (isGameRunning)
	{
		int cmpResult = compareCard(head1, head2);

		if (cmpResult > 0)
		{
			tail1 = head2;
			head2 = head2->nextCard;

			if (head1 == head2)
			{
				cout << "the second player won" << endl;
				isGameRunning = false;
			}
		}
		else if (cmpResult < 0)
		{
			tail2 = head1;
			head1 = head1->nextCard;

			if (head1 == head2)
			{
				cout << "the first player won" << endl;
				isGameRunning = false;
			}
		}
		else
		{
			Card *tempHead1 = head1->nextCard;
			Card *tempHead2 = head2->nextCard;

			while (true)
			{
				cout << "sub card" << endl;

				int cmpResultSub = compareCard(tempHead1, tempHead2);

				if (cmpResultSub > 0)
				{
					tail1 = tempHead2;
					head2 = tempHead2->nextCard;
					break;
				}
				else if (cmpResultSub < 0)
				{
					tail2 = tempHead1;
					head1 = tempHead1->nextCard;
					break;
				}
				else
				{
					tempHead1 = tempHead1->nextCard;
					tempHead2 = tempHead2->nextCard;

					if (tempHead1 == head2 && tempHead2 != head1)
					{
						cout << "draw!" << endl;
						isGameRunning = false;
						break;
					}
					else if (tempHead1 == head2)
					{
						cout << "first player deck is empty" << endl;
						isGameRunning = false;
						break;
					}
					else if (tempHead2 != head1)
					{
						cout << "second player deck is empty" << endl;
						isGameRunning = false;
						break;
					}
				}
			}
		}
	}

	freeDeck(&deck);
	return 0;
}