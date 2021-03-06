#include "deck.h"


deck::deck()
{	
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 13; j++)
		{
			cards.push_back(Card((mast)i, (nom)(j + 2)));
		}
	}
	for (size_t i = 0; i < 3; i++)
	{
		random_shuffle(begin(cards), end(cards));
	}
}

void deck::shuffle()
{
	srand(time(NULL));
	int ran = rand() % +8;
	for (size_t i = 0; i < ran; i++)
	{
		random_shuffle(begin(cards), end(cards));
	}	
}

Card deck::getNextCard()
{
	Card c = cards[0];
	cards.erase(begin(cards));
	return c;
}

void deck::addCard(const Card & c)
{
	cards.push_back(c);
}
