#include <iostream>
#include <string>
#include <stdlib.h>
#include <memory.h>
using namespace std;


int getLCS(const string& A, const string& B)
{
	//int (*lcs)[B.size() + 1] = new int[(A.size() + 1)][(B.size() + 1)];
	int** lcs = nullptr;
	lcs = new int*[A.size() + 1];
	for (int i = 0; i <= A.size(); i++)
	{
		lcs[i] = new int[B.size() + 1];
	}
	memset(lcs, 0, sizeof(int) * (A.size() + 1) * (B.size() + 1));
	//int** lcs = (int**)arr;
	for (int i = 1; i <= A.size(); ++i)
	{
		for (int j = 1; j <= B.size(); ++j)
		{
			if (A[i - 1] == B[j - 1])
			{
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else
			{
				lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
			}
		}
	}
	return lcs[A.size()][B.size()];
}
int main()
{
	string a,b;
	while (cin >> a >> b)
	{
		cout << getLCS(a, b) << endl;
	}
	return 0;
}
