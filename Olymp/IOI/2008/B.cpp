#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 100;

typedef long long ll;

int in_cycle[N], cycle_cnt;
vector <int> cycles[N], d[N];
int tmp_ans;
int u[N];
int p[N];
vector <pair <int, int> > g[N];
int pos_in_cycle[N];
vector <int> tree[N];
int n;

inline void dfs (const int &v, const int &pr) {
	p[v] = pr;
	u[v] = 1;
	bool flag = 1;
	for (auto edge : g[v]) {
		int to = edge.first;
		if (to == pr) {
			if (flag == 1) {
				flag = 0;
				continue;
			}
		}
		if (u[to] == 1) {
			++cycle_cnt;
			//cerr << v << " " << to << " " << p[to] << "\n";
			for (int z = v; z != to; z = p[z]) {
				u[z] = 2;
				pos_in_cycle[z] = cycles[cycle_cnt].size ();
				in_cycle[z] = cycle_cnt;
				cycles[cycle_cnt].emplace_back (z);
			}
			u[to] = 2;
			pos_in_cycle[to] = cycles[cycle_cnt].size ();
			in_cycle[to] = cycle_cnt;
			cycles[cycle_cnt].emplace_back (to);
			d[cycle_cnt].resize (cycles[cycle_cnt].size ());
		} else if (!u[to]) {
			dfs (to, v);
		}
	}
}

inline ll dfs2 (const int &v, const int &pr) {
	int mx = 0;
	for (auto edge : g[v]) {
		int to = edge.first;
		if (to == pr)
			continue;
		int tmp = edge.second + dfs2 (to, v);
		tmp_ans = max (tmp_ans, mx + tmp);
		mx = max (mx, tmp);
	}
	return mx;
}

inline int pr (const int &x, const int &y) {
	if (x == 0)
		return y - 1;
	return x - 1;
}


int ans;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;
	
	for (int i = 1; i <= n; ++i) {
		int y, l;
		cin >> y >> l;
		g[i].emplace_back (make_pair (y, l));
		g[y].emplace_back (make_pair (i, l));
	}	
	

	for (int i = 1; i <= n; ++i)
		if (!u[i])
			dfs (i, -1);	

	for (int i = 1; i <= cycle_cnt; ++i)
		d[i].resize (cycles[i].size ());
	
	for (int i = 1; i <= n; ++i)
		for (auto edge : g[i])
			if (in_cycle[i] && edge.first == cycles[in_cycle[i]][(pos_in_cycle[i] + 1) % cycles[cycle_cnt].size ()])
				d[in_cycle[i]][pos_in_cycle[i]] = edge.second;
	
	
	for (int i = 1; i <= cycle_cnt; ++i)
		for (int j = 1; j < cycles[i].size (); ++j)
			d[i][j] += d[i][j - 1];
	
	memset (u, 0, sizeof (u));
	
	for (int i = 1; i <= n; ++i) {
		if (in_cycle[i]) {
			for (auto edge : g[i]) {
				int to = edge.first;
				if (!in_cycle[to])
					tree[i].emplace_back (dfs2 (to, i));
			}
		}
	}
	
	for (int cycle = 1; cycle <= cycle_cnt; ++cycle) {
		int len = cycles[cycle].size ();
		tmp_ans = 0;
		for (int j = 0; j < len; ++j) {
			if (j == 0)
				tmp_ans = max (tmp_ans, d[cycle][len - 1] - d[cycle][j]);
			else 
				tmp_ans = max (tmp_ans, d[cycle][len - 1] - d[cycle][j] + d[cycle][j - 1]);
		}
		for (auto i : cycles[cycle]) {
			for (auto edge : g[i]) {
				int to = edge.first;
				if (!in_cycle[to])
					tree[i].emplace_back (dfs2 (to, i));
			}
			sort (tree[i].begin (), tree[i].end ());
			reverse (tree[i].begin (), tree[i].end ());
			if (tree[i].size () > 1) {
				tmp_ans = max (tmp_ans, tree[i][0] + tree[i][1]);
			}
		}
		for (auto i : cycles[cycle]) {
			for (auto j : cycles[cycle]) {
				if (i == j)
					continue;
				int pos1 = pos_in_cycle[i], pos2 = pos_in_cycle[j];
				if (pos1 < pos2)
					swap (pos1, pos2);
				tmp_ans = max (tmp_ans, max (d[cycle][pr (pos1, len)] - d[cycle][pr (pos2, len)], d[cycle][len] - d[cycle][pr (pos1, len)] + d[cycle][pr (pos2, len)]) /*+*//*TODO*/);
			}
		}
		ans += tmp_ans;
	}
	
	return 0;
}