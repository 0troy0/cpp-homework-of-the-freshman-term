#include <iostream>
using namespace std;

int main()
{
	int num, i, j=0, k;
	int a[65535];
	cin >> num;
	if (num >= 2 && num <= 65535) {
		for (i = 2; i <= num; ++i)
		{
			while (true) {
				if (num%i == 0) {
					a[j] = i;
					j++;
					num = num / i;
				}
				else break;
			}
		}
		for (k = 0; k < j-1; ++k)
			cout << a[k] << " ";
		cout << a[k];
	}
	else cout << "Error!";
	return 0;
}
