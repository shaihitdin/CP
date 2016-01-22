#include <bits/stdc++.h>

using namespace std;

const int N = 220;

bool u[N];
int a[N];

inline bool rec (const int &pos, const int &n) {
	if (pos == 2 * n + 1)
		return 1;

	if (a[pos] > 0)
		return rec (pos + 1, n);

	for (int i = n + 1; i >= 1; --i) {
		if (u[i] || pos + i > 2 * n || a[pos + i] > 0)
			continue;
		a[pos] = i;
		a[pos + i] = i;
		u[i] = 1;
		if (rec (pos + 1, n))
			return 1;
		a[pos] = 0;
		a[pos + i] = 0;
		u[i] = 0;
	}
	return 0;
}

int main () {

	freopen ("sequence.in", "r", stdin);
	freopen ("sequence.out", "w", stdout);
	
	int n;
	
	cin >> n;
	memset (u, 0, sizeof (u));
	memset (a, 0, sizeof (a));
	rec (1, n);
	if (a[1] == 0) {
		cout << "-1\n";
		return 0;
	}
	for (int i = 1; i <= 2 * n; ++i)
		cout << a[i] << " ";
	cout << "\n";

	return 0;
}