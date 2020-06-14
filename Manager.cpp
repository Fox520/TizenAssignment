#include <string>
#include "Employee.h"
#include "BaseException.h"
#include "Log.h"

// Checks if pointer is of a certain type
template<typename Base, typename T>
inline bool instanceof(const T* ptr) {
	return dynamic_cast<const Base*>(ptr) != nullptr;
}

class Manager : Employee {
private:
	double monthlySalary;
	string role;
public:
	void setRole(string r) {
		role = r;
	}
	string getRole() { return role; }

	void raiseSalary(Employee* e, double amount) {
		// Check if the employee is a manager
		if (instanceof<Manager>(e)) {
			if (amount > 0) {
				// Cast to Manager pointer then update salary
				((Manager*)e)->setIncentive(amount);
			}
			else {
				LOG("Amount should be greater than 0.")
			}
		}
		else {
			LOG("You are not a manager, cannot update salary.")
		}
	}

	void setIncentive(double amount) {
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