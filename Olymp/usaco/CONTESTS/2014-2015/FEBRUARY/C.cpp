#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

#define mkp make_pair
#define F first
#define S second

const int N = 2001;

int n, a[N];
long long ans;
int p[N];

vector <pair <int, pii> > g;

inline int gp (const int &x) {
	return x == p[x] ? x : p[x] = gp (p[x]);
}

inline void Merge (int x, int y) {
	x = gp (x);
	y = gp (y);
	if (rand() & 1)
		p[x] = y;
	else
		p[y] = x;
}

inline bool cmp (const pair <int, pii> &x, const pair <int, pii> &y) {
	return x.F > y.F;
}

int main () {
	freopen ("superbull.in", "r", stdin);
	freopen ("superbull.out", "w", stdout);
	srand (time (0));
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			g.push_back (mkp (a[i] ^ a[j], mkp (i, j)));
	sort (g.begin(), g.end(), cmp);
	
	for (int i = 1; i <= n; ++i)
		p[i] = i;

	for (auto it : g) {
		if (gp (it.S.S) != gp (it.S.F)) {
			Merge (it.S.S, it.S.F);
			ans += it.F;
		}
	}
	cout << ans;
	return 0;
}