#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> map;
int n, m;

int main() {
	cin >> n >> m;
	for (int line = 0; line < n; line++) {
		vector<int> tmp;
		map.emplace_back(tmp);
		string num;
		cin >> num;
		for (int pos = 0; pos < m; pos++) {
			map[line].emplace_back(num[pos]);
		}
	}

	dp(0, 0, 0);
}

void dp(int x, int y, int count) {
	if (x == n || y == m) {
		return;
	}
	if (map[x + 1][y] == 1) {
		dp(x + 1, y, count);
		if (count == -1) {
			return -1;
		}
		else {
			return count + 1;
		}
	}

}