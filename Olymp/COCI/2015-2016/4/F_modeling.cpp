#include <bits/stdc++.h>

using namespace std;

double pos[5000], direction[5000];

vector <double> crash[5000];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	int n;
	
	cin >> n;
	
	for (int i = 1; i <= n; ++i)
		pos[i] = pos[i - 1] + 1 + (rand () % 2), direction[i] = (i & 1) ? 1 : -1;
	
	for (double t = 0.5; t <= n * n; t += 0.5) {
		for (int i = 1; i <= n; ++i) {
			pos[i] += 0.5 * direction[i];
		}
		for (int i = 1; i <= n; ++i) {
			if (pos[i] == pos[i + 1]) {
				crash[i].emplace_back (t);
				crash[i + 1].emplace_back (t);
				swap (direction[i], direction[i + 1]);
			}
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		cout << crash[i].size () << " ";
		for (auto t : crash[i])
			cout << t << " ";
		cout << "\n";
	}
	return 0;
}