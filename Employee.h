#pragma once
#include <string>

#include "Department.h"

using namespace std;
// Forward declaration
class Department;
// Abstract class
class Employee {
private:
	int _empID, _payDay;
	string _compName;
	Department _dept;
	bool _isEmployed = true;
public:
	virtual void setIncentive(double amount) = 0;
	virtual double getIncentive() = 0;
	void setCompany(string name) { _compName = name; };
	string getCompany() { return _compName; }

	bool setEmployeeID(int num) {
		if (num > 0) {
			// Any number greater than 0 is a valid ID
			_empID = num;
			return true;
		}
		return false;
	}
	int getEmployeeID() { return _empID; }

	void setDepartment(Department d) {
		_dept = d;
	}
	Department getDepartment() { return _dept; }

	bool isFired() { return _isEmployed; }

	bool setPayDay(int d) {
		// Ensure the date is valid
		if ((d > 0)& (d < 32)) {
			_payDay = d;
			return true;
		}
		return false;
	}

	int getPayDay() { return _payDay; }

};