#include <iostream>
using namespace std;

int main()
{
	int a, b, i, m = 0, n, k, add = 0, x, array[100] = { 0 };
	cin >> a >> b;
	if (a > 0 && b >= a) {
		for (i = a; i <= b; ++i)
		{
			k = i;
			while (k) {
				x = k % 10;
				add += x * x*x;
				k /= 10;
			}
			if (i == add) {
					array[m] = i;
					m++;
			}
			add = 0;
		}
		if (array[0] == 0) cout << "no";
		else {
			for (n = 0; n < m-1; ++n)
				cout << array[n] << endl;
			cout << array[n];
		}
	}
	else cout << "error";
	return 0;
}
