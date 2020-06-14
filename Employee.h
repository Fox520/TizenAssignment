#pragma once
#include <string>
#include "Log.h"
#include "Department.h"
#include "Company.h"

// Forward declaration
class Department;
// Abstract class
class Employee {
private:
	int _empID, _payDay;
	std::string _compName;
	Department _dept;
	bool _isEmployed = true;
public:
	virtual void setIncentive(double amount) = 0;
	virtual double getIncentive() = 0;
	void setCompany(std::string name) { _compName = name; };
	std::string getCompany() { return _compName; }

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

#include "Manager.h" // Including here to avoid compiler errors
// Add an employee to company
// https://docs.microsoft.com/en-us/cpp/error-messages/tool-errors/linker-tools-error-lnk2005?f1url=https%3A%2F%2Fmsdn.microsoft.com%2Fquery%2Fdev16.query%3FappId%3DDev16IDEF1%26l%3DEN-US%26k%3Dk(LNK2005)%26rd%3Dtrue&view=vs-2019
inline void addEmployee(Company *comp) {
	LOG("Adding an employee (manager for now)");
	std::string employeeType = "hourly";
	Manager m;
	m.getPayDay();

}