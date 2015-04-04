#include <bits/stdc++.h>
#include <map>

using namespace std;

const int N = 1e5 + 1;

struct t {
	int link, len;
	map <char, int> nx;
};

char q;
t node[N * 2];
int sz, last;

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
			node[clone].len = node[p].len + 1;
			node[clone].link = node[q].link;
			node[clone].nx = node[q].nx;
			for (; p != -1 && node[p].nx[c] == q; p = node[p].link)
				node[p].nx[c] = clone;
			node[q].link = node[cur].link = clone;
		}
	}
	last = cur;
}

int main () {	
	freopen ("nenokku.in", "r", stdin);
	freopen ("nenokku.out", "w", stdout);

	node[0].link = -1;

	while ((q = getchar()) != EOF) {
		char it;
		getchar();
		if (q == '?') {
			int now = 0;
			bool flag = 0;
			while (((it = getchar()) != '\n') && it != EOF) {
				if (!flag)
					now = node[now].nx[tolower (it)];
				if (!now)
					flag = 1;
			}
			puts (flag ? "NO" : "YES");
		}
		else
			while (((it = getchar()) != '\n') && it != EOF)
				sa_extend (tolower (it));
	}

	return 0;
}