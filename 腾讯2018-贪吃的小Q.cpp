#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <memory>
#include <vector>
using namespace std;
/***********************************************************************

小Q的父母要出差N天，走之前给小Q留下了M块巧克力。小Q决定每天吃的巧克力数量不少于前一天吃的一半，但是他又不想在父母回来之前的某一天没有巧克力吃，请问他第一天最多能吃多少块巧克力
输入描述:
每个输入包含一个测试用例。
每个测试用例的第一行包含两个正整数，表示父母出差的天数N(N<=50000)和巧克力的数量M(N<=M<=100000)。


输出描述:
输出一个数表示小Q第一天最多能吃多少块巧克力。
示例1
输入
3 7
输出
4                                                                     
**********************************************************************/

bool isEnough(int day, int cnt, int first)
{
	int eat = first;
	for (int i = 0; i < day; ++i)
	{
		if (cnt < eat)
		{
			return false;
		}
		cnt -= eat;
		eat = (eat + 1) / 2;
	}
	return true;
}

int main()
{
	int day = 0, cnt = 0;
	while (cin >> day >> cnt)
	{
		int left = 1, right = cnt, mid = 0;
		while (left != right)
		{
			mid = (left + right + 1) / 2;
			if (isEnough(day, cnt, mid) == true)
			{
				left = mid;
			}
			else
			{
				right = mid - 1;
			}
		}
		cout << left << endl;
	}
	return 0;
}
