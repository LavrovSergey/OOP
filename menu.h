/*! The file that contains the submenu function declaration.*/
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include<map>
#include <conio.h>
#include "windows.h"
#include "BinarySearchTree.h"
#include "NarrayTree.h"
#include "BinaryTree.h"
#include "Functions.h"
#include "Book.h"
#include "BookFunctions.h"
#include "HeroFunctions.h"
#include "Hero.h"
#include "Node.h"
#include "Part1.h"
using namespace std;
/*! Output menu to select the type with which we will work.*/
int menu_inf(int a);
/*! Display a menu to select what we want to do with the tree.*/
int menu_console();
/*! Output the menu to select what we want to do with the second part of the lab.*/
int menu_part2();
/*! Implementation of the menu to do with the tree int.*/
int menu1(bool isRunning, int a);
/*! Implementation of the menu to do with the tree double.*/
int menu2(bool isRunning, int a);
/*! Implementation of the menu to do with the tree string.*/
int menu3(bool isRunning, int a);
/*! Implementation of the menu of the second part.*/
int part2(bool isRunning);
/*! Implementation of the start.*/
int inf(bool isRunning, int a);
/*! Output items to select a treeà.*/
int menu_start();