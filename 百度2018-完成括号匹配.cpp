#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
/***********************************************************************
���ӣ�https://www.nowcoder.com/questionTerminal/fe8d6a1b88af4ba6b4dbb10972059040
��Դ��ţ����

�Ϸ�������ƥ�����б�����Ϊ:
1. �մ�""�ǺϷ�����������
2. ���"X"��"Y"�ǺϷ�������,��ô"XY"Ҳ��һ���Ϸ�����������
3. ���"X"��һ���Ϸ�������,��ô"[X]"Ҳ��һ���Ϸ�����������
4. ÿ���Ϸ����������ж�����������Ĺ�������
����"", "[]", "[][][]", "[[][]]", "[[[[]]]]"���ǺϷ��ġ�
ţţ���ڸ���һ����������s,ţţ������ִ�еĲ�����:��s�Ŀ�ʼ�ͽ�β�����һ��������������('[')����������(']')ʹ���Ϊһ���Ϸ�������ƥ�����С�ţţϣ���������������ٵ�����֮��ĺϷ�������ƥ��������ʲô��
��������:
�������һ���ַ���s,s�ĳ���length(1 �� length �� 50),s��ֻ����'['��']'��


�������:
���һ���ַ���,��ʾ������ȫƥ������С�
ʾ��1
����
][
���
[][]
********************************************************************/


void match(string & str)
{
	vector<char> left, right;
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == '[')
		{
			left.push_back('[');
		}
		if (str[i] == ']')
		{
			if (left.size() == 0)
			{
				str.insert(str.begin(), '[');
				i++;
			}
			else
			{
				left.pop_back();
			}
		}
	}
	for (int i = str.size() - 1; i >= 0; --i)
	{
		if (str[i] == ']')
		{
			right.push_back(']');
		}
		if (str[i] == '[')
		{
			if (right.size() == 0)
			{
				str.insert(str.end(), ']');
			}
			else
			{
				right.pop_back();
			}
		}
	}
	
}

int main()
{
	string str;
	while (cin >> str)
	{
		match(str);
		cout << str << endl;
	}
	return 0;
}
