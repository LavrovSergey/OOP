#include"menu.h"
using namespace std;


int main(bool isRunning)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	isRunning = true;
	while (isRunning)
	{
		int answer = 0;
		answer = menu_start();
		switch (answer)
		{
		case 0: inf(true, 1); break;
		case 1: inf(true, 2);  break;
		case 2: inf(true, 3); break;
		case 3:  break;
		case 4: system("cls"); cout << "Goodbye!\n__________________"; isRunning = false;
		}

	}
	return 0;
}