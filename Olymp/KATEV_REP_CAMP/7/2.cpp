#include <bits/stdc++.h>

using namespace std;

const int N = 2e5;

long long n, a[N], st[N], enq, ans, ans1, ans2, l[N], r[N], d[N];

int main () {
	freopen ("2.in", "r", stdin);
	freopen ("2.out", "w", stdout);

	ios_base :: sync_with_stdio (0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	enq = 0;
	for (int i = 1; i <= n; ++i) {
		while (enq && a[st[enq]] >= a[i])
			--enq;
		if (!enq)
			l[i] = 1;
		else
			l[i] = st[enq] + 1;
		st[++enq] = i;
	}
	enq = 0;
	for (int i = n; i; --i) {
		while (enq && a[st[enq]] >= a[i])
			--enq;
		if (!enq)
			r[i] = n;
		else
			r[i] = st[enq] - 1;
		st[++enq] = i;
	}

	for (int i = 1; i <= n; ++i)
		d[i] = d[i - 1] + a[i];
	
	for (int i = 1; i <= n; ++i) {
		if (ans < (d[r[i]] - d[l[i] - 1]) * a[i]) {
			ans = (d[r[i]] - d[l[i] - 1]) * a[i];
			ans1 = l[i];
			ans2 = r[i];
		}
	}

	cout << ans << "\n" << ans1 << " " << ans2;
	return 0;
}