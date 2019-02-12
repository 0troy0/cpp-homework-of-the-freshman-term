#include <iostream>
using namespace std;

int main()
{
	int n,a,b,c,d;
	char e, f, g, h;
	cin >> n;
	if (n > 9999 or n < 1000) cout << "Error!";
	else
	{
		a = n % 10;
		n = n - a;
		b = (n % 100)/10;
		n = n - b;
		c =( n % 1000)/100;
		n = n - c;
		d = n / 1000;
		e = 'A' + a + 12;
		f = 'A' + b + 12;
		g = 'A' + c + 12;
		h = 'A' + d + 12;
		cout << h << g << f << e;
	}

	return 0;
}
