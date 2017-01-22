/// Forever

#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1);
  
const int oo = 1e9, bpr = 1e9 + 7, N = 5010, K = 64;
const int M = N / K + 2;

ll d[N][M];
bitset <N> d2[N];
pair <int, int> cnt[N];

inline bool calc (ll a[], ll b[]) {
	int val = 0;
	for (int i = 0; i < M; ++i) {
		val += __builtin_popcountll (a[i] & b[i]);
		if (val > 1)
			return 1;
	}
	return 0;
}

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	int n, m;
	
	scanf ("%d%d", &n, &m);
	
	if (m <= 3e4) {
		pair <int, int> e[n * 16 + 1];
		bool d3[N][N];
		memset (d3, 0, sizeof (d3));
		for (int i = 1; i <= m; ++i) {
			int x, y;
			scanf ("%d%d", &x, &y);
			e[i] = make_pair (x, y);
			d3[x][y] = d3[y][x] = 1;
		}
		for (int i = 1; i <= m; ++i) {
			for (int j = i + 1; j <= m; ++j) {
				if (e[i].first == e[j].first || e[i].first == e[j].second || e[i].second == e[j].first || e[i].second == e[j].second)
					continue;
				if ((d3[e[i].first][e[j].first] && d3[e[i].second][e[j].second])) {
					puts ("TAIP");
					printf ("%d %d %d %d", e[i].first, e[i].second, e[j].second, e[j].first);
					return 0;
				} else if (d3[e[i].first][e[j].second] && d3[e[i].second][e[j].first]) {
					puts ("TAIP");
					printf ("%d %d %d %d", e[i].first, e[i].second, e[j].first, e[j].second);
					return 0;
				}
			}
		}
		puts ("NE");
		return 0;
	}
	
	for (int i = 1; i <= m; ++i) {
		int x, y;
		scanf ("%d%d", &x, &y);
		d[x][y / K] |= (1ll << (y % K));
		d[y][x / K] |= (1ll << (x % K));
		d2[x][y] = d2[y][x] = 1;
		++cnt[x].first;
		++cnt[y].first;
	}

	for (int i = 1; i <= n; ++i)
		cnt[i].second = i;
	
	sort (cnt + 1, cnt + n + 1);
	reverse (cnt + 1, cnt + n + 1);
	
	for (int it = 1; it <= n; ++it) {
		int i = cnt[it].second;
		for (int it2 = it + 1; it2 <= n && it2 <= it + 60; ++it2) {
			int j = cnt[it2].second;
			if (calc (d[i], d[j])) {
				auto save = d2[i] & d2[j];
				printf ("TAIP\n%d ", i);
				int val = 1;
				for (int k = 1; k <= n; ++k) {
					if (save[k]) {
						printf ("%d ", k);
						++val;
					}
					if (val == 2) {
						printf ("%d ", j);
						++val;
					}
					if (val == 4)
						return 0;
				}
				assert (0);
			}
		}
	}

	puts ("NE");
	
	return 0;
}