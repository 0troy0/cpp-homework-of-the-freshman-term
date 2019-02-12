#include <iostream>
using namespace std;

int main()
{
	int A, B;
	cin >> A >> B;
	if (B < 0)
	{
		cout << A << '+' << '(' << B << ')' << '=' << A + B << endl;
		cout << A << '*' << '(' << B << ')' << '=' << A * B << endl;
		cout << A << '/' << '(' << B << ')' << '=' << A / B << endl;
		cout << A << '%' << '(' << B << ')' << '=' << A % B << endl;
	}
	else if (B > 0)
	{
		cout << A << '+' << B << '=' << A + B << endl;
		cout << A << '*' << B << '=' << A * B << endl;
		cout << A << '/' << B << '=' << A / B << endl;
		cout << A << '%' << B << '=' << A % B << endl;
	}
	else cout << "B=0 error" << endl;
	return 0;
}

