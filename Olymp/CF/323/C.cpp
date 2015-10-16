#include <bits/stdc++.h>

using namespace std;

const int N = 600;

int n, a[N];

multiset <int> b;

int gcd (int a, int b) {
	return b ? gcd (b, a % b) : a;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;

	int sqr_n = n * n;
	
	for (int i = 1; i <= sqr_n; ++i) {
		int x;
		cin >> x;
		b.insert (x);
	}

	for (int i = 1; i <= n; ++i) {
		a[i] = *b.rbegin ();
		for (int j = 1; j < i; ++j) {
			b.erase (b.find (gcd (a[j], a[i])));
			b.erase (b.find (gcd (a[j], a[i])));
		}
		b.erase (b.find (a[i]));
	}
	
	for (int i = 1; i <= n; ++i)
		cout << a[i] << " ";
	
	return 0;
}