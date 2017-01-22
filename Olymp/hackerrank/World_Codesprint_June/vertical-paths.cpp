#include <bits/stdc++.h>
using namespace std;
int n,m,a,b,d;

void do_a_barell_roll (int v, int parent) {
	po[v] = parent;
	for (auto to : g[v]) {
		if (to.first == parent)
			continue;
		do_a_barell_roll (to.first, v);
	}
}

main () {
	std::cin>>test_num;
	for (int test = 1; test <= test_num; ++test)
	{
		std::cin>>n>>m;
		for (int i = 1 ; i <= n; ++i)
			g[i].resize (0);
		for (int i = 1; i < n; ++i) {
			int a,b,d;
			std::cin >>             a>>b>>d;
			g[a].push_back(mp (b, d));
			g[b].push_back(mp(a, d));
		}
		do_a_barell_roll (1, 0);
		for(int i = 1; i <= n; ++i)
		{
			for (auto u : g[i])
				if (u == g[i].first)
					lim[i] = g[i].second;
		}
		for(int i =0; i < (1 << m); ++i) {
			for(int j = 0; j < m; ++j)
				if (i & (1 << j)) {
					
				}
		}
	}
}