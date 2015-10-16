#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

int n, m, k[N];

int comp_num[N];
int broken_till[N];
int pos[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> m;

	for (int i = 1; i <= m; ++i) {
		cin >> k[i];
		
		for (int j = 1; j <= k[i]; ++j) {
			int x;
			cin >> x;
			pos[x] = j;
			comp_num[x] = i;
		}
	}
	
	for (int i = 1; i <= m; ++i)
		broken_till[i] = k[i];
	
	for (int i = n - 1; i >= 1; --i) {
		if (comp_num[i] == comp_num[i + 1] && pos[i + 1] == pos[i] + 1)
			continue;
		broken_till[comp_num[i]] = pos[i];
		broken_till[comp_num[i + 1]] = pos[i + 1];
	}


	long long ans = 0, diff_cnt = 0;
	for (int i = 1; i <= m; ++i) {
		ans += k[i] - broken_till[i];
		diff_cnt += (k[i] - broken_till[i]) + 1;
	}
	
	cerr << ans << " " << diff_cnt << " ";
	cout << ans + diff_cnt - 1 << " ";
	return 0;
}