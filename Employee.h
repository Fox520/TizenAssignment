#pragma once
#include <string>
#include "Log.h"
#include "DepartmentCompany.h"

// Forward declaration
class Department;
// Abstract class
class Employee 
{
private:
	int _empID=0, _payDay=0;
	double payment;
	std::string _compName = "Tizen Productions Management System";
	std::string _deptName;
	std::string _role;
	bool _isEmployed = true;
public:
	void setPayment(double amount) {
		// Make sure salary is greater than 0
		if (amount > 0) {
			this->payment = amount;
		}
		else {
			throw BaseException();
		}
	}

	double getPayment() 
	{ 
		return payment;
	};

	void setCompany(std::string name) 
	{ 
		_compName = name; 
	};

	std::string getCompany() 
	{ 
		return _compName; 
	}

	void setRole(std::string role) {
		this->_role = role;
	}

	std::string getRole() {
		return this->_role;
	}

	Employee(int id, int pd, std::string dn, Company& c, std::string role) {
		setEmployeeID(id);
		_payDay = pd;
		setDepartment(dn, c);
		setRole(role);
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
#include "Hourly.h"
#include "Salaried.h"
// Add an employee to company
inline void addEmployee(Company& comp) {
	LOG("Enter employee type: [manager, hourly, salaried]");
	std::cout << "1. manager" << std::endl;
	std::cout << "2. hourly" << std::endl;
	std::cout << "3. salaried" << std::endl;
	std::cout << "> ";
	int choice;
	std::cin >> choice;
	std::string employeeType;
	switch (choice)
	{
		case 1: 
		employeeType = "manager";
		break;
		case 2: 
			employeeType = "hourly";
				break;
		case 3: 
			employeeType = "salaried";
			break;
	default:
		LOG("The employee type that you are trying to enter is not on the System.");
		break;
	}
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
		std::getline(std::cin, r);

		Manager* m = new Manager(id, pd, dep, sal, r, comp);
		LOG("Manager added to system!")

	}
	else if (employeeType == "hourly") {
		std::cout << "Employee ID [number]: ";
		int id;
		std::cin >> id;

		std::cout << "Pay Day [number]: ";
		int pd;
		std::cin >> pd;

		std::cout << "Department Name: ";
		std::string dep;
		std::getline(std::cin, dep);

		std::cout << "Hourly rate: ";
		double rate;
		std::cin >> rate;

		std::cout << "Hours worked: ";
		int hours;
		std::cin >> hours;

		std::cout << "Role: ";
		std::string r;
		std::getline(std::cin, r);

		Hourly* h = new Hourly(id, pd, dep, rate, hours , r, comp);
		LOG("Hourly Employee added to system!");
	}
	else if (employeeType == "salaried") {
		std::cout << "Employee ID [number]: ";
		int id;
		std::cin >> id;

		std::cout << "Pay Day [number]: ";
		int pd;
		std::cin >> pd;

		std::cout << "Department Name: ";
		std::string dep;
		std::getline(std::cin, dep);

		std::cout << "Salary: ";
		double sal;
		std::cin >> sal;

		std::cout << "Role: ";
		std::string r;
		std::getline(std::cin, r);

		Salaried* s = new Salaried(id, pd, dep, sal, r, comp);
		LOG("Salary Employee added to system!");
	}
	else {
		LOG("Invalid option");
	}

}