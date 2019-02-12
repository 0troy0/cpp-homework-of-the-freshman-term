#include <iostream>
using namespace std;

int main()
{
	float a, b, c;
	cin >> a >> b >> c;
	if (a <= 0 || b <= 0 || c <= 0) cout << "-1";
	else if (a*a + b * b == c * c || b * b + c * c == a * a || c * c + a * a == b * b) cout << "1";
	else if (a + b > c && b + c > a && c + a > b) cout << "0";
	else cout << "-1";
	return 0;
}
