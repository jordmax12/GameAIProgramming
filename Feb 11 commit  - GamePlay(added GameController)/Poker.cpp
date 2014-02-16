#include "Poker.h"

using namespace std;

void Poker::createdeck(vector<string>& deck)
{
	const int suits = 5;
	const int values = 13;
	string cardValue[] = { "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A" };
	string cardSuit[] = { "H", "D", "S", "C", "CP" };
	string card;

	for (int i = 0; i < suits; ++i)
	{
		for (int j = 0; j < values; ++j)
		{
			card = cardValue[j] + cardSuit[i];
			deck.push_back(card);
		}
	}

}

