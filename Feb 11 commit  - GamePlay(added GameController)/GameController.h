//if and define
#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H


//includes

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

//menu defines
#define MaxNo_Menu 5
#define MaxNo_Menu1 3
#define MaxNo_Menu2 3

class GameController
{
public:
	//
	vector<string> tablehand;
	vector<string> cards;
	vector<string> computerhand;
	vector<string> cpuhand;
	vector<string> deck;
	vector<string> hand;
	vector<string> playerhand;
	//
	vector<char> csuits;
	vector<int> cvalues;
	vector<char> dsuits;
	vector<int> dvalues;
	vector<char> psuits;
	vector<int> pvalues;
	//
	bool allin;
	bool duringhand;
	bool foldc;
	bool foldv;
	bool ngamemenu;
	//
	int bet;
	int cash;
	int cpucash;
	int cpubet;
	int g;
	int pot;
	int random;
	int v;
	int z;
	//
	string arrows;
	string chand;
	string enter;
	string fold;
	string inhand;
	string result;
	string stpidppl;
};

//endif
#endif