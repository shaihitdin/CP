#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 30;

int ans = -1;

int n, h_t;

int h[N], w[N], s[N];
bool u[N];

inline bool bit (const int &mask, const int &pos) {
	return (mask >> pos) & 1;
}

int main () {
	freopen ("guard.in", "r", stdin);
	freopen ("guard.out", "w", stdout);

	ios_base :: sync_with_stdio (0);

	cin >> n >> h_t;

	for (int i = 0; i < n; ++i)
		cin >> h[i] >> w[i] >> s[i];

	for (int i = 0; i < (1 << n); ++i) {
		memset (u, 0, sizeof (u));
		int cnt = 0;
		for (int j = 0; j < n; ++j)
			if (bit (i, j))
				u[j] = 1, ++cnt;
		
		int sum = 0;
		for (int j = 0; j < n; ++j) {
			if (!u[j])
				continue;
			sum = min (sum + h[j], (int)1e9);
		}

		if (sum < h_t)
			continue;

		bool flag = 0;
		int res = 2e9;
		for (int j = 0; j < cnt; ++j) {
			sum = 0;
			for (int k = 0; k < n; ++k) {
				if (!u[k])
					continue;
				if (sum + w[k] < 0) {
					flag = 1;
					break;
				}
				sum += w[k];
			}
			int f_id = -1;
			for (int k = 0; k < n; ++k) {
				if (!u[k])
					continue;
				if (s[k] >= sum - w[k] && (f_id == -1 || s[k] - sum + w[k] > s[f_id] - sum + w[f_id]))
					f_id = k;
			}
			if (f_id == -1) {
				flag = 1;
				break;
			}
			res = min (res, s[f_id] - sum + w[f_id]);
			u[f_id] = 0;
		}
		if (!flag)
			ans = max (ans, res);
	}
	
	if (ans == -1)
		cout << "Mark is too tall\n";
	else
		cout << ans << "\n";
	
	return 0;
}