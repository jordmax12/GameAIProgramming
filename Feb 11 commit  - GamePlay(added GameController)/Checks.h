//if and define
#ifndef CHECKS_H
#define CHECKS_H

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

class Checks
{
public:
	int determinecpuhand(vector<int>cvalues, vector<char>csuits);
	int determinehand(vector<int>pvalues, vector<char>psuits);
	int flush(vector<char> dsuits);
	int fourofakind(vector<int>dvalues);
	int fullhouse(vector<int>dvalues);
	int ispair(vector<int> dvalues);
	int straight(vector<int> dvalues);
	int threeofakind(vector<int>dvalues);
	//
	void determine(int v, int z);
	void FoldValue();
	void FoldValueC();
	//
	Checks();
};


//endif
#endif