//if and define
#ifndef GAMEPLAY_H
#define GAMEPLAY_H


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

class GamePlay
{
public:
	//BOOLS
	bool lose;
	bool showc;
	bool shows;
	bool win;
	//INTS
	int earn;
	int loseM;
	int money;
	int Omoney;
	int Tmoney;
	int v;
	int z;
	// 
	int menu();
	//
	void AltGame();
	void AltNext();
	void Betting(int bet);
	void Cards();
	void checkhands();
	void Clear();
	void CpuBetting(int x);
	void CpuFold(int);
	void Flow();
	void Fold();
	void Game();
	void NGameMenu();
	void NGameMenu2();
	void NewHand();
	void Start();
	void Text();
	void thirdhand();
	void thirdhand2();
	//
	GamePlay();
};



//endif
#endif