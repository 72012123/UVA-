#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
int main()
{
	int Case;
	cin >> Case;
	while (Case--) {
		int b, sb, sg, i, temp, compare, battlefields[100000];
		multiset<int> blue, green;
		cin >> b >> sg >> sb;
		for (i = 0; i < sg; i++) {
			cin >> temp;
			green.insert(temp);
		}
		for (i = 0; i < sb; i++) {
			cin >> temp;
			blue.insert(temp);
		}
		while (!blue.empty() && !green.empty()) {
			int size = 0;
			for (i = 0; i < b; i++) {
				if (green.empty() || blue.empty()) {
					break;
				}
				battlefields[size++] = *green.rbegin() - *blue.rbegin();
				green.erase(green.lower_bound(*green.rbegin()));
				blue.erase(blue.lower_bound(*blue.rbegin()));
			}
			for (i = 0; i < size; i++) {
				if (battlefields[i] > 0)
					green.insert(battlefields[i]);
				else if (battlefields[i] < 0)
					blue.insert(-battlefields[i]);
			}
		}
		if (green.empty() && blue.empty())
			cout << "green and blue died\n";
		else if (green.empty()) {
			cout << "blue wins\n";
			while (!blue.empty()) {
				cout << *blue.rbegin() << endl;
				blue.erase(blue.lower_bound(*blue.rbegin()));
			}
		}
		else {
			cout << "green wins\n";
			while (!green.empty()) {
				cout << *green.rbegin() << endl;
				green.erase(green.lower_bound(*green.rbegin()));
			}
		}
		if (Case)
			cout << endl;
	}
	return 0;
}
