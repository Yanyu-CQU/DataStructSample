#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <memory>
#include <vector>
using namespace std;
/*
小Q的公司最近接到m个任务, 第i个任务需要xi的时间去完成, 难度等级为yi。
小Q拥有n台机器, 每台机器最长工作时间zi, 机器等级wi。
对于一个任务,它只能交由一台机器来完成, 如果安排给它的机器的最长工作时间小于任务需要的时间, 则不能完成,如果完成这个任务将获得200 * xi + 3 * yi收益。

对于一台机器,它一天只能完成一个任务, 如果它的机器等级小于安排给它的任务难度等级, 则不能完成。

小Q想在今天尽可能的去完成任务, 即完成的任务数量最大。如果有多种安排方案,小Q还想找到收益最大的那个方案。小Q需要你来帮助他计算一下。


输入描述:
输入包括N + M + 1行,
输入的第一行为两个正整数n和m(1 <= n, m <= 100000), 表示机器的数量和任务的数量。
接下来n行,每行两个整数zi和wi(0 < zi < 1000, 0 <= wi <= 100), 表示每台机器的最大工作时间和机器等级。
接下来的m行,每行两个整数xi和yi(0 < xi < 1000, 0 <= yi<= 100), 表示每个任务需要的完成时间和任务的难度等级。


输出描述:
输出两个整数, 分别表示最大能完成的任务数量和获取的收益。
示例1
输入
1 2
100 3
100 2
100 1
输出
1 20006
*/
struct Info
{
	int time;
	int level;
};

int main()
{
	int n = 0, m = 0;//机器，任务
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
