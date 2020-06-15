#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Department.h"
// Forward declaration
class Department;

class Company {
private:
	std::string companyName;
	std::vector<Department> departmentList;
public:
	/* Copy constructor */
	Company(const Company& com)
	{
		this -> companyName = com.companyName;
		this -> departmentList = com.departmentList;
	}

	// Normal constructor
	Company() {

	}

	void setCompanyName(std::string n) {
		companyName = n;
	}
	std::string getCompanyName() { return companyName; }

	std::vector<Department> getDepartments() { return departmentList; }

	void addDepartment(Department d) {
		departmentList.push_back(d);
	}
	void removeDepartment(Department d) {
		for (int i = 0; i < (int)departmentList.size(); i++) {
			// Compare if addresses are the same
			if (departmentList.at(i) == d) {
				// Remove Department pointer from vector
				departmentList.erase(departmentList.begin() + i);
			}
		}
	}
};