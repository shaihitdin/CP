#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <complex>

#define pb push_back
#define mp make_pair

#define f first
#define s second

using namespace std;

const int N = (int) 1e5 + 7;

typedef long long ll;

struct vec {
    int x, y;
    vec (int xx, int yy) {
        x = xx;
        y = yy;
    }
    vec () {
        x = 0;
        y = 0;
    }
};

inline ll scalar (vec a, vec b) {
    return a.x * 1ll * b.y - a.y * 1ll * b.x;
}

struct edge {
    int to, cap, flow;
};
vector <edge> e;
vector <int> g[N];

int n, k, h, m, s, t;
bool u[500];

inline void add_edge (int x, int y, int Z) {
    g[x].emplace_back (e.size ());
    e.push_back ({y, Z, 0});
    g[y].emplace_back (e.size ());
    e.push_back ({x, 0, 0});
}

inline int dfs (int v, int K, int flow) {
    if (!flow)
        return 0;
    if (v == t)
        return flow;
    if (u[v])
        return 0;
    u[v] = 1;
    for (auto id : g[v]) {
        int pushed = dfs (e[id].to, K, min (flow, e[id].cap - e[id].flow));
        if (pushed) {
            e[id].flow += pushed;
            e[id ^ 1].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}


int lx[N], ly[N], hx[N], hy[N], mx[N], my[N];


int main() {
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
    #else
        //#define FNAME
        //freopen(FNAME".in", "r", stdin);
        //freopen(FNAME".out", "w", stdout);
    #endif

    cin >> n >> k >> h >> m;

    for (int i = 0; i < n; ++i) {
        cin >> lx[i] >> ly[i];
    }

    for (int i = 0; i < h; ++i) {
        cin >> hx[i] >> hy[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> mx[i] >> my[i];
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < h; ++j) {
            int good = 0;
            for (int k = 0; k < n; ++k) {
                vec fline = vec (hx[j] - mx[i], hy[j] - my[i]);
                vec sline = vec (lx[k] - mx[i], ly[k] - my[i]);
                vec tline = vec (lx[(k + 1) % n] - mx[i], ly[(k + 1) % n] - my[i]);
                int val = 0;
                if ((scalar (fline, sline) < 0 && scalar (fline, tline) > 0) || (scalar (fline, sline) > 0 && scalar (fline, tline) < 0)) {
                    val += 1;
                }
                fline = vec (lx[(k + 1) % n] - lx[k], ly[(k + 1) % n] - ly[k]);
                sline = vec (mx[i] - lx[k], my[i] - ly[k]);
                tline = vec (hx[j] - lx[k], hy[j] - ly[k]);
                if ((scalar (fline, sline) < 0 && scalar (fline, tline) > 0) || (scalar (fline, sline) > 0 && scalar (fline, tline) < 0)) {
                    val += 1;
                }
                if (val == 2)
                    good += 1;
            }
            //cerr << i + 1 << " " << j + 1 << " " << good << "\n";
            if (good == 0) {
                //cerr << i + 1 << " " << j + 1<< endl;
                add_edge (i, m + j);
            }
        }
    }

    s = m + h;
    t = s + 1;

    for (int i = 0; i < m; ++i) {
        add_edge (s, i, 1);
    }
    for (int i = 0; i < h; ++i) {
        add_edge (m + i, t);
    }


    for (int K = 8; K; K >>= 1) {
        while (dfs (s, K, K)) {
            memset (u, 0, sizeof (u));
        }
    }
    int ans = 0;
    for (int i = 0; i < h; ++i) {
        for (auto id : g[m + i]) {
            int to = e[id].to;
            if (to == t) {
                ans += e[id].flow;
            }
        }
    }

    //cerr << ans << " ";
    if (ans == m) {
        puts ("Possible");
    } else {
        puts ("Impossible");
    }
    return 0;
}
