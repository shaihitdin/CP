#include <bits/stdc++.h>

using namespace std;

const int N = 6e5 + 1;


int nxt[N][26];

int sz;
int mx[N];
bool is_end[N];


inline void add_string (const string &s) {
	int v = 0;
	mx[v] = max (mx[v], (int)s.size ());
	for (auto ch : s) {
		if (!nxt[v][ch - 'a'])
			nxt[v][ch - 'a'] = ++sz;
		v = nxt[v][ch - 'a'];
		mx[v] = max (mx[v], (int)s.size ());
	}
	is_end[v] = 1;
}

char ans[N * 2];
int ans_sz;

inline void go (const int &v) {
	pair <int, char> edges[27];
	int edges_sz;

	if (is_end[v]) {
		ans[++ans_sz] = 'P';
	}
	edges_sz = 0;
	for (int i = 0; i < 26; ++i) {
		if (!nxt[v][i])
			continue;
		edges[++edges_sz] = make_pair (mx[nxt[v][i]], i);
	}
	sort (edges + 1, edges + 1 + edges_sz);
	for (int i = 1; i <= edges_sz; ++i) {
		auto to = edges[i];
		ans[++ans_sz] = to.second + 'a';
		go (nxt[v][to.second]);
	}
	ans[++ans_sz] = '-';
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	/*
	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	*/

	int n;
	
	scanf ("%d", &n);

	string s;

	
	for (int i = 0; i < n; ++i) {
		s.resize (22);
		scanf ("%s\n", s.c_str ());
		s.resize (strlen (s.c_str ()));
		add_string (s);
	}

	go (0);
	
	while (ans_sz && ans[ans_sz] == '-')
		--ans_sz;
	

	printf ("%d\n", ans_sz);

	for (int i = 1; i <= ans_sz; ++i) {
		putchar (ans[i]);
		putchar ('\n');
	}
	
	return 0;
}