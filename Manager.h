#pragma once
#include <string>
//#include "Employee.h"
#include "BaseException.h"
#include "Log.h"

class Employee;

// Checks if pointer is of a certain type
template<typename Base, typename T>
inline bool instanceof(const T* ptr) {
	return dynamic_cast<const Base*>(ptr) != nullptr;
}

class Manager : public Employee {
private:
	double monthlySalary;
	std::string role;
public:
	Manager(int id, int pd, std::string dep, double sal, std::string r, Company& c) :Employee(id, pd, dep, c){
		this->monthlySalary = sal;
		this->role = r;
	}

	void setRole(std::string r) {
		role = r;
	}
	std::string getRole() { return role; }

	void setPayment(double amount) {
		// Make sure salary is greater than 0
		if (amount > 0) {
			monthlySalary = amount;
		}
		else {
			throw BaseException();
		}
	}
	double getIncentive() {
		return monthlySalary;
	}
};