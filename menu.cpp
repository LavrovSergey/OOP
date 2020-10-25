#include "menu.h"
int menu_inf(int a) {
	int key = 0;
	int code;
	do {
		system("cls");
		key = (key + 4) % 4;
		if (key == 0) cout << "-> INT" << endl;
		else  cout << "   INT" << endl;
		if (key == 1) cout << "-> DOUBLE" << endl;
		else  cout << "   DOUBLE" << endl;
		if (key == 2) cout << "-> STRING" << endl;
		else  cout << "   STRING" << endl;
		if (key == 3) cout << "-> Выход" << endl;
		else  cout << "   Выход" << endl;
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}
int menu_console() {
	int key = 0;
	int code;
	do {
		system("cls");
		key = (key + 55) % 55;
		if (key == 0) cout << "-> Записать" << endl;
		else  cout << "   Записать" << endl;
		if (key == 1) cout << "-> Вывести InOrder" << endl;
		else  cout << "   Вывести InOrder" << endl;
		if (key == 2) cout << "-> Вывести PreOrder" << endl;
		else  cout << "   Вывести PreOrder" << endl;
		if (key == 3) cout << "-> Вывести PostOrder" << endl;
		else  cout << "   Вывести PostOrder " << endl;
		if (key == 4) cout << "-> Найти по пути" << endl;
		else  cout << "   Найти по пути" << endl;
		if (key == 5) cout << "-> Найти" << endl;
		else  cout << "   Найти" << endl;
		if (key == 6) cout << "-> Удалить по значению" << endl;
		else  cout << "   Удалить по значению" << endl;
		if (key == 7) cout << "-> Удалить по id" << endl;
		else  cout << "   Удалить по id" << endl;
		if (key == 8) cout << "-> Удалить по отцу" << endl;
		else  cout << "   Удалить по отцу" << endl;
		if (key == 9) cout << "-> Записать vector" << endl;
		else  cout << "   Записать vector" << endl;
		if (key == 10) cout << "-> Вывести InOrder vector" << endl;
		else  cout << "   Вывести InOrder vector" << endl;
		if (key == 11) cout << "-> Вывести PreOrder vector" << endl;
		else  cout << "   Вывести PreOrder vector" << endl;
		if (key == 12) cout << "-> Вывести PostOrder vector" << endl;
		else  cout << "   Вывести PostOrder vector" << endl;
		if (key == 13) cout << "-> Найти по пути vector " << endl;
		else  cout << "   Найти по пути vector" << endl;
		if (key == 14) cout << "-> Найти vector" << endl;
		else  cout << "   Найти vector" << endl;
		if (key == 15) cout << "-> Удалить vector по значению" << endl;
		else  cout << "   Удалить vector по значению" << endl;
		if (key == 16) cout << "-> Удалить vector по id" << endl;
		else  cout << "   Удалить int vector id" << endl;
		if (key == 17) cout << "-> Удалить vector по отцу" << endl;
		else  cout << "   Удалить vector по отцу" << endl;
		if (key == 54) cout << "-> Выход" << endl;
		else  cout << "   Выход" << endl;
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}
int menu1(bool isRunning, int a, int b)
{
		Functions1<int> i;
		Functions1<int> i_v;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	isRunning = true;
	while (isRunning)
	{
		int answer = 0;
		answer = menu_console();

		switch (answer)
		{
		case 0: i.AddLeaf(a); break;
		case 1: i.PrintInOrder(a); break;
		case 2: i.PrintPreOrder(a); break;
		case 3: i.PrintPostOrder(a); break;
		case 4: i.FindByTheWay(a); break;
		case 5: i.Find(a); break;
		case 6: i.PrintInOrder(a); i.Delete(a, 1);  break;
		case 7: i.PrintInOrder(a); i.Delete(a, 2);  break;
		case 8: i.PrintInOrder(a); i.Delete(a, 3);  break;
		case 9: i_v.AddLeaf_vect(a); break;
		case 10: i_v.PrintInOrder_vect(a); break;
		case 11: i_v.PrintPreOrder_vect(a); break;
		case 12: i_v.PrintPostOrder_vect(a); break;
		case 13: i_v.FindByTheWay(a); break;
		case 14: i_v.Find_vect(a); break;
		case 15: i_v.PrintInOrder_vect(a); i_v.Delete_vect(a, 1); break;
		case 16: i_v.PrintInOrder_vect(a); i_v.Delete_vect(a, 2); break;
		case 17: i_v.PrintInOrder_vect(a); i_v.Delete_vect(a, 3); break;
		case 18: system("cls"); cout << "Goodbye!\n__________________"; isRunning = false;
		}
	}
	return 0;
}
int menu2(bool isRunning, int a, int b)
{
	Functions1<double> d;
	Functions1<double> d_v;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	isRunning = true;
	while (isRunning)
	{
		int answer = 0;
		answer = menu_console();

		switch (answer)
		{
		case 0: d.AddLeaf(a); break;
		case 1: d.PrintInOrder(a); break;
		case 2: d.PrintPreOrder(a); break;
		case 3: d.PrintPostOrder(a); break;
		case 4: d.FindByTheWay(a); break;
		case 5: d.Find(a); break;
		case 6: d.PrintInOrder(a); d.Delete(a, 1);  break;
		case 7: d.PrintInOrder(a); d.Delete(a, 2);  break;
		case 8: d.PrintInOrder(a); d.Delete(a, 3);  break;
		case 9: d_v.AddLeaf_vect(a); break;
		case 10: d_v.PrintInOrder_vect(a); break;
		case 11: d_v.PrintPreOrder_vect(a); break;
		case 12: d_v.PrintPostOrder_vect(a); break;
		case 13: d_v.FindByTheWay(a); break;
		case 14: d_v.Find_vect(a); break;
		case 15: d_v.PrintInOrder_vect(a); d_v.Delete_vect(a, 1); break;
		case 16: d_v.PrintInOrder_vect(a); d_v.Delete_vect(a, 2); break;
		case 17: d_v.PrintInOrder_vect(a); d_v.Delete_vect(a, 3); break;
		case 18: system("cls"); cout << "Goodbye!\n__________________"; isRunning = false;
		}
	}
	return 0;
}
int menu3(bool isRunning, int a, int b)
{
	Functions1<string> s;
	Functions1<string> s_v;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	isRunning = true;
	while (isRunning)
	{
		int answer = 0;
		answer = menu_console();

		switch (answer)
		{
		case 0: s.AddLeaf(a); break;
		case 1: s.PrintInOrder(a); break;
		case 2: s.PrintPreOrder(a); break;
		case 3: s.PrintPostOrder(a); break;
		case 4: s.FindByTheWay(a); break;
		case 5: s.Find(a); break;
		case 6: s.PrintInOrder(a); s.Delete(a, 1);  break;
		case 7: s.PrintInOrder(a); s.Delete(a, 2);  break;
		case 8: s.PrintInOrder(a); s.Delete(a, 3);  break;
		case 9: s_v.AddLeaf_vect(a); break;
		case 10: s_v.PrintInOrder_vect(a); break;
		case 11: s_v.PrintPreOrder_vect(a); break;
		case 12: s_v.PrintPostOrder_vect(a); break;
		case 13: s_v.FindByTheWay(a); break;
		case 14: s_v.Find_vect(a); break;
		case 15: s_v.PrintInOrder_vect(a); s_v.Delete_vect(a, 1); break;
		case 16: s_v.PrintInOrder_vect(a); s_v.Delete_vect(a, 2); break;
		case 17: s_v.PrintInOrder_vect(a); s_v.Delete_vect(a, 3); break;
		case 18: system("cls"); cout << "Goodbye!\n__________________"; isRunning = false;
		}
	}
	return 0;
}
int inf(bool isRunning, int a)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	isRunning = true;
	while (isRunning)
	{
		int answer = 0;
		answer = menu_inf(a);
		switch (answer)
		{
		case 0: menu1(true, a, 1); break;
		case 1: menu1(true, a, 2);  break;
		case 2: menu1(true, a, 3); break;
		case 3:  break;
		case 4: system("cls"); cout << "Goodbye!\n__________________"; isRunning = false;
		}

	}
	return 0;
}
int menu_start() {
	int key = 0;
	int code;
	do {
		system("cls");
		key = (key + 5) % 5;
		if (key == 0) cout << "-> BinarySearchTree" << endl;
		else  cout << "   BinarySearchTree" << endl;
		if (key == 1) cout << "-> Binary Tree" << endl;
		else  cout << "   Binary Tree" << endl;
		if (key == 2) cout << "-> Tree list of sons" << endl;
		else  cout << "   Tree list of sons" << endl;
		if (key == 3) cout << "-> Part 2" << endl;
		else  cout << "   Part 2" << endl;
		if (key == 4) cout << "-> Выход" << endl;
		else  cout << "   Выход" << endl;
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}