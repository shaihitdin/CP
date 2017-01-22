/// izizi

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
  
const int oo = 1e9, bpr = 1e9 + 7, N = 5100;

#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

int st[N], stq, enq;
int d[3010][3010];

struct qq {
	int v1, v2;
	int sum;
};

vector <qq> d2[3010];
int ans, ans1, ans2, ans3, ans4;
vector <int> g[3010];
int n, m;

inline bool operator < (qq as, qq bs) {
	return as.sum < bs.sum;
}

inline void bfs (int d[], int v) {
	for (int i = 1; i <= n; ++i)
		d[i] = -1;
	d[v] = 0;
	stq = enq = 0;
	st[enq++] = v;
	while (stq != enq) {
		int u = st[stq++];
		for (auto to : g[u]) {
			if (d[to] == -1) {
				d[to] = d[u] + 1;
				st[enq++] = to;
			}
		}
	}
}

inline void relax (vector <qq> &was, qq nw) {
	if (nw.sum <= 0)
		return;
	was.eb (nw);
	sort (was.begin (), was.end ());
	reverse (was.begin (), was.end ());
	while (was.size () > 8)
		was.pop_back ();
}

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	cin >> n >> m;

	for (int i = 1; i <= m; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].eb (y);
	}
	
	for (int i = 1; i <= n; ++i)
		bfs (d[i], i);
	
	for (int i = 1; i <= n; ++i) {
		vector <pair <int, int> > cc;
		for (int j = 1; j <= n; ++j)
			if (d[i][j] != -1 && i != j)
				cc.eb (mp (d[i][j], j));
		sort (cc.begin (), cc.end ());
		reverse (cc.begin (), cc.end ());
		for (int j = 1; j <= n; ++j) {
			if (i == j || d[j][i] == -1)
				continue;
			for (int cnt = 0, k = 0; cnt < 2 && k < cc.size (); ++k) {
				if (cc[k].se == j)
					continue;
				relax (d2[j], {i, cc[k].se, d[j][i] + cc[k].fe});
				++cnt;
			}
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j || d[i][j] == -1)
				continue;
			for (auto it : d2[j]) {
				if (it.v1 == i || it.v2 == i || it.v1 == j || it.v2 == j)
					continue;
				ans = max (ans, d[i][j] + it.sum);
				if (ans == d[i][j] + it.sum)
					ans1 = i, ans2 = j, ans3 = it.v1, ans4 = it.v2;					
			}
		}
	}
	
	cout << ans1 << " " << ans2 << " " << ans3 << " " << ans4;
	
	return 0;
}