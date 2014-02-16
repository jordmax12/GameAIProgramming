//if and define
#ifndef AESTHETICS_H
#define AESTHETICS_H


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


class Aesthetics
{

public:
	Aesthetics();
	void Credits();
	void gotoxy(int, int);
	void header();
	void MainMenu();
	void SetWindow(int, int);
	void text1(string);
	void textattr(int);
};

//end if
#endif