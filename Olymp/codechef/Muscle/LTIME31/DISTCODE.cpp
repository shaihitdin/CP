#include <bits/stdc++.h>

using namespace std;

const int N = 110;

bool d[N][N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	d[1][0] = 1;
	d[2][1] = 1;

	
	
	for (int i = 0; i < N; ++i) {
		for (int i1 = 0; i1 < N; ++i1) {
			for (int j = 0; j < N; ++j) {
				for (int j1 = 0; j1 < N; ++j1) {
				
				}
			}
		}
	}
	
	/*
	int t;

	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; ++i)
			g[i].clear ();
		
	}
	*/
	return 0;	
}