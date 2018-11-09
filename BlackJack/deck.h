#pragma once
#include "Card.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <time.h>

class deck
{
	vector<Card> cards;
public:	
	deck();
	//void print();
	void shuffle();
	Card getNextCard();
	int getCountCards() const {	return cards.size(); };
	void addCard(const Card&c);
};

