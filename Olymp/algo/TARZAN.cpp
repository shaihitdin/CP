#include <bits/stdc++.h>

using namespace std;

const int N = 600001;

struct dsu {
	int p, sz, ans;
} s[N];


vector <int> g[N], q_v[N];
char type[N][6];
int x[N], y[N];
int q_ans[N];


inline int get_p (const int &v) {
	return (v == s[v].p) ? (v) : (s[v].p = get_p (s[v].p));
}

inline void unity (int a, int b) {
	a = get_p (a);
	b = get_p (b);
	if (s[a].sz < s[b].sz)
		swap (a, b);
	s[b].p = a;
	s[a].sz += s[b].sz;
	/*
	if (s[a].rank == s[b].rank)
		++s[a].rank;
	*/
}

inline void dfs (const int &v) {
	s[v].p = v;
	s[v].sz = 1;
	s[get_p (v)].ans = v;
	for (auto to : g[v]) {
		dfs (to);
		unity (v, to);
		s[get_p (v)].ans = v;
	}
	for (auto it : q_v[v]) {
		if (x[it] == v)
			swap (x[it], y[it]);
		if (s[x[it]].p)
			q_ans[it] = s[get_p (x[it])].ans;
	} 
}

int main () {

	#ifndef ONLINE_JUDGE
	freopen ("lca.in", "r", stdin);
	freopen ("lca.out", "w", stdout);
	#endif

	srand (time (0));

	int m;

	scanf ("%d\n", &m);

	for (int i = 1; i <= m; ++i) {
		scanf ("%s %d %d\n", &type[i], &x[i], &y[i]);
		if (type[i][0] == 'A')
			g[x[i]].push_back (y[i]);
		else
			q_v[x[i]].push_back (i), q_v[y[i]].push_back (i);
	}

	dfs (1);

	for (int i = 1; i <= m; ++i) {
		if (type[i][0] == 'G')
			cout << q_ans[i] << "\n";
	}
	
	return 0;
}