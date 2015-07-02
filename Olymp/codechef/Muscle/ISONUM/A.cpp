#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector <int> number;
vector <int> now;
bool u[15];
int ans;
int m, n;

inline vector <int> to_str (int x, const int &base) {
	vector <int> res;
	res.resize(0);
	while (x) {
		res.push_back (x % base);
		x /= base;
	}
	reverse (res.begin (), res.end());
	return res;
}

inline int bin_pow (const int &x, const int &y) {
	if (y <= 0)
		return 1;
	if (y & 1)
		return x * 1ll * bin_pow (x, y - 1);
	int xx = bin_pow (x, y / 2);
	return xx * 1ll * xx;
}

inline void rec (const int &lvl, const int &cnt, const ) {
	if (lvl == number.size ()) {
		int unused = cnt;
		memset (u, 0, sizeof (u));
		for (int i = 0; i < number.size (); ++i) {
			if (!u[now[i]]) {
				u[now[i]] = 1;
				--unused;
			}
			if (i == 0)
				ans = (ans + ((number[i] - 1) * bin_pow (10, unused))) % m;
			else
				ans = (ans + ((number[i]) * bin_pow (10, unused))) % m;
		}
		return;
	}	
	ans = (ans + 9 * bin_pow (10, cnt - 1)) % m;
	for (int i = 1; i <= cnt; ++i) {
		now[lvl] = i;
		rec (lvl + 1, cnt);
	}
	now[lvl] = cnt + 1;
	rec (lvl + 1, cnt + 1);
}

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	
	int t;

	scanf ("%d", &t);

	
	while (t--) {
		cin >> n >> m;
		number = to_str (n, 10);
		now.resize (number.size ());
		rec (0, 0);
		cout << ans << "\n";
	}	

	return 0;
}