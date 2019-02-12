#include <iostream>
#include<string.h>
using namespace std;

int main()
{
	char ch[80] = { 0 }, begin[80], temp;
	int n, len, i, j = 0, a, b, c, d, r = 0;
	bool t;

	cin >> n;
	cin.getline(begin, 80);


	for (i = 0; i < strlen(begin); ++i) {
		if (((begin[i] >= '0') && (begin[i] <= '9')) || ((begin[i] >= 'A') && (begin[i] <= 'Z')) || ((begin[i] >= 'a') && (begin[i] <= 'z')))
			ch[j++] = begin[i];
	}

	len = strlen(ch)-1;

	if (n > 0 && n < 10) {
		for (i = 0; i < len+1; ++i) {
				if ((ch[i] >= 'A')&&(ch[i] <= 'Z')) ch[i] = ch[i] - 'A' + 'a';
				else if ((ch[i] >= 'a')&&(ch[i] <= 'z')) ch[i] = ch[i] - 'a' + 'A';
		}
	}
	else cout << "error" << endl;

	for (a = len; a > 0; --a) {
		t = false;
		for (b = 0; b < a; ++b) {
			if (ch[b] > ch[b + 1]) {
				temp = ch[b];
				ch[b] = ch[b + 1];
				ch[b + 1] = temp;
				t = true;
			}
		}
		if (!t) break;
	}

	for (i = 0; i < len + 1; ++i) {
		for (j = 0; j < r; ++j) 
			if (ch[j] == ch[i]) break;
		if (j == r)
			ch[r++] = ch[i];
	}


	for (c = 0; c < n; ++c)
		for (d = r - 1; d >= 0; --d)
			cout << ch[d];

	return 0;
}
