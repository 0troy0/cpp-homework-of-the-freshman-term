#include <iostream>
#include <algorithm> 
using namespace std;


int main()
{
	int n, a[100], i, j, t, temp, ans = 0;
	bool flag;

	cin >> n;
	for (i = 0; i < n; ++i)
		cin >> a[i];

	for (i = 1; i < n; ++i) 
	{
		flag = false;
		for (j = 0; j < n - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				flag = true;
			}
		}
		if (!flag) break;
	}

	t = n - 1;

	while (1)
	{
		if (n == 1)
		{
			ans += a[0];
			break;
		}
		if (n == 2)
		{
			ans += a[1];
			break;
		}
		if (n == 3)
		{
			ans += a[0] + a[1] + a[2];
			break;
		}
		else ans += min(a[t-1] + a[0] + a[t] + a[0], a[1] + a[0] + a[t] + a[1]);
		t -= 2;
		n -= 2;
	}

	cout << ans;

	return 0;
}