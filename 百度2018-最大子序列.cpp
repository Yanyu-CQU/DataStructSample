#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
/***********************************************************************
链接：https://www.nowcoder.com/questionTerminal/17ba5b5df1fc49ca8d6cf8ea407b1972
来源：牛客网

对于字符串x和y, 如果擦除x中的某些字母(有可能全擦掉或者都不擦)能够得到y,我们就称y是x的子序列。例如."ncd"是"nowcoder"的子序列,而"xt"不是。
现在对于给定的一个字符串s,请计算出字典序最大的s的子序列。
输入描述:
输入包括一行,一个字符串s,字符串s长度length(1 ≤ length ≤ 50).
s中每个字符都是小写字母


输出描述:
输出一个字符串,即字典序最大的s的子序列。
示例1
输入
test
输出
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
