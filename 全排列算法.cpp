#include <iostream>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <memory>
using namespace std;

void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}
void permutation(char *start, char *s)
{
	if (s == nullptr)
	{
		return;
	}
	else if (*s == '\0')
	{
		cout << start << endl;
		return;
	}
	else
	{
		int len = strlen(s);
		for (int i = 0; i < len; ++i)
		{
			swap(s, s + i);
			permutation(start, s + 1);
			swap(s, s + i);
		}
	}
}
int main()
{
	while (true)
	{
		cout << "permutation:" << endl;
		char buf[1000];
		scanf("%s", buf);
		permutation(buf, buf);
	}
	return 0;
}
