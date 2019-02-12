#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	char ch[50][50] = { ' ' }, a[50];
	int n, len, x, y, i, j = 0;

	cin >> n;
	cin.getline(a, 30);
	len = strlen(a) - 1;

	if (n == 1)
	{
		for (i = 1; i < len + 1; ++i)
			cout << a[i];
	}

	else if (n >= 2)
	{
		for (i = 1; i < len + 1; ++i)
		{
			x = i / (2 * n - 2);
			y = i % (2 * n - 2);
			if (y <= n && y >= 1)
				ch[y - 1][x*(n - 1)] = a[i];
			else if (y == 0)
				ch[1][x*(n - 1) - 1] = a[i];
			else
				ch[2 * n - 1 - y][x*(n - 1) + (y - n)] = a[i];
		}

		for (i = 0; i < n; ++i)
		{
			for (j = 0; j < 30; ++j)
			{
				if (ch[i][j] >= '!'&&ch[i][j] <= '~')
					cout << ch[i][j];
			}
		}
	}

	return 0;
}
