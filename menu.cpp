/*! The file in which the submenu implementation is located. */
#include <iostream>
#include <string>
#include "menu.h"
/*! Output items to select a tree.*/
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
		if (key == 4) cout << "-> Exit" << endl;
		else  cout << "   Exit" << endl;
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
/*!Output menu to select the type with which we will work.*/
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
		if (key == 3) cout << "-> Exit" << endl;
		else  cout << "   Exit" << endl;
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
/*! Display a menu to select what we want to do with the tree.*/
int menu_console() {
	int key = 0;
	int code;
	do {
		system("cls");
		key = (key + 19) % 19;
		if (key == 0) cout << "-> Enter" << endl;
		else  cout << "   Enter" << endl;
		if (key == 1) cout << "-> Print InOrder" << endl;
		else  cout << "   Print InOrder" << endl;
		if (key == 2) cout << "-> Print PreOrder" << endl;
		else  cout << "   Print PreOrder" << endl;
		if (key == 3) cout << "-> Print PostOrder" << endl;
		else  cout << "   Print PostOrder " << endl;
		if (key == 4) cout << "-> Find by the way" << endl;
		else  cout << "   Find by the way" << endl;
		if (key == 5) cout << "-> Find" << endl;
		else  cout << "   Find" << endl;
		if (key == 6) cout << "-> Remove by value" << endl;
		else  cout << "   Remove by value" << endl;
		if (key == 7) cout << "-> Delete by id" << endl;
		else  cout << "   Delete by id" << endl;
		if (key == 8) cout << "-> Delete by Father" << endl;
		else  cout << "   Delete by Father" << endl;
		if (key == 9) cout << "-> Enter vector" << endl;
		else  cout << "   Enter vector" << endl;
		if (key == 10) cout << "-> Print InOrder vector" << endl;
		else  cout << "   Print InOrder vector" << endl;
		if (key == 11) cout << "-> Print PreOrder vector" << endl;
		else  cout << "   Print PreOrder vector" << endl;
		if (key == 12) cout << "-> Print PostOrder vector" << endl;
		else  cout << "   Print PostOrder vector" << endl;
		if (key == 13) cout << "-> Find by the way vector " << endl;
		else  cout << "   Find by the way vector" << endl;
		if (key == 14) cout << "-> Find vector" << endl;
		else  cout << "   Find vector" << endl;
		if (key == 15) cout << "-> Delete vector by value" << endl;
		else  cout << "   Delete vector by value" << endl;
		if (key == 16) cout << "-> Delete vector by id" << endl;
		else  cout << "   Delete int vector by id" << endl;
		if (key == 17) cout << "-> Delete vector by Father" << endl;
		else  cout << "   Delete vector by Father" << endl;
		if (key == 18) cout << "-> Выход" << endl;
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
/*!Output the menu to select what we want to do with the second part of the lab.*/
int menu_part2() {
	int key = 0;
	int code;
	do {
		system("cls");
		key = (key + 10) % 10;
		if (key == 0) cout << "-> Add a book" << endl;
		else  cout << "   Add a book" << endl;
		if (key == 1) cout << "-> Add a character" << endl;
		else  cout << "   Add a character" << endl;
		if (key == 2) cout << "-> Show books" << endl;
		else  cout << "   Show books" << endl;
		if (key == 3) cout << "-> Show characters" << endl;
		else  cout << "   Show characters" << endl;
		if (key == 4) cout << "-> Delete the book" << endl;
		else  cout << "   Delete the book" << endl;
		if (key == 5) cout << "-> Delete a character" << endl;
		else  cout << "   Delete a character" << endl;
		if (key == 6) cout << "-> Find a book" << endl;
		else  cout << "   Find a book" << endl;
		if (key == 7) cout << "-> Find a character" << endl;
		else  cout << "   Find a character" << endl;
		if (key == 8) cout << "-> Show series of books" << endl;
		else  cout << "   Show series of books" << endl;
		if (key == 9) cout << "-> Exit" << endl;
		else  cout << "   Exit" << endl;
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
/*! Implementation of the menu of the second part.*/
int part2(bool isRunning)
{
	BookFunctions <string, Book> b;
	HeroFunctions <string, Hero> h;
	BookSeriesFunctions<string, BookSeries> bs;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	isRunning = true;
	while (isRunning)
	{
		int answer = 0;
		answer = menu_part2();

		switch (answer)
		{
		case 0: b.AddBook();/* b.InFile();*/ break;
	    case 1: h.AddHero(b.bst.GetRoot()); break;
		case 2:b.PrintInOrder(b.bst.GetRoot()); break;
		case 3:h.PrintInOrder(); break;
		case 4: b.Delete();/* b.InFile();*/ break;
	    case 5: h.Delete(); /*h.InFile()*/; break;
		case 6: b.Find(); break;
		case 7: h.Find(); break;
		case 8: { bs.CreateTree(h.bst.GetRoot());
			bs.Print(); break; }
		case 9: system("cls"); cout << "Goodbye!\n__________________"; isRunning = false;
		}
	}
	return 0;
}
/*! Implementation of the menu for work with a tree int.*/
int menu1(bool isRunning, int a)
{
		Functions<int,Part1<int>> i;
		Functions<int, Part1<int>> i_v;
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
/*! Implementation of the menu for work with a tree double.*/
int menu2(bool isRunning, int a)
{
	Functions<double, Part1<double>> d;
	Functions<double, Part1<double>> d_v;
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
/*! Implementation of the menu for work with a tree string.*/
int menu3(bool isRunning, int a)
{
	Functions<string, Part1<string>> s;
	Functions<string, Part1<string>> s_v;
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
/*!Implementation of the initial menu.*/
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
		case 0: menu1(true, a); break;
		case 1: menu2(true, a);  break;
		case 2: menu3(true, a); break;
		case 3: part2(true); break;
		case 4: system("cls"); cout << "Goodbye!\n__________________"; isRunning = false;
		}
	}
	return 0;
}
