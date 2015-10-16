#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 100;

typedef long long ll;

int a[N];
vector <int> v[N / 2];
bool u[N];
int cnt[N];

inline void upd (const int &el, const int &pos, const int &res, const int &type) {
	if (pos == v[el].size ()) {
		if (type == -1)
			--cnt[res];
		else
			++cnt[res];
		return;
	}
	upd (el, pos + 1, res * v[el][pos], type);
	upd (el, pos + 1, res, type);
}

inline ll get_cnt (const int &el, const int &pos, const int &res, const int &type) {
	if (pos == v[el].size ())
		return type * cnt[res];
	return get_cnt (el, pos + 1, res * v[el][pos], type * -1) + get_cnt (el, pos + 1, res, type);
}

int n, q;

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	scanf ("%d%d", &n, &q);

	for (int i = 1; i <= n; ++i)
		scanf ("%d", &a[i]);

	for (int i = 1; i <= n; ++i) {
		int j = a[i];
		if (j % 2 == 0) {
			while (j % 2 == 0)
				j /= 2;
			v[i].push_back (2);
		}
		for (int k = 3; k * k <= j; k += 2) {
			if (j % k == 0) {
				while (j % k == 0)
					j /= k;
				v[i].push_back (k);
			}
		}
		if (j > 1)
			v[i].push_back (j);
	}

	int t_num = 0;
	ll ans = 0;

	while (q--) {
		int x;
		scanf ("%d", &x);
		if (u[x]) {
			upd (x, 0, 1, -1);
			ans -= get_cnt (x, 0, 1, -1);
			u[x] = 0;
			--t_num;
		} else {
			ans += get_cnt (x, 0, 1, -1);
			upd (x, 0, 1, 1);
			u[x] = 1;
			++t_num;
		}

		printf ("%I64d\n", -ans);
	}
	
	return 0;
}