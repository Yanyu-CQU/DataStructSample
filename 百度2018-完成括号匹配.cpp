#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
/***********************************************************************
链接：https://www.nowcoder.com/questionTerminal/fe8d6a1b88af4ba6b4dbb10972059040
来源：牛客网

合法的括号匹配序列被定义为:
1. 空串""是合法的括号序列
2. 如果"X"和"Y"是合法的序列,那么"XY"也是一个合法的括号序列
3. 如果"X"是一个合法的序列,那么"[X]"也是一个合法的括号序列
4. 每个合法的括号序列都可以由上面的规则生成
例如"", "[]", "[][][]", "[[][]]", "[[[[]]]]"都是合法的。
牛牛现在给出一个括号序列s,牛牛允许你执行的操作是:在s的开始和结尾处添加一定数量的左括号('[')或者右括号(']')使其变为一个合法的括号匹配序列。牛牛希望你能求出添加最少的括号之后的合法的括号匹配序列是什么。
输入描述:
输入包括一个字符串s,s的长度length(1 ≤ length ≤ 50),s中只包含'['和']'。


输出描述:
输出一个字符串,表示括号完全匹配的序列。
示例1
输入
][
输出
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
