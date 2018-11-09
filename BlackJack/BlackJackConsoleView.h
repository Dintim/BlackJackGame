#pragma once
#include <iostream>
#include <Windows.h>
#include "BlackJack.h"
using namespace std;

class BlackJackConsoleView
{
	BlackJack game;
public:
	BlackJackConsoleView();
	void start();
	void printScreen();
	void printScreenTillStop();
	void printSleepingMode();
	void printAddMoney();
	void printSetBet();
};

