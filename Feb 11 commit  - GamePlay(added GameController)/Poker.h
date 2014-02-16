//if and define
#ifndef POKER_H
#define POKER_H

//includes
#include "GameController.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <conio.h>
#include <algorithm>
#include <Windows.h>
#include <stdio.h>
#include <vector>
#include <ctime>



//namespace
using namespace std;

class Poker
{
public:
	// C(o)
	void computertest(vector<string>, vector<string>);
	void computersuit(vector<string>);
	void computerval(vector<string>);
	//C(p)
	void cpucard(vector<string>& deck);
	//C(r)
	void createdeck(vector<string>& deck);
	//C(p)
	void cpucard(vector<string>& deck);
	void createhand(vector<string> hand, int, int);
	void createtable(vector<string>, int, int);
	//D
	void draw1card(string, vector<string>, int, int, int);
	void drawcpucard(vector<string>, int, int);
	void drawcpucard2(vector<string>, int, int);
	void drawdefaultcpu(vector<string>, int, int);
	//P
	void playercard(vector<string>& deck);
	void playertest(vector<string>, vector<string>);
	void playerval(vector<string>);
	void playersuit(vector<string>);
	//S
	void shuffle(vector<string>& deck);
	//T
	void tablecards(vector<string>& deck, int);
	//
	vector<string> suits(vector<string>, string);

};


//endif
#endif