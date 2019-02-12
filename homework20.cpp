#include <iostream>
using namespace std;

class Time {
private:
	int hour, minute, second;
	void simp();
public:
	void in();
	Time& operator+=(const Time& t);
	Time& operator-=(const Time& t);
	Time & operator++();
	Time operator++(int);
	Time & operator--();
	Time operator--(int);
	friend istream& operator>>(istream &in, Time& obj) {
		in >> obj.hour >> obj.minute >> obj.second;
		return in;
	}
	friend ostream& operator<<(ostream &out, Time& obj) {
		int h[2], m[2], s[2];
		h[0] = obj.hour / 10;
		h[1] = obj.hour % 10;
		m[0] = obj.minute / 10;
		m[1] = obj.minute % 10;
		s[0] = obj.second / 10;
		s[1] = obj.second % 10;
		out << h[0] << h[1] << ":" << m[0] << m[1] << ":" << s[0] << s[1];
		return out;
	}
};

void Time::simp() {
	if (second >= 60) {
		second -= 60;
		minute++;
	}
	if (minute >= 60) {
		minute -= 60;
		hour++;
	}
	if (hour >= 24) {
		hour -= 24;
	}
	if (second < 0) {
		second += 60;
		minute--;
	}
	if (minute < 0) {
		minute += 60;
		hour--;
	}
	if (hour < 0) {
		hour += 24;
	}
}

void Time::in() {
	cin >> hour >> minute >> second;
}

Time& Time::operator+=(const Time& t) {
	hour += t.hour;
	minute += t.minute;
	second += t.second;
	simp();
	return *this;
}

Time& Time::operator-=(const Time& t) {
	hour -= t.hour;
	minute -= t.minute;
	second -= t.second;
	simp();
	return *this;
}

Time & Time::operator++() {
	second++;
	simp();
	return *this;
}

Time Time::operator++(int t) {
	Time temp = *this;
	second++;
	simp();
	return temp;
}

Time & Time::operator--() {
	second--;
	simp();
	return *this;
}

Time Time::operator--(int t) {
	Time temp = *this;
	second--;
	simp();
	return temp;
}

int main()
{
	Time t1, t2;
	cin >> t1;
	cin >> t2;

	cout << (t1 += (t2++)) << endl;
	cout << (t1 -= t2) << endl;
	cout << (++t2) << endl;
	cout << (t2 += (t1--)) << endl;
	cout << (--t1) << endl;
	cout << (t2 -= t1);

	return 0;
}