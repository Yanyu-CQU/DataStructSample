#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
/***********************************************************************
���ӣ�https://www.nowcoder.com/questionTerminal/e1630df2759d43258046ef67514e7b25
��Դ��ţ����

һ����Сд��ĸ��ɵ��ַ������Կ���һЩͬһ��ĸ�������Ƭ��ɵġ�����,"aaabbaaac"����������Ƭ��ɵ�:'aaa','bb','c'��ţţ���ڸ���һ���ַ���,���������������ַ�����������Ƭ��ƽ�������Ƕ��١�

��������:
�������һ���ַ���s,�ַ���s�ĳ���length(1 �� length �� 50),sֻ��Сд��ĸ('a'-'z')


�������:
���һ������,��ʾ������Ƭ��ƽ������,�������뱣����λС����

��������ʾ: s = "aaabbaaac"
������Ƭ��ƽ������ = (3 + 2 + 3 + 1) / 4 = 2.25
ʾ��1
����
aaabbaaac
���
2.25
********************************************************************/

float getAvgLen(string str)
{
	int sum = 0, types = 1;
	int cnt = 1;
	char pre = str[0];
	for (int i = 1; i < str.size(); ++i)
	{
		if (str[i] != pre)
		{
			sum += cnt;
			cnt = 1;
			types++;
		}
		else
		{
			cnt++;
		}
		pre = str[i];
	}
	sum += cnt;
	//types++;
	return (float)sum / types;
	
}

int main()
{
	string s;
	while (cin >> s)
	{
		if (s.size() == 0) cout << "0.00" << endl;
		float re = getAvgLen(s);
		printf("%.2f", re);
	}
	return 0;
}
