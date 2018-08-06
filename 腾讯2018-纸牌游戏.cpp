#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/************************************************************************/
/* 链接：https://www.nowcoder.com/questionTerminal/ebec6fac8a834bf7aed2d5da7c8aa432
来源：牛客网

牛牛和羊羊正在玩一个纸牌游戏。这个游戏一共有n张纸牌, 第i张纸牌上写着数字ai。
牛牛和羊羊轮流抽牌, 牛牛先抽, 每次抽牌他们可以从纸牌堆中任意选择一张抽出, 直到纸牌被抽完。
他们的得分等于他们抽到的纸牌数字总和。
现在假设牛牛和羊羊都采用最优策略, 请你计算出游戏结束后牛牛得分减去羊羊得分等于多少。


输入描述:
输入包括两行。
第一行包括一个正整数n(1 <= n <= 105),表示纸牌的数量。
第二行包括n个正整数ai(1 <= ai <= 109),表示每张纸牌上的数字。


输出描述:
输出一个整数, 表示游戏结束后牛牛得分减去羊羊得分等于多少。
示例1
输入
3
2 7 4
输出
5                                                                     */
/************************************************************************/
int main()
{
	int n = 0;
	while (cin >> n)
	{
		vector<int> pai(n);
		int sum = 0, niuniu = 0;
		for (int i = 0; i < n; ++i) 
		{
			cin >> pai[i];
			sum += pai[i];
		}
		sort(pai.begin(), pai.end(), [](int a, int b) {
			return a > b;
		});
		for (int i = 0; i < n; i += 2) niuniu += pai[i];
		cout << niuniu - (sum - niuniu) << endl;
		
	}
	return 0;
}
