#pragma once
#include <string>
#include <vector>

class Employee;
class Company;

class Department {
private:
	std::string deptName;
	std::vector<Employee*>employeeList;
public:
	std::string getDeptName() { return deptName; }
	void setDeptName(std::string name) { deptName = name; }

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
	~Department() {
		employeeList.clear();
	}
};

// Add an department to company
inline void addDepartment(Company *comp) {
	LOG("Adding a department");
}