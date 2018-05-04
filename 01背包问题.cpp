#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <memory.h>
using namespace std;

struct item 
{
	int val;
	int quanlity;
};
int main()
{
	vector<item> vec;
	item it = {0, 0};
	int cap = 0;
	cin >> cap;
	while (cin >> it.quanlity >> it.val)
	{
		vec.push_back(it);
	}
	vector<vector<int>> res;
	vector<int> temp(cap + 1, 0);
	for (int i = 0; i <= vec.size(); ++i)
	{
		res.push_back(temp);
	}
	for (int i = 1; i <= vec.size(); ++i)
	{
		for (int j = 1; j <= cap; ++j)
		{
			if (j < vec[i - 1].quanlity)
			{
				res[i][j] = res[i - 1][j];
			}
			else
			{
				res[i][j] = max(res[i - 1][j], res[i - 1][j - vec[i - 1].quanlity] + vec[i - 1].val);
			}
		}
	}
	cout << res[vec.size()][cap];
	return 0;
}
