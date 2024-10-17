#include<iostream>
#include<vector>
#include<set>

#ifndef BLUM.H
#define BLUM.H
std::vector<bool> primeInit(1000005, true);
void erathorness(int n) { // find out all the prime under N
	primeInit[0] = primeInit[1] = false;
	for(int i = 2; i * i <= n; i++) {
		if (primeInit[i] == true) {
			for (int j = i * i; j <= n; j += i) {
				primeInit[j] = false;
			}
		}
	}
}
void blumFunc(int n, int blum) {
	erathorness(n);
	//init the blum series
	std::set<int> blumSeries;
	{ // temporary vector -> minimum the memory
		std::vector<int> primeList;
		primeList.push_back(2);
		for (int i = 3; i <= n; i += 2) {
			if (primeInit[i] == true) primeList.push_back(i);
		}
		int numOfPrime = primeList.size();
		for (int i = 0; i < numOfPrime - 1; i++) {
			for (int j = i + 1; j < numOfPrime; j++) {
				if ((primeList[i] * primeList[j]) % 4 == 3) {
					blumSeries.insert(primeList[i] * primeList[j]);
				}
			}
		}
		primeList.clear(); // remove vector to reduce memory consumption
	}
	//list out the availabel total Blum 
	std::cout << "The total blum list (if available): ";
	bool avai = true;
	for (auto& i : blumSeries) {
		for (auto& j : blumSeries) {
			if (j > i) { // make sure it over the first i
				if (blumSeries.find(j + i) != blumSeries.end()) {
					avai = true;
					std::cout << i + j << " ";
				}
			}
		}
	}
	if (avai == false) std::cout << "Not available";
	// find the blum in blum series
	if (blumSeries.find(blum) != blumSeries.end()) {
		std::cout << "The blum " << blum << "is exsist!" << std::endl;
	}
}
#endif // !BLUM.H
