#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
long long a[N], b[N], c[N], ans1, ans, ans2, s, n;
bool u[N];
inline bool cmp (const int &x, const int &y) {
	return b[x] < b[y];
}

int main () {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);	
	ios_base :: sync_with_stdio (0);
	cin >> n >> s;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i];
		if (i == s) {
			ans += a[i];
			u[i] = 1;
			continue;
		}
		if (a[i] >= b[i]) {
			ans += a[i] - b[i];
			u[i] = 1;
			++ans1;
		}
	}
	ans2 = ans;
	for (int i = 1; i <= n; ++i)
		c[i] = i;
	sort (c + 1, c + n + 1, cmp);
	for (int i = 1; i <= n; ++i)
		if (!u[c[i]] && ans2 >= b[c[i]]) {
			++ans1;
			ans2 -= b[c[i]];
			u[c[i]] = 1;
		}
	cout << ans << " " << ans1;
	return 0;
}