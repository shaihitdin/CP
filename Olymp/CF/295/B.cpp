#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int N = 1e5 + 10;
const ll bp = 1e9 + 9;

map <pii, int> Map;
map <int, int> Mapx;
set <ll> Set;

int df[] = {-1, 0, 1};

int x[N], y[N];
ll ans;

inline int cp (const int &px, const int &py) {
	if (!Map.count (pii (px, py)))
		return -1;
	return Map[pii (px, py)];
}

inline bool acan (const int &px, const int &py, const int &ax) {
	for (int i = 0; i < 3; ++i)
		if (px + df[i] != ax && cp (px + df[i], py - 1) != -1)
			return 1;
	return 0;
}

inline bool can (const int &px, const int &py) {
	for (int i = 0; i < 3; ++i)
		if (cp (px + df[i], py + 1) != -1 && !acan (px + df[i], py + 1, px))
			return 0;
	return 1;
}

int n;
ll p[N];

int main () {
	#ifndef ONLINE_JUDGE	
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	ios_base :: sync_with_stdio (0);
	cin >> n;
	p[0] = 1;
	for (int i = 1; i < n; ++i)
		p[i] = (p[i - 1] * n) % bp;
	
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
		Map[pii (x[i], y[i])] = i;
	}
	
	for (int i = 0; i < n; ++i)
		if (can (x[i], y[i]))
			Set.insert (i);
	for (int step = 0, power = n - 1; step < n; ++step, --power) {
		int found;
		if (step & 1)
			found = *Set.begin();
		else
			found = *Set.rbegin();
		Map.erase (pii (x[found], y[found]));
		Set.erase (found);
		ans = (ans + p[power] * found) % bp;
		for (int j = y[found] + 1; j >= y[found] - 1; --j) {
			for (int i = x[found] - 5; i <= x[found] + 5; ++i) {
				if (cp (i, j) == -1)
					continue;
				if (can (i, j))
					Set.insert (cp (i, j));
				else
					Set.erase (cp (i, j));
			}
		}
	}
	cout << ans;

	return 0;
}