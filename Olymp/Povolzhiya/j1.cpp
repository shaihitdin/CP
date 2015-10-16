#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 100;

int cnt[N];
int total_sz;
int n, m;
vector <int> v[N];
bool u[N];

inline void add (const int &x) {
	++cnt[x];
	if (cnt[x] == 1)
		++total_sz;
}

inline void del (const int &x) {
	assert (cnt[x]);
	--cnt[x];
	if (cnt[x] == 0)
		--total_sz;
}

int main () {


	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	
	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		u[x] = 1;
	}

	for (int i = 0; i < N; ++i)
		if (u[i])
			v[0].emplace_back (i), add (0);

	int ans = 0;
	
	for (int i = 0; i <= m; ++i) {
		if (i > 0)
			for (auto it : v[i - 1])
				add ((i - 1) / it + 1);

		for (auto it : v[i]) {
			if (i > 0)
				del ((i - 1) / it);
			v[i + it].emplace_back (it);
		}
		ans = max (ans, total_sz);
	}


	cout << ans;
	
	return 0;
}