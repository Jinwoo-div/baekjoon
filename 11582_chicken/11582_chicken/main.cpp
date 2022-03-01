#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num, people;
	vector<int> chicken;
	vector<int>::iterator it;

	cin >> num;
	for (int i = 0; i < num; i++) {
		int temp;
		cin >> temp;
		chicken.emplace_back(temp);
	}
	cin >> people;

	int perPerson = num / people;
	it = chicken.begin();

	while(true) {
		sort(it, it+perPerson);
		if (it + perPerson == chicken.end()) {
			break;
		}
		it = it + perPerson;
	}

	for (int i = 0; i < chicken.size(); i++) {
		cout << chicken[i] << " ";
	}

	return 0;
}