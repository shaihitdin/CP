/**
	Oh, my dear
**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 11000;

vector <int> primes[N];

inline bool common_element (const vector <int> &a, const vector <int> &b) {
	for (int i = 0, j = 0; i < a.size () && j < b.size (); ++i) {
		while (j < b.size () && b[j] < a[i])
			++j;
		if (j == b.size ())
			return 0;
		if (a[i] == b[j])
			return 1;
	}
	return 0;
}

inline bool leq (int a, int b, int c, int d) {
	return a * d <= c * b;
}

double x;
int n;
int c, d, g;

inline void convert (int &c, int &d) {
	string damn;
	cin >> damn;
	if (damn == "1" || damn == "1.0" || damn == "1.00" || damn == "1.000" || damn == "1.0000") {
		c = 1, d = 1;
		return;
	}
	while (damn.size () < 6)
		damn += "0";
	d = 10000;
	for (int i = 2; i < damn.size (); ++i) {
		c *= 10;
		c += (damn[i] - '0');
	}
}

int main () {
	#ifdef BROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	convert (c, d);
	
	cin >> n;

	for (int i = 2; i <= n; ++i) {
		int s = i;
		for (int j = 2; j * j <= s; ++j) {
			if (s % j == 0) {
				while (s % j == 0) {
					s /= j;
				}
				primes[i].emplace_back (j);
			}
		}
		if (s > 1)
			primes[i].emplace_back (s);
	}
	
	int ans = 0;

	for (int i = 2; i <= n; ++i) {
		for (int j = 1; leq (j, i, c, d); ++j) {
			if (!common_element (primes[i], primes[j]))
				++ans;
		}
	}

	/*
	#ifdef BROKEN
		cerr << clock () * 1000 / CLOCKS_PER_SEC << "\n";
	#endif
	*/

	cout << ans;

	return 0;
}