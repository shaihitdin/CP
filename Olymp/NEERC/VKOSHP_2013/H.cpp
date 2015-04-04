#include <iostream>
#include <stdio.h>
#include <set>
#include <vector>
#define mkp make_pair
#define forn(i, x, n) for(int i = int(x); i <= int(n); ++i)
using namespace std;                          
const int N = 5001,inf = N * 100001 * 2;
vector < pair <int,int> > v[N];
int n, m, i, x, y, z, d[N], from, to, a[N], last[N], ans = inf, ans1, ans2;
set<pair<int,int> > st;
int main() {
	freopen ("secure.in", "r", stdin);
	freopen ("secure.out", "w", stdout);
	scanf ("%d%d", &n, &m);
	for (i = 1; i <= n; ++i) {
		scanf ("%d", &a[i]);
	}
	for (i = 1; i <= m; ++i) {
		scanf ("%d%d%d", &x, &y, &z);
		v[x].push_back(mkp(y,z));
		v[y].push_back(mkp(x,z));
	}
	for (i = 1; i <= n; ++i) {
		d[i] = inf;
		if(a[i] == 1) {
			d[i] = 0;
			st.insert (mkp (0, i));
		}
	}
	while (st.size()) {    
		from = st.begin()->second;
		st.erase(st.begin());
		for(i = 0; i < v[from].size(); ++i) {
			to = v[from][i].first;
		    if(d[to] > d[from] + v[from][i].second) {
		    	st.erase(mkp(d[to], to));
		    	d[to] = d[from] + v[from][i].second;
		    	st.insert(mkp(d[to], to));
				last[to] = last[from];
				if(a[from] == 1) {
					last[to] = from;			
				}
			}
		}
	}
	forn (i, 1, n) {
		if (a[i] == 2) {
			if (d[i] - d[last[i]] < ans) { 
				ans = d[i] - d[last[i]];
				ans1 = last[i];
				ans2 = i;
			}
		}
	}
	if(ans == inf) {
		printf ("-1");
		return 0;
	}
	printf("%d %d %d", ans1, ans2, ans);
	return 0;
}