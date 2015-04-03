#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <set>
#define mkp make_pair
#define F first
#define S second
using namespace std;
typedef long long ll;
const int N = 503, inf = 1e9;
int n, m, x, y, h, temp, l[N], r[N];
vector <pair <int, int>> g[N];
vector <int> e[N];
string q;
ll d[N][N];
set <pair <int, int>> s[N], s2;
inline ll arith (const ll &f_num, const ll &num, const ll &change) {
	return (2 * f_num + change * (num - 1) ) * num / 2 ;
}
int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> x >> y >> q;
		if (q == "x")
			e[x].push_back (y);
		else
			g[x].push_back (mkp (y, atoi(q.c_str())));
	}
	cin >> m;
	for (int t = 1; t <= m; ++t) {
		int a, b;
		cin >> a >> b;
		// d[x][y] -> x = hyperspace teleports, y = vertex
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				d[i][j] = inf;
		d[0][a] = 0;
		s[0].insert (mkp (0, a));
		for (int i = 0; i <= 500; ++i) {
			while (s[i].size()) {
				auto v = s[i].begin() -> S;
				s[i].erase (s[i].begin());
				if (d[i + 1][v] > d[i][v]) {
					s[i + 1].erase (mkp (d[i + 1][v], v));
					d[i + 1][v] = d[i][v];
					s[i + 1].insert (mkp (d[i + 1][v], v));
				}
				for (auto to : g[v]) {
					if (d[i][to.F] > d[i][v] + to.S) {
						s[i].erase (mkp (d[i][to.F], to.F));
						d[i][to.F] = d[i][v] + to.S;
						s[i].insert (mkp (d[i][to.F], to.F));
					}
				}
				for (auto to : e[v]) {
					if (d[i + 1][to] > d[i][v]) {
						s[i].erase (mkp (d[i + 1][to], to));
						d[i + 1][to] = d[i][v];
						s[i].insert (mkp (d[i + 1][to], to));
					}
				}
			}
		}
		
		if (d[0][b] == inf && d[500][b] != inf) {
			puts ("inf");
			continue;
		}
		if (d[0][b] == inf && d[500][b] == inf) {
			puts ("0 0");
			continue;
		}
		l[0] = 1;
		r[0] = inf + 2;
		long long found;
		for (int i = 1; i <= 500; ++i) {
			int lo = 0, hi = inf + 2;			
			if (d[i][b] >= d[i - 1][b]) {
				continue;
			}
			while (hi - lo > 1) {
				int mid = (lo + hi) >> 1;
				for (int j = 0; j < i; ++j) {
					if (l[j] <= mid && mid <= r[j]) {
						found = j;
						break;
					}
				}
				if (d[found][b] + found * mid > d[i][b] + i * mid)
					lo = mid;
				else
					hi = mid;
			}
			l[i] = 1;
			r[i] = lo;
			for (int j = 0; j < i; ++j) {
					l[j] = max (l[j], r[i] + 1);
			}
		}
		long long diff_n = 0, sum = 0;
		for (int i = 1; i <= 500; ++i) {
			if (l[i] > r[i])
				continue;
			if (d[i][b] >= d[i - 1][b]) {
				continue;
			}
			if (d[i][b] == inf + 2)
				continue;
			diff_n += r[i] - l[i] + 1;
			sum += arith (i * l[i] + d[i][b], r[i] - l[i] + 1, i);
		} 
		sum += d[0][b];
		++diff_n;
		cout << diff_n << " " << sum << "\n";
	}
	return 0;
}