#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100;

int n, m;



int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	while (1) {
		cin >> n >> m;
		for (int i = 1; i <= n; ++i)
			p[i] = i;
		cin >> m;
		for (int i = 1; i <= m; ++i) {
			cin >> q_type[i] >> a[i] >> b[i];
			if (q_type[i] == '!')
				cin >> w[i];
			
		}
	}
	
	return 0;
}