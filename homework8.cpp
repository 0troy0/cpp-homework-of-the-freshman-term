#include <iostream>
using namespace std;

int main()
{
	int m, n, i, j, a[10][10];
	cin >> m >> n;
	for (i = 0; i < m; ++i) {
		for (j = 0; j < n; ++j)
			cin >> a[j][m-i-1];
	}
	cout << n << " " << m << endl;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m-1; ++j) {
			cout << a[i][j] << " ";
		}
		cout << a[i][m - 1] << endl;
	}
	return 0;
}

