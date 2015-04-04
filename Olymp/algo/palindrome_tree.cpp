#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

struct node {
	int nxt[26];
	int sz;
	int sufflink;
	long long ans;
};

node t[N];
int now, tree_sz;
long long res;
string s;

inline void add (const int &pos) {
	int cur = now, ch = s[pos] - 'a';
	while (1) {
		int curlen = t[cur].sz;
		if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos])
			break;
		cur = t[cur].sufflink; 
	}
	if (t[cur].nxt[ch]) {
		now = t[cur].nxt[ch];
		return;
	}
	now = ++tree_sz;
	t[cur].nxt[ch] = now;
	t[now].sz = t[cur].sz + 2;
	
	if (t[now].sz == 1) {
		t[now].sufflink = 2;
		t[now].ans = 1;
		return;
	}
	
	while (1) {
		cur = t[cur].sufflink;
		int curlen = t[cur].sz;
		if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos]) {
			t[now].sufflink = t[cur].nxt[ch];			
			break;
		}
	}
	t[now].ans = 1 + t[t[now].sufflink].ans;
}

int main () {
	/*	
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	*/
	cin >> s;

	tree_sz = 2;
	t[1].sufflink = 1, t[1].sz = -1;
	t[2].sufflink = 1, t[2].sz = 0;
	now = 2;

	for (int i = 0; i < s.size(); ++i) {
		add (i);
		res += t[now].ans;
	}
	cout << res;
	return 0;
}