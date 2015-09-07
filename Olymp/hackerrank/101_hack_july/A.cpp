#include <bits/stdc++.h>

using namespace std;

pair <int, int> a[6];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	for (int i = 1; i <= 5; ++i) {
		cin >> a[i].first >> a[i].second;
	}

	sort (a + 1, a + 6);

	do {
		bool flag = 0;
		for (int i = 2; i <= 5; ++i) {
			if (a[i].first > a[i - 1].first && a[i].second > a[i - 1].second)
				continue;
			else
				flag = 1;
		}
		if (!flag) {
			cout << 1;
			return 0;
		}
	} while (next_permutation (a + 1, a + 6));
	
	cout << 0;
	
	return 0;
}