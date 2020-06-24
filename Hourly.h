#pragma once
#include <iostream>
#include<string>
#include "Log.h"
#include "BaseException.h"
#include "Employee.h"

class Hourly : public Employee {
private: 
	double rate;
	int hours;
	const char* role;
public:
	Hourly(int id, int pd, std::string dep, double rate, int hours, std::string r, Company& comp) :Employee(id, pd, dep, comp, r) {
		this->rate = rate;
		this->hours = hours;
		setTotalValue();
	}

	void setTotalValue() {
		double t = rate * hours;
		setPayment(t);
	}
};
