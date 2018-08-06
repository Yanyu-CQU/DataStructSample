#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <memory>
#include <vector>
using namespace std;
/*
СQ�Ĺ�˾����ӵ�m������, ��i��������Ҫxi��ʱ��ȥ���, �Ѷȵȼ�Ϊyi��
СQӵ��n̨����, ÿ̨���������ʱ��zi, �����ȼ�wi��
����һ������,��ֻ�ܽ���һ̨���������, ������Ÿ����Ļ����������ʱ��С��������Ҫ��ʱ��, �������,������������񽫻��200 * xi + 3 * yi���档

����һ̨����,��һ��ֻ�����һ������, ������Ļ����ȼ�С�ڰ��Ÿ����������Ѷȵȼ�, ������ɡ�

СQ���ڽ��쾡���ܵ�ȥ�������, ����ɵ����������������ж��ְ��ŷ���,СQ�����ҵ����������Ǹ�������СQ��Ҫ��������������һ�¡�


��������:
�������N + M + 1��,
����ĵ�һ��Ϊ����������n��m(1 <= n, m <= 100000), ��ʾ�����������������������
������n��,ÿ����������zi��wi(0 < zi < 1000, 0 <= wi <= 100), ��ʾÿ̨�����������ʱ��ͻ����ȼ���
��������m��,ÿ����������xi��yi(0 < xi < 1000, 0 <= yi<= 100), ��ʾÿ��������Ҫ�����ʱ���������Ѷȵȼ���


�������:
�����������, �ֱ��ʾ�������ɵ����������ͻ�ȡ�����档
ʾ��1
����
1 2
100 3
100 2
100 1
���
1 20006
*/
struct Info
{
	int time;
	int level;
};

int main()
{
	int n = 0, m = 0;//����������
	int time = 0, level = 0;
	Info temp;
	
	while (cin >> n >> m)
	{
		vector<Info> task(m);
		vector<Info> machine(n);
		vector<int> cnt(110, 0);
		int value = 0, cntTask = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> machine[i].time >> machine[i].level;
		}
		for (int i = 0; i < m; ++i)
		{
			cin >> task[i].time >> task[i].level;
		}

		sort(task.begin(), task.end(), [](Info a, Info b) {
			if (a.time == b.time)
			{
				return a.level > b.level;
			}
			else
			{
				return a.time > b.time;
			}
		});
		sort(machine.begin(), machine.end(), [](Info a, Info b) {
			if (a.time == b.time)
			{
				return a.level > b.level;
			}
			else
			{
				return a.time > b.time;
			}
		});

		for (int i = 0, j = 0; i < m; ++i)
		{
			for (; j < n && machine[j].time >= task[i].time; ++j)
			{
				cnt[machine[j].level]++;
			}
			for (int j = task[i].level; j < 110; ++j)
			{
				if (cnt[j] != 0)
				{
					cnt[j]--;
					value += task[i].time * 200 + task[i].level * 3;
					cntTask++;
					break;
				}
			}
		}
		cout << cntTask << ' ' << value << endl;
	}
	return 0;
}
