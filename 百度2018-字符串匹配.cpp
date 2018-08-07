#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;
/***********************************************************************
链接：https://www.nowcoder.com/questionTerminal/6e6ad6338289498da79b7afb60e823b3
来源：牛客网

牛牛有两个字符串A和B, 其中A串是一个01串, B串中除了可能有0和1, 还可能有'?', B中的'?'可以确定为0或者1。 寻找一个字符串T是否在字符串S中出现的过程, 称为字符串匹配。牛牛现在考虑所有可能的字符串B, 有多少种可以在字符串A中完成匹配。

例如 : A = "00010001", B = "??"
	字符串B可能的字符串是"00", "01", "10", "11", 只有"11"没有出现在字符串A中, 所以输出3

	输入描述 :
输入包括两行, 第一行一个字符串A, 字符串A长度length(1 ≤ length ≤ 50), A中每个字符都是'0'或者'1'。
第二行一个字符串B, 字符串B长度length(1 ≤ length ≤ 50), B中的字符包括'0', '1'和'?'。


输出描述 :
输出一个整数, 表示能完成匹配的字符串种数。
示例1
输入
00010001
? ?
输出
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
