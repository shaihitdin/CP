#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;

struct node {
	int link, len;
	map <char, int> nx;
};

node a[N * 2];

int last, sz;

inline void sa_extend (const char &c) {
	int cur = ++sz;
	a[cur].len = a[prev].len + 1;
	int p = prev;
	for (; p != -1 && !a.nx.count (c); p = a[p].link)
		a[p].nx[c] = cur;
	if (p == -1) {
		a[cur].link = 0;
	} else {
		int q = a[p].nx[c];
		if (a[q].len == a[p].len + 1) {
			a[cur].link = q;
		} else {
			int clone = ++sz;
			a[clone].len = a[p].len + 1;
			a[clone].link = a[q].link;
			a[clone].nx = a[q].nx;
			for (; p != -1 && a[p].nx[c] == q; p = a[p].link)
				a[p].nx[c] = clone;
			a[q].link = a[cur].link = clone;
		}
	}
	prev = cur;
}

int main () {

}