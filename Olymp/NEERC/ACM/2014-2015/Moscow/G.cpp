#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 100;

int cnt = 0;

inline int myrand (const int &r) {
	return (rand () * 1ll * rand ()) % r;
}

map <string, int> convert;
int u[N];
bool in_list[N];
vector <int> g[N];

inline int dfs (const int &v) {
	if (!in_list[v])
		return 0;
	if (u[v])
		return u[v];
	u[v] = 1;
	int mx = 0;
	for (auto to : g[v]) {
		if (u[to])
			continue;
		mx = max (mx, dfs (to));
	}
	u[v] += mx;
	return u[v];
}


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	srand (time (0));
	
	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n;
	
	cin >> n;

	
	for (int i = 1; i <= n; ++i) {
		string s1, s2, s3;
		cin >> s1 >> s2;
		cin >> s3;
		cin >> s3;
		cin >> s3;
		if (convert[s1 + '#' + s3] == 0)
			convert[s1 + '#' + s3] = ++cnt;
		if (convert[s1 + '#' + s2] == 0)
			convert[s1 + '#' + s2] = ++cnt;
		int v1, v2;
		v1 = convert[s1 + '#' + s2];
		v2 = convert[s1 + '#' + s3];
		in_list[v1] = 1;
		g[v1].push_back (v2);
	}
	
	int ans = 0;
	
	for (int magic = 1; magic <= 100; ++magic) {
		for (int i = 1; i <= cnt; ++i)
			random_shuffle (g[i].begin (), g[i].end (), myrand);
	    memset (u, 0, sizeof (u));
		for (int i = 1; i <= cnt; ++i) {
			ans = max (ans, dfs (i));
		}	
	}
	cout << ans;

	return 0;
}