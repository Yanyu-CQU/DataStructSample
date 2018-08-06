#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <memory>
#include <vector>
using namespace std;

char picture[55][55] = { 0 };
/*
���ӣ�https://www.nowcoder.com/questionTerminal/6acc6504df67406c98a75f5575e4b94a
��Դ��ţ����

����СQ�ֿ�ʼ��������������СQ�ó���һ����NxM���ظ�Ļ���, �����ʼ״̬�ǿհ׵�,��'X'��ʾ��
СQ�������صĻ滭����,ÿ��СQ��ѡ��һ��б��, ���б�ߵķ�������'/',��б��Ϊ1,СQ��ѡ������б���е�һ�θ���,��Ϳ��Ϊ��ɫ,��'B'��ʾ;����Խ��ߵķ�������'\',��б��Ϊ-1,СQ��ѡ������б���е�һ�θ���,��Ϳ��Ϊ��ɫ,��'Y'��ʾ��
���һ�����Ӽȱ���ɫͿ�����ֱ���ɫͿ����,��ô������Ӿͻ�����ɫ,��'G'��ʾ��
СQ�Ѿ����뻭������Ʒ������, �����������һ����������Ҫ���ٴβ�������������
��������:
ÿ���������һ������������
ÿ�����������ĵ�һ�а�������������N��M(1 <= N, M <= 50), ��ʾ����ĳ���
��������N�а���N������ΪM���ַ���, ���а����ַ�'B','Y','G','X',�ֱ��ʾ��ɫ,��ɫ,��ɫ,�հס�������ʾСQҪ��ɵ���Ʒ��


�������:
���һ��������, ��ʾСQ������Ҫ���ٴβ�����ɻ滭��
ʾ��1
����
4 4
YXXB
XYGX
XBYY
BXXY
���
3
˵��
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
