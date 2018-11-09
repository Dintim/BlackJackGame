#include "BlackJackConsoleView.h"



BlackJackConsoleView::BlackJackConsoleView()
	:game(0, 0)
{
	cout << "Casino ""Lucky 777"" welcomes you!\nPlease, show your money and set the bet.\n";
	cout << "\n------------------------------\n";
	printAddMoney();	
	printSetBet();
}

void BlackJackConsoleView::start()
{	
	if (game.isGameStart()) {
		int choice = 0;
		while (true) {
			system("cls");
			printScreen();			
			if (game.getPoints(game.getPlayerCards()) == 21) {				
				game.addMoney(game.getBet()*1.5);
				cout << "\nBlack Jack! You win!!! Your money = " << game.getMoney() << endl;
				break;
			}
			cout << "1 - new game\n2 - add money\n3 - set bet\n4 - exit";
			cout << "\n\nYour choice: ";
			cin >> choice;
			if (choice == 4) break;

			if (choice == 1) {
				game.startRound();				
				break;
			}
			if (choice == 2) {
				printAddMoney();
				continue;				
			}
			if (choice == 3) {
				printSetBet();
				continue;				
			}			
		}
	}
	if (!game.isGameStart()) {
		
		int choice = 0;
		while (true) {
			system("cls");			
			printScreenTillStop();
			if (game.getPoints(game.getPlayerCards()) == 21) {				
				game.addMoney(game.getBet()*1.5);
				cout << "\nBlack Jack! You win!!! Your money = " << game.getMoney() << endl;
				break;
			}
			if (game.getPoints(game.getPlayerCards()) > 21) {
				cout << "\nYou lose. Your money = " << game.getMoney() << endl;
				break;
			}
			cout << "1 - get new card\n2 - stop\n3 - exit";
			cout << "\n\nYour choice: ";
			cin >> choice;
			if (choice == 3) break;
			if (choice == 1) {				
				game.pushCardToPlayer();	
			}
			if (choice == 2) {
				//ход передается дилеру				
				system("cls");
				cout << "\nIt's dealer's turn." << endl;
				printScreen();
				if (game.getPoints(game.getDillerCards()) == 21) {
					cout << "\nBlack Jack! You lose. Your money = " << game.getMoney() << endl;
					break;
				}				
				if (game.getPoints(game.getDillerCards()) < 21) {
					while (true) {
						if (game.getPoints(game.getDillerCards()) == 21) {
							cout << "\nBlack Jack! You lose. Your money = " << game.getMoney() << endl;
							break;
						}
						if (game.getPoints(game.getDillerCards()) > 21) {
							game.addMoney(game.getBet()*1.5);
							cout << "\nYou win - dealer loses! Your money = " << game.getMoney() << endl;
							break;
						}
						if (game.getPoints(game.getDillerCards()) > 16) {
							cout << "\nDealer stops. Let's compare. " << endl;
							if (game.getPoints(game.getDillerCards()) > game.getPoints(game.getPlayerCards()))
								cout << "\nDealer wins - you lose. Your money = " << game.getMoney() << endl;
							else if (game.getPoints(game.getDillerCards()) < game.getPoints(game.getPlayerCards())) {
								game.addMoney(game.getBet()*1.5);
								cout << "\nYou win - dealer loses! Your money = " << game.getMoney() << endl;
							}
							else
								cout << "\nDealer's and yours points are equal. Your money = " << game.getBet() + game.getMoney() << endl;
							break;
						}
						printSleepingMode();
						game.pushCardToDiller();
						system("cls");
						printScreen();						
					}					
					break;
				}				
			}			
		}
	}		
	cout << "\nGood bye!\n";	
}

	void BlackJackConsoleView::printScreen()
	{
		cout << "\nYour money = " << game.getMoney();
		cout << "\nYour bet = " << game.getBet();
		cout << "\n\n------------------------------\n";
		cout << "Dealer\'s cards: \n";
		for (size_t i = 0; i < game.getDillerCards().size(); i++)
		{
			cout << game.getDillerCards()[i].getInfo() << endl;
		}
		cout << "\ndealer\'s points = " << game.getPoints(game.getDillerCards());

		cout << "\n\nYour cards: \n";
		for (size_t i = 0; i < game.getPlayerCards().size(); i++)
		{
			cout << game.getPlayerCards()[i].getInfo() << endl;
		}
		cout << "\nYour points = " << game.getPoints(game.getPlayerCards());		
		cout << "\n-----------------\n";		
	}

	void BlackJackConsoleView::printScreenTillStop()
	{
		cout << "\nYour money = " << game.getMoney();
		cout << "\nYour bet = " << game.getBet();
		cout << "\n\n------------------------------\n";
		cout << "Dealer\'s cards: \n";
		cout << game.getDillerCards()[0].getInfo() << endl;
		cout << "hidden card" << endl;
		cout << "\ndealer\'s points = " << game.getDillerFirstPoints(game.getDillerCards()) << endl;		

		cout << "\n\nYour cards: \n";
		for (size_t i = 0; i < game.getPlayerCards().size(); i++)
		{
			cout << game.getPlayerCards()[i].getInfo() << endl;
		}
		cout << "\nYour points = " << game.getPoints(game.getPlayerCards());		
		cout << "\n-----------------\n";
	}

	
	void BlackJackConsoleView::printSleepingMode()
	{
		int cnt = 0;
		cout << "Dealer gets a new card";
		for (size_t i = 0; i < 7; i++)
		{
			Sleep(300);
			for (size_t j = 0; j < cnt; j++)
			{
				cout << ".";
			}
			cnt++;
			if (cnt == 4)
				cnt = 0;
		}
	}

	void BlackJackConsoleView::printAddMoney()
	{
		cout << "\nAdd money: ";
		int m;
		cin >> m;
		game.addMoney(m);
	}

	void BlackJackConsoleView::printSetBet()
	{
		cout << "\nSet bet: ";
		int b;
		cin >> b;
		game.setBet(b);
	}



