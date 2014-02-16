Checks::Checks()
{
}

int Checks::ispair(vector<int> dvalues)
{
	vector<int> test;
	int z;
	sort(dvalues.begin(), dvalues.end());

	for (z = 0; z < dvalues.size(); z++)
	{
		for (int j = 0; j < dvalues.size(); j++)
		{
			if (j != z)
			{
				if (dvalues[z] == dvalues[j])
				{
					test.push_back(dvalues[z]);

				}
			}
		}
	} // end loop.
	if (test.size() >= 2 && test.size() < 4)
	{
		return 1;
	}

	if (test.size() >= 4 && test.size() <= 6)
	{
		return 2;
	}

	else
		return 0;
}//working//working//working
//working
int Checks::flush(vector<char> dsuits)
{
	vector<int> test;
	test.clear();
	int z;
	sort(dsuits.begin(), dsuits.end());
	int j;

	for (z = 0; z < dsuits.size(); z++)
	{
		for (int j = 1; j < dsuits.size(); j++)
		{
			if (j != z)
			{
				if (dsuits[z] == dsuits[j])
				{
					test.push_back(dvalues[j]);

				}
			}
		}
	} // end loop.
	if (test.size() >= 20 && test.size() <= 35)
	{
		return 1;
	}
	else
		return 0;


	//if ((dsuits[0] == dsuits[1]) && (dsuits[0] == dsuits[2]) && (dsuits[0] == dsuits[3]) && (dsuits[0] == dsuits[4]))
	//{
	//	return 1;
	//}

	return 0;


}
//working
int Checks::straight(vector<int> dvalues)
{
	//vector<int> test;
	//test.clear();
	//int z;
	//sort(dvalues.begin(), dvalues.end());
	//int j;

	//for (z = 0; z < dvalues.size(); z++)
	//{
	//	for (int j = 0; j < dvalues.size(); j++)
	//	{
	//		if (j != z)
	//		{
	//			if (dvalues[z] - dvalues[j] == 1)
	//			{
	//				test.push_back(dvalues[j]);

	//			}
	//		}
	//	}
	//} // end loop.
	//if (test.size() == 7)
	//{
	//	return 1;
	//}
	//else
	//	return 0;
	sort(dvalues.begin(), dvalues.end());

	if (dvalues.size() == 5)
	{
		if ((dvalues[4] - dvalues[3] == 1) && (dvalues[3] - dvalues[2] == 1) && (dvalues[2] - dvalues[1] == 1) && (dvalues[1] - dvalues[0] == 1))
			return 1;
		else
			return 0;
	}
	if (dvalues.size() == 6)
	{
		if ((dvalues[4] - dvalues[3] == 1) && (dvalues[3] - dvalues[2] == 1) && (dvalues[2] - dvalues[1] == 1) && (dvalues[1] - dvalues[0] == 1))
			return 1;
		else if ((dvalues[5] - dvalues[4] == 1) && (dvalues[4] - dvalues[3] == 1) && (dvalues[3] - dvalues[2] == 1) && (dvalues[2] - dvalues[1] == 1))
			return 1;
		else
			return 0;
	}
	if (dvalues.size() == 7)
	{
		if ((dvalues[4] - dvalues[3] == 1) && (dvalues[3] - dvalues[2] == 1) && (dvalues[2] - dvalues[1] == 1) && (dvalues[1] - dvalues[0] == 1))
			return 1;
		else if ((dvalues[5] - dvalues[4] == 1) && (dvalues[4] - dvalues[3] == 1) && (dvalues[3] - dvalues[2] == 1) && (dvalues[2] - dvalues[1] == 1))
			return 1;
		else if ((dvalues[6] - dvalues[5] == 1) && (dvalues[5] - dvalues[4] == 1) && (dvalues[4] - dvalues[3] == 1) && (dvalues[3] - dvalues[2] == 1))
			return 1;
		else
			return 0;
	}
} // end straight.
//working
int Checks::threeofakind(vector<int> dvalues)
{

	vector<int> test;
	test.clear();
	int z;
	int j;
	sort(dvalues.begin(), dvalues.end());

	for (z = 0; z < dvalues.size(); z++)
	{
		for (int j = 1; j < dvalues.size(); j++)
		{
			if (j != z)
			{
				if (dvalues[z] == dvalues[j])
				{
					test.push_back(dvalues[z]);

				}
			}
		}
	} // end loop.
	if (test.size() >= 6 && test.size() <= 9)
	{
		return 1;
	}

	else
		return 0;
	//sort(dvalues.begin(), dvalues.end());

	//if ((dvalues[0] == dvalues[1]) && (dvalues[1] == dvalues[2]))
	//	return 1;
	//else if ((dvalues[1] == dvalues[2]) && (dvalues[2] == dvalues[3]))
	//	return 1;
	//else if ((dvalues[2] == dvalues[3]) && (dvalues[3] == dvalues[4]))
	//	return 1;
	//else
	//	return 0;
}//working
//working 
int Checks::fourofakind(vector<int> dvalues)
{
	vector<int> test;
	test.clear();
	int z;
	sort(dvalues.begin(), dvalues.end());
	int j;

	for (z = 0; z < dvalues.size(); z++)
	{
		for (int j = 1; j < dvalues.size(); j++)
		{
			if (j != z)
			{
				if (dvalues[z] == dvalues[j])
				{
					test.push_back(dvalues[j]);

				}
			}
		}
	} // end loop.
	if (test.size() >= 12 && test.size() <= 22)
	{
		return 1;
	}
	else
		return 0;


	//sort(dvalues.begin(), dvalues.end());

	//if (((dvalues[0] == dvalues[1]) && ((dvalues[0] == dvalues[2])) && ((dvalues[0] == dvalues[3])) || ((dvalues[1] == dvalues[2])) && ((dvalues[1] == dvalues[3])) && ((dvalues[1] == dvalues[4]))))
	//	return 1;
	//else
	//	return 0;

}
//working
int Checks::fullhouse(vector<int> dvalues)
{
	vector<int> test;
	test.clear();
	int z;
	sort(dvalues.begin(), dvalues.end());
	int j;

	for (z = 0; z < dvalues.size(); z++)
	{
		for (int j = 0; j < dvalues.size(); j++)
		{
			if (j != z)
			{
				if (dvalues[z] == dvalues[j])
				{
					test.push_back(dvalues[j]);

				}
			}
		}
	} // end loop.
	if (test.size() >= 8 && test.size() <= 12)
	{
		return 1;
	}
	else
		return 0;


	//sort(dvalues.begin(), dvalues.end());

	//if ((dvalues[0] == dvalues[1]) && (dvalues[1] == dvalues[2]) && (dvalues[3] == dvalues[4]))
	//	return 1;
	//else if ((dvalues[1] == dvalues[2]) && (dvalues[2] == dvalues[3]) && (dvalues[0] == dvalues[4]))
	//	return 1;
	//else if ((dvalues[2] == dvalues[3]) && (dvalues[3] == dvalues[4]) && (dvalues[0] == dvalues[1]))
	//	return 1;
	//else
	return 0;
}
//

// determing hand checks
int Checks::determinehand(vector<int >pvalues, vector<char>psuits)
{
	dvalues.empty();
	dsuits.empty();
	dvalues = pvalues;
	dsuits = psuits;
	if (foldc = true)
	{
		inhand = "FOLD!";
	}

	//gotoxy(30, 20);          // checking the hands starting with the highest possible hand and going down from there.
	sort(dvalues.begin(), dvalues.end());
	if ((flush(dsuits)) && (straight(dvalues)))
	{


		if (dvalues[7] = 14)
		{
			inhand = "Royal Flush!!";
			return 100;
		}
		else
		{
			inhand = "Straight Flush!!";
			return 90;
		}
	}

	else if (flush(dsuits) == 1)
	{
		inhand = "Flush!!";
		return 80;

	}
	else if (straight(dvalues) == 1)
	{
		inhand = "Straight!!";
		return 70;

	}

	else if (fourofakind(dvalues) == 1)
	{
		inhand = "Four of a Kind!!";
		return 60;

	}
	else if (fullhouse(dvalues) == 1)
	{
		inhand = "Fullhouse!!";
		return 50;

	}

	else if (threeofakind(dvalues) == 1)
	{
		inhand = "Three of a Kind!!";
		return 40;

	}
	else if (ispair(dvalues) == 2)
	{
		inhand = "Two Pair!!";
		return 30;
	}
	else if (ispair(dvalues) == 1)
	{
		inhand = "Pair!!";
		return 20;

	}





	else {

		inhand = "Absolutely Nothing!!";


		return dvalues.back();
	}
}
int Checks::determinecpuhand(vector<int> cvalues, vector<char>csuits)
{
	//gotoxy(30, 20);          // checking the hands starting with the highest possible hand and going down from there.
	dvalues.empty();
	dsuits.empty();

	dvalues = cvalues;
	dsuits = csuits;

	sort(dvalues.begin(), dvalues.end());
	if ((flush(dsuits)) && (straight(dvalues)))
	{


		if (dvalues[4] == 14)
		{
			chand = " ROYAL FLUSH!!!";
			return 100;
		}
		else
		{
			chand = "STRAIGHT FLUSH!";
			return 90;
		}
	}

	else if (flush(dsuits) == 1)
	{
		chand = "Flush!";
		return 80;

	}
	else if (straight(dvalues) == 1)
	{
		chand = "Straight!";
		return 70;

	}

	else if (fourofakind(dvalues) == 1)
	{
		chand = "Four of a Kind!";
		return 60;

	}
	else if (fullhouse(dvalues) == 1)
	{
		chand = "Full House!";
		return 50;

	}

	else if (threeofakind(dvalues) == 1)
	{
		chand = "Three of a Kind!";
		return 40;

	}
	else if (ispair(dvalues) == 2)
	{
		chand = "Two Pair";
		return 30;
	}
	else if (ispair(dvalues) == 1)
	{
		chand = "Pair!";
		return 20;

	}

	else if (ispair(dvalues) == 0)
	{

		chand = "Absolutely nothing!";
		return 4;

	}
	return dvalues.back();
}
//

//determine the winner
void Checks::determine(int v, int z)
{
	if (v == z)
	{
		result = "Split Pot";
		int pot1 = pot / 2;
		int pot2 = pot;
		cash = cash + pot1;
		cpucash = cpucash + pot1;
	}
	if (v > z)
	{
		result = "You Win";
		cash = cash + pot;
	}
	if (v < z)
	{
		result = "You Lose";
		cpucash = cpucash + pot;
	}

}
void Checks::FoldValue()
{
	if (foldv)
	{
		cpucash = cpucash + pot;
		cash = cash - bet;
	}
}
void Checks::FoldValueC()
{
	if (foldv)
	{
		cash = cash + pot;
		cpucash = cpucash - bet;
	}
}