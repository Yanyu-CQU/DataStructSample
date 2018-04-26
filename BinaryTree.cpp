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
//��������ڵ���� 
int getNodeNum(BinNode* node)
{
	if (node == nullptr) return 0;
	return getNodeNum(node->left) + getNodeNum(node->right) + 1;
}

//��������߶�
int getHeight(BinNode* node)
{
	if (node == nullptr) return 0;
	int lH = getHeight(node->left);
	int rH = getHeight(node->right);
	
	return max(lH,rH) + 1;
} 

//ǰ�����
//��ͷ��ʼ��һ�ߴ�ӡһ�������ߵ���
//��·���ߣ�����һ���ҷ�֧��һ·�����ߵ��� 
void preVisit(BinNode* node)
{
	if (node == nullptr) return;
	std::cout << node->val << std::endl;
	preVisit(node->left);
	preVisit(node->right);
}

//�������
//˳�Ÿ�һ·�����ߵ��ף�Ȼ���ӡ
//��·���ߣ�����һ�㣬�Ȳ���ӡ��������з�֧��һ·�ߵ����ٴ�ӡ 
void postVisit(BinNode* node)
{
	if (node == nullptr) return;
	postVisit(node->left);
	postVisit(node->right);
	std::cout << node->val << std::endl;
}

//�������
//�������ұ��� 
void midVisit(BinNode* node)
{
	if (node == nullptr) return;
	midVisit(node->left);
	std::cout << node->val << std::endl;
	midVisit(node->right);
}

//�ֲ��ӡ
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

//�ֲ��ӡ���һ��� 
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

int main()
{
	BinNode* root = new BinNode(1);
	root->left = new BinNode(2);
	root->right = new BinNode(3);
	root->left->left = new BinNode(4);
	root->left->right = new BinNode(5);
	root->right->left = new BinNode(6);
	root->right->right = new BinNode(7);
	
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
}
