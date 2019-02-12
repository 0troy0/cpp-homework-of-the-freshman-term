#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	char ch1[51], ch2[51];
	int ch3[51];
	int i, j = 0, n;

	cin.getline(ch1,51);
	n = strlen(ch1);

	for (i =n - 1; i >= 0; --i)
	{
		ch3[n - i - 1] = ch1[i] - '0';
	}

	ch3[0]++;

	for (i = 0; i < n-1; ++i)
	{
		if (ch3[i] >= 10) 
		{
			ch3[i] = ch3[i] - 10;
			ch3[i + 1]++;
		}
	}

	if (ch3[n - 1] >= 10) {
		ch3[n] = 1;
		ch3[n - 1] = ch3[n - 1] - 10;
		n++;
	}

	for (i = 0; i < n; ++i)
		ch2[n - i - 1] = '0' + ch3[i];
	for (i = 0; i < n; ++i)
		cout << ch2[i];

	return 0;
}
