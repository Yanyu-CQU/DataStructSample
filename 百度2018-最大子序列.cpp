#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
/***********************************************************************
���ӣ�https://www.nowcoder.com/questionTerminal/17ba5b5df1fc49ca8d6cf8ea407b1972
��Դ��ţ����

�����ַ���x��y, �������x�е�ĳЩ��ĸ(�п���ȫ�������߶�����)�ܹ��õ�y,���Ǿͳ�y��x�������С�����."ncd"��"nowcoder"��������,��"xt"���ǡ�
���ڶ��ڸ�����һ���ַ���s,�������ֵ�������s�������С�
��������:
�������һ��,һ���ַ���s,�ַ���s����length(1 �� length �� 50).
s��ÿ���ַ�����Сд��ĸ


�������:
���һ���ַ���,���ֵ�������s�������С�
ʾ��1
����
test
���
tt
********************************************************************/

int main()
{
	string s;
	while (cin >> s)
	{
		stringstream ss;
		while (s.size() != 0)
		{
			auto it = max_element(s.begin(), s.end());
			ss << *it;
			s.erase(s.begin(), it + 1);
		}
		ss >> s;
		cout << s << endl;
	}
	return 0;
}
