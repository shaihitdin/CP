#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;


bool u[N];
vector <int> g[N], top_sort;
int pos[N];


inline void dfs (const int &v) {
	u[v] = 1;
	for (auto to : g[v])
		if (!u[to]) dfs (to);
	top_sort.push_back (v);
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int n;
	
	cin >> n;

	for (int i = 1; i < n; ++i) {
		char x;
		cin >> x;
		if (x == '<')
			g[i + 1].push_back (i);
		else
			g[i].push_back (i + 1);
	}
	
	for (int i = 1; i <= n; ++i)
		if (!u[i])
			dfs (i);

	reverse (top_sort.begin (), top_sort.end ());

	for (int i = 0; i < top_sort.size (); ++i) {
		pos[top_sort[i]] = n - i;
	}
	
	for (int i = 1; i <= n; ++i)
		cout << pos[i] << " ";
	
	return 0;
}