#include "Aesthetics.h"
#include "GameController.h"


using namespace std;


int main()
{
	Aesthetics a;
	system("CLS");
	a.SetWindow(100, 55);

	a.header();
	a.MainMenu();
}