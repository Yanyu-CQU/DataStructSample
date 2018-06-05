// DEBUG.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <memory>
#include <queue>
using namespace std;

template <typename T>
class BinNode
{
public:
	T val;
	BinNode *left;
	BinNode *right;
	BinNode(const T & v = 0) : val(v)
	{
		left = nullptr;
		right = nullptr;
	}
};

template <typename T>
class BinSearchTree
{
private:
	
	BinNode<T> *root;
	void insert(const T & t, BinNode<T> * & tree);
	void remove(const T & t, BinNode<T> * & tree);
	BinNode<T> * getMin(BinNode<T> *tree);
	BinNode<T> * getMax(BinNode<T> *tree);
	bool isContain(const T & t, BinNode<T> *tree);
public:
	bool isEmpty() {return root == nullptr;}
	bool isContain(const T & t) {return isContain(t, root);}
	const T & getMin() 
	{
		BinNode<T> *min = getMin(root);
		if (min != nullptr) return min->val;
		else throw exception("No element!");
	}
	const T & getMax()
	{
		BinNode<T> *max = getMax(root);
		if (max != nullptr) return max->val;
		else throw exception("No element!");
	}
	void print();
	void insert(const T & t) {insert(t, root);}
	void remove(const T & t) {remove(t, root);}
	BinSearchTree()
	{
		root = nullptr;
	}
};

template <typename T>
bool BinSearchTree<T>::isContain(const T & t, BinNode<T> *tree)
{
	if (tree == nullptr) return false;
	if (tree->val < t) return isContain(t, tree->right);
	else if (tree->val > t) return isContain(t, tree->left);
	else return true;
}
template <typename T>
BinNode<T>* BinSearchTree<T>::getMin(BinNode<T>* tree)
{
	if (tree == nullptr) return nullptr;
	if (tree->left == nullptr) return tree;
	return getMin(tree->left);
}
template <typename T>
BinNode<T>* BinSearchTree<T>::getMax(BinNode<T> *tree)
{
	if (tree == nullptr) return nullptr;
	if (tree->right == nullptr) return tree;
	return getMax(tree->right);
}
template <typename T>
void BinSearchTree<T>::insert(const T & t, BinNode<T> * & tree)
{
	if (tree == nullptr) tree = new BinNode<T>(t);
	if (t < tree->val) insert(t, tree->left);
	else if (t > tree->val) insert(t, tree->right);
	else ;//不允许元素重复
}
template <typename T>
void BinSearchTree<T>::remove(const T & t, BinNode<T> * & tree)
{
	if (tree == nullptr) return;
	if (t < tree->val) remove(t, tree->left);
	else if (t > tree->val) remove(t, tree->right);
	else if (tree->left != nullptr && tree->right != nullptr)//如果该节点有两个孩子，从右子树中，拷贝最小节点，然后删除该最小节点
	{
		BinNode<T> * min = getMin(tree->right);
		tree->val = min->val;
		remove(min->val, tree->right);
	}
	else//没有子节点，或者只有一个节点
	{
		BinNode<T> * del = tree;
		tree = (tree->left != nullptr) ? tree->left : tree->right;
		delete del;
	}
}
template <typename T>
void BinSearchTree<T>::print()
{
	if (root == nullptr) return;
	queue<BinNode<T>*> q, temp;
	q.push(root);
	while(q.empty() == false)
	{
		while (q.empty() == false)
		{
			BinNode<T> *t = q.front();
			cout << t->val << '\t';
			q.pop();
			if (t->left != nullptr) temp.push(t->left);
			if (t->right != nullptr) temp.push(t->right);
		}
		cout << '\n';
		q = move(temp);
	}
}

int main()
{
	BinSearchTree<int> t;
	t.insert(1);
	t.insert(0);
	t.insert(3);
	t.insert(5);
	t.insert(2);
	t.insert(4);
	t.remove(0);
	t.print();
	cout << t.getMax() << endl;
	cout << t.getMin() << endl;
	cout << t.isContain(3) << endl;
	cout << t.isEmpty() << endl;
	system("pause");
	return 1;
}
