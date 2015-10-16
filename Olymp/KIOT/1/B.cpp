#include <bits/stdc++.h>

using namespace std;

const int N = 1200;

int a[N], n;
char u[N];

inline bool cmp (const int &x, const int &y) {
	cout << "1 " << x << " " << y << "\n";
	cout.flush ();
	string s;
	cin >> s;
	return s == "YES";
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> n;

	for (int i = 1; i <= n; ++i)
		a[i] = i;

	stable_sort (a + 1, a + n + 1, cmp);
	/*
	for (int i = 2; i <= n; ++i) {
		if (!cmp (a[i - 1], a[i])) {
			cout << "0 ";
			for (int i = 0; i <= n; ++i)
				cout << 0 << " ";
			return 0;
		}
	}
	*/
	cout << "0 ";
	
	for (int i = 1; i <= n; ++i)
		cout << a[i] << " ";
	
	return 0;
}