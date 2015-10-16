#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1;

vector <int> g[N];

int pos[N];
int In[N], Out[N], n, sz;
vector <int> euler;

inline void dfs (const int &v) {
	for (; pos[v] < g[v].size();) {
		int to = g[v][pos[v]];
		++pos[v];
		dfs (to);
	}
	euler.push_back (v);
}

map <string, int> counter;
string a[N], s;

inline void EulerPath (const int &v) {
	memset (pos, 0, sizeof (pos));
	euler.resize (0);
	dfs (v);
	reverse (euler.begin(), euler.end());
}

inline void no_solution() {
	puts ("NO");
	exit (0);
}

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	ios_base :: sync_with_stdio(0);
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> s;
		string s1, s2;
		s1 += s[0]; s1 += s[1];
		s2 += s[1]; s2 += s[2];
		if (!counter[s1])
			counter[s1] = ++sz;
		if (!counter[s2])
			counter[s2] = ++sz;
		int x = counter[s1], y = counter[s2];
		a[x] = s1;
		a[y] = s2;
		g[x].push_back (y);
		++Out[x];
		++In[y];
	}
	int start = 0,
	finish = 0;
	for (int i = 1; i <= sz; ++i) {
		if (Out[i] == In[i] || Out[i] - In[i] == 1 || Out[i] - In[i] == -1) {
			if (Out[i] - In[i] == 1 && !start)
				start = i;
			else if (Out[i] - In[i] == 1)
				no_solution();
			else if (Out[i] - In[i] == -1 && !finish)
				finish = i;
			else if (Out[i] - In[i] == -1)	
				no_solution();
		}
		else
			no_solution();
	}
	start = start ? start : !start;
	//cout << "YES\n" << a[euler[0]][0];
	EulerPath (start);
	for (int i = 1; i <= sz; ++i) {
		if (pos[i] != g[i].size())
			no_solution();
	}
	cout << "YES\n" << a[euler[0]][0];
	for (int it : euler)
		cout << a[it][1];
	return 0;
}