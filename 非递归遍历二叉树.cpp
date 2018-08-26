
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <stdio.h>
#include <queue>
using namespace std;



struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

void qianxu(TreeNode *root)
{
	if (root == nullptr) return;
	stack<TreeNode*> s;
	TreeNode *cur = root;
	
	while (cur != nullptr || !s.empty())
	{
		while (cur != nullptr)
		{
			cout << cur->val << ' ';
			s.push(cur);
			cur = cur->left;
		}
		if (!s.empty())
		{
			cur = s.top();
			s.pop();
			cur = cur->right;
		}
	}
	cout << endl;
}

void houxu(TreeNode* root) {
	if (!root) return ;
	stack<TreeNode*> st;
	st.push(root);
	TreeNode* cur = NULL;
	TreeNode* pre = NULL;
	while (!st.empty())
	{
		cur = st.top();
		if ((cur->left == NULL&&cur->right == NULL) || (pre && (pre == cur->left || pre == cur->right))) {
			//path.push_back(cur->val);
			cout << cur->val << ' ';
			st.pop();
			pre = cur;
		}
		else {
			if (cur->right) st.push(cur->right);
			if (cur->left) st.push(cur->left);
		}
	}
	return ;
}


int main()
{
	TreeNode* root1 = new TreeNode(8);	TreeNode* root2 = new TreeNode(8);
	root1->left = new TreeNode(8);		root2->left = new TreeNode(9);
	root1->right = new TreeNode(7);		root2->right = new TreeNode(2);
	root1->left->left = new TreeNode(9);
	root1->left->right = new TreeNode(2);
	houxu(root1);
	//system("pause");
	return 0;
}
