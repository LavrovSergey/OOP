#pragma once
#include "Node.h"
#include "Hero.h"
#include "BinarySearchTree.h"
#include "HeroFunctions.h"
#include <iostream>
#include <fstream>
using namespace std;
/*! @param T -data type
* @param U -object.*/
/*! Function class for working with books.*/
template <class T, class U>
class BookSeriesFunctions
{
public:
	int id = 1;
	BinarySearchTree<T, U> bst;
	HeroFunctions<T, Hero> hf;
	void CreateTree(Node<Hero>* r) {
		 CreateTreePrivate( r);
	}
	void Print() {
		PrintInOrderPrivate(bst.GetRoot());
	}
private:
	void PrintSeries(Node<U>* node) {
		cout << "Books in one series: ";
		for (int i = 0; i < node->data->GetVectorSize(); i++)
		{
			cout << node->data->GetData(i);
			if (i < node->data->GetVectorSize() - 1) { cout << ", "; }
			else(cout << endl);
		}
	}
	void PrintInOrderPrivate(Node<U>* node) {
		if (node != NULL)
		{
			if (node->left != NULL)
			{
				PrintInOrderPrivate(node->left);
			}
			PrintSeries(node);
			if (node->right != NULL)
			{
				PrintInOrderPrivate(node->right);
			}
		}
		else(cout << "Empty" << endl);
	}
	void CreateTreePrivate(Node<Hero>* node) {
		if (node != NULL)
		{
			BookSeries* bs = new BookSeries(node->data->GetBooks(), id);
				id++;
			bst.AddLeafDate(bs, bst.GetRoot());
			if (node->left != NULL)
			{
				CreateTreePrivate(node->left);
			}
			if (node->right != NULL)
			{
				CreateTreePrivate(node->right);
			}
		}
		else(cout << "Empty" << endl);
	}
};