#include <iostream>
#include <vector>
#include <stdio.h>
#include <bitset>
using namespace std;
const int N = (1e5) + 1;
typedef long long ll;
#define mkp make_pair
#define F first
#define S second
ll sum[N], total_sum, ans;
bool u[N];
vector <pair <ll, ll> > g[N];
int n, x, y, l;
pair <ll, ll> dfs (const int &v, const int &number_v, const ll &p_sum, const ll &p_e) {
	ll new_sum = 0, n_num = 0;
	u[v] = 1;
	for (auto to : g[v]) {
		if (!u[to.F]) {
		    auto get = dfs (to.F, n_num + number_v + 1, p_sum + new_sum * to.S + to.S * (n_num + number_v + 1), to.S);
			new_sum += get.F;
			n_num += get.S;
		}
	}
	sum[v] = new_sum;
	cerr << v << " " << sum[v] << "\n";
	//cerr << v << " : " << new_sum + p_e * (n_num + 1) << " " << n_num + 1 << "\n";
	return mkp (new_sum + p_e * (n_num + 1), n_num + 1);
}
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin >> n;
	cout << fixed;
	for (int i = 1; i < n; ++i) {
		cin >> x >> y >> l;
		g[x].push_back(mkp (y, l));
		g[y].push_back(mkp (x, l));
		
	}
	dfs (1, 0, 0, 0);
	for (int i = 1; i <= n; ++i) {
		total_sum += sum[i];
	}
	for (int i = 1; i <= n; ++i) {
		ans += sum[i] + total_sum;
	}
	cerr << ans;
	return 0;
}