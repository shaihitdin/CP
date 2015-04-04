/*
ID: shaihit1
PROG: wormhole
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 20;

map <int, vector <int> > Map;
bool u[N];
int x[N], y[N], p[N], n, ans;
int g[N];


inline bool dfs (const int &v) {	
	if (u[v]) {
		/*
		for (int i = 1; i <= n; ++i) {
			cerr << i << " -> " << p[i] << "\n";
		}
		cerr << "\n";
		*/
		return 1;
	}
	u[v] = 1;
	int to = p[g[v]];
	if (!to)
		return 0;
	return dfs (to);
}

inline void rec (const int &num) {
	
	if (num == n + 1) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j)
				u[j] = 0;
			if (dfs (i)) {
				++ans;
				return;
			}
		}
		return;
	}
	
	if (p[num]) {
		rec (num + 1);
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (!p[i] && num != i) {
			p[i] = num;
			p[num] = i;
			rec (num + 1);
			p[i] = 0;
			p[num] = 0;
		}
	}

}

inline bool cmp (const int &l, const int &r) {
	return x[l] < x[r];
}

int main() {
	
	freopen ("wormhole.in", "r", stdin);
	freopen ("wormhole.out", "w", stdout);
	
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf ("%d%d", &x[i], &y[i]);
		Map[y[i]].push_back (i);
	}
	for (auto &it : Map)
		sort (it.second.begin(), it.second.end(), cmp);
	for (auto it : Map) {
		for (int i = 0; i < it.second.size(); ++i) {
			if (i + 1 == it.second.size())
				continue;
			g[it.second[i]] = it.second[i + 1];
		}
	}
	rec (1);
	printf ("%d\n", ans);
	return 0;
}                    	