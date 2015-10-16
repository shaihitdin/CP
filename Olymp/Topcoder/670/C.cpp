#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned int ui;


using namespace std;
class Treestrat {
	
	public:
    int roundcnt(vector <int> tree, vector <int> A, vector <int> B) {
    	int num = 100000;
    	
    	int N = 101;

    	int n = tree.size () + 1;
		vector <int> g[N];
		int d[N][N];
		
		memset (d, 0, sizeof (d));
		
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				d[i][j] = 1000;
		
		for (int i = 0; i < tree.size (); ++i) {
			g[tree[i]].emplace_back (i + 1);
			g[i + 1].emplace_back (tree[i]);
		}

		for (int i = 0; i < n; ++i)
			for (auto to : g[i])
				d[i][to] = 1;
		
		for (int i = 0; i < n; ++i)
			d[i][i] = 0;		
		
		for (int k = 0; k < n; ++k)
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					d[i][j] = min (d[i][j], d[i][k] + d[k][j]);		
		
		for (auto v : A) {
			int mx = 0;
			for (int to = 0; to < n; ++to) {
				bool flag = 1;
				for (auto u : B)
					if (d[u][to] <= d[v][to])
						flag = 0;
				if (flag) {
					int assign = 10000;
					for (auto u : B)
						assign = min (assign, d[u][to]);
					mx = max (mx, assign);
				}
			}
			num = min (num, mx);
		}
		return num;
	}

};

#ifdef LOCAL
int main () {
	
	return 0;
}
#endif