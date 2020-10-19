#pragma once
template <class T>
class Functions1 :public BinarySearchTree<int>, public BinaryTree<int>, public TreeChildrenList<int> {
public:
	void FindByTheWay(int a) {
		bool count = false, i = 0;
		int n;
		cout << "Введите длину маршрута" << endl;
		cin >> n;
		bool* mas = new bool[n];
		cout << "Заполните маршрут" << endl;
		for (int j = 0; j < n; j++) {
			cin >> mas[j];
		}
		if (a == 1) {
			if (FindByTheWayPrivate1(mas, BinarySearchTree::root, count, i, n) == 0)
			{
				cout << "Такого нема";
			}
		}
		else if (a == 2) {
			if (FindByTheWayPrivate2(mas, BinaryTree::root, count, i, n) == 0)
			{
				cout << "Такого нема";
			}
		}
		else {
			if (FindByTheWayPrivate3(mas, TreeChildrenList::root, count, i, n) == 0)
			{
				cout << "Такого нема";
			}
		}
		delete[]mas;
		system("pause");
	}
	void Delete(int a, int b)
	{
		if (b == 1) {
			T inf;
			cout << "Введите, что хотите удалить" << endl;
			cin >> inf;
			if (a == 1)
			{
				Node1* ptr = FindPrivate1(inf, BinarySearchTree::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else  (BinarySearchTree::RemoveNode(ptr, BinarySearchTree::root, 1));
			}
			else if (a == 2)
			{
				Node2* ptr = FindPrivate2(inf, BinaryTree::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (BinaryTree::RemoveNode(ptr, BinaryTree::root, 1));
			}
			else if (a == 3)
			{
				Node3* ptr = FindPrivate3(inf, TreeChildrenList::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (TreeChildrenList::RemoveNode(ptr, TreeChildrenList::root, 1));
			}
		}
		else if (b == 2) {
			PrintPreOrder(a);
			int id;
			cout << "Введите id" << endl;
			cin >> id;
			if (a == 1)
			{
				Node1* ptr = FindPrivateId1(id, BinarySearchTree::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else  (BinarySearchTree::RemoveNode(ptr, BinarySearchTree::root, 1));
			}
			else if (a == 2)
			{
				Node2* ptr = FindPrivateId2(id, BinaryTree::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (BinaryTree::RemoveNode(ptr, BinaryTree::root, 1));
			}
			else if (a == 3)
			{
				Node3* ptr = FindPrivateId3(id, TreeChildrenList::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (TreeChildrenList::RemoveNode(ptr, TreeChildrenList::root, 1));
			}
		}
		else if (b == 3)
		{
			PrintPreOrder(a);
			int id;
			cout << "Введите id отца" << endl;
			cin >> id;
			if (a == 1)
			{
				Node1* ptr = FindPrivateId1(id, BinarySearchTree::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else  (BinarySearchTree::RemoveNode(ptr, BinarySearchTree::root, 2));
			}
			else if (a == 2)
			{
				Node2* ptr = FindPrivateId2(id, BinaryTree::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (BinaryTree::RemoveNode(ptr, BinaryTree::root, 2));
			}
			else if (a == 3)
			{
				Node3* ptr = FindPrivateId3(id, TreeChildrenList::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (TreeChildrenList::RemoveNode(ptr, TreeChildrenList::root, 2));
			}
		}
	}
	void AddLeaf(int a) {
		T inf;
		cout << "Введите информацию" << endl;
		cin >> inf;
		if (a == 1) { BinarySearchTree::AddLeaf(inf, BinarySearchTree::root); }
		else if (a == 2) { BinaryTree::root = AddLeaf1(BinaryTree::root, BinaryTree::creat_leaf(inf, 0)); }
		else if (a == 3) { TreeChildrenList::AddLeaf(inf, TreeChildrenList::root); }
	}
	void AddLeaf_vect(int a) {
		int n;
		T inf;
		vector<T> v;
		cout << "Размер вектора: " << endl;
		cin >> n;
		cout << "Заполните вектор" << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> inf;
			v.push_back(inf);
		}
		if (a == 1) { BinarySearchTree::AddLeaf_v(v, BinarySearchTree::root); }
		else if (a == 2) { BinaryTree::root = AddLeaf1_v(BinaryTree::root, BinaryTree::creat_leaf_v(v, 0)); }
		else if (a == 3) { TreeChildrenList::AddLeaf_v(v, TreeChildrenList::root); }
	}
	void Find(int a) {
		T inf;
		cout << "Введите, что хотите найти" << endl;
		cin >> inf;
		if (a == 1)
		{
			Node1* ptr = FindPrivate1(inf, BinarySearchTree::root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }
			else(cout << ptr->id << ". " << ptr->data << endl);
			system("pause");
		}
		else if (a == 2)
		{
			Node2* ptr = FindPrivate2(inf, BinaryTree::root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }
			else(cout << ptr->id << ". " << ptr->data << endl);
			system("pause");
		}
		else if (a == 3)
		{
			Node3* ptr = FindPrivate3(inf, TreeChildrenList::root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }
			else(cout << ptr->id << ". " << ptr->data << endl);
			system("pause");
		}
	}
	void PrintInOrder(int a) {
		if (a == 1) { PrintInOrderPrivate1(BinarySearchTree::root); }
		else if (a == 2) { PrintInOrderPrivate2(BinaryTree::root); }
		else if (a == 3) { PrintPreOrderPrivate3(TreeChildrenList::root); }
		system("pause");
	}
	void PrintInOrder_vect(int a) {
		if (a == 1) { PrintInOrderPrivate1_vect(BinarySearchTree::root); }
		else if (a == 2) { PrintInOrderPrivate2_vect(BinaryTree::root); }
		else if (a == 3) { PrintPreOrderPrivate3_vect(TreeChildrenList::root); }
		system("pause");
	}
	void PrintPostOrder(int a) {
		if (a == 1) { PrintPostOrderPrivate1(BinarySearchTree::root); }
		else if (a == 2) { PrintPostOrderPrivate2(BinaryTree::root); }
		else if (a == 3) { PrintPreOrderPrivate3(TreeChildrenList::root); }
		system("pause");
	}
	void PrintPostOrder_vect(int a) {
		if (a == 1) { PrintPostOrderPrivate1_vect(BinarySearchTree::root); }
		else if (a == 2) { PrintPostOrderPrivate2_vect(BinaryTree::root); }
		else if (a == 3) { PrintPreOrderPrivate3_vect(TreeChildrenList::root); }
		system("pause");
	}
	void PrintPreOrder(int a) {
		if (a == 1) { PrintPreOrderPrivate1(BinarySearchTree::root); }
		else if (a == 2) { PrintPreOrderPrivate2(BinaryTree::root); }
		else if (a == 3) { PrintPreOrderPrivate3(TreeChildrenList::root); }
		system("pause");
	}
	void PrintPreOrder_vect(int a) {
		if (a == 1) { PrintPreOrderPrivate1_vect(BinarySearchTree::root); }
		else if (a == 2) { PrintPreOrderPrivate2_vect(BinaryTree::root); }
		else if (a == 3) { PrintPreOrderPrivate3_vect(TreeChildrenList::root); }
		system("pause");
	}
	void Find_vect(int a) {
		T inf;
		vector<T> v;
		int n;
		cout << "Введите размер вектора" << endl;
		cin >> n;
		cout << "Введите, что хотите найти" << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> inf;
			v.push_back(inf);
		}
		if (a == 1)
		{
			Node1* ptr = FindPrivate1_vect(v, BinarySearchTree::root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }                       //тут почемуто не работает но такое же в удалении работает
			else {
				cout << ptr->id << ". ";
				for (int i = 0; i < n; i++)
				{
					cout << v[i];
				}
			}
			system("pause");
		}
		if (a == 2)
		{
			Node2* ptr = FindPrivate2_vect(v, BinaryTree::root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }
			else {
				cout << ptr->id << ". ";
				for (int i = 0; i < n; i++)
				{
					cout << v[i];
				}
			}
			system("pause");
		}
		if (a == 3)
		{
			Node3* ptr = FindPrivate3_vect(v, TreeChildrenList::root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }
			else {
				cout << ptr->id << ". ";
				for (int i = 0; i < n; i++)
				{
					cout << v[i];
				}
			}
			system("pause");
		}
	}
	void Delete_vect(int a, int b)
	{
		if (b == 1) {
			T inf;
			vector<T> v;
			int n;
			cout << "Введите размер вектора, который хотите удалить" << endl;
			cin >> n;
			cout << "Введите, что хотите удалить" << endl;
			for (int i = 0; i < n; i++)
			{
				cin >> inf;
				v.push_back(inf);
			}
			if (a == 1)
			{
				Node1* ptr = FindPrivate1_vect(v, BinarySearchTree::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else  (BinarySearchTree::RemoveNode_vect(ptr, BinarySearchTree::root, a));
			}
			else if (a == 2)
			{
				Node2* ptr = FindPrivate2_vect(v, BinaryTree::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (BinaryTree::RemoveNode_vect(ptr, BinaryTree::root, a));
			}
			else if (a == 3)
			{
				Node3* ptr = FindPrivate3_vect(v, TreeChildrenList::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (TreeChildrenList::RemoveNode_vect(ptr, TreeChildrenList::root, a));
			}

		}
		else if (b == 2) {
			PrintPreOrder_vect(a);
			int id;
			cout << "Введите id" << endl;
			cin >> id;
			if (a == 1)
			{
				Node1* ptr = FindPrivateId1(id, BinarySearchTree::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else  (BinarySearchTree::RemoveNode_vect(ptr, BinarySearchTree::root, a));
			}
			else if (a == 2)
			{
				Node2* ptr = FindPrivateId2(id, BinaryTree::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (BinaryTree::RemoveNode_vect(ptr, BinaryTree::root, a));
			}
		}
		else if (b == 3)
		{
			PrintPreOrder_vect(a);
			int id;
			cout << "Введите id отца" << endl;
			cin >> id;
			if (a == 1)
			{
				Node1* ptr = FindPrivateId1(id, BinarySearchTree::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else  (BinarySearchTree::RemoveNode_vect(ptr, BinarySearchTree::root, 2));
			}
			else if (a == 2)
			{
				Node2* ptr = FindPrivateId2(id, BinaryTree::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (BinaryTree::RemoveNode_vect(ptr, BinaryTree::root, 2));
			}
		}
	}
private:
	bool FindByTheWayPrivate1(bool* mas, Node1* node, bool count, int i, int n) {
		if (node != NULL)
		{
			if (i == n)
			{
				cout << node->data << endl;
				count = true;
			}
			else
			{
				if (mas[i] == 0)
				{
					i++;
					FindByTheWayPrivate1(mas, node->left, count, i, n);
				}
				else
				{
					i++;
					FindByTheWayPrivate1(mas, node->right, count, i, n);
				}
			}
		}
		else { return count; }
	}
	bool FindByTheWayPrivate2(bool* mas, Node2* node, bool count, int i, int n) {
		if (node != NULL)
		{
			if (i == n)
			{
				cout << node->data << endl;
				count = true;
			}
			else
			{
				if (mas[i] == 0)
				{
					i++;
					FindByTheWayPrivate2(mas, node->left, count, i, n);
				}
				else
				{
					i++;
					FindByTheWayPrivate2(mas, node->right, count, i, n);
				}
			}
		}
		else { return count; }
	}
	bool FindByTheWayPrivate3(bool* mas, Node3* node, bool count, int i, int n) {
		if (node != NULL)
		{
			if (i == n)
			{
				cout << node->data << endl;
				count = true;
			}
			else
			{
				if (mas[i] == 0)
				{
					i++;
					FindByTheWayPrivate3(mas, node->child, count, i, n);
				}
				else
				{
					i++;
					FindByTheWayPrivate3(mas, node->next, count, i, n);
				}
			}
		}
		else { return count; }
	}
	void PrintInOrderPrivate1(Node1* node)
	{
		if (BinarySearchTree::root != NULL)
		{
			if (node->left != NULL)
			{
				PrintInOrderPrivate1(node->left);
			}
			cout << node->id << ". ";
			cout << node->data << endl;
			if (node->right != NULL)
			{
				PrintInOrderPrivate1(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	}
	void PrintInOrderPrivate2(Node2* node) {
		if (BinaryTree::root != NULL)
		{
			if (node->left != NULL)
			{
				PrintInOrderPrivate2(node->left);
			}
			cout << node->id << ". ";
			cout << node->data << endl;
			if (node->right != NULL)
			{
				PrintInOrderPrivate2(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	};
	void PrintPreOrderPrivate1(Node1* node) {
		if (node != NULL)
		{
			cout << node->id << ".";
			cout << node->data << endl;
			if (node->left != NULL)
			{
				PrintPreOrderPrivate1(node->left);
			}
			if (node->right != NULL)
			{
				PrintPreOrderPrivate1(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPreOrderPrivate2(Node2* node) {
		if (node != NULL)
		{
			cout << node->id << ".";
			cout << node->data << endl;
			if (node->left != NULL)
			{
				PrintPreOrderPrivate2(node->left);
			}
			if (node->right != NULL)
			{
				PrintPreOrderPrivate2(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPreOrderPrivate3(Node3* node)
	{
		while (node)
		{
			cout << node->id << ". " << node->data;
			if (node->child)
			{
				PrintPreOrderPrivate3(node->child);
			}
			node = node->next;
		}
	}
	void PrintPostOrderPrivate1(Node1* node)
	{
		if (node != NULL)
		{
			if (node->left != NULL)
			{
				PrintPostOrderPrivate1(node->left);
			}
			if (node->right != NULL)
			{
				PrintPostOrderPrivate1(node->right);
			}
			cout << node->id << ".";
			cout << node->data << endl;
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPostOrderPrivate2(Node2* node)
	{
		if (node != NULL)
		{
			if (node->left != NULL)
			{
				PrintPostOrderPrivate2(node->left);
			}
			if (node->right != NULL)
			{
				PrintPostOrderPrivate2(node->right);
			}
			cout << node->id << ".";
			cout << node->data << endl;
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPreOrderPrivate1_vect(Node1* node) {
		if (node != NULL)
		{
			cout << node->id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
			if (node->left != NULL)
			{
				PrintPreOrderPrivate1_vect(node->left);
			}
			if (node->right != NULL)
			{
				PrintPreOrderPrivate1_vect(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPreOrderPrivate2_vect(Node2* node) {
		if (node != NULL)
		{
			cout << node->id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
			if (node->left != NULL)
			{
				PrintPreOrderPrivate2_vect(node->left);
			}
			if (node->right != NULL)
			{
				PrintPreOrderPrivate2_vect(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPreOrderPrivate3_vect(Node3* node)
	{
		while (node)
		{
			cout << node->id << ". ";
			for (int i = 0; i < node->v.size(); i++) {
				cout << node->v[i] << " ";
			}
			cout << endl;
			if (node->child)
			{
				PrintPreOrderPrivate3_vect(node->child);
			}
			node = node->next;
		}
	}
	void PrintPostOrderPrivate1_vect(Node1* node)
	{
		if (node != NULL)
		{
			if (node->left != NULL)
			{
				PrintPostOrderPrivate1_vect(node->left);
			}
			if (node->right != NULL)
			{
				PrintPostOrderPrivate1_vect(node->right);
			}
			cout << node->id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPostOrderPrivate2_vect(Node2* node)
	{
		if (node != NULL)
		{
			if (node->left != NULL)
			{
				PrintPostOrderPrivate2_vect(node->left);
			}
			if (node->right != NULL)
			{
				PrintPostOrderPrivate2_vect(node->right);
			}
			cout << node->id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
		}
		else(cout << "Пусто" << endl);
	}
	void PrintInOrderPrivate1_vect(Node1* node)
	{
		if (BinarySearchTree::root != NULL)
		{
			if (node->left != NULL)
			{
				PrintInOrderPrivate1_vect(node->left);
			}
			cout << node->id << ". ";
			for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
			if (node->right != NULL)
			{
				PrintInOrderPrivate1_vect(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	};
	void PrintInOrderPrivate2_vect(Node2* node)
	{
		if (BinaryTree::root != NULL)
		{
			if (node->left != NULL)
			{
				PrintInOrderPrivate2(node->left);
			}
			cout << node->id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
			if (node->right != NULL)
			{
				PrintInOrderPrivate2(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	};
	Node1* FindPrivate1(T e, Node1* node)
	{
		if (node != NULL)
		{
			if (node->data == e)
			{
				return node;
			}
			else
			{
				if (e <= node->data)
				{
					FindPrivate1(e, node->left);
				}
				else if (e > node->data)
				{
					FindPrivate1(e, node->right);
				}
			}
		}
		else { return node; }
	}
	Node2* FindPrivate2(T inf, Node2* node)
	{
		if (node == NULL) return node;

		if (inf == node->data) {
			return node;
		}
		Node2* tmp1 = FindPrivate2(inf, node->left);
		if (tmp1 != NULL) {
			if (inf == tmp1->data) { return tmp1; }
		}
		Node2* tmp2 = FindPrivate2(inf, node->right);
		if (tmp2 != NULL) {
			if (inf == tmp2->data) { return tmp2; }
		}
	}
	Node3* FindPrivate3(T e, Node3* node) {
		if (node != NULL)
		{
			if (node->data == e)
			{
				return node;
			}
			else

			{
				if (node->child) {
					if (e <= node->child->data)
					{
						FindPrivate3(e, node->child);
					}
					else if (e > node->child->data)
					{
						FindPrivate3(e, node->child->next);
					}
				}
				else {
					FindPrivate3(e, node->next);
				}
			}
		}
		else { return node; }
	}
	Node1* FindPrivate1_vect(vector<T> v, Node1* node)
	{
		if (node != NULL)
		{

			if (node->v == v)
			{
				return node;
			}
			else
			{
				if (v[0] <= node->v[0])
				{
					FindPrivate1_vect(v, node->left);
				}
				else if (v[0] > node->v[0])
				{
					FindPrivate1_vect(v, node->right);
				}
			}
		}
		else {
			return 0;
		}
	}
	Node2* FindPrivate2_vect(vector<T> v, Node2* node)
	{
		if (node == NULL) return node;

		if (v == node->v) { return node; }
		Node2* tmp1 = FindPrivate2_vect(v, node->left);
		if (tmp1 != NULL) {
			if (v.size() == tmp1->v.size() && v == node->v)
			{
				return tmp1;
			}
		}
		Node2* tmp2 = FindPrivate2_vect(v, node->right);
		if (tmp2 != NULL) {
			if (v.size() == tmp2->v.size() && v == node->v)
			{
				return tmp2;
			}
		}
	}
	Node3* FindPrivate3_vect(vector<T> v, Node3* node)
	{
		if (node != NULL)
		{
			if (node->v == v)
			{
				return node;
			}
			else
			{
				if (node->child) {
					if (v[0] <= node->child->v[0])
					{
						FindPrivate3_vect(v, node->child);
					}
					else if (v[0] > node->child->v[0])
					{
						FindPrivate3_vect(v, node->child->next);
					}
				}
				else {
					FindPrivate3_vect(v, node->next);
				}
			}
		}
		else { return node; }
	}
	Node1* FindPrivateId1(int id, Node1* node) {
		if (node == NULL) return node;
		if (id == node->id) {
			return node;
		}
		Node1* tmp1 = FindPrivateId1(id, node->left);
		if (tmp1 != NULL) {
			if (id == tmp1->id) { return tmp1; }
		}
		Node1* tmp2 = FindPrivateId1(id, node->right);
		if (tmp2 != NULL) {
			if (id == tmp2->id) { return tmp2; }
		}
	}
	Node2* FindPrivateId2(int id, Node2* node) {
		if (node == NULL) return node;
		if (id == node->id) {
			return node;
		}
		Node2* tmp1 = FindPrivateId2(id, node->left);
		if (tmp1 != NULL) {
			if (id == tmp1->id) { return tmp1; }
		}
		Node2* tmp2 = FindPrivateId2(id, node->right);
		if (tmp2 != NULL) {
			if (id == tmp2->id) { return tmp2; }
		}
	}
	Node3* FindPrivateId3(int id, Node3* node)
	{
		while (node)
		{
			if (id == node->id) { return node; }
			if (node->child)
			{
				FindPrivateId3(id, node->child);
			}
			node = node->next;
		}
		return 0;
	}
};
template <class T>
class Functions2 :public BinarySearchTree<double>, public BinaryTree<double>, public TreeChildrenList<double> {
public:
	void FindByTheWay(int a) {
		bool count = false, i = 0;
		int n;
		cout << "Введите длину маршрута" << endl;
		cin >> n;
		bool* mas = new bool[n];
		cout << "Заполните маршрут" << endl;
		for (int j = 0; j < n; j++) {
			cin >> mas[j];
		}
		if (a == 1) {
			if (FindByTheWayPrivate1(mas, BinarySearchTree::root, count, i, n) == 0)
			{
				cout << "Такого нема";
			}
		}
		else if (a == 2) {
			if (FindByTheWayPrivate2(mas, BinaryTree::root, count, i, n) == 0)
			{
				cout << "Такого нема";
			}
		}
		else {
			if (FindByTheWayPrivate3(mas, TreeChildrenList::root, count, i, n) == 0)
			{
				cout << "Такого нема";
			}
		}
		delete[]mas;
		system("pause");
	}
	void Delete(int a, int b)
	{
		if (b == 1) {
			T inf;
			cout << "Введите, что хотите удалить" << endl;
			cin >> inf;
			if (a == 1)
			{
				Node1* ptr = FindPrivate1(inf, BinarySearchTree::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else  (BinarySearchTree::RemoveNode(ptr, BinarySearchTree::root, 1));
			}
			else if (a == 2)
			{
				Node2* ptr = FindPrivate2(inf, BinaryTree::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (BinaryTree::RemoveNode(ptr, BinaryTree::root, 1));
			}
			else if (a == 3)
			{
				Node3* ptr = FindPrivate3(inf, TreeChildrenList::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (TreeChildrenList::RemoveNode(ptr, TreeChildrenList::root, 1));
			}
		}
		else if (b == 2) {
			PrintPreOrder(a);
			int id;
			cout << "Введите id" << endl;
			cin >> id;
			if (a == 1)
			{
				Node1* ptr = FindPrivateId1(id, BinarySearchTree::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else  (BinarySearchTree::RemoveNode(ptr, BinarySearchTree::root, 1));
			}
			else if (a == 2)
			{
				Node2* ptr = FindPrivateId2(id, BinaryTree::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (BinaryTree::RemoveNode(ptr, BinaryTree::root, 1));
			}
			else if (a == 3)
			{
				Node3* ptr = FindPrivateId3(id, TreeChildrenList::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (TreeChildrenList::RemoveNode(ptr, TreeChildrenList::root, 1));
			}
		}
		else if (b == 3)
		{
			PrintPreOrder(a);
			int id;
			cout << "Введите id отца" << endl;
			cin >> id;
			if (a == 1)
			{
				Node1* ptr = FindPrivateId1(id, BinarySearchTree::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else  (BinarySearchTree::RemoveNode(ptr, BinarySearchTree::root, 2));
			}
			else if (a == 2)
			{
				Node2* ptr = FindPrivateId2(id, BinaryTree::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (BinaryTree::RemoveNode(ptr, BinaryTree::root, 2));
			}
			else if (a == 3)
			{
				Node3* ptr = FindPrivateId3(id, TreeChildrenList::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (TreeChildrenList::RemoveNode(ptr, TreeChildrenList::root, 2));
			}
		}
	}
	void AddLeaf(int a) {
		T inf;
		cout << "Введите информацию" << endl;
		cin >> inf;
		if (a == 1) { BinarySearchTree::AddLeaf(inf, BinarySearchTree::root); }
		else if (a == 2) { BinaryTree::root = AddLeaf1(BinaryTree::root, BinaryTree::creat_leaf(inf, 0)); }
		else if (a == 3) { TreeChildrenList::AddLeaf(inf, TreeChildrenList::root); }
	}
	void AddLeaf_vect(int a) {
		int n;
		T inf;
		vector<T> v;
		cout << "Размер вектора: " << endl;
		cin >> n;
		cout << "Заполните вектор" << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> inf;
			v.push_back(inf);
		}
		if (a == 1) { BinarySearchTree::AddLeaf_v(v, BinarySearchTree::root); }
		else if (a == 2) { BinaryTree::root = AddLeaf1_v(BinaryTree::root, BinaryTree::creat_leaf_v(v, 0)); }
		else if (a == 3) { TreeChildrenList::AddLeaf_v(v, TreeChildrenList::root); }
	}
	void Find(int a) {
		T inf;
		cout << "Введите, что хотите найти" << endl;
		cin >> inf;
		if (a == 1)
		{
			Node1* ptr = FindPrivate1(inf, BinarySearchTree::root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }
			else(cout << ptr->id << ". " << ptr->data << endl);
			system("pause");
		}
		else if (a == 2)
		{
			Node2* ptr = FindPrivate2(inf, BinaryTree::root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }
			else(cout << ptr->id << ". " << ptr->data << endl);
			system("pause");
		}
		else if (a == 3)
		{
			Node3* ptr = FindPrivate3(inf, TreeChildrenList::root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }
			else(cout << ptr->id << ". " << ptr->data << endl);
			system("pause");
		}
	}
	void PrintInOrder(int a) {
		if (a == 1) { PrintInOrderPrivate1(BinarySearchTree::root); }
		else if (a == 2) { PrintInOrderPrivate2(BinaryTree::root); }
		else if (a == 3) { PrintPreOrderPrivate3(TreeChildrenList::root); }
		system("pause");
	}
	void PrintInOrder_vect(int a) {
		if (a == 1) { PrintInOrderPrivate1_vect(BinarySearchTree::root); }
		else if (a == 2) { PrintInOrderPrivate2_vect(BinaryTree::root); }
		else if (a == 3) { PrintPreOrderPrivate3_vect(TreeChildrenList::root); }
		system("pause");
	}
	void PrintPostOrder(int a) {
		if (a == 1) { PrintPostOrderPrivate1(BinarySearchTree::root); }
		else if (a == 2) { PrintPostOrderPrivate2(BinaryTree::root); }
		else if (a == 3) { PrintPreOrderPrivate3(TreeChildrenList::root); }
		system("pause");
	}
	void PrintPostOrder_vect(int a) {
		if (a == 1) { PrintPostOrderPrivate1_vect(BinarySearchTree::root); }
		else if (a == 2) { PrintPostOrderPrivate2_vect(BinaryTree::root); }
		else if (a == 3) { PrintPreOrderPrivate3_vect(TreeChildrenList::root); }
		system("pause");
	}
	void PrintPreOrder(int a) {
		if (a == 1) { PrintPreOrderPrivate1(BinarySearchTree::root); }
		else if (a == 2) { PrintPreOrderPrivate2(BinaryTree::root); }
		else if (a == 3) { PrintPreOrderPrivate3(TreeChildrenList::root); }
		system("pause");
	}
	void PrintPreOrder_vect(int a) {
		if (a == 1) { PrintPreOrderPrivate1_vect(BinarySearchTree::root); }
		else if (a == 2) { PrintPreOrderPrivate2_vect(BinaryTree::root); }
		else if (a == 3) { PrintPreOrderPrivate3_vect(TreeChildrenList::root); }
		system("pause");
	}
	void Find_vect(int a) {
		T inf;
		vector<T> v;
		int n;
		cout << "Введите размер вектора" << endl;
		cin >> n;
		cout << "Введите, что хотите найти" << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> inf;
			v.push_back(inf);
		}
		if (a == 1)
		{
			Node1* ptr = FindPrivate1_vect(v, BinarySearchTree::root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }                       //тут почемуто не работает но такое же в удалении работает
			else {
				cout << ptr->id << ". ";
				for (int i = 0; i < n; i++)
				{
					cout << v[i];
				}
			}
			system("pause");
		}
		if (a == 2)
		{
			Node2* ptr = FindPrivate2_vect(v, BinaryTree::root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }
			else {
				cout << ptr->id << ". ";
				for (int i = 0; i < n; i++)
				{
					cout << v[i];
				}
			}
			system("pause");
		}
		if (a == 3)
		{
			Node3* ptr = FindPrivate3_vect(v, TreeChildrenList::root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }
			else {
				cout << ptr->id << ". ";
				for (int i = 0; i < n; i++)
				{
					cout << v[i];
				}
			}
			system("pause");
		}
	}
	void Delete_vect(int a, int b)
	{
		if (b == 1) {
			T inf;
			vector<T> v;
			int n;
			cout << "Введите размер вектора, который хотите удалить" << endl;
			cin >> n;
			cout << "Введите, что хотите удалить" << endl;
			for (int i = 0; i < n; i++)
			{
				cin >> inf;
				v.push_back(inf);
			}
			if (a == 1)
			{
				Node1* ptr = FindPrivate1_vect(v, BinarySearchTree::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else  (BinarySearchTree::RemoveNode_vect(ptr, BinarySearchTree::root, a));
			}
			else if (a == 2)
			{
				Node2* ptr = FindPrivate2_vect(v, BinaryTree::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (BinaryTree::RemoveNode_vect(ptr, BinaryTree::root, a));
			}
			else if (a == 3)
			{
				Node3* ptr = FindPrivate3_vect(v, TreeChildrenList::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (TreeChildrenList::RemoveNode_vect(ptr, TreeChildrenList::root, a));
			}

		}
		else if (b == 2) {
			PrintPreOrder_vect(a);
			int id;
			cout << "Введите id" << endl;
			cin >> id;
			if (a == 1)
			{
				Node1* ptr = FindPrivateId1(id, BinarySearchTree::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else  (BinarySearchTree::RemoveNode_vect(ptr, BinarySearchTree::root, a));
			}
			else if (a == 2)
			{
				Node2* ptr = FindPrivateId2(id, BinaryTree::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (BinaryTree::RemoveNode_vect(ptr, BinaryTree::root, a));
			}
		}
		else if (b == 3)
		{
			PrintPreOrder_vect(a);
			int id;
			cout << "Введите id отца" << endl;
			cin >> id;
			if (a == 1)
			{
				Node1* ptr = FindPrivateId1(id, BinarySearchTree::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else  (BinarySearchTree::RemoveNode_vect(ptr, BinarySearchTree::root, 2));
			}
			else if (a == 2)
			{
				Node2* ptr = FindPrivateId2(id, BinaryTree::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (BinaryTree::RemoveNode_vect(ptr, BinaryTree::root, 2));
			}
		}
	}
private:
	bool FindByTheWayPrivate1(bool* mas, Node1* node, bool count, int i, int n) {
		if (node != NULL)
		{
			if (i == n)
			{
				cout << node->data << endl;
				count = true;
			}
			else
			{
				if (mas[i] == 0)
				{
					i++;
					FindByTheWayPrivate1(mas, node->left, count, i, n);
				}
				else
				{
					i++;
					FindByTheWayPrivate1(mas, node->right, count, i, n);
				}
			}
		}
		else { return count; }
	}
	bool FindByTheWayPrivate2(bool* mas, Node2* node, bool count, int i, int n) {
		if (node != NULL)
		{
			if (i == n)
			{
				cout << node->data << endl;
				count = true;
			}
			else
			{
				if (mas[i] == 0)
				{
					i++;
					FindByTheWayPrivate2(mas, node->left, count, i, n);
				}
				else
				{
					i++;
					FindByTheWayPrivate2(mas, node->right, count, i, n);
				}
			}
		}
		else { return count; }
	}
	bool FindByTheWayPrivate3(bool* mas, Node3* node, bool count, int i, int n) {
		if (node != NULL)
		{
			if (i == n)
			{
				cout << node->data << endl;
				count = true;
			}
			else
			{
				if (mas[i] == 0)
				{
					i++;
					FindByTheWayPrivate3(mas, node->child, count, i, n);
				}
				else
				{
					i++;
					FindByTheWayPrivate3(mas, node->next, count, i, n);
				}
			}
		}
		else { return count; }
	}
	void PrintInOrderPrivate1(Node1* node)
	{
		if (BinarySearchTree::root != NULL)
		{
			if (node->left != NULL)
			{
				PrintInOrderPrivate1(node->left);
			}
			cout << node->id << ". ";
			cout << node->data << endl;
			if (node->right != NULL)
			{
				PrintInOrderPrivate1(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	}
	void PrintInOrderPrivate2(Node2* node) {
		if (BinaryTree::root != NULL)
		{
			if (node->left != NULL)
			{
				PrintInOrderPrivate2(node->left);
			}
			cout << node->id << ". ";
			cout << node->data << endl;
			if (node->right != NULL)
			{
				PrintInOrderPrivate2(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	};
	void PrintPreOrderPrivate1(Node1* node) {
		if (node != NULL)
		{
			cout << node->id << ".";
			cout << node->data << endl;
			if (node->left != NULL)
			{
				PrintPreOrderPrivate1(node->left);
			}
			if (node->right != NULL)
			{
				PrintPreOrderPrivate1(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPreOrderPrivate2(Node2* node) {
		if (node != NULL)
		{
			cout << node->id << ".";
			cout << node->data << endl;
			if (node->left != NULL)
			{
				PrintPreOrderPrivate2(node->left);
			}
			if (node->right != NULL)
			{
				PrintPreOrderPrivate2(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPreOrderPrivate3(Node3* node)
	{
		while (node)
		{
			cout << node->id << ". " << node->data;
			if (node->child)
			{
				PrintPreOrderPrivate3(node->child);
			}
			node = node->next;
		}
	}
	void PrintPostOrderPrivate1(Node1* node)
	{
		if (node != NULL)
		{
			if (node->left != NULL)
			{
				PrintPostOrderPrivate1(node->left);
			}
			if (node->right != NULL)
			{
				PrintPostOrderPrivate1(node->right);
			}
			cout << node->id << ".";
			cout << node->data << endl;
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPostOrderPrivate2(Node2* node)
	{
		if (node != NULL)
		{
			if (node->left != NULL)
			{
				PrintPostOrderPrivate2(node->left);
			}
			if (node->right != NULL)
			{
				PrintPostOrderPrivate2(node->right);
			}
			cout << node->id << ".";
			cout << node->data << endl;
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPreOrderPrivate1_vect(Node1* node) {
		if (node != NULL)
		{
			cout << node->id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
			if (node->left != NULL)
			{
				PrintPreOrderPrivate1_vect(node->left);
			}
			if (node->right != NULL)
			{
				PrintPreOrderPrivate1_vect(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPreOrderPrivate2_vect(Node2* node) {
		if (node != NULL)
		{
			cout << node->id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
			if (node->left != NULL)
			{
				PrintPreOrderPrivate2_vect(node->left);
			}
			if (node->right != NULL)
			{
				PrintPreOrderPrivate2_vect(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPreOrderPrivate3_vect(Node3* node)
	{
		while (node)
		{
			cout << node->id << ". ";
			for (int i = 0; i < node->v.size(); i++) {
				cout << node->v[i] << " ";
			}
			cout << endl;
			if (node->child)
			{
				PrintPreOrderPrivate3_vect(node->child);
			}
			node = node->next;
		}
	}
	void PrintPostOrderPrivate1_vect(Node1* node)
	{
		if (node != NULL)
		{
			if (node->left != NULL)
			{
				PrintPostOrderPrivate1_vect(node->left);
			}
			if (node->right != NULL)
			{
				PrintPostOrderPrivate1_vect(node->right);
			}
			cout << node->id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPostOrderPrivate2_vect(Node2* node)
	{
		if (node != NULL)
		{
			if (node->left != NULL)
			{
				PrintPostOrderPrivate2_vect(node->left);
			}
			if (node->right != NULL)
			{
				PrintPostOrderPrivate2_vect(node->right);
			}
			cout << node->id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
		}
		else(cout << "Пусто" << endl);
	}
	void PrintInOrderPrivate1_vect(Node1* node)
	{
		if (BinarySearchTree::root != NULL)
		{
			if (node->left != NULL)
			{
				PrintInOrderPrivate1_vect(node->left);
			}
			cout << node->id << ". ";
			for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
			if (node->right != NULL)
			{
				PrintInOrderPrivate1_vect(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	};
	void PrintInOrderPrivate2_vect(Node2* node)
	{
		if (BinaryTree::root != NULL)
		{
			if (node->left != NULL)
			{
				PrintInOrderPrivate2(node->left);
			}
			cout << node->id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
			if (node->right != NULL)
			{
				PrintInOrderPrivate2(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	};
	Node1* FindPrivate1(T e, Node1* node)
	{
		if (node != NULL)
		{
			if (node->data == e)
			{
				return node;
			}
			else
			{
				if (e <= node->data)
				{
					FindPrivate1(e, node->left);
				}
				else if (e > node->data)
				{
					FindPrivate1(e, node->right);
				}
			}
		}
		else { return node; }
	}
	Node2* FindPrivate2(T inf, Node2* node)
	{
		if (node == NULL) return node;

		if (inf == node->data) {
			return node;
		}
		Node2* tmp1 = FindPrivate2(inf, node->left);
		if (tmp1 != NULL) {
			if (inf == tmp1->data) { return tmp1; }
		}
		Node2* tmp2 = FindPrivate2(inf, node->right);
		if (tmp2 != NULL) {
			if (inf == tmp2->data) { return tmp2; }
		}
	}
	Node3* FindPrivate3(T e, Node3* node) {
		if (node != NULL)
		{
			if (node->data == e)
			{
				return node;
			}
			else

			{
				if (node->child) {
					if (e <= node->child->data)
					{
						FindPrivate3(e, node->child);
					}
					else if (e > node->child->data)
					{
						FindPrivate3(e, node->child->next);
					}
				}
				else {
					FindPrivate3(e, node->next);
				}
			}
		}
		else { return node; }
	}
	Node1* FindPrivate1_vect(vector<T> v, Node1* node)
	{
		if (node != NULL)
		{

			if (node->v == v)
			{
				return node;
			}
			else
			{
				if (v[0] <= node->v[0])
				{
					FindPrivate1_vect(v, node->left);
				}
				else if (v[0] > node->v[0])
				{
					FindPrivate1_vect(v, node->right);
				}
			}
		}
		else {
			return 0;
		}
	}
	Node2* FindPrivate2_vect(vector<T> v, Node2* node)
	{
		if (node == NULL) return node;

		if (v == node->v) { return node; }
		Node2* tmp1 = FindPrivate2_vect(v, node->left);
		if (tmp1 != NULL) {
			if (v.size() == tmp1->v.size() && v == node->v)
			{
				return tmp1;
			}
		}
		Node2* tmp2 = FindPrivate2_vect(v, node->right);
		if (tmp2 != NULL) {
			if (v.size() == tmp2->v.size() && v == node->v)
			{
				return tmp2;
			}
		}
	}
	Node3* FindPrivate3_vect(vector<T> v, Node3* node)
	{
		if (node != NULL)
		{
			if (node->v == v)
			{
				return node;
			}
			else
			{
				if (node->child) {
					if (v[0] <= node->child->v[0])
					{
						FindPrivate3_vect(v, node->child);
					}
					else if (v[0] > node->child->v[0])
					{
						FindPrivate3_vect(v, node->child->next);
					}
				}
				else {
					FindPrivate3_vect(v, node->next);
				}
			}
		}
		else { return node; }
	}
	Node1* FindPrivateId1(int id, Node1* node) {
		if (node == NULL) return node;
		if (id == node->id) {
			return node;
		}
		Node1* tmp1 = FindPrivateId1(id, node->left);
		if (tmp1 != NULL) {
			if (id == tmp1->id) { return tmp1; }
		}
		Node1* tmp2 = FindPrivateId1(id, node->right);
		if (tmp2 != NULL) {
			if (id == tmp2->id) { return tmp2; }
		}
	}
	Node2* FindPrivateId2(int id, Node2* node) {
		if (node == NULL) return node;
		if (id == node->id) {
			return node;
		}
		Node2* tmp1 = FindPrivateId2(id, node->left);
		if (tmp1 != NULL) {
			if (id == tmp1->id) { return tmp1; }
		}
		Node2* tmp2 = FindPrivateId2(id, node->right);
		if (tmp2 != NULL) {
			if (id == tmp2->id) { return tmp2; }
		}
	}
	Node3* FindPrivateId3(int id, Node3* node)
	{
		while (node)
		{
			if (id == node->id) { return node; }
			if (node->child)
			{
				FindPrivateId3(id, node->child);
			}
			node = node->next;
		}
		return 0;
	}
};
template <class T>
class Functions3 :public BinarySearchTree<string>, public BinaryTree<string>, public TreeChildrenList<string> {
public:
	void FindByTheWay(int a) {
		bool count = false, i = 0;
		int n;
		cout << "Введите длину маршрута" << endl;
		cin >> n;
		bool* mas = new bool[n];
		cout << "Заполните маршрут" << endl;
		for (int j = 0; j < n; j++) {
			cin >> mas[j];
		}
		if (a == 1) {
			if (FindByTheWayPrivate1(mas, BinarySearchTree::root, count, i, n) == 0)
			{
				cout << "Такого нема";
			}
		}
		else if (a == 2) {
			if (FindByTheWayPrivate2(mas, BinaryTree::root, count, i, n) == 0)
			{
				cout << "Такого нема";
			}
		}
		else {
			if (FindByTheWayPrivate3(mas, TreeChildrenList::root, count, i, n) == 0)
			{
				cout << "Такого нема";
			}
		}
		delete[]mas;
		system("pause");
	}
	void Delete(int a, int b)
	{
		if (b == 1) {
			T inf;
			cout << "Введите, что хотите удалить" << endl;
			cin >> inf;
			if (a == 1)
			{
				Node1* ptr = FindPrivate1(inf, BinarySearchTree::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else  (BinarySearchTree::RemoveNode(ptr, BinarySearchTree::root, 1));
			}
			else if (a == 2)
			{
				Node2* ptr = FindPrivate2(inf, BinaryTree::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (BinaryTree::RemoveNode(ptr, BinaryTree::root, 1));
			}
			else if (a == 3)
			{
				Node3* ptr = FindPrivate3(inf, TreeChildrenList::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (TreeChildrenList::RemoveNode(ptr, TreeChildrenList::root, 1));
			}
		}
		else if (b == 2) {
			PrintPreOrder(a);
			int id;
			cout << "Введите id" << endl;
			cin >> id;
			if (a == 1)
			{
				Node1* ptr = FindPrivateId1(id, BinarySearchTree::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else  (BinarySearchTree::RemoveNode(ptr, BinarySearchTree::root, 1));
			}
			else if (a == 2)
			{
				Node2* ptr = FindPrivateId2(id, BinaryTree::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (BinaryTree::RemoveNode(ptr, BinaryTree::root, 1));
			}
			else if (a == 3)
			{
				Node3* ptr = FindPrivateId3(id, TreeChildrenList::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (TreeChildrenList::RemoveNode(ptr, TreeChildrenList::root, 1));
			}
		}
		else if (b == 3)
		{
			PrintPreOrder(a);
			int id;
			cout << "Введите id отца" << endl;
			cin >> id;
			if (a == 1)
			{
				Node1* ptr = FindPrivateId1(id, BinarySearchTree::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else  (BinarySearchTree::RemoveNode(ptr, BinarySearchTree::root, 2));
			}
			else if (a == 2)
			{
				Node2* ptr = FindPrivateId2(id, BinaryTree::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (BinaryTree::RemoveNode(ptr, BinaryTree::root, 2));
			}
			else if (a == 3)
			{
				Node3* ptr = FindPrivateId3(id, TreeChildrenList::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (TreeChildrenList::RemoveNode(ptr, TreeChildrenList::root, 2));
			}
		}
	}
	void AddLeaf(int a) {
		T inf;
		cout << "Введите информацию" << endl;
		cin >> inf;
		if (a == 1) { BinarySearchTree::AddLeaf(inf, BinarySearchTree::root); }
		else if (a == 2) { BinaryTree::root = AddLeaf1(BinaryTree::root, BinaryTree::creat_leaf(inf, 0)); }
		else if (a == 3) { TreeChildrenList::AddLeaf(inf, TreeChildrenList::root); }
	}
	void AddLeaf_vect(int a) {
		int n;
		T inf;
		vector<T> v;
		cout << "Размер вектора: " << endl;
		cin >> n;
		cout << "Заполните вектор" << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> inf;
			v.push_back(inf);
		}
		if (a == 1) { BinarySearchTree::AddLeaf_v(v, BinarySearchTree::root); }
		else if (a == 2) { BinaryTree::root = AddLeaf1_v(BinaryTree::root, BinaryTree::creat_leaf_v(v, 0)); }
		else if (a == 3) { TreeChildrenList::AddLeaf_v(v, TreeChildrenList::root); }
	}
	void Find(int a) {
		T inf;
		cout << "Введите, что хотите найти" << endl;
		cin >> inf;
		if (a == 1)
		{
			Node1* ptr = FindPrivate1(inf, BinarySearchTree::root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }
			else(cout << ptr->id << ". " << ptr->data << endl);
			system("pause");
		}
		else if (a == 2)
		{
			Node2* ptr = FindPrivate2(inf, BinaryTree::root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }
			else(cout << ptr->id << ". " << ptr->data << endl);
			system("pause");
		}
		else if (a == 3)
		{
			Node3* ptr = FindPrivate3(inf, TreeChildrenList::root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }
			else(cout << ptr->id << ". " << ptr->data << endl);
			system("pause");
		}
	}
	void PrintInOrder(int a) {
		if (a == 1) { PrintInOrderPrivate1(BinarySearchTree::root); }
		else if (a == 2) { PrintInOrderPrivate2(BinaryTree::root); }
		else if (a == 3) { PrintPreOrderPrivate3(TreeChildrenList::root); }
		system("pause");
	}
	void PrintInOrder_vect(int a) {
		if (a == 1) { PrintInOrderPrivate1_vect(BinarySearchTree::root); }
		else if (a == 2) { PrintInOrderPrivate2_vect(BinaryTree::root); }
		else if (a == 3) { PrintPreOrderPrivate3_vect(TreeChildrenList::root); }
		system("pause");
	}
	void PrintPostOrder(int a) {
		if (a == 1) { PrintPostOrderPrivate1(BinarySearchTree::root); }
		else if (a == 2) { PrintPostOrderPrivate2(BinaryTree::root); }
		else if (a == 3) { PrintPreOrderPrivate3(TreeChildrenList::root); }
		system("pause");
	}
	void PrintPostOrder_vect(int a) {
		if (a == 1) { PrintPostOrderPrivate1_vect(BinarySearchTree::root); }
		else if (a == 2) { PrintPostOrderPrivate2_vect(BinaryTree::root); }
		else if (a == 3) { PrintPreOrderPrivate3_vect(TreeChildrenList::root); }
		system("pause");
	}
	void PrintPreOrder(int a) {
		if (a == 1) { PrintPreOrderPrivate1(BinarySearchTree::root); }
		else if (a == 2) { PrintPreOrderPrivate2(BinaryTree::root); }
		else if (a == 3) { PrintPreOrderPrivate3(TreeChildrenList::root); }
		system("pause");
	}
	void PrintPreOrder_vect(int a) {
		if (a == 1) { PrintPreOrderPrivate1_vect(BinarySearchTree::root); }
		else if (a == 2) { PrintPreOrderPrivate2_vect(BinaryTree::root); }
		else if (a == 3) { PrintPreOrderPrivate3_vect(TreeChildrenList::root); }
		system("pause");
	}
	void Find_vect(int a) {
		T inf;
		vector<T> v;
		int n;
		cout << "Введите размер вектора" << endl;
		cin >> n;
		cout << "Введите, что хотите найти" << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> inf;
			v.push_back(inf);
		}
		if (a == 1)
		{
			Node1* ptr = FindPrivate1_vect(v, BinarySearchTree::root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }                       //тут почемуто не работает но такое же в удалении работает
			else {
				cout << ptr->id << ". ";
				for (int i = 0; i < n; i++)
				{
					cout << v[i];
				}
			}
			system("pause");
		}
		if (a == 2)
		{
			Node2* ptr = FindPrivate2_vect(v, BinaryTree::root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }
			else {
				cout << ptr->id << ". ";
				for (int i = 0; i < n; i++)
				{
					cout << v[i];
				}
			}
			system("pause");
		}
		if (a == 3)
		{
			Node3* ptr = FindPrivate3_vect(v, TreeChildrenList::root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }
			else {
				cout << ptr->id << ". ";
				for (int i = 0; i < n; i++)
				{
					cout << v[i];
				}
			}
			system("pause");
		}
	}
	void Delete_vect(int a, int b)
	{
		if (b == 1) {
			T inf;
			vector<T> v;
			int n;
			cout << "Введите размер вектора, который хотите удалить" << endl;
			cin >> n;
			cout << "Введите, что хотите удалить" << endl;
			for (int i = 0; i < n; i++)
			{
				cin >> inf;
				v.push_back(inf);
			}
			if (a == 1)
			{
				Node1* ptr = FindPrivate1_vect(v, BinarySearchTree::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else  (BinarySearchTree::RemoveNode_vect(ptr, BinarySearchTree::root, a));
			}
			else if (a == 2)
			{
				Node2* ptr = FindPrivate2_vect(v, BinaryTree::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (BinaryTree::RemoveNode_vect(ptr, BinaryTree::root, a));
			}
			else if (a == 3)
			{
				Node3* ptr = FindPrivate3_vect(v, TreeChildrenList::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (TreeChildrenList::RemoveNode_vect(ptr, TreeChildrenList::root, a));
			}

		}
		else if (b == 2) {
			PrintPreOrder_vect(a);
			int id;
			cout << "Введите id" << endl;
			cin >> id;
			if (a == 1)
			{
				Node1* ptr = FindPrivateId1(id, BinarySearchTree::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else  (BinarySearchTree::RemoveNode_vect(ptr, BinarySearchTree::root, a));
			}
			else if (a == 2)
			{
				Node2* ptr = FindPrivateId2(id, BinaryTree::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (BinaryTree::RemoveNode_vect(ptr, BinaryTree::root, a));
			}
		}
		else if (b == 3)
		{
			PrintPreOrder_vect(a);
			int id;
			cout << "Введите id отца" << endl;
			cin >> id;
			if (a == 1)
			{
				Node1* ptr = FindPrivateId1(id, BinarySearchTree::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else  (BinarySearchTree::RemoveNode_vect(ptr, BinarySearchTree::root, 2));
			}
			else if (a == 2)
			{
				Node2* ptr = FindPrivateId2(id, BinaryTree::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (BinaryTree::RemoveNode_vect(ptr, BinaryTree::root, 2));
			}
		}
	}
private:
	bool FindByTheWayPrivate1(bool* mas, Node1* node, bool count, int i, int n) {
		if (node != NULL)
		{
			if (i == n)
			{
				cout << node->data << endl;
				count = true;
			}
			else
			{
				if (mas[i] == 0)
				{
					i++;
					FindByTheWayPrivate1(mas, node->left, count, i, n);
				}
				else
				{
					i++;
					FindByTheWayPrivate1(mas, node->right, count, i, n);
				}
			}
		}
		else { return count; }
	}
	bool FindByTheWayPrivate2(bool* mas, Node2* node, bool count, int i, int n) {
		if (node != NULL)
		{
			if (i == n)
			{
				cout << node->data << endl;
				count = true;
			}
			else
			{
				if (mas[i] == 0)
				{
					i++;
					FindByTheWayPrivate2(mas, node->left, count, i, n);
				}
				else
				{
					i++;
					FindByTheWayPrivate2(mas, node->right, count, i, n);
				}
			}
		}
		else { return count; }
	}
	bool FindByTheWayPrivate3(bool* mas, Node3* node, bool count, int i, int n) {
		if (node != NULL)
		{
			if (i == n)
			{
				cout << node->data << endl;
				count = true;
			}
			else
			{
				if (mas[i] == 0)
				{
					i++;
					FindByTheWayPrivate3(mas, node->child, count, i, n);
				}
				else
				{
					i++;
					FindByTheWayPrivate3(mas, node->next, count, i, n);
				}
			}
		}
		else { return count; }
	}
	void PrintInOrderPrivate1(Node1* node)
	{
		if (BinarySearchTree::root != NULL)
		{
			if (node->left != NULL)
			{
				PrintInOrderPrivate1(node->left);
			}
			cout << node->id << ". ";
			cout << node->data << endl;
			if (node->right != NULL)
			{
				PrintInOrderPrivate1(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	}
	void PrintInOrderPrivate2(Node2* node) {
		if (BinaryTree::root != NULL)
		{
			if (node->left != NULL)
			{
				PrintInOrderPrivate2(node->left);
			}
			cout << node->id << ". ";
			cout << node->data << endl;
			if (node->right != NULL)
			{
				PrintInOrderPrivate2(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	};
	void PrintPreOrderPrivate1(Node1* node) {
		if (node != NULL)
		{
			cout << node->id << ".";
			cout << node->data << endl;
			if (node->left != NULL)
			{
				PrintPreOrderPrivate1(node->left);
			}
			if (node->right != NULL)
			{
				PrintPreOrderPrivate1(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPreOrderPrivate2(Node2* node) {
		if (node != NULL)
		{
			cout << node->id << ".";
			cout << node->data << endl;
			if (node->left != NULL)
			{
				PrintPreOrderPrivate2(node->left);
			}
			if (node->right != NULL)
			{
				PrintPreOrderPrivate2(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPreOrderPrivate3(Node3* node)
	{
		while (node)
		{
			cout << node->id << ". " << node->data;
			if (node->child)
			{
				PrintPreOrderPrivate3(node->child);
			}
			node = node->next;
		}
	}
	void PrintPostOrderPrivate1(Node1* node)
	{
		if (node != NULL)
		{
			if (node->left != NULL)
			{
				PrintPostOrderPrivate1(node->left);
			}
			if (node->right != NULL)
			{
				PrintPostOrderPrivate1(node->right);
			}
			cout << node->id << ".";
			cout << node->data << endl;
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPostOrderPrivate2(Node2* node)
	{
		if (node != NULL)
		{
			if (node->left != NULL)
			{
				PrintPostOrderPrivate2(node->left);
			}
			if (node->right != NULL)
			{
				PrintPostOrderPrivate2(node->right);
			}
			cout << node->id << ".";
			cout << node->data << endl;
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPreOrderPrivate1_vect(Node1* node) {
		if (node != NULL)
		{
			cout << node->id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
			if (node->left != NULL)
			{
				PrintPreOrderPrivate1_vect(node->left);
			}
			if (node->right != NULL)
			{
				PrintPreOrderPrivate1_vect(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPreOrderPrivate2_vect(Node2* node) {
		if (node != NULL)
		{
			cout << node->id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
			if (node->left != NULL)
			{
				PrintPreOrderPrivate2_vect(node->left);
			}
			if (node->right != NULL)
			{
				PrintPreOrderPrivate2_vect(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPreOrderPrivate3_vect(Node3* node)
	{
		while (node)
		{
			cout << node->id << ". ";
			for (int i = 0; i < node->v.size(); i++) {
				cout << node->v[i] << " ";
			}
			cout << endl;
			if (node->child)
			{
				PrintPreOrderPrivate3_vect(node->child);
			}
			node = node->next;
		}
	}
	void PrintPostOrderPrivate1_vect(Node1* node)
	{
		if (node != NULL)
		{
			if (node->left != NULL)
			{
				PrintPostOrderPrivate1_vect(node->left);
			}
			if (node->right != NULL)
			{
				PrintPostOrderPrivate1_vect(node->right);
			}
			cout << node->id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPostOrderPrivate2_vect(Node2* node)
	{
		if (node != NULL)
		{
			if (node->left != NULL)
			{
				PrintPostOrderPrivate2_vect(node->left);
			}
			if (node->right != NULL)
			{
				PrintPostOrderPrivate2_vect(node->right);
			}
			cout << node->id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
		}
		else(cout << "Пусто" << endl);
	}
	void PrintInOrderPrivate1_vect(Node1* node)
	{
		if (BinarySearchTree::root != NULL)
		{
			if (node->left != NULL)
			{
				PrintInOrderPrivate1_vect(node->left);
			}
			cout << node->id << ". ";
			for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
			if (node->right != NULL)
			{
				PrintInOrderPrivate1_vect(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	};
	void PrintInOrderPrivate2_vect(Node2* node)
	{
		if (BinaryTree::root != NULL)
		{
			if (node->left != NULL)
			{
				PrintInOrderPrivate2(node->left);
			}
			cout << node->id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
			if (node->right != NULL)
			{
				PrintInOrderPrivate2(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	};
	Node1* FindPrivate1(T e, Node1* node)
	{
		if (node != NULL)
		{
			if (node->data == e)
			{
				return node;
			}
			else
			{
				if (e <= node->data)
				{
					FindPrivate1(e, node->left);
				}
				else if (e > node->data)
				{
					FindPrivate1(e, node->right);
				}
			}
		}
		else { return node; }
	}
	Node2* FindPrivate2(T inf, Node2* node)
	{
		if (node == NULL) return node;

		if (inf == node->data) {
			return node;
		}
		Node2* tmp1 = FindPrivate2(inf, node->left);
		if (tmp1 != NULL) {
			if (inf == tmp1->data) { return tmp1; }
		}
		Node2* tmp2 = FindPrivate2(inf, node->right);
		if (tmp2 != NULL) {
			if (inf == tmp2->data) { return tmp2; }
		}
	}
	Node3* FindPrivate3(T e, Node3* node) {
		if (node != NULL)
		{
			if (node->data == e)
			{
				return node;
			}
			else

			{
				if (node->child) {
					if (e <= node->child->data)
					{
						FindPrivate3(e, node->child);
					}
					else if (e > node->child->data)
					{
						FindPrivate3(e, node->child->next);
					}
				}
				else {
					FindPrivate3(e, node->next);
				}
			}
		}
		else { return node; }
	}
	Node1* FindPrivate1_vect(vector<T> v, Node1* node)
	{
		if (node != NULL)
		{

			if (node->v == v)
			{
				return node;
			}
			else
			{
				if (v[0] <= node->v[0])
				{
					FindPrivate1_vect(v, node->left);
				}
				else if (v[0] > node->v[0])
				{
					FindPrivate1_vect(v, node->right);
				}
			}
		}
		else {
			return 0;
		}
	}
	Node2* FindPrivate2_vect(vector<T> v, Node2* node)
	{
		if (node == NULL) return node;

		if (v == node->v) { return node; }
		Node2* tmp1 = FindPrivate2_vect(v, node->left);
		if (tmp1 != NULL) {
			if (v.size() == tmp1->v.size() && v == node->v)
			{
				return tmp1;
			}
		}
		Node2* tmp2 = FindPrivate2_vect(v, node->right);
		if (tmp2 != NULL) {
			if (v.size() == tmp2->v.size() && v == node->v)
			{
				return tmp2;
			}
		}
	}
	Node3* FindPrivate3_vect(vector<T> v, Node3* node)
	{
		if (node != NULL)
		{
			if (node->v == v)
			{
				return node;
			}
			else
			{
				if (node->child) {
					if (v[0] <= node->child->v[0])
					{
						FindPrivate3_vect(v, node->child);
					}
					else if (v[0] > node->child->v[0])
					{
						FindPrivate3_vect(v, node->child->next);
					}
				}
				else {
					FindPrivate3_vect(v, node->next);
				}
			}
		}
		else { return node; }
	}
	Node1* FindPrivateId1(int id, Node1* node) {
		if (node == NULL) return node;
		if (id == node->id) {
			return node;
		}
		Node1* tmp1 = FindPrivateId1(id, node->left);
		if (tmp1 != NULL) {
			if (id == tmp1->id) { return tmp1; }
		}
		Node1* tmp2 = FindPrivateId1(id, node->right);
		if (tmp2 != NULL) {
			if (id == tmp2->id) { return tmp2; }
		}
	}
	Node2* FindPrivateId2(int id, Node2* node) {
		if (node == NULL) return node;
		if (id == node->id) {
			return node;
		}
		Node2* tmp1 = FindPrivateId2(id, node->left);
		if (tmp1 != NULL) {
			if (id == tmp1->id) { return tmp1; }
		}
		Node2* tmp2 = FindPrivateId2(id, node->right);
		if (tmp2 != NULL) {
			if (id == tmp2->id) { return tmp2; }
		}
	}
	Node3* FindPrivateId3(int id, Node3* node)
	{
		while (node)
		{
			if (id == node->id) { return node; }
			if (node->child)
			{
				FindPrivateId3(id, node->child);
			}
			node = node->next;
		}
		return 0;
	}
};