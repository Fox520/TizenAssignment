#pragma once
#include <string>
#include "Log.h"
#include "DepartmentCompany.h"

// Forward declaration
class Department;
// Abstract class
class Employee {
private:
	int _empID=0, _payDay=0;
	std::string _compName = "Tizen Productions Management System";
	std::string _deptName;
	bool _isEmployed = true;
public:
	virtual void setPayment(double amount) = 0;
	virtual double getIncentive() = 0;
	void setCompany(std::string name) { _compName = name; };
	std::string getCompany() { return _compName; }

	Employee(int id, int pd, std::string dn, Company& c) {
		_empID = id;
		_payDay = pd;
		setDepartment(dn, c);
	}

	bool setEmployeeID(int num) {
		if (num > 0) {
			// Any number greater than 0 is a valid ID
			_empID = num;
			return true;
		}
		return false;
	}

	int getEmployeeID() { return _empID; }

	void setDepartment(std::string d, Company& c) {

		for (int i = 0; i < (int)c.getDepartments().size(); i++) {
			// Compare if departments are the same
			if (c.getDepartments().at(i)->getDeptName() == d) {
				_deptName = d;
				c.getDepartments().at(i)->addEmployee(this);
				break;
			}
		}
	}
	inline Department* getDept(Company& c, String d) {
		
	}

	std::string getDepartment() { return _deptName; }

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
inline void addEmployee(Company& comp) {
	LOG("Enter employee type: [manager, hourly, salaried]");
	std::cout << "> ";
	std::string employeeType;
	std::cin >> employeeType;
	if (employeeType == "manager") {
		//int id, int pd, std::string dep, double sal, std::string r, Company& c
		std::cout <<"Employee ID [number]: ";
		int id;
		std::cin >> id;

		std::cout << "Pay Day [number]: ";
		int pd;
		std::cin >> pd;

		std::cout << "Department Name: ";
		std::string dep;
		std::cin >> dep;

		std::cout << "Salary: ";
		double sal;
		std::cin >> sal;

		std::cout << "Role: ";
		std::string r;
		std::cin >> r;

		Manager* m = new Manager(id, pd, dep, sal, r, comp);
		LOG("Manager added to system.")

	}
	else if (employeeType == "hourly") {

	}
	else if (employeeType == "salaried") {

	}
	else {
		LOG("Invalid option");
	}

}