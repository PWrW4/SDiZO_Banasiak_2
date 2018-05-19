#include "stdafx.h"
#include "menu.h"
#include <iostream>


void menu::mainMenu()
{
	int decision = 0;

	do
	{
		std::cout<<mainMenuStr<<std::endl;
		std::cin >> decision;
		switch (decision)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		default:
			break;
		}
	}
	while (decision);

}

menu::menu()
{
	mainMenu();
}


menu::~menu()
{
}
