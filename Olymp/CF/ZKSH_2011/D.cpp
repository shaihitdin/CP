#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

int q_type[N], num[N];

int ans[N];
int b, f;
int n;
int l[N], r[N];
bool invalid[N];

inline bool is_used (const int &till, const int &nl, const int &nr) {
	for (int i = 1; i < till; ++i) {
		if (q_type[i] == 2)
			continue;
		if (invalid[i])
			continue;
		if (((nl <= l[i] && l[i] <= nr) || (nl <= r[i] && r[i] <= nr)) || ((l[i] <= nl && nl <= r[i]) || (l[i] <= nr && nr <= r[i])))
			return 1;
		if (nr < l[i]) {
			if (l[i] - nr < f) {
				return 1;
			}
		}
		else {
			if (nl - r[i] < b) {
				return 1;
			}
		}
	} 
	return 0;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> b >> f;

	int q;

	cin >> q;
	
	for (int it = 1; it <= q; ++it) {
		cin >> q_type[it] >> num[it];
		if (q_type[it] == 1) {
			ans[it] = -1;
			for (int i = 0; i + num[it] <= n; ++i) {
				if (!is_used (it, i, i + num[it])) {
					l[it] = i;
					r[it] = i + num[it];
					ans[it] = i;
					break;
				}
			}
			if (ans[it] == -1)
				invalid[it] = 1;
			cout << ans[it] << "\n";
		} else {
			invalid[num[it]] = 1;
		}
	}
	
	
	return 0;
}