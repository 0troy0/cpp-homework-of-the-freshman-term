#include <iostream>
#include <string.h>
using namespace std;

class studentT {
public:
	char id[10];
	int chi, math, en, add;
	void in(studentT &stu)
	{
		cin >> stu.id >> stu.chi >> stu.math >> stu.en;
		stu.add = stu.chi + stu.math + stu.en;
	}
	void out(studentT &stu)
	{
		cout << stu.id << " " << stu.add;
	}
};

int main()
{
	studentT *menu, temp;
	int n, range, i, j;
	bool flag;

	cin >> n;
	menu = new studentT[n];

	for (i = 0; i < n; ++i)
		menu[i].in(menu[i]);

	cin >> range;

	for (i = 1; i < n; ++i) {
		flag = false;
		for (j = 0; j < n - i; ++j) {
			if ((menu[j].add < menu[j + 1].add)
				|| (menu[j].add == menu[j + 1].add && menu[j].chi < menu[j + 1].chi)
				|| (menu[j].add == menu[j + 1].add && menu[j].chi == menu[j + 1].chi && menu[j].math < menu[j + 1].math)
				|| (menu[j].add == menu[j + 1].add && menu[j].chi == menu[j + 1].chi && menu[j].math == menu[j + 1].math && menu[j].en < menu[j + 1].en)
				|| (menu[j].add == menu[j + 1].add && menu[j].chi == menu[j + 1].chi && menu[j].math == menu[j + 1].math && menu[j].en == menu[j + 1].en && strcmp(menu[j].id, menu[j + 1].id) > 0)
				) {
				temp = menu[j];
				menu[j] = menu[j + 1];
				menu[j + 1] = temp;
				flag = true;
			}
		}
		if (!flag) break;
	}

	menu[range - 1].out(menu[range - 1]);

	delete[]menu;

	return 0;
}

