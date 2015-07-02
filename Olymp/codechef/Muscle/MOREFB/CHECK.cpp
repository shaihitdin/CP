#include <bits/stdc++.h>

using namespace std;

#define mp make_pair

map <pair <int, int>, int> Map;

const int bpr = 99991;

int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	int f1 = 1, f2 = 1, num = 2;


	for (int i = 3;; ++i) {
		if (Map.count (mp (f1, f2))) {
			cout << Map[mp (f1, f2)] << " " << i << " " << f1 << " " << f2 << "\n";
			return 0;
		}
		Map[mp (f1, f2)] = i;
		num = (f1 + f2) % bpr;
		f1 = f2;
		f2 = num;
	}
	

	return 0;
}