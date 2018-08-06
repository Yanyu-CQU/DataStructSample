#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <memory>
#include <vector>
using namespace std;
/***********************************************************************

СQ�ĸ�ĸҪ����N�죬��֮ǰ��СQ������M���ɿ�����СQ����ÿ��Ե��ɿ�������������ǰһ��Ե�һ�룬�������ֲ����ڸ�ĸ����֮ǰ��ĳһ��û���ɿ����ԣ���������һ������ܳԶ��ٿ��ɿ���
��������:
ÿ���������һ������������
ÿ�����������ĵ�һ�а�����������������ʾ��ĸ���������N(N<=50000)���ɿ���������M(N<=M<=100000)��


�������:
���һ������ʾСQ��һ������ܳԶ��ٿ��ɿ�����
ʾ��1
����
3 7
���
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
