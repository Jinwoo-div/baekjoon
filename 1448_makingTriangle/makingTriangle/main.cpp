#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count;
	vector<int> strow;
	
	cin >> count;

	for (int i = 0; i < count; i++) {
		int temp;
		cin >> temp;
		if (temp < 1) {
			continue;
		}
		strow.emplace_back(temp);
	}
	sort(strow.begin(), strow.end()); 
	
	if (strow[count - 1] < strow[count - 2] + strow[count - 3]) {
		cout << strow[count - 1] + strow[count - 2] + strow[count - 3];
		return 0;
	}
	else if (count == 3) {
		cout << "-1";
		return 0;
	}
	else {
		int i = 2;
		while (true) {
			if (strow[count - i] < strow[count - i - 1] + strow[count - i - 2]) {
				cout << strow[count - i] + strow[count - i - 1] + strow[count - i - 2];
				return 0;
			}
			else {
				if (i + 2 == count) {
					cout << "-1";
					return 0;
				}
				i++;
				continue;
			}
		}
	}
}