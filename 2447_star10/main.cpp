#include <iostream>
#include <vector>
#include <cmath> 

using namespace std;

vector<vector<int>> def;

void sol(int kei);

int main() {
	int k;
	cin >> k;
	sol(k);
	for (int i = 0; i < def.size(); i++) {
		for (int j = 0; j < def.size(); j++) {
			if (def[i][j] == 1) {
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << "\n";
	}
}

void sol(int kei) {
	if (kei > 1) {
		sol(kei - 1);
	}
	else {
		vector<int> tmpVec1;
		tmpVec1.emplace_back(1);
		tmpVec1.emplace_back(1);
		tmpVec1.emplace_back(1);
		def.emplace_back(tmpVec1);
		vector<int> tmpVec2;
		tmpVec2.emplace_back(1);
		tmpVec2.emplace_back(0);
		tmpVec2.emplace_back(1);
		def.emplace_back(tmpVec2);
		vector<int> tmpVec3;
		tmpVec3.emplace_back(1);
		tmpVec3.emplace_back(1);
		tmpVec3.emplace_back(1);
		def.emplace_back(tmpVec3);
		return;
	}
	int blank = pow(3, kei - 1);
	vector<int> zeroVec;
	for (int i = 0; i < blank; i++) {
		zeroVec.emplace_back(0);
	}
	int s = def.size();

	for (int i = 0; i < blank * 2; i++) {
		vector<int> tmpVec = def[i % s];
		def.emplace_back(tmpVec);
	}

	for (int i = 0; i < blank * 3; i++) {
		vector<int> tmpVec;
		if (i >= blank && blank * 2 > i) {
			tmpVec.insert(tmpVec.end(), def[i].begin(), def[i].end());
			tmpVec.insert(tmpVec.end(), zeroVec.begin(), zeroVec.end());
			tmpVec.insert(tmpVec.end(), def[i].begin(), def[i].end());
		}
		else {
			for (int j = 0; j < 3; j++) {
				tmpVec.insert(tmpVec.end(), def[i].begin(), def[i].end());
			}
		}
		def[i].clear();
		def[i] = tmpVec;
	}
}
