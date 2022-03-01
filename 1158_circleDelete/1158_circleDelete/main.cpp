#include <iostream>
#include <vector>

using namespace std;

int main() {
	int people;
	int turn;
	int point = 0;
	int count = 0;

	cin >> people >> turn;
	int* circle = new int[people];
	vector<int> num;
	
	for (int i = 0; i < people; i++) {
		circle[i] = i + 1;
	}

	for (int i = people; i > 0; i--) {
		if (i == people) {
			point = turn - 1;
			num.emplace_back(circle[point]);
			circle[point] = 0;
			continue;
		}
		while (true) {
			if (point == people - 1) {
				point = 0;
			}
			else {
				point += 1;
			}
			if (circle[point] == 0) {
			}
			else {
				count += 1;
			}
			if (count == turn) {
				break;
			}
		}
		count = 0;
		num.emplace_back(circle[point]);
		circle[point] = 0;
	}
	cout << "<";
	for (int i = 0; i < people; i++) {
		if (i == people - 1) {
			cout << num[i];
			break;
		}
		cout << num[i] << ", ";
	}
	cout << ">";
}