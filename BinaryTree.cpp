#include <iostream>
#include <queue>
#define max(a,b) (a > b ? a : b)
struct BinNode
{
	int val;
	BinNode* left;
	BinNode* right;
	BinNode(int v = 0, BinNode* l = nullptr, BinNode* r = nullptr) : val(v), left(l), right(r) {}
};
//求二叉树节点个数 
int getNodeNum(BinNode* node)
{
	if (node == nullptr) return 0;
	return getNodeNum(node->left) + getNodeNum(node->right) + 1;
}

//求二叉树高度
int getHeight(BinNode* node)
{
	if (node == nullptr) return 0;
	int lH = getHeight(node->left);
	int rH = getHeight(node->right);

	return max(lH,rH) + 1;
} 

//前序遍历
//从头开始，一边打印一边向左走到底
//无路可走，向上一层找分支，一路向左走到底 
void preVisit(BinNode* node)
{
	if (node == nullptr) return;
	std::cout << node->val << std::endl;
	preVisit(node->left);
	preVisit(node->right);
}

//后序遍历
//顺着根一路向下走到底，然后打印
//无路可走，向上一层，先不打印，如果还有分支，一路走到底再打印 
void postVisit(BinNode* node)
{
	if (node == nullptr) return;
	postVisit(node->left);
	postVisit(node->right);
	std::cout << node->val << std::endl;
}

//中序遍历
//从左向右遍历 
void midVisit(BinNode* node)
{
	if (node == nullptr) return;
	midVisit(node->left);
	std::cout << node->val << std::endl;
	midVisit(node->right);
}

//分层打印
void levelPrint(BinNode* root)
{
	if (root == nullptr) return;
	BinNode* pNode = root, *pTemp = root;
	std::queue<BinNode*> qu;
	qu.push(pNode);
	while (qu.size() != 0)
	{
		pTemp = qu.front();
		std::cout << pTemp->val << "\t";
		if (pTemp->left != nullptr)
			qu.push(pTemp->left);
		if (pTemp->right != nullptr)
			qu.push(pTemp->right);
		qu.pop();
	}
	std::cout << "\n";
}

//分层打印并且换行 
void levelPrintln(BinNode* root)
{
	if (root == nullptr) return;
	BinNode* pNode = root, *pTemp = root;
	std::queue<BinNode*> qu,next;
	qu.push(pNode);
	while (qu.size() != 0)
	{
		while (qu.size() != 0)
		{
			pTemp = qu.front();
			std::cout << pTemp->val << "\t";
			if (pTemp->left != nullptr)
				next.push(pTemp->left);
			if (pTemp->right != nullptr)
				next.push(pTemp->right);
			qu.pop();
		}
		qu.swap(next);
		std::cout << "\n";
	}
}

//求第K层节点数,层数从1开始 
int getKthNodeNum(BinNode* node, int k)
{
	if (node == nullptr) return 0;
	if (k == 1) return 1;
	return getKthNodeNum(node->left,k - 1) + getKthNodeNum(node->right, k - 1);
}

//求叶子结点个数
int getLeafNodeNum(BinNode* node)
{
	if (node == nullptr) return 0;
	else if (node->left == nullptr && node->right == nullptr) return 1;
	else
	{
		return getLeafNodeNum(node->left) + getLeafNodeNum(node->right);
	}
}

//判断两棵树结构是否一样
bool isSameStruct(BinNode* node1, BinNode* node2)
{
	if (node1 == nullptr && node2 == nullptr) return true;
	else if (node1 == nullptr || node2 == nullptr) return false;
	return isSameStruct(node1->left, node2->left) && isSameStruct(node1->right, node2->right);
}

//转换为双向链表
//对于搜索二叉树，转换为排序双向链表
void convertDbList(BinNode* root, BinNode* &pFirst, BinNode* &pLast)//开始和结尾指针必须是引用
{
	BinNode *pLeftFir = nullptr, *pLeftLst = nullptr, *pRightFir = nullptr, *pRightLst = nullptr;
	if (root == nullptr)
	{
		pFirst = nullptr;
		pLast = nullptr;
		return;
	}
	if (root->left == nullptr)
	{
		pFirst = root;
	}
	else
	{
		convertDbList(root->left, pLeftFir, pLeftLst);
		root->left = pLeftLst;
		pLeftLst->right = root;
		pFirst = pLeftFir;//注意要把分支的头尾赋给合并的头尾
	}

	if (root->right == nullptr)
	{
		pLast = root;
	}
	else
	{
		convertDbList(root->right, pRightFir, pRightLst);
		root->right = pRightFir;
		pRightFir->left = root;
		pLast = pRightLst;
	}
	return;
}

//打印双向链表
void printDbList(BinNode* first, BinNode* last)
{
	BinNode* temp = first;
	std::cout << "from head to tail: \n";
	while (temp != nullptr)
	{
		std::cout << temp->val << "\t";
		temp = temp->right;
	}
	std::cout << "\n";
	temp = last;
	std::cout << "from tail to head: \n";
	while (temp != nullptr)
	{
		std::cout << temp->val << "\t";
		temp = temp->left;
	}
	std::cout << "\n";
}
int main()
{
	BinNode* root = new BinNode(1);			BinNode* root1 = new BinNode(1);
	root->left = new BinNode(2);			root1->left = new BinNode(2);
	root->right = new BinNode(3);			root1->right = new BinNode(3);
	root->left->left = new BinNode(4);		root1->left->left = new BinNode(4);
	root->left->right = new BinNode(5);		root1->left->right = new BinNode(5);
	root->right->left = new BinNode(6);		root1->right->left = new BinNode(6);
	root->right->right = new BinNode(7);	//root1->right->right = new BinNode(7);

	std::cout << "get number of tree when tree have 1,2,3,4,5 node:	" << std::endl;
	std::cout << getNodeNum(root) << std::endl;

	std::cout << "get height of tree: " << std::endl;
	std::cout << getHeight(root) << std::endl;

	std::cout << "pre visit: " << std::endl;
	preVisit(root);

	std::cout << "post visit when have 1,2,3,4,5,6,7: " << std::endl;
	postVisit(root);

	std::cout << "mid visit: " << std::endl;
	midVisit(root);

	std::cout << "level print: " << std::endl;
	levelPrint(root);

	std::cout << "level print by lines: " << std::endl;
	levelPrintln(root);

	//std::cout << "get node num at 3rd level: " << std::endl;
	std::cout << "get node num at 3rd level: " << getKthNodeNum(root,3) << std::endl;

	//std::cout << "get leaf node num: " << std::endl;
	std::cout << "get leaf node num: " << getLeafNodeNum(root) << std::endl;

	std::cout << "is root ans root1 have same struct: " << isSameStruct(root, root1) << std::endl;

	std::cout << "convert into double list, if thr tree is a search tree, the list will be sorted" << std::endl;
	BinNode *first = nullptr, *last = nullptr;
	convertDbList(root, first, last);
	printDbList(first, last);

	return 1;
}
