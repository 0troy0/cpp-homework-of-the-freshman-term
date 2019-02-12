#include <iostream>
using namespace std;

int runnian(int a);

int main()
{
	int month_date[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int y, m, d, ch, day, sum, i;
	int out[8];
	cin >> ch >> day;

	y = ch / 10000;
	m = (ch - 10000 * y) / 100;
	d = ch - 10000 * y - 100 * m;
	sum = day + d;

	while (sum > month_date[m - 1]) {
		if (m == 2) {
			month_date[1] = 28;
			month_date[1] += runnian(y);
		}
		sum -= month_date[m - 1];
		m++;
		if (m == 13) {
			y++;
			if (y > 9999) {
				break;
			}
			m = 1;
		}
	}
	if (y > 9999)cout << "out of limitation!";
	else {
		d = sum;
		out[0] = y / 1000;
		out[1] = (y - out[0] * 1000) / 100;
		out[2] = (y - out[0] * 1000 - out[1] * 100) / 10;
		out[3] = y - out[0] * 1000 - out[1] * 100 - out[2] * 10;
		out[4] = m / 10;
		out[5] = m % 10;
		out[6] = d / 10;
		out[7] = d % 10;
		for (i = 0; i < 8; ++i)
			cout << out[i];
	}

	return 0;
}

int runnian(int a) {
	if ((a % 400 == 0) || (a % 100 != 0 && a % 4 == 0))
		return 1;
	else return 0;
}