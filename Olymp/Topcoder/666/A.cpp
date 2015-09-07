#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned int ui;

#define N 51
#define end can

using namespace std;
class WalkOverATree {
	
	int n;
	vector <int> g[51], till_top[51][101], tmp1[101], tmp2[101];
	int ans, d[51][101], end[51][101];

	inline void del_parent (const int &v, const int &p) {
		for (int i = 0; i < g[v].size (); ++i) {
			if (v == p)
				g[v].erase (g[v].begin () + i);
			del_parent (g[v][i], v);
		}
	}
	
	inline void dfs (const int &v, const int &p) {
		for (int i = 1; i <= 100; ++i)
			till_top[v][i][0] = 1;
		for (int i = 0; i < g[v].size (); ++i) {
			int to = g[v][i];
			dfs (to, v);
			for (int j = 0; j <= 100; ++j)
				till_top[v][j + 1][i + 1] = end[to][j];

		}
		
		for (int i = 1; i <= 100; ++i) {
			tmp1[i].resize (0);
			tmp2[i].resize (0);
			tmp1[i].resize (g[v].size () + 1);
			tmp2[i].resize (g[v].size () + 1);
		}
		
		for (int j = 0; j <= 100; ++j)
			tmp1[j][0] = till_top[v][j][0];
		for (int j = 0; j <= 100; ++j)
			tmp2[j][g[v].size ()] = till_top[v][j][g[v].size ()];
		
		for (int i = 1; i <= g[v].size (); ++i)
			for (int j = 0; j <= 100; ++j)
				for (int k = 0; j + k <= 100; ++k)
					tmp1[j + k][i] = max (tmp1[j + k][i], tmp1[j][i - 1] + till_top[v][k][i]);
		
		for (int i = g[v].size () - 1; i >= 0; --i)
			for (int j = 0; j <= 100; ++j)
				for (int k = 0; j + k <= 100; ++k)
					tmp2[j + k][i] = max (tmp2[j + k][i], tmp2[j][i + 1] + till_top[v][k][i]);

		for (int i = 0; i <= g[v].size (); ++i) {
			int to = g[v][i];
			if (i == 0) {
				if (i != g[v].size ()) {
					for (int j = 0; j + 1 <= 100; ++j) {
						for (int k = 0; j + 1 + k <= 100; ++k) {
							d[v][j + 1 + k] = max (d[v][j + 1 + k], d[to][j] + tmp2[k][i + 1]);
						}
					}
				} else {
					for (int j = 0; j + 1 <= 100; ++j)
						d[v][j + 1] = max (d[v][j + 1], d[to][j]);
				}
			} else if (i == g[v].size ()) {
				for (int j = 0; j + 1 <= 100; ++j) {
					for (int k = 0; j + 1 + k <= 100; ++k) {
						d[v][j + 1 + k] = max (d[v][j + 1 + k], d[to][j] + tmp1[k][i - 1]);
					}
				}
			} else {
				for (int j = 0; j <= 100; ++j) {
					for (int k = 0; j + k <= 100; ++k) {
						for (int l = 0; l + 1 + j + k <= 100; ++l) {
							d[v][j + k + l + 1] = max (d[v][j + k + l + 1], tmp1[j][i - 1] + tmp2[k][i + 1] + d[to][l]);
						}
					}
				}
			}
		}
		
		for (int i = 0; i <= 100; ++i) {
			ans = max (ans, d[v][i]);
		}
		
		for (int i = 0; i <= 100; ++i)
			end[v][i] = tmp1[i][g[v].size ()];
	}
	
	public:
    int maxNodesVisited(vector <int> parent, int L) {
    	n = parent.size () + 1;
    	for (int i = 0; i < parent.size (); ++i) {
    		g[parent[i]].emplace_back (i + 1);
    		g[i + 1].emplace_back (parent[i]);
    	}
    	del_parent (0, -1);
    	for (int i = 0; i < n; ++i) {
    		for (int j = 0; j <= 100; ++j) {
    			till_top[i][j].resize (g[i].size () + 1);
    		}
    	}
    	dfs (0, -1);
    	return ans;
    }

};

#ifdef LOCAL
int main () {
	
	return 0;
}
#endif