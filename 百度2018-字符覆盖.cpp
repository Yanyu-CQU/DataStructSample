#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
/***********************************************************************
链接：https://www.nowcoder.com/questionTerminal/d7ae059c1cee491989412c4fa39d4384?orderByHotValue=1&page=1&onlyReference=false
来源：牛客网

小度有一个小写字母组成的字符串s.字符串s已经被写在墙上了.
小度还有很多卡片,每个卡片上有一个小写字母,组成一个字符串t。小度可以选择字符串t中任意一个字符,然后覆盖在字符串s的一个字符之上。小度想知道在选取一些卡片覆盖s的一些字符之后,可以得到的字典序最大的字符串是什么。
输入描述:
输入包括两行,第一行一个字符串s,字符串s长度length(1 ≤ length ≤ 50),s中每个字符都是小写字母
第二行一个字符串t,字符串t长度length(1 ≤ length ≤ 50),t中每个字符都是小写字母


输出描述:
输出一个字符串,即可以得到的字典序最大字符串
示例1
输入
fedcba
ee
输出
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
