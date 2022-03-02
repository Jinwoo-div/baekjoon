#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int main() {
	int changeNum;
	int cupNum[3] = { 1, 2, 3 };
	int* cupPoint[3] = { &cupNum[0], &cupNum[1], &cupNum[2] };
	cin >> changeNum;
	vector<pii> changeHistory;
	for (int i = changeNum; i > 0; i--) {
		int temp1, temp2;
		cin >> temp1 >> temp2;
		changeHistory.emplace_back(temp1, temp2);
	}

	for (int i = 0; i < changeNum; i++) {
		if (changeHistory[i].first == changeHistory[i].second) {
			continue;
		}
		int tempNum;
		for (int j = 0; j < 3; j++) {
			if (*cupPoint[j] == changeHistory[i].first) {
				cupPoint[j] = &cupNum[changeHistory[i].second - 1];
				tempNum = j;
				break;
			}
		}
		for (int j = 0; j < 3; j++) {
			if (*cupPoint[j] == changeHistory[i].second && j != tempNum) {
				cupPoint[j] = &cupNum[changeHistory[i].first - 1];
				break;
			}
		}
	}
	cout << *cupPoint[0];
	return 0;
}