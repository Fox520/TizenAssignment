#include <vector>
#include "Film.h"

struct Films {

	void addFilm(Film f) {
		filmList.push_back(f);
	}

	vector<Film> getFilms() { return filmList; }

	void clearFilms() {
		filmList.clear();
	}

	double calculateTotalSpent() {
		// Find the overall budget on all films
		double sum = 0;
		for (int i = 0; i < filmList.size(); i++) {
			sum += filmList.at(i).getBudget();
		}
		return 0;
	}

private:
	vector<Film> filmList;
};