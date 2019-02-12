#include <iostream>
using namespace std;

int main()
{
	static int a[2000001] = { 0 }, b[2000001];
	int i, j, x = 0, y, num;
	cin >> num;

	for (i = 2; i < num + 1; ++i) {
		if (a[i] == 0) {
			for (j = 2; j <= num / i; ++j) {
				a[i*j] = 1;
			}
			x++;
			b[x] = i;
		}
	}
	for (y = 1; y < x; ++y) {
		cout << b[y] << " ";
	}
	cout << b[x];
	return 0;
}
