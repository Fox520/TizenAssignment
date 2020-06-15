#pragma once
#include <string>
#include <iostream>
#include <string>
#include <vector>

using String = std::string;

class Employee;
class Company;

class Department {
private:
	String deptName;
	std::vector<Employee*>employeeList;
public:

	Department(String deptName) {
		this->deptName = deptName;
	}

	String getDeptName() { return deptName; }

	void setDeptName(String name) { deptName = name; }

	// Can't pass abstract class by value, use reference or pointer
	void addEmployee(Employee* e) {
		employeeList.push_back(e);
	}

	void removeEmployee(Employee* e) {
		for (int i = 0; i < (int)employeeList.size(); i++) {
			// Compare if addresses are the same
			if (employeeList.at(i) == e) {
				// Remove Employee pointer from vector
				employeeList.erase(employeeList.begin() + i);
			}
		}
	}

	std::vector<Employee*> getEmployees() {
		return employeeList;
	}

	
	bool operator==(Department& other) const {
		return this->deptName == other.getDeptName();  // Compare the values, and return a bool result.
	}

	~Department() {
		employeeList.clear();
	}
};

class Company {
private:
	std::string companyName;
	std::vector<Department*> departmentList;
public:
	/* Copy constructor */
	Company(const Company& com)
	{
		this->companyName = com.companyName;
		this->departmentList = com.departmentList;
	}

	// Normal constructor
	Company() {

	}

	void setCompanyName(std::string n) {
		companyName = n;
	}
	std::string getCompanyName() { return companyName; }

	std::vector<Department*> getDepartments() { return departmentList; }

	void addDepartment(Department& d) {
		departmentList.push_back(&d);
	}
	void removeDepartment(Department& d) {
		for (int i = 0; i < (int)departmentList.size(); i++) {
			// Compare if departments are the same
			if (*departmentList.at(i) == d) {
				// Remove Department pointer from vector
				departmentList.erase(departmentList.begin() + i);
			}
		}
	}
};

// Add an department to company
inline void addDepartment(Company& comp) {
	LOG("Enter department name:");
	std::cout << "> ";
	std::string dname;
	std::cin >> dname;
	
	Department* d = new Department(dname);
	comp.addDepartment(*d);
}

inline bool checkIfDeptExist(Company& c, String d) {
	for (int i = 0; i < (int)c.getDepartments().size(); i++) {
		// Compare if departments are the same
		if (c.getDepartments().at(i)->getDeptName() == d) {
			return true;
		}
	}
}