#pragma once
#include <iostream>
#include <string>
#include "Log.h"
#include "Employee.h"

class Salaried : public Employee {
public:
	Salaried(int id, int pd, std::string dep, double sal, std::string r, Company& comp) :Employee(id, pd, dep, comp, r) {
		setPayment(sal);
	}
	
};
