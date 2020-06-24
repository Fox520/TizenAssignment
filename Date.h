#pragma once
#include <string>
class Date {
private:
	int _day=-1, _month=-1, _year=-1;
public:
	int getDay() { return _day; }
	int getMonth() { return _month; }
	int getYear() { return _year; }

	std::string display() {
		return std::to_string(_day) + "/"+ std::to_string(_month)+"/"+ std::to_string(_year);
	}

	Date(std::vector<int> s) {
		setDate(s.at(0), s.at(1), s.at(2));
	}

	Date(int d, int m, int y) {
		setDate(d, m, y);
	}

	Date(){}

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