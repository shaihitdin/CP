#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int ans;
int n, m;
bool s[N];

inline int calc () {
	ans = 0;
	for (int i = 0; i < n; ++i) {
		int l_side = i + (n / 2);
		int r_side = i + ((n + 1) / 2);
		if (l_side == r_side)
			l_side += n - 1, ++r_side;
		l_side %= n, r_side %= n;
		while (l_side != i && r_side != i) {
			if (s[i] == s[l_side] && s[l_side] == s[r_side])
				++ans;
			--l_side;
			++r_side;
			if (l_side == -1)
				l_side = n - 1;
			if (r_side == n)
				r_side = 0;
		}
	}
	if (n % 3 == 0) {
		int cnt2 = 0;
		for (int i = 0; i < n; ++i) {
			int j = i + (n / 3);
			j %= n;
			int k = j + (n / 3);
			k %= n;
			if (s[i] == s[j] && s[j] == s[k])
				++cnt2;
		}
		cnt2 /= 3;
		ans -= cnt2 * 2;
		//cerr << cnt2 << " ";
	}
}

int main () {

	freopen ("triangles.in", "r", stdin);
	freopen ("triangles.out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		char x;
		cin >> x;
		s[i] = (x == 'W');
	}

	for (int i = 1; i <= m; ++i) {
		int x;
		cin >> x;
		--x;
		s[x] ^= 1;
		calc ();
		cout << ans << "\n";
	}	

	
	return 0;
}