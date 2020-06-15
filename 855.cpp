#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	int i, j, Case, s, a, f, x[50000], y[50000];
	cin >> Case;
	while (Case--) {
		cin >> s >> a >> f;
		int meet[2] = { 0 }, temp;
		for (i = 0; i < f; i++) {
			cin >> x[i] >> y[i];
		}
		sort(x, x + f);
		sort(y, y + f);
		if (f % 2 != 0)
			cout << "(Street: " << x[f / 2] << ", Avenue: " << y[f / 2] << ")\n";
		else cout << "(Street: " << x[f / 2 - 1] << ", Avenue: " << y[f / 2 - 1] << ")\n";
	}
	return 0;
}
