/**
	Mom, I'm on someone's monitor!
**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e6 + 100, bpr = 1e9 + 7;

inline int f (int x) {
	int res = 0;
	while (x) {
		++res;
		x /= 2;
	}
	return res;
}

inline void add (int &x, int y) {
	x += y;
	if (x >= bpr)
		x -= bpr;
}


int dp[77][1 << 20];
vector <pair <int, int> > ke[77];
set <int> ok;
int n;
char s[100];
int ans;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	/*
	int ans = 0;
	for (int i = 1; i <= 20; ++i) {
		cout << i << " " << (ans += f (i)) << "\n";
	}
	*/
	
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		char x;
		cin >> x;
		s[i] = (x == '1');
	}

	for (int i = 1; i <= n; ++i) {
		int res = 0;
		for (int j = i; j <= n; ++j) {
			res <<= 1;
			res |= s[j];
			if (res > 20)
				break;
			if (res > 0)
				ke[i].emplace_back (make_pair (j + 1, (1 << (res - 1))));
		}
	}
	
	for (int i = 2; i <= (1 << 20); i *= 2) {
		ok.insert (i - 1);
	}
		
	for (int i = 1; i <= n + 1; ++i) {
		add (dp[i][0], 1);
		for (int mask = 0; mask < (1 << 20); ++mask) {
			for (auto it : ke[i]) {
				add (dp[it.first][mask | it.second], dp[i][mask]);
			}
		}
		for (auto it : ok)
			add (ans, dp[i][it]);
	}
	
	cout << ans;
	return 0;
}