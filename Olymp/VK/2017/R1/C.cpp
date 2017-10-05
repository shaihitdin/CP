//

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1);

#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

const int oo = 1e9, bpr = 1e9 + 7, N = 2e5 + 100, K = 5;

int n, k;
int lvl[N];
int cnt[N][K];
ll sum[N][K], ans[N];
ll dpsum[N][K], dpcnt[N][K], ndpsum[K], ndpcnt[K];
vector <int> g[N];

inline void dfs (int v, int pp) {
    lvl[v] = lvl[pp] + 1;
    lvl[v] %= 5;
    for (auto to : g[v]) {
        if (to == pp)
            continue;
        dfs (to, v);
        for (int i = 0; i < k; ++i)
            cnt[v][i] += cnt[to][i], sum[v][i] += sum[to][i];
    }
    for (int i = 0; i < k; ++i)
        ans[v] += sum[v][i] + cnt[v][i];
    sum[v][lvl[v]] += cnt[v][lvl[v]];
    cnt[v][lvl[v]]++;

}

inline void dfsup (int v, int pp) {
    for (int i = 0; i < k; ++i)
        ans[v] += dpsum[v][i] + dpcnt[v][i];
    dpsum[v][0] += dpcnt[v][0];

    for (auto to : g[v]) {
        if (to == pp)
            continue;

        for (int i = 0; i < k; ++i)
            sum[v][i] -= sum[to][i], cnt[v][i] -= cnt[to][i];
        sum[v][lvl[v]] -= cnt[to][lvl[v]];

        for (int i = 0; i < k; ++i) {
            dpsum[to][(i + 1) % k] = dpsum[v][i];
            dpcnt[to][(i + 1) % k] = dpcnt[v][i];
        }

        for (int i = 0; i < k; ++i) {
            dpsum[to][(i - lvl[v] + k + 1) % k] += sum[v][i];
            dpcnt[to][(i - lvl[v] + k + 1) % k] += cnt[v][i];
        }


        dfsup (to, v);



        for (int i = 0; i < k; ++i)
            sum[v][i] += sum[to][i], cnt[v][i] += cnt[to][i];
        sum[v][lvl[v]] += cnt[to][lvl[v]];
    }

}

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

    cin >> n >> k;

    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].eb (y);
        g[y].eb (x);
    }

    dfs (1, 0);
    dfsup (1, 0);

    ll total = 0;

    for (int i = 1; i <= n; ++i)
        total += ans[i];
    assert (total % 2 == 0);
    cout << total / 2;
    return 0;
}
