#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;
/***********************************************************************
���ӣ�https://www.nowcoder.com/questionTerminal/6e6ad6338289498da79b7afb60e823b3
��Դ��ţ����

ţţ�������ַ���A��B, ����A����һ��01��, B���г��˿�����0��1, ��������'?', B�е�'?'����ȷ��Ϊ0����1�� Ѱ��һ���ַ���T�Ƿ����ַ���S�г��ֵĹ���, ��Ϊ�ַ���ƥ�䡣ţţ���ڿ������п��ܵ��ַ���B, �ж����ֿ������ַ���A�����ƥ�䡣

���� : A = "00010001", B = "??"
	�ַ���B���ܵ��ַ�����"00", "01", "10", "11", ֻ��"11"û�г������ַ���A��, �������3

	�������� :
�����������, ��һ��һ���ַ���A, �ַ���A����length(1 �� length �� 50), A��ÿ���ַ�����'0'����'1'��
�ڶ���һ���ַ���B, �ַ���B����length(1 �� length �� 50), B�е��ַ�����'0', '1'��'?'��


������� :
���һ������, ��ʾ�����ƥ����ַ���������
ʾ��1
����
00010001
? ?
���
3 * /
********************************************************************/

bool isMatch(string a, string b)
{
	for (int i = 0; i < a.size(); ++i)
	{
		if (b[i] != '?' && b[i] != a[i])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	string strA, strB;
	while (cin >> strA >> strB)
	{
		int offset = 0;
		set<string> r;
		for (; offset + strB.size() <= strA.size(); ++offset)
		{
			string cmp = strA.substr(offset, strB.size());
			if (isMatch(cmp, strB))
			{
				r.insert(cmp);
			}
		}
		cout << r.size() << endl;
	}
	return 0;
}
