#pragma once
class Date {
private:
	int _day, _month, _year;
public:
	int getDay() { return _day; }
	int getMonth() { return _month; }
	int getYear() { return _year; }

	bool setDay(int d) {
		if (d > 0 && d < 32) {
			_day = d;
			return true;
		}
		return false;
	}
	bool setMonth(int m) {
		if (m > 0 && m < 13) {
			_month = m;
			return true;
		}
		return false;
	}
	bool setYear(int y) {
		if (y > 0) {
			_year = y;
			return true;
		}
		return false;
	}

	bool setDate(int d, int m, int y) {
		return (setDay(d) & setMonth(m) & setYear(y));
	}
};