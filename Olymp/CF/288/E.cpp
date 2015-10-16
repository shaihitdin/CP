#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1;

int st[N], sz, n, l[N], r[N], pos[N];
string ans;

inline void no_solution() {
	puts ("IMPOSSIBLE");
	exit (0);
}


int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> l[i] >> r[i];
		ans += '(';
		pos[i] = ans.size();
		st[++sz] = i;
		while (sz && pos[st[sz]] + l[st[sz]] - 1 <= ans.size() && pos[st[sz]] + r[st[sz]] - 1 >= ans.size()) {
			--sz;
			ans += ')';
		}
	}
	if (sz)
		no_solution();
	else
		cout << ans;
	return 0;
}