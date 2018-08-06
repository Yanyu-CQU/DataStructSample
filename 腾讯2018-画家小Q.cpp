#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <memory>
#include <vector>
using namespace std;

char picture[55][55] = { 0 };
/*
链接：https://www.nowcoder.com/questionTerminal/6acc6504df67406c98a75f5575e4b94a
来源：牛客网

画家小Q又开始他的艺术创作。小Q拿出了一块有NxM像素格的画板, 画板初始状态是空白的,用'X'表示。
小Q有他独特的绘画技巧,每次小Q会选择一条斜线, 如果斜线的方向形如'/',即斜率为1,小Q会选择这条斜线中的一段格子,都涂画为蓝色,用'B'表示;如果对角线的方向形如'\',即斜率为-1,小Q会选择这条斜线中的一段格子,都涂画为黄色,用'Y'表示。
如果一个格子既被蓝色涂画过又被黄色涂画过,那么这个格子就会变成绿色,用'G'表示。
小Q已经有想画出的作品的样子, 请你帮他计算一下他最少需要多少次操作完成这幅画。
输入描述:
每个输入包含一个测试用例。
每个测试用例的第一行包含两个正整数N和M(1 <= N, M <= 50), 表示画板的长宽。
接下来的N行包含N个长度为M的字符串, 其中包含字符'B','Y','G','X',分别表示蓝色,黄色,绿色,空白。整个表示小Q要完成的作品。


输出描述:
输出一个正整数, 表示小Q最少需要多少次操作完成绘画。
示例1
输入
4 4
YXXB
XYGX
XBYY
BXXY
输出
3
说明
XXXX
XXXX
XXXX
XXXX
->
YXXX
XYXX
XXYX
XXXY
->
YXXB
XYBX
XBYX
BXXY
->
YXXB
XYGX
XBYY
BXXY
*/
void drawY(char (*p)[55], int x, int y)
{
	int sX = x, sY = y;
	while (sX >= 0 && sY >= 0)
	{
		if (p[sX][sY] == 'Y') p[sX][sY] = 'X';
		else if (p[sX][sY] == 'G') p[sX][sY] = 'B';
		else break;
		sX--;
		sY--;
	}
	sX = x + 1; sY = y + 1;
	while (sX < 55 && sY < 55)
	{
		if (p[sX][sY] == 'Y') p[sX][sY] = 'X';
		else if (p[sX][sY] == 'G') p[sX][sY] = 'B';
		else break;
		sX++;
		sY++;
	}
}

void drawB(char(*p)[55], int x, int y)
{
	int sX = x, sY = y;
	while (sX >= 0 && sY < 55)
	{
		if (p[sX][sY] == 'B') p[sX][sY] = 'X';
		else if (p[sX][sY] == 'G') p[sX][sY] = 'Y';
		else break;
		sX--;
		sY++;
	}
	sX = x + 1; sY = y - 1;
	while (sX < 55 && sY >= 0)
	{
		if (p[sX][sY] == 'B') p[sX][sY] = 'X';
		else if (p[sX][sY] == 'G') p[sX][sY] = 'Y';
		else break;
		sX++;
		sY--;
	}
}

int main()
{
	int n = 0, m = 0;
	while (cin >> n >> m)
	{
		int cnt = 0;
		for (int i = 0; i < n; ++i) scanf("%s", picture[i]);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (picture[i][j] == 'Y')
				{
					drawY(picture, i, j);
					cnt++;
				}
				else if (picture[i][j] == 'B')
				{
					drawB(picture, i, j);
					cnt++;
				}
				else if (picture[i][j] == 'G')
				{
					drawY(picture, i, j);
					cnt++;
					drawB(picture, i, j);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
