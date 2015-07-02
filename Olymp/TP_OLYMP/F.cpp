#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
typedef long double ld;

ll n, p1, p2, h;

unordered_map <ll, vector <string> > Set;

bool can[256];

inline ll pl (ll i1, ll i2) {
	i1 %= p2;
	i2 %= p2;
	ld res = ld (i1) + ld (i2);
	while (res >= p2)
		res -= p2;
	return ll (res);
}

inline ll bin_mult (const ll &i1, const ll &i2) {
	if (i1 == 0 || i2 == 0)
		return 0;
	if (i2 % 2 == 1)
		return pl (bin_mult (i1, i2 - 1), i1);
	ll b = bin_mult (i1, i2 / 2);
	return pl (b, b);
}

inline void rec1 (const ll &h_now, const ll &p1_now, const int &n, const string &check) {
	if (n == 0) {
		Set[h_now].push_back (check);
		return;
	}
	for (int i = 0; i < 26; ++i)
		if (can['a' + i])	
			rec1 (pl (h_now, bin_mult (p1_now, i)), bin_mult (p1_now, p1), n - 1, check + char ('a' + i));
}

inline void rec2 (const ll &h_now, const ll &p1_now, const int &n, const string &check) {
	if (n == 0) {
		for (auto it : Set[max (h, h_now) - min (h, h_now)])
			cout << it << check << "\n";
		return;
	}
	for (int i = 0; i < 26; ++i)
		if (can['a' + i])
			rec2 (pl (h_now, bin_mult (p1_now, i)), bin_mult (p1_now, p1), n - 1, check + char ('a' + i));
}

int main () {
	/*
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	*/
	ios_base :: sync_with_stdio (0);

	can['q'] = can['w'] = can['e'] = can['r'] = can['t'] =  can['y'] = can['u'] = can['i'] = can['o'] = can['p'] = 1;

	cin >> n >> p1 >> p2;

	cin >> h;
	
	rec1 (0, 1, n / 2, "");
	ll pww = 1;
	for (int i = 1; i <= (n / 2); ++i)
		pww = bin_mult (pww, p1);
	//cerr << pww << " ";
	rec2 (0, pww, n / 2 + (n % 2 == 1), "");
	return 0;
}