#include "Department.h"
#include <string>

class Company {
private:
	string companyName;
	std::vector<Department*> departmentList;
public:
	void setCompanyName(string n) {
		companyName = n;
	}
	string getCompanyName() { return companyName; }

	std::vector<Department*> getDepartments() { return departmentList; }

	void addDepartment(Department* d) {
		departmentList.push_back(d);
	}
	void removeDepartment(Department* d) {
		for (int i = 0; i < departmentList.size(); i++) {
			// Compare if addresses are the same
			if (departmentList.at(i) == d) {
				// Remove Department pointer from vector
				departmentList.erase(departmentList.begin() + i);
			}
		}
	}
};