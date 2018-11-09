#pragma once
#include <string>
#include <map>
#include <iostream>
#include <io.h>
#include <fcntl.h>
using namespace std;


enum mast {
	kresti,
	chervy,
	piki,
	bubi
};

enum nom {
	two = 2, three, four, five, six, seven,
	eight, nine, ten, jack,
	queen, king, ace, jocker
};

class Card
{
	mast m;
	nom n;
	static map<nom, string> value;
public:
	Card(mast m1, nom n1);
	mast getCardMast()const { return this->m; }
	nom getCardNom()const { return this->n; }	
	string getSMast()const;
	string getSNom()const;
	string getInfo()const;
};

