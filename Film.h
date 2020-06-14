#pragma once
#include <string>
#include "Date.h"

using namespace std;

class Film {
private:
	string _title, _director, _script;
	int _crewSize;
	double _budget;
	Date _expectedDate;
public:
	void setTitle(string t) {
		_title = t;
	}
	string getTitle() { return _title; }

	bool setCrewSize(int s) {
		// Check if crew size if above acceptable minimum
		if (s > 0) {
			_crewSize = s;
			return true;
		}
		// Crew size is negative
		return false;
	}

	int getCrewSize() { return _crewSize; }

	bool setBudget(double b) {
		// Don't allow negative amounts
		if (b > 0) {
			_budget = b;
			return true;
		}
		// Budget is negative
		return false;
	}

	double getBudget() { return _budget; }

	void setDate(Date d) {
		// No need to perform checks as they're done in the Date class
		_expectedDate = d;
	}

	Date getDate() { return _expectedDate; }

	void setDirector(string d) {
		_director = d;
	}

	void setScript(string s) {
		_script = s;
	}

	string getScript() { return _script; }

	Film(string title, double budget, string director, Date expected, string script = "", int crew = 1) {
		// Use setters which will perform checks
		setTitle(title);
		setBudget(budget);
		setDirector(director);
		setDate(expected);
		setScript(script);
		setCrewSize(crew);
	}
};