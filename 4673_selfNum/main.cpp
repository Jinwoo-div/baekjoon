#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

vector<string> graph;
int visit[101][101];
int countRoad[101][101];

int n, m;

void bfs();

int main() {
	cin >> n >> m;
	for (int line = 0; line < n; line++) {
		string num;
		cin >> num;
		graph.emplace_back(num);
	}

	bfs();

	cout << countRoad[n - 1][m - 1] + 1;
}

void bfs() {
	queue<pair<int, int>> que;
	que.push(make_pair(0, 0));
	visit[0][0] = 1;
	while (!que.empty()) {
		pair<int, int> item = que.front();
		que.pop();

			if (item.first - 1 >= 0) {
				if (graph[item.first - 1][item.second] == '1' && visit[item.first - 1][item.second] == 0) {
					que.push(make_pair(item.first - 1, item.second));
					countRoad[item.first - 1][item.second] = countRoad[item.first][item.second] + 1;
					visit[item.first - 1][item.second] = 1;
				}
			}

			if (item.first + 1 < n) {
				if (graph[item.first + 1][item.second] == '1' && visit[item.first + 1][item.second] == 0) {
					que.push(make_pair(item.first + 1, item.second));
					countRoad[item.first + 1][item.second] = countRoad[item.first][item.second] + 1;
					visit[item.first + 1][item.second] = 1;
				}
			}

			if (item.second - 1 >= 0) {
				if (graph[item.first][item.second - 1] == '1' && visit[item.first][item.second - 1] == 0) {
					que.push(make_pair(item.first, item.second - 1));
					countRoad[item.first][item.second - 1] = countRoad[item.first][item.second] + 1;
					visit[item.first][item.second - 1] = 1;
				}
			}

			if (item.second + 1 < m) {
				if (graph[item.first][item.second + 1] == '1' && visit[item.first][item.second + 1] == 0) {
					que.push(make_pair(item.first, item.second + 1));
					countRoad[item.first][item.second + 1] = countRoad[item.first][item.second] + 1;
					visit[item.first][item.second + 1] = 1;
				}
			}
	}
}