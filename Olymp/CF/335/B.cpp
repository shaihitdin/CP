#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 100;

struct edge {
	int cost, in, id;
};

inline bool operator < (const edge &a, const edge &b) {
	if (a.cost == b.cost)
		return a.in > b.in;
	return a.cost < b.cost;
}

int cnt;
int till[N];
int now;
pair <int, int> ans[N];
vector <edge> edges;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n, m;
	
	cin >> n >> m;

	for (int i = 1; i <= m; ++i) {
		int x, y;
		cin >> x >> y;
		edges.push_back ({x, y, i});
	}

	sort (edges.begin (), edges.end ());

	cnt = 1;
	now = 2;
	for (int i = 2; i <= n; ++i)
		till[i] = i;
	
	for (auto it : edges) {
		if (it.in) {
			ans[it.id] = make_pair (1, ++cnt);
			now = 2;
		} else {
			while (now <= cnt && till[now] >= cnt)
				++now;
			if (now > cnt) {
				cout << -1;
				return 0;
			}
			ans[it.id] = make_pair (now, ++till[now]);
		}
	}
	
	for (int i = 1; i <= m; ++i)
		cout << ans[i].first << " " << ans[i].second << "\n";
	
	return 0;
}