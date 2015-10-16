#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 100;

typedef long long ll;

int m, h[3], a[3], x[3], y[3], size[3];
int cnt[3][N];

inline ll gcd (const ll &x, const ll &y) {
	return y ? gcd (y, x % y) : x;
}

int main () {
    #ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> m;

	for (int i = 1; i <= 2; ++i)
		cin >> h[i] >> a[i] >> x[i] >> y[i];
	
	memset (cnt, -1, sizeof (cnt));
	
	
	for (int i = 1; i <= 2; ++i) {
		int num = 0;
		for (int j = h[i]; cnt[i][j] == -1; j = (j * 1ll * x[i] + y[i]) % m, ++num)
			cnt[i][j] = num;
		size[i] = num;
	}

	if (cnt[1][a[1]] == -1 || cnt[2][a[2]] == -1) {
		cout << "-1";
		return 0;
	}

	ll res1 = (size[1] * 1ll * size[2] / gcd (size[1], size[2]));
	
	cout << size[1] * 1ll * res1 + cnt[1][a[1]];

	return 0;
}