#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 100;

inline bool bit (const int &mask, const int &pos) {
	return (mask >> pos) & 1;	
}

int t[31 * N][2], ens[31 * N];
int sz;
int a[N], n;

inline void add (const int &x, const int &id) {
	int now = 0;
	for (int i = 29; i >= 0; --i) {
		if (!t[now][bit (x, i)])
			t[now][bit (x, i)] = ++sz;
		now = t[now][bit (x, i)];
	}
	ens[now] = id;
}

inline pair <int, int> check (const int &x) {
	int now = 0, res = 0;
	for (int i = 29; i >= 0; --i) {
		if (!t[now][bit (x, i)]) {
			now = t[now][!bit (x, i)];
			res ^= (1 << i);
		} else {
			now = t[now][bit (x, i)];
		}
	}
	return make_pair (res, ens[now]);
}

int main () {

	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	add (a[1], 1);
	
	int ans1 = INT_MAX, ans2 = 0, ans3 = 0;
	
	for (int i = 2; i <= n; ++i) {
		auto it = check (a[i]);
		if (it.first < ans1) {
			ans2 = it.second;
			ans3 = i;
			ans1 = it.first;
		}
		add (a[i], i);
	}
	
	cout << ans2 << " " << ans3 << "\n";
	
	return 0;
}