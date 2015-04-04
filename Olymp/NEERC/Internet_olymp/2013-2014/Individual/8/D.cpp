#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
const int N = (1e6) + 1, inf = (1e9) + 1;
vector <int> g[N],v[N];
int main () {
	freopen ("bluetube.in", "r", stdin);
	freopen ("bluetube.out", "w", stdout);
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf ("%d", &a[i]);
		cnt[a[i]].push_back(i);
	}
	sort (a + 1, a + n + 1);
	for (int i = 2; i < N; i += 2)
		l_p[i] = 2;
	for (int i = 3; i < N; i += 2) {
		if (!l_p[i]) {
			for (int j = i * i; j * j < N; j += i * 2) {
				if (!l_p[j])	l_p[j] = i;
			}
			l_p[i] = i;
		}
	}
	for (int i = 2; i < N; ++i) {
		v[i] = v[i / l_p[i]];
		v[i].push_back(l_p[i]);
	}
	for (int i = 2; i < N; ++i) {
		sort (v[i].begin(), v[i].end());
		nw.resize(0);
		nw.push_back (v[i][0]);
		for (int j = 1; j < v[i].size(); ++j)
			if (nw.back() != v[i][j])
				nw.push_back (v[i][j]);
		g[i] = nw;
	}
	for (int i = 1; i < N; ++i)
		d[i] = inf;
	for (int i = 1; i <= n; ++i) {
		int ans = 0;
		if (cnt[a[i]].size() > 1) {
			ans = cnt[a[i]][0];
			if (ans == i) {
				ans = cnt[a[i]][1];
			}
			printf ("%d\n", ans);
			continue;
		}
		st[enq++] = a[i];
		d[a[i]] = 1;
		p[a[i]] = 
		temp = inf;
		while (stq < enq) {
			v = st[stq++];
			for (int i = 0; i < g[v].size(); ++i) {
			
			}
		}
	}
	return 0;
}