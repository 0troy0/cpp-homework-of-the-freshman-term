#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int n, i, j, k, len = 0, begin, r;
	char ch[10001];

	cin.getline(ch, 10001);
	n = strlen(ch);

	for (i = 0; i < n; ++i) {
		for (j = n - 1; j > i; --j) {
			if (ch[i] == ch[j]) {
				r = 0;
				for (k = 0; k < (j - i + 1) / 2; ++k) {
					if (ch[i + k] == ch[j - k]) ++r;
				}
				if ((r == (j - i + 1) / 2) && ((j - i + 1) > len)) {
					len = j - i + 1;
					begin = i;
				}
			}
		}
	}

	cout << len << endl;
	for (i = begin; i < begin + len; ++i)
		cout << ch[i];
	
	return 0;
}
