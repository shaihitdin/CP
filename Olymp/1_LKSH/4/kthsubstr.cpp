#include <bits/stdc++.h>
#include <map>

using namespace std;

const int N = 1e5 + 1;
typedef long long ll;
const ll inf = 1e18;

#define mkp make_pair
#define F first
#define S second

struct automata {
	int len, link;
	ll sz;
	map <char, int> nx;
};

automata node[N * 2];

int last, sz;

inline void sa_extend (const char &c) {
	int cur = ++sz;
	node[cur].len = node[last].len + 1;
	int p = last;
	for (; p != -1 && !node[p].nx[c]; p = node[p].link)
		node[p].nx[c] = cur;
	if (p == -1) {
		node[cur].link = 0;
	} else {
		int q = node[p].nx[c];
		if (node[p].len + 1 == node[q].len) {
			node[cur].link = q;
		} else {
			int clone = ++sz;
			node[clone].nx = node[q].nx;
			node[clone].len = node[p].len + 1;
			node[clone].link = node[q].link;
			for (; p != -1 && node[p].nx[c] == q; p = node[p].link)
				node[p].nx[c] = clone;
			node[cur].link = node[q].link = clone;
		}
	}
	last = cur;
}

inline void dfs (const int &v) {
	if (node[v].sz)
		return;
	node[v].sz = 1;
	for (auto it : node[v].nx) {
		dfs (it.S);
		node[v].sz += node[it.S].sz;
	}
	return;
}

inline void get (const int &v, ll cnt) {
	if (!node[v].nx.size() || !cnt) {
		exit (0);
	}
	--cnt;
	for (auto it : node[v].nx) {
		if (node[it.S].sz <= cnt) {
			cnt -= node[it.S].sz;
		} else {
			putchar (it.F);
			get (it.S, cnt);
		}
	}
	putchar (node[v].nx.rbegin() -> F);
	get (node[v].nx.rbegin() -> S, inf);
}

ll x;

int main () {
	freopen ("kthsubstr.in", "r", stdin);
	freopen ("kthsubstr.out", "w", stdout);
	char c;	
	node[0].link = -1;
	while ( (c = getchar()) != '\n') {
		sa_extend (c);
	}
	dfs (0);
	scanf ("%lld", &x);
	get (0, x);	
	return 0;
}