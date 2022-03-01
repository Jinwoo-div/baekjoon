#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef pair <int, int> pii;


int main() {
	vector <pii> setting;
	vector <long long int> same;
	int tempVil;
	int tempPeo;
	int count;
	int tempCount;
	long long int result = 0;
	long long int total = 0;
	long long int totPeo = 0;
	int rest;

	cin >> count;
	tempCount = count;

	for (int i = count; i > 0; i--) {
		cin >> tempVil;
		cin >> tempPeo;
		setting.emplace_back(tempVil, tempPeo);
	}

	sort(setting.begin(), setting.end());

	for (int i = count - 1; i > -1; i--) {
		total += setting[i].second * setting[i].first;
	}
	for (int i = count - 1; i > -1; i--) {
		totPeo += setting[i].second;
	}

	int first = setting[0].first;
	int last = setting[count - 1].first;

	result = total / totPeo;
	rest = total % totPeo;
	while (true) {
		if (result < first || result > last) {
			rest = result / totPeo;
			result = result / totPeo;
			continue;
		}
		else {
			if (result / totPeo >= first || result / totPeo <= last) {
				if (result < totPeo) {
					break;
				}
				rest = result / totPeo;
				result = result / totPeo;
				continue;
			}
			else {
				break;
			}
		}
	}

	if (totPeo % 2 == 0 && rest == totPeo / 2) {

		long long int rightP = 0;
		long long int leftP = 0;

		for (int i = count - 1; i > -1; i--) {
			if (setting[i].first <= result) {
				for (int j = count - i - 1; j > 0; j--) {
					rightP += setting[i].second;
				}
				for (int j = i + 1; j > 0; j--) {
					leftP += setting[i].second;
				}
			}
		}
		if (result > 0) {
			if (rightP <= leftP) {
				cout << result;
			}
			else {
				cout << result + 1;
			}
		}
		else {
			if (rightP <= leftP) {
				cout << result - 1;
			}
			else {
				cout << result;
			}
		}
	}
	else {
		if (result > 0) {
			if (rest < totPeo / 2) {
				cout << result;
			}
			else {
				cout << result + 1;
			}
		}
		else {
			if (abs(rest) < abs(totPeo / 2)) {
				cout << result;
			} 
			else {
				cout << result - 1;
			}
		}
	}
	return 0;
}
