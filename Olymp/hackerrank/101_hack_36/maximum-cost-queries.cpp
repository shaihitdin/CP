#include <bits/stdc++.h>
 
using namespace std;
 
struct edge {
    int from;
    int to;
    int w;
};
 
struct node {
    int v;
    int d;
    int comp;
};
 
int const N = 333333;
 
vector<edge> edges[N];
vector<node> sv[N];
int sz[N], banned[N];
multiset<int> best[N];
int painted[N];

#define mp make_pair
 
void dfs(int v, int p) {
    sz[v] = 1;
    for (edge & e : edges[v]) {
        if (e.to == p || banned[e.to]) continue;
        dfs(e.to, v);
        sz[v] += sz[e.to];
    }
}
 
void dfs2(int v, int p, int centroid, int d, int colorito) {
    sv[v].push_back({centroid, d, colorito});
    for (edge & e : edges[v]) {
        if (e.to == p || banned[e.to]) continue;
        dfs2(e.to, v, centroid, max (d, e.w), (colorito == -1) ? e.to : colorito);
    }
}
 
void go(int v) {
    dfs(v, -1);
    int all = sz[v];
    {
        int pv = -1;
        while (true) {
            bool changed = false;
            for (edge & e : edges[v]) {
                if (e.to == pv || banned[e.to]) continue;
                if (sz[e.to] * 2 > all) {
                    pv = v;
                    v = e.to;
                    changed = true;
                    break;
                }
            }
            if (!changed) break;
        }
    }
    dfs2(v, -1, v, 0, -1);
    banned[v] = true;
    for (edge & e : edges[v]) {
        if (!banned[e.to]) go(e.to);
    }
}
 
int const INF = 1 << 29;
multiset <pair <int, int> > c[N];
map <int, int> cc;
 
int main() {
    freopen("treeeg.in", "r", stdin);
    freopen("treeeg.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 0; i + 1 < n; i++) {
        int v, u, l;
        scanf("%d%d%d", &v, &u, &l);
        --v;
        --u;
        edges[v].push_back({v, u, l});
        edges[u].push_back({u, v, l});
    }
    go(0);
    int q;
    scanf("%d", &q);
	for (int i = 0; i < n; ++i) {
		for (auto ee : sv[i]) {
			c[ee.v].insert (mp (ee.d, ee.comp));
		}
	}
	for (int i = 0; i < n; ++i) {
		int cnt = 0;
		for (auto v : c[i]) {
			ans += cnt - cc[v.second]++;
			++cnt;
		}
	}
	cout << ans;
}