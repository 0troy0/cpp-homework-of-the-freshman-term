#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	char a[30], *p, ch;
	int i, j = 0, b[30];
	
	p = a;
	cin >> a;
	cin >> ch;

	for (i = 0; i < strlen(a); ++i) {
		if (*(p + i) == ch) {
			b[j++] = i;
		}
	}

	if (j == 0) cout << "NULL";
	else {
		for (i = 0; i < j - 1; ++i)
			cout << b[i] << " ";
		cout << b[j - 1];
	}

	return 0;
}

