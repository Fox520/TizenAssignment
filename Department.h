#pragma once
#include <string>
#include <vector>
class Employee;


using namespace std;

class Department {
private:
	string deptName;
	vector<Employee*>employeeList;
public:
	string getDeptName() { return deptName; }
	void setDeptName(string name) { deptName = name; }

	// Can't pass abstract class by value, use reference or pointer
	void addEmployee(Employee* e) {
		employeeList.push_back(e);
	}

	void removeEmployee(Employee* e) {
		for (int i = 0; i < employeeList.size(); i++) {
			// Compare if addresses are the same
			if (employeeList.at(i) == e) {
				// Remove Employee pointer from vector
				employeeList.erase(employeeList.begin() + i);
			}
		}
	}

	vector<Employee*> getEmployees() {
		return employeeList;
	}
	~Department() {
		employeeList.clear();
	}
};