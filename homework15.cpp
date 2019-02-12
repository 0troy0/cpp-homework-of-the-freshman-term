#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	char a[30][100], ch, b[30][30], temp[30], d[30][31];
	int num = 0, i, j, k;
	bool flag;

	cin >> ch;
	for (i = 0; i < 30; ++i) {
		cin >> a[i];
		if (strcmp(a[i], "@") == 0) break;
	}
	num = i;

	for (i = 0; i < num; ++i)
		strncpy(d[i], a[i], 30);

	for (i = 0; i < num; ++i) {
		j = 0;
		for (k = 0; k < strlen(d[i]); ++k) {
			if (d[i][k] != ch) b[i][j++] = d[i][k];
			b[i][j + 1] = '\0';
		}
	}

	for (i = 0; i < num - 1; ++i) {
		flag = false;
		for (j = num - 1; j > i; --j) {
			if (strcmp(b[j], b[j - 1]) > 0) {
				strncpy(temp, b[j], 30);
				strncpy(b[j], b[j - 1], 30);
				strncpy(b[j - 1], temp, 30);
				flag = true;
			}
		}
		if (!flag) break;
	}

	for (i = 0; i < num - 1; ++i)
		cout << b[i] << endl;
	cout << b[num - 1];


	return 0;
}