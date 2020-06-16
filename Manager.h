#pragma once
#include <string>
//#include "Employee.h"
#include "BaseException.h"
#include "Log.h"

class Employee; // if you include this will the code between this line of code and the Manager class be necessary? Please do answer :)

// Checks if pointer is of a certain type
template<typename Base, typename T>
inline bool instanceof(const T* ptr) {
	return dynamic_cast<const Base*>(ptr) != nullptr;
}

class Manager : public Employee {
private:
public:
	Manager(int id, int pd, std::string dep, double sal, std::string r, Company& c) :Employee(id, pd, dep, c, r) {
		setPayment(sal);
	}
};