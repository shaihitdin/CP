/**
	Oh, my dear
**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 110, bmo = 1e9;

vector <pair <int, int> > s;

inline bool bit (int mask, int pos) {
	return (mask >> pos) & 1;
}

int d[400][30];
int n;

inline int calc (int x, int till) {
	if (x == s.size ())
		return (till == n);
	if (d[x][till] != -1)
		return d[x][till];
	d[x][till] = 0;
	d[x][till] += calc (x + 1, till);
	if (s[x].first < (till + 1)) {
		d[x][till] += calc (x + 1, max (till, s[x].second));
		d[x][till] %= bmo;
	}
	return d[x][till];
}

int main () {
	#ifdef BROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n;
	
	if (n == 1) {
		cout << 0;
		return 0;
	}
	
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			if (__gcd (i, j) == 1)
				s.emplace_back (make_pair (i, j));
	
	memset (d, -1, sizeof (d));

	cout << calc (0, 1);
	
	return 0;
}