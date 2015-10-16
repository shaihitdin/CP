#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 100;

int cnt[N];
int total_sz;
int n, m;
bool u[N];

inline void add (const int &x) {
	++cnt[x];
	if (cnt[x] == 1)
		++total_sz;
}

inline void del (const int &x) {
	//assert(cnt[x]);
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

	for (int i = 1; i < N; ++i)
		if (u[i])
			++cnt[0];
	
	int ans = 0;
	
	for (int i = 1; i <= m; ++i) {
		if (u[1]) {
			del(i - 1);
			add(i);
		}
		if (i == 1) {
		    for (int j = 2; j < N; ++j)
		    	if (u[j])
		    		add(1);
			ans = max (ans, total_sz);
			continue;
		}                  
		//del old
		cerr << total_sz << "\n";
		for (int j = 1; j * j <= i; ++j) {
			if (i % j == 0) {
				int j1 = j, j2 = i / j;
				if (j1 > 1 && u[j1]) 
					del(j2 - 1);										
				if (u[j2]) 
					del(j1 - 1);
			}
		}
		//add new
		for (int j = 1; j * j <= (i - 1); ++j) {
			if ((i - 1) % j == 0) {
				int j1 = j, j2 = (i - 1) / j;
				if (j1 > 1 && u[j1])           
					add(j2 + 1);										
				if (u[j2]) 
					add(j1 + 1);
			}
		}

		ans = max (ans, total_sz);
	}


	cout << ans;
	
	return 0;
}