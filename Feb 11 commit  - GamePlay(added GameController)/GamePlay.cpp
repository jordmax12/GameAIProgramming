#include "GameController.h"
#include "Aesthetics.h"
#include "GamePlay.h"
#include "Poker.h"
#include "Checks.h"


GameController GCa = GameController();
GamePlay GPa = GamePlay();

GamePlay::GamePlay() : Omoney(200)
{ //Constructor class, defines Omoney (original money)

}
//clears
void GamePlay::Clear()
{
	
	GCa.playerhand.clear();
	GCa.cards.clear();
	GCa.deck.clear();
	GCa.hand.clear();
	GCa.cpuhand.clear();
	GCa.tablehand.clear();
	GCa.computerhand.clear();
	GCa.pvalues.clear();
	GCa.psuits.clear();
	GCa.cvalues.clear();
	GCa.csuits.clear();
	GCa.dvalues.clear();
	GCa.dsuits.clear();
	GCa.pot = 0;
	GCa.result = "";
	GCa.inhand = "";
}
//resets all game stuff 
void GamePlay::Start() //What user will see first, displays start money (Omoney)
{
	Poker Pa;
	//call the Start method when you want to start a new game
	Clear();// clearing all stored variables
	//GamePlay();
	system("CLS"); // clearing the screen
	GCa.cash = 200; // initializing player cash amount
	GCa.cpucash = 200; // initializing cpu cash amount
	GCa.pot = 0; // initializing pot value to 0
	Pa.createdeck(GCa.deck); // creating a deck of cards
	Pa.shuffle(GCa.deck); // shuffling the deck
	Pa.tablecards(GCa.deck, 8); // creating the table cards passing value for amount of cards
	// begins at 5, so 8 for 3 cards 9 for 4 cards and 10 for 5 cards, should be able to clear tablecards and pass in
	//new value as long as deck is not shuffled so starts at 8, bet 1 add card bet 2 add another, bet 3 determine winner
	Pa.playercard(GCa.deck);// creates the players hand with 2 cards
	Pa.cpucard(GCa.deck);//creates the players hand with 2 cards
	Pa.createhand(GCa.hand, 25, 40); // draw player cards, passing in hand, 5 and 20 stay the same for location
	Pa.createtable(GCa.tablehand, 5, 17);// drawing the table cards passing in table hand, 5 and 7 stay for location
	Game(); // begins the game

}
void GamePlay::Fold()
{
	GCa.result = "You Win!";
	Text();
	GCa.foldc = false;
	thirdhand();
	NewHand();
}
void GamePlay::NewHand()
{
	Poker a;
	//Aesthetics cb;
	GCa.foldc = false;
	//call the NewHand method to begin a new hand without changing the pot and cash values
	Clear();// clearing all stored variables
	GCa.cash = GCa.cash;
	GCa.cpucash = GCa.cpucash;
	system("CLS"); // clearing the screen
	a.createdeck(GCa.deck); // creating a deck of cards
	a.shuffle(GCa.deck); // shuffling the deck
	a.tablecards(GCa.deck, 8); // creating the table cards passing value for amount of cards
	// begins at 5, so 8 for 3 cards 9 for 4 cards and 10 for 5 cards, should be able to clear tablecards and pass in
	//new value as long as deck is not shuffled so starts at 8, bet 1 add card bet 2 add another, bet 3 determine winner
	a.playercard(GCa.deck);// creates the players hand with 2 cards
	a.cpucard(GCa.deck);//creates the players hand with 2 cards
	//createhand(hand, 5, 20); // draw player cards, passing in hand, 5 and 20 stay the same for location
	//createtable(tablehand, 5, 7);// drawing the table cards passing in table hand, 5 and 7 stay for location
	Game(); // begins the game



}
//game menu
int GamePlay::menu()//side menu
{
	char *menu_list[MaxNo_Menu] = { "Check", "Bet 10", "Bet 50", "All In", "Fold" };
	int i,
		xpos[MaxNo_Menu] = { 15, 30, 45, 60, 75 },
		ypos = 53;

	// list the menu
	for (i = 0; i< MaxNo_Menu; ++i)
	{
		Aesthetics a;
		a.gotoxy(xpos[i], ypos);
		a.textattr(3);
		printf("%s", menu_list[i]);
	}

	// make menu available to choose
	i = 0; // set i to 0 to start menu at the begining
	while (1)
	{
		Aesthetics a;
		a.gotoxy(xpos[i], ypos);// set cursor position
		a.textattr(11); // this sets menu item to green text
		printf("%s", menu_list[i]); // print out highlighted item in new color

		/* note : 72 -> UP button
		75 -> RIGHT button
		77 -> LEFT button
		80 -> DOWN button
		*/
		//getting key information switch
		switch (_getch())
		{
			//right
		case 75:
			if (i>0)
			{
				Aesthetics a;
				a.gotoxy(xpos[i], ypos);//set cursor position passing in i
				a.textattr(3); // set text color passing in color
				printf("%s", menu_list[i]); // print the menu item out in new color
				--i;//up key subtract from i
			}
			else
			{
				Aesthetics a;
				a.gotoxy(xpos[i], ypos);// set cursor position passing in i
				a.textattr(3); // reset text color
				printf("%s", menu_list[i]);//print the menu item out in new color
				i = 3;//set i to 2 to start menu from bottom
			}
			break;

			//left
		case 77:
			if (i< MaxNo_Menu - 1)
			{
				Aesthetics a;
				a.gotoxy(xpos[i], ypos);//set cursor position passing in i
				a.textattr(3);//set text color
				printf("%s", menu_list[i]);//print the menu item out in new color
				++i;// down key add to i
			}
			else
			{
				Aesthetics a;
				a.gotoxy(xpos[i], ypos);// set cursor position passing in i
				a.textattr(3); // reset text color
				printf("%s", menu_list[i]);//print the menu item out in new color
				i = 0;//set i to 0 to restart menu
			}
			break;

			//enter
		case 13:
			Poker cd;
			if (i == 0) { return 0; } /*system("cls"); hand.push_back(deck[3]); choosecard(deck,hand);*/
			if (i == 1) { return 10; }
			if (i == 2) { return 50; }
			if (i == 3) {

				//cd.tablecards(deck, 10); 
				return 100;
				AltGame();

			}
			if (i == 4)  { Fold(); return 0; }
			break;
		}
	}
}
//return bet;

//game screen text
void GamePlay::AltGame()
{
	GCa.allin = true;
	Poker a;

	if (GCa.allin)
	{
		//a.tablecards(deck, 10);
		GCa.allin = false;
		Text();
		thirdhand2();
		GCa.duringhand = false;
		Start();

	}


}
void GamePlay::NGameMenu()
{
	Aesthetics cd;
	cd.textattr(8);
	cout << "		 _________ ";
	cd.textattr(12);
	cout << "  _________   ";
	cd.textattr(8);
	cout << "_________   ";
	cd.textattr(12);
	cout << "__________" << endl;
	cd.textattr(8);
	cout << "	        /         \\";
	cd.textattr(12);
	cout << " /         \\ ";
	cd.textattr(8);
	cout << "/         \\ ";
	cd.textattr(12);
	cout << "/          \\" << endl;
	cd.textattr(8);
	cout << "                 Game Over  ";
	cd.textattr(12);
	cout << " Game Over ";
	cd.textattr(8);
	cout << "  Game Over ";
	cd.textattr(12);
	cout << "  Game Over   " << endl;
	cd.textattr(8);
	cout << "                     ,      ";
	cd.textattr(12);
	cout << "    _ _     ";
	cd.textattr(8);
	cout << "     _      ";
	cd.textattr(12);
	cout << "            " << endl;
	cd.textattr(8);
	cout << "                    / \\     ";
	cd.textattr(12);
	cout << "   / ^ \\   ";
	cd.textattr(8);
	cout << "     (_)    ";
	cd.textattr(12);
	cout << "      /\\     " << endl;
	cd.textattr(8);
	cout << "                   (_ _)    ";
	cd.textattr(12);
	cout << "   \\   /   ";
	cd.textattr(8);
	cout << "    (_)_)   ";
	cd.textattr(12);
	cout << "     <  >    " << endl;
	cd.textattr(8);
	cout << "                    /_\\     ";
	cd.textattr(12);
	cout << "    \\ /    ";
	cd.textattr(8);
	cout << "     /_\\    ";
	cd.textattr(12);
	cout << "      \\/     " << endl;
	cd.textattr(8);
	cout << "                            ";
	cd.textattr(12);
	cout << "     `     ";
	cd.textattr(8);
	cout << "            ";
	cd.textattr(12);
	cout << "             " << endl;
	cd.textattr(8);
	cout << "                 Game Over   ";
	cd.textattr(12);
	cout << "Game Over";
	cd.textattr(8);
	cout << "   Game Over";
	cd.textattr(12);
	cout << "   Game Over   " << endl;
	cd.textattr(8);
	cout << "		\\_________/ ";
	cd.textattr(12);
	cout << "\\_________/ ";
	cd.textattr(8);
	cout << "\\_________/";
	cd.textattr(12);
	cout << " \\__________/" << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	char *menu_list[MaxNo_Menu2] = { "New Game", "Main Menu", "Exit" };
	int i,
		xpos = 36,
		ypos[MaxNo_Menu2] = { 15, 18, 21 };
	Aesthetics cb;

	for (i = 0; i< MaxNo_Menu2; ++i)
	{
		cb.gotoxy(xpos, ypos[i]);
		cb.textattr(3);
		printf("%s", menu_list[i]);
	}

	i = 0;
	while (1)
	{
		cb.gotoxy(xpos, ypos[i]);
		cb.textattr(11);
		printf("%s", menu_list[i]);

		/* note : 72 -> UP button
		75 -> RIGHT button
		77 -> LEFT button
		80 -> DOWN button
		*/

		switch (_getch())
		{
			//up
		case 72:
			if (i>0)
			{
				cb.gotoxy(xpos, ypos[i]);
				cb.textattr(3);
				printf("%s", menu_list[i]);
				--i;
			}
			else
			{
				cb.gotoxy(xpos, ypos[i]);
				cb.textattr(3);
				printf("%s", menu_list[i]);
				i = 2;
			}
			break;

			//down
		case 80:
			if (i< MaxNo_Menu2 - 1)
			{
				cb.gotoxy(xpos, ypos[i]);
				cb.textattr(3);
				printf("%s", menu_list[i]);
				++i;
			}
			else
			{
				cb.gotoxy(xpos, ypos[i]);
				cb.textattr(3);
				printf("%s", menu_list[i]);
				i = 0;
			}
			break;

			//enter
		case 13:
			if (i == 0) { GamePlay gp; gp.Start(); }
			if (i == 1) {
				GamePlay gp;
				Aesthetics a;
				gp.Clear();
				system("CLS");
				a.header();
				a.MainMenu();
			};
			if (i == 2) { exit(0); }
			break;
		}
	}
}
void GamePlay::NGameMenu2()

{
	char *menu_list[MaxNo_Menu2] = { "New Game", "Main Menu", "Exit" };
	int i,
		xpos = 36,
		ypos[MaxNo_Menu2] = { 15, 18, 21 };
	Aesthetics cb;

	for (i = 0; i< MaxNo_Menu2; ++i)
	{
		cb.gotoxy(xpos, ypos[i]);
		cb.textattr(3);
		printf("%s", menu_list[i]);
	}

	i = 0;
	while (1)
	{
		cb.gotoxy(xpos, ypos[i]);
		cb.textattr(11);
		printf("%s", menu_list[i]);

		/* note : 72 -> UP button
		75 -> RIGHT button
		77 -> LEFT button
		80 -> DOWN button
		*/

		switch (_getch())
		{
			//up
		case 72:
			if (i>0)
			{
				cb.gotoxy(xpos, ypos[i]);
				cb.textattr(3);
				printf("%s", menu_list[i]);
				--i;
			}
			else
			{
				cb.gotoxy(xpos, ypos[i]);
				cb.textattr(3);
				printf("%s", menu_list[i]);
				i = 2;
			}
			break;

			//down
		case 80:
			if (i< MaxNo_Menu2 - 1)
			{
				cb.gotoxy(xpos, ypos[i]);
				cb.textattr(3);
				printf("%s", menu_list[i]);
				++i;
			}
			else
			{
				cb.gotoxy(xpos, ypos[i]);
				cb.textattr(3);
				printf("%s", menu_list[i]);
				i = 0;
			}
			break;

			//enter
		case 13:
			if (i == 0) { GamePlay gp; gp.Start(); }
			if (i == 1) {
				GamePlay gp;
				Aesthetics a;
				gp.Clear();
				system("cls");
				a.header();
				a.MainMenu();
			};
			if (i == 2) { exit(0); }
			break;
		}
	}
}
void GamePlay::Text()
{
	Aesthetics a;
	GCa.arrows = "[<-- --> arrow keys to move]";
	GCa.enter = "[Hit Enter]";
	a.textattr(11);
	a.gotoxy(33, 38);
	printf("%s", "Your Cards");
	a.textattr(2);
	a.gotoxy(31, 50);
	printf("%s", "Your Money");
	a.gotoxy(42, 50);
	a.textattr(10);
	printf("%i", GCa.cash); // displaying player cash


	a.gotoxy(75, 46);
	a.textattr(11);
	printf("%s", "Current Hand:");
	a.gotoxy(75, 48);
	a.textattr(15);
	cout << GCa.inhand; // displaying what you have in your hand
	a.textattr(14);
	a.gotoxy(33, 1);
	printf("%s", "CPU Cards");
	a.textattr(14);
	a.gotoxy(75, 1);
	printf("%s", "CPU Hand");
	a.gotoxy(75, 3);
	a.textattr(15);
	cout << GCa.chand;
	a.gotoxy(30, 13);
	a.textattr(2);
	printf("%s", "CPU Money");
	a.gotoxy(71, 30);
	a.textattr(15);
	printf("%s", "Instructions:");
	a.gotoxy(71, 33);
	a.textattr(15);
	cout << GCa.arrows;
	a.gotoxy(71, 36);
	a.textattr(15);
	cout << GCa.enter;
	a.gotoxy(40, 13);
	a.textattr(10);
	printf("%i", GCa.cpucash); // displaying cpu cash
	a.textattr(13);
	a.gotoxy(55, 28);
	cout << GCa.stpidppl;
	a.gotoxy(35, 28);
	a.textattr(2);
	printf("%s", "Pot Total");
	a.textattr(8);
	a.gotoxy(37, 33);
	cout << GCa.fold;
	a.gotoxy(45, 28);
	a.textattr(10);
	printf("%i", GCa.pot); // displaying the pot total

	a.textattr(8);
	a.gotoxy(37, 30);
	cout << GCa.result; // displaying if you won or lost the hand






}
// main game logic goes in here 
void GamePlay::Game()
{

	//// need these to redraw the table and split cards once new one is added
	//createtable(tablehand, 5, 7);  // this will create the table, passing in the table hand, always pass in 5 and 7 for location
	//Cards();//creating the hands  
	////

	////determine the hand values
	//v = determinehand(pvalues, psuits);// determine the player hand storing value in v
	//z = determinecpuhand(cvalues, csuits);// determine the cpu hand storing value in z
	////
	////determine the winner do not call this here it should be placed after the 3rd bet
	//determine(); // this method will compare v and z to determine the winner call this at end of game -
	//             // calling here for testing , do not leave in main logic
	////

	////draw text on console, needs to be after the determine hand logic to display
	//Text(); // method to display the text on screen
	////
	////betting logic
	//CpuBetting(z); // method for cpu betting logic, passing in z to determine what it does

	//bet = menu(); // storing the variable returned from menu class to bet
	//Betting(bet); // player betting method passing in the value stored at bet
	////

	Checks ck1;
	Checks ck2;
	Checks ck3;
	Poker a;
	Aesthetics cb;

	int x = 24;
	int y = 3;

	GCa.duringhand = true;



	if (GCa.g == 0)
	{
		v = 0;
		z = 0;
		GCa.result = "";

		system("CLS");
		showc = false;
		shows = false;
		GCa.foldc = false;
		GCa.fold = " ";
		a.createhand(GCa.hand, 25, 40);
		a.createtable(GCa.tablehand, 5, 17);  // this will create the table, passing in the table hand, always pass in 5 and 7 for location
		Cards();//creating the hands  
		a.drawdefaultcpu(GCa.cpuhand, x, y);
		v = ck1.determinehand(GCa.pvalues, GCa.psuits);// determine the player hand storing value in v
		z = ck1.determinecpuhand(GCa.cvalues, GCa.csuits);// determine the cpu hand storing value in z
		if (!showc)
		{
			GCa.chand = "?????";
		}
		if (!shows)
		{
			GCa.stpidppl = " ";
		}
		if (!GCa.foldc)
		{
			GCa.fold = " ";
		}
		GCa.random = rand() % 10;
		if (GCa.random < 3)
		{
			CpuFold(z);
		}
		Text(); // method to display the text on screen
		//
		//betting logic

		// method for cpu betting logic, passing in z to determine what it does
		GCa.bet = menu(); // storing the variable returned from menu class to bet
		Betting(GCa.bet); // player betting method passing in the value stored at bet
		CpuBetting(GCa.bet);


		GCa.g++;
		Game();
	}
	if (GCa.g == 1)
	{
		v = 0;
		z = 0;
		GCa.result = "";
		system("CLS");
		a.createhand(GCa.hand, 25, 40);
		if (!GCa.allin)
		{
			a.tablecards(GCa.deck, 9);
		}
		a.createtable(GCa.tablehand, 5, 17);
		a.createtable(GCa.tablehand, 5, 17);// this will create the table, passing in the table hand, always pass in 5 and 7 for location
		Cards();//creating the hands  
		a.drawdefaultcpu(GCa.cpuhand, x, y);
		v = ck2.determinehand(GCa.pvalues, GCa.psuits);// determine the player hand storing value in v
		z = ck2.determinecpuhand(GCa.cvalues, GCa.csuits);// determine the cpu hand storing value in z
		if (!showc)
		{
			GCa.chand = "?????";
		}
		if (!shows)
		{
			GCa.stpidppl = " ";
		}
		if (!GCa.foldc)
		{
			GCa.fold = " ";
		}
		GCa.random = rand() % 10;
		if (GCa.random < 3)
		{
			CpuFold(z);
		}
		Text(); // method to display the text on screen
		//
		GCa.bet = menu(); // storing the variable returned from menu class to bet
		Betting(GCa.bet); // player betting method passing in the value stored at bet
		CpuBetting(GCa.bet);

		GCa.g = 2;
		//Game();
	}
	if (GCa.g == 2)
	{
		v = 0;
		z = 0;
		GCa.result = "";

		system("CLS");
		a.createhand(GCa.hand, 25, 40);
		if (!GCa.allin)
		{
			a.tablecards(GCa.deck, 10);
		}
		a.createtable(GCa.tablehand, 5, 17);  // this will create the table, passing in the table hand, always pass in 5 and 7 for location
		Cards();//creating the hands  
		a.drawdefaultcpu(GCa.cpuhand, x, y);
		v = ck3.determinehand(GCa.pvalues, GCa.psuits);// determine the player hand storing value in v
		z = ck3.determinecpuhand(GCa.cvalues, GCa.csuits);// determine the cpu hand storing value in z
		if (!showc)
		{
			GCa.chand = "?????";
		}
		if (!shows)
		{
			GCa.stpidppl = " ";
		}
		if (!GCa.foldc)
		{
			GCa.fold = " ";
		}

		GCa.random = rand() % 10;
		if (GCa.random < 3)
		{
			CpuFold(z);
		}
		Text(); // method to display the text on screen
		//
		GCa.bet = menu(); // storing the variable returned from menu class to bet
		Betting(GCa.bet); // player betting method passing in the value stored at bet
		CpuBetting(GCa.bet);

		GCa.g = 3;
		//Game();
	}
	if (GCa.g == 3)
	{
		thirdhand();
	}
}
void GamePlay::thirdhand()
{
	Checks b;
	v = 0;
	z = 0;
	GCa.result = "";
	int x = 24;
	int y = 3;
	showc = true;
	shows = true;
	GCa.stpidppl = "Press Enter To Continue...";

	Checks ck;
	Poker a;
	Aesthetics cb;
	system("CLS");
	a.createhand(GCa.hand, 25, 40);
	a.createtable(GCa.tablehand, 5, 17);  // this will create the table, passing in the table hand, always pass in 5 and 7 for location
	Cards();
	a.drawcpucard(GCa.cpuhand, x, y);//creating the hands  
	v = ck.determinehand(GCa.pvalues, GCa.psuits);// determine the player hand storing value in v
	z = ck.determinecpuhand(GCa.cvalues, GCa.csuits);// determine the cpu hand storing value in z

	if (GCa.foldv)
	{
		v = 0;
	}
	ck.determine(v, z);
	if (showc)
	{
		GCa.chand = GCa.chand;
	}
	if (shows)
	{
		GCa.stpidppl = GCa.stpidppl;
	}
	if (!GCa.foldc)
	{
		GCa.fold = " ";
	}
	if (GCa.foldc == true)
	{
		//fold = "YOU LOSE!";
	}
	Text(); // method to display the text on screen
	cin.get();
	cout << GCa.chand;
	GCa.g = 0;
	GCa.duringhand = true;
	if (!GCa.duringhand)
	{
		cb.text1("You Ran Out of Money!");
		cin.get();
		system("CLS");
		Clear();
		NGameMenu();
	}
	if (GCa.cash == 0)
	{
		Clear();
		system("CLS");
		NGameMenu();
	}
	if (GCa.cpucash == 0)
	{
		system("CLS");
		Aesthetics a;
		a.textattr(13);
		cout << " " << endl;
		cout << " " << endl;
		cout << "               /////////////////////////////////////////////////" << endl;
		cout << "               // "; a.textattr(3); cout << "*         *  *           *        *       * "; a.textattr(13); cout << "//" << endl;
		cout << "               //    "; a.textattr(3); cout << " * "; a.textattr(6); cout << "    CPU RAN OUT OF MONEY!         "; a.textattr(3); cout << "*   "; a.textattr(13); cout << "//" << endl;
		cout << "               // "; a.textattr(3); cout << "*                                     *     "; a.textattr(13); cout << "//" << endl;
		cout << "               //   "; a.textattr(3); cout << "*          "; a.textattr(6); cout << "You Win!                     "; a.textattr(3); cout << "* "; a.textattr(13); cout << "//" << endl;
		cout << "               //  "; a.textattr(3); cout << "*   "; a.textattr(3); cout << "*                             *    *   "; a.textattr(13); cout << "//" << endl;
		a.textattr(13); cout << "               //"; a.textattr(3); cout << "*********************************************"; a.textattr(13); cout << "//" << endl;
		a.textattr(13); cout << "               /////////////////////////////////////////////////" << endl;
		cout << " " << endl;
		cout << " " << endl;
		cout << " " << endl;
		NGameMenu2();
	}
	NewHand();

}
void GamePlay::thirdhand2()
{
	Checks b;
	v = 0;
	z = 0;
	GCa.result = "";
	int x = 24;
	int y = 3;
	showc = true;
	shows = true;
	GCa.stpidppl = "Press Enter To Continue...";

	Checks ck;
	Poker a;
	Aesthetics cb;
	system("CLS");
	a.tablecards(GCa.deck, 10);
	a.createhand(GCa.hand, 25, 40);
	a.createtable(GCa.tablehand, 5, 17);  // this will create the table, passing in the table hand, always pass in 5 and 7 for location
	Cards();
	a.drawcpucard(GCa.cpuhand, x, y);//creating the hands  
	v = ck.determinehand(GCa.pvalues, GCa.psuits);// determine the player hand storing value in v
	z = ck.determinecpuhand(GCa.cvalues, GCa.csuits);// determine the cpu hand storing value in z

	if (GCa.foldv)
	{
		v = 0;
	}
	ck.determine(v, z);
	if (showc)
	{
		GCa.chand = GCa.chand;
	}
	if (shows)
	{
		GCa.stpidppl = GCa.stpidppl;
	}
	if (!GCa.foldc)
	{
		GCa.fold = " ";
	}
	if (GCa.foldc == true)
	{
		//fold = "YOU LOSE!";
	}
	Text(); // method to display the text on screen
	cout << GCa.chand;
	cin.get();
	GCa.g = 0;
	GCa.cash = 0;
	if (GCa.cash == 0)
	{
		Clear();
		system("CLS");
		NGameMenu();
	}
	NewHand();

}


//creating the cards in hand
void GamePlay::Cards()
{
	Poker a;
	a.playertest(GCa.tablehand, GCa.hand);
	a.playerval(GCa.playerhand);
	a.playersuit(GCa.playerhand);

	a.computertest(GCa.tablehand, GCa.cpuhand);
	a.computerval(GCa.computerhand);
	a.computersuit(GCa.computerhand);
}
//bet system stuff in here
void GamePlay::Betting(int bet)
{
	if (GCa.cash > 0)
	{
		if (bet == 100)
		{

			bet = GCa.cash;
			GCa.cash = GCa.cash - bet;
			GCa.pot = GCa.pot + bet;
		}
		else if (bet == 50)
		{
			bet = 50;
			GCa.cash = GCa.cash - bet;
			GCa.pot = GCa.pot + bet;
		}
		else if (bet == 10)
		{
			//need to turn on for actual game
			bet = 10;
			GCa.cash = GCa.cash - bet;
			GCa.pot = GCa.pot + bet;

			////DO NOT LEAVE THIS IN
			//Start();
		}
		else if (bet == 0)
		{

			bet = 0;
			GCa.cash = GCa.cash - bet;
			GCa.pot = GCa.pot + bet;
		}

	}
	else
	{
		system("CLS");

	}

}
void GamePlay::CpuBetting(int z)
{
	if (GCa.cpucash > 0)
	{
		if (z >= 90)
		{

			GCa.cpubet = GCa.cpucash;
			GCa.cpucash = GCa.cpucash - GCa.cpubet;
			GCa.pot = GCa.pot + GCa.cpubet;

		}
		else if (z < 90 && z >= 50)
		{
			GCa.cpubet = 50;
			GCa.cpucash = GCa.cpucash - GCa.cpubet;
			GCa.pot = GCa.pot + GCa.cpubet;

		}
		else if (z < 50 && z >= 6)
		{
			GCa.cpubet = 10;
			GCa.cpucash = GCa.cpucash - GCa.cpubet;
			GCa.pot = GCa.pot + GCa.cpubet;
		}
		else if (z < 5)
		{
			GCa.cpubet = 0;
			GCa.cpucash = GCa.cpucash - GCa.cpubet;
			GCa.pot = GCa.pot + GCa.cpubet;
			//thirdhand();
		}
	}
}
void GamePlay::CpuFold(int z)
{
	Poker a;
	if (GCa.cpucash > 0)
	{
		if (z < 5)
		{
			GCa.cpubet = 0;
			GCa.cpucash = GCa.cpucash - GCa.cpubet;
			GCa.pot = GCa.pot + GCa.cpubet;
			a.tablecards(GCa.deck, 10);

			//thirdhand();
			Fold();
		}
	}

}