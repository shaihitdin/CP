/**
	Oh, my dear
**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 110;

int a[N], c[N];
bool col[N];
ll cnt[2];
ll sum[2];

inline ld get_p_i (int i) {
	return sum[i] / (cnt[i] * ld (1));
}

int main () {
	#ifdef BROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int n, l;

	cin >> n >> l;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
	}
	for (int i = 1; i <= l; ++i)
		col[i] = 0, cnt[0] += a[i], sum[0] += c[i];
	for (int i = l + 1; i <= n; ++i)
		col[i] = 1, cnt[1] += a[i], sum[1] += c[i];
	while (1) {
		ld new_val = get_p_i (0) * get_p_i (1);
		int id[2];
		id[0] = id[1] = -1;
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				if (col[i] == col[j])
					continue;
				sum[col[i]] -= c[i];
				sum[col[j]] -= c[j];
				cnt[col[i]] -= a[i];
				cnt[col[j]] -= a[j];

				sum[col[i] ^ 1] += c[i];
				sum[col[j] ^ 1] += c[j];
				cnt[col[i] ^ 1] += a[i];
				cnt[col[j] ^ 1] += a[j];			

				if (get_p_i (0) * get_p_i (1) < new_val) {
					id[col[i]] = i;
					id[col[j]] = j;
				}
				
				sum[col[i] ^ 1] -= c[i];
				sum[col[j] ^ 1] -= c[j];
				cnt[col[i] ^ 1] -= a[i];
				cnt[col[j] ^ 1] -= a[j];

				sum[col[i]] += c[i];
				sum[col[j]] += c[j];
				cnt[col[i]] += a[i];
				cnt[col[j]] += a[j];			
			}
		}
		if (id[0] != -1) {
			sum[0] -= c[id[0]];
			sum[1] -= c[id[1]];
			cnt[0] -= a[id[0]];
			cnt[1] -= a[id[1]];

			sum[1] += c[id[0]];
			sum[0] += c[id[1]];
			cnt[1] += a[id[0]];
			cnt[0] += a[id[1]];

			col[id[0]] = 1;
			col[id[1]] = 0;
		} else {
			break;
		}
	}
	
	cout << fixed;
	cout << setprecision (3);
	cout << get_p_i (0) * get_p_i (1);

	return 0;
}