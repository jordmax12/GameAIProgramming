void Aesthetics::gotoxy(int x, int y)
{
	COORD Coord;
	Coord.X = x;
	Coord.Y = y;

	SetConsoleCursorPosition(con, Coord);
}
void Aesthetics::textattr(int color)
{
	SetConsoleTextAttribute(con, color);
}
void Aesthetics::text1(string words)
{


	system("cls");
	gotoxy(1, 20);
	textattr(15);
	printf("%s", words.c_str());

}
void Aesthetics::text2(string words)
{
	gotoxy(30, 20);
	textattr(15);
	printf("%s", words.c_str());
}
void Aesthetics::text3(string words)

{


	//system("cls");
	gotoxy(50, 28);
	textattr(3);
	printf("%s", words.c_str());
	/*gotoxy(50, 20);
	textattr(15);
	*///printf("%i", value);


}
void Aesthetics::text4(string words, int value)

{


	system("cls");
	gotoxy(10, 19);
	textattr(15);
	printf("%s", words.c_str());
	/*gotoxy(50, 20);
	textattr(15);
	*///printf("%i", value);


}
//

//setting window size and hiding cursor
void Aesthetics::SetWindow(int Width, int Height)
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle
	SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size
	SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size


	HANDLE hConsoleOutput;
	CONSOLE_CURSOR_INFO structCursorInfo;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleCursorInfo(hConsoleOutput, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hConsoleOutput, &structCursorInfo);

}
//

//main stuff
Aesthetics::Aesthetics()
{
	//system("cls");
	//SetWindow(85, 35);

	//header();
	//MainMenu();
}
void Aesthetics::header()
{
	textattr(8);
	cout << "		  _________ ";
	textattr(12);
	cout << "  _________   ";
	textattr(8);
	cout << "_________   ";
	textattr(12);
	cout << "__________" << endl;
	textattr(8);
	cout << "		 /         \\";
	textattr(12);
	cout << " /         \\ ";
	textattr(8);
	cout << "/         \\ ";
	textattr(12);
	cout << "/          \\" << endl;
	textattr(8);
	cout << "                 |A        | ";
	textattr(12);
	cout << "|A        | ";
	textattr(8);
	cout << "|A        | ";
	textattr(12);
	cout << "|A         |" << endl;
	textattr(8);
	cout << "                 |    ,    | ";
	textattr(12);
	cout << "|   _ _   | ";
	textattr(8);
	cout << "|    _    | ";
	textattr(12);
	cout << "|          |" << endl;
	textattr(8);
	cout << "                 |   / \\   | ";
	textattr(12);
	cout << "|  / ^ \\  |";
	textattr(8);
	cout << " |   (_)   |";
	textattr(12);
	cout << " |    /\\    |" << endl;
	textattr(8);
	cout << "                 |  (_ _)  | ";
	textattr(12);
	cout << "|  \\   /  |";
	textattr(8);
	cout << " |  (_)_)  |";
	textattr(12);
	cout << " |   <  >   |" << endl;
	textattr(8);
	cout << "                 |   /_\\   | ";
	textattr(12);
	cout << "|   \\ /   |";
	textattr(8);
	cout << " |   /_\\   |";
	textattr(12);
	cout << " |    \\/    |" << endl;
	textattr(8);
	cout << "                 |         | ";
	textattr(12);
	cout << "|    `    |";
	textattr(8);
	cout << " |         |";
	textattr(12);
	cout << " |          |" << endl;
	textattr(8);
	cout << "                 |        A| ";
	textattr(12);
	cout << "|        A|";
	textattr(8);
	cout << " |        A|";
	textattr(12);
	cout << " |         A|" << endl;
	textattr(8);
	cout << "		 \\_________/ ";
	textattr(12);
	cout << "\\_________/ ";
	textattr(8);
	cout << "\\_________/";
	textattr(12);
	cout << " \\__________/" << endl;
	cout << "" << endl;
	textattr(15);
	cout << "                           C++ I Final : Console Poker" << endl;
	cout << " " << endl;
	cout << "                           By: Jordan Max & Neil Inglese" << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;

}
void Aesthetics::MainMenu()
{
	char *menu_list[MaxNo_Menu1] = { "Start", "Credits", "Exit" };
	int i,
		xpos = 36,
		ypos[MaxNo_Menu1] = { 15, 18, 21 };

	for (i = 0; i< MaxNo_Menu1; ++i)
	{
		gotoxy(xpos, ypos[i]);
		textattr(3);
		printf("%s", menu_list[i]);
	}

	i = 0;
	while (1)
	{
		gotoxy(xpos, ypos[i]);
		textattr(11);
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
				gotoxy(xpos, ypos[i]);
				textattr(3);
				printf("%s", menu_list[i]);
				--i;
			}
			else
			{
				gotoxy(xpos, ypos[i]);
				textattr(3);
				printf("%s", menu_list[i]);
				i = 2;
			}
			break;

			//down
		case 80:
			if (i< MaxNo_Menu1 - 1)
			{
				gotoxy(xpos, ypos[i]);
				textattr(3);
				printf("%s", menu_list[i]);
				++i;
			}
			else
			{
				gotoxy(xpos, ypos[i]);
				textattr(3);
				printf("%s", menu_list[i]);
				i = 0;
			}
			break;

			//enter
		case 13:
			if (i == 0) { GamePlay gp;  gp.Start(); }
			if (i == 1) { Aesthetics cd; cd.Credits(); }
			if (i == 2) { exit(0); }
			break;
		}
	}

}
void Aesthetics::Credits()
{
	system("cls");
	textattr(8);
	cout << "		 _________ ";
	textattr(12);
	cout << "  _________   ";
	textattr(8);
	cout << "_________   ";
	textattr(12);
	cout << "__________" << endl;
	textattr(8);
	cout << "	        /         \\";
	textattr(12);
	cout << " /         \\ ";
	textattr(8);
	cout << "/         \\ ";
	textattr(12);
	cout << "/          \\" << endl;
	textattr(8);
	cout << "                 Jordan Max ";
	textattr(12);
	cout << " A          ";
	textattr(8);
	cout << " K          ";
	textattr(12);
	cout << "Neil Inglese" << endl;
	textattr(8);
	cout << "                     ,      ";
	textattr(12);
	cout << "    _ _     ";
	textattr(8);
	cout << "     _      ";
	textattr(12);
	cout << "            " << endl;
	textattr(8);
	cout << "                    / \\     ";
	textattr(12);
	cout << "   / ^ \\   ";
	textattr(8);
	cout << "     (_)    ";
	textattr(12);
	cout << "      /\\     " << endl;
	textattr(8);
	cout << "                   (_ _)    ";
	textattr(12);
	cout << "   \\   /   ";
	textattr(8);
	cout << "    (_)_)   ";
	textattr(12);
	cout << "     <  >    " << endl;
	textattr(8);
	cout << "                    /_\\     ";
	textattr(12);
	cout << "    \\ /    ";
	textattr(8);
	cout << "     /_\\    ";
	textattr(12);
	cout << "      \\/     " << endl;
	textattr(8);
	cout << "                            ";
	textattr(12);
	cout << "     `     ";
	textattr(8);
	cout << "            ";
	textattr(12);
	cout << "             " << endl;
	textattr(8);
	cout << "                 jdmdev.net  ";
	textattr(12);
	cout << "         A ";
	textattr(8);
	cout << "          K";
	textattr(12);
	cout << " neildev.net " << endl;
	textattr(8);
	cout << "		\\_________/ ";
	textattr(12);
	cout << "\\_________/ ";
	textattr(8);
	cout << "\\_________/";
	textattr(12);
	cout << " \\__________/" << endl;
	cout << "" << endl;
}