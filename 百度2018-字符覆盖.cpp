#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
/***********************************************************************
���ӣ�https://www.nowcoder.com/questionTerminal/d7ae059c1cee491989412c4fa39d4384?orderByHotValue=1&page=1&onlyReference=false
��Դ��ţ����

С����һ��Сд��ĸ��ɵ��ַ���s.�ַ���s�Ѿ���д��ǽ����.
С�Ȼ��кܶ࿨Ƭ,ÿ����Ƭ����һ��Сд��ĸ,���һ���ַ���t��С�ȿ���ѡ���ַ���t������һ���ַ�,Ȼ�󸲸����ַ���s��һ���ַ�֮�ϡ�С����֪����ѡȡһЩ��Ƭ����s��һЩ�ַ�֮��,���Եõ����ֵ��������ַ�����ʲô��
��������:
�����������,��һ��һ���ַ���s,�ַ���s����length(1 �� length �� 50),s��ÿ���ַ�����Сд��ĸ
�ڶ���һ���ַ���t,�ַ���t����length(1 �� length �� 50),t��ÿ���ַ�����Сд��ĸ


�������:
���һ���ַ���,�����Եõ����ֵ�������ַ���
ʾ��1
����
fedcba
ee
���
feeeba
********************************************************************/

void replace(string & s, string & t)
{
	sort(t.begin(), t.end(), [](char a, char b) {
		return a > b;
	});
	int index = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if (index >= t.size()) break;
		if (t[index] > s[i]) s[i] = t[index++];
	}
}


int main()
{
	string s, t;
	while (cin >> s >> t)
	{
		replace(s, t);
		cout << s << endl;
	}
	return 0;
}
