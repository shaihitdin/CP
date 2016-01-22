#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 100;

typedef long long ll;

int a[N];

int l[N], r[N];
int st[N];
int n;
int len[N];

ll ans;

int main () {

	freopen ("banks.in", "r", stdin);
	freopen ("banks.out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	int sz = 0;

	for (int i = 1; i <= n; ++i) {
		while (sz && a[st[sz]] >= a[i])
			--sz;
		if (sz)
			l[i] = st[sz] + 1;
		else
			l[i] = 1;
		st[++sz] = i;
	}
	
	sz = 0;

	for (int i = n; i >= 1; --i) {
		while (sz && a[st[sz]] >= a[i])
			--sz;
		if (sz)
			r[i] = st[sz] - 1;
		else
			r[i] = n;
		st[++sz] = i;            
	}
	
	for (int i = 1; i <= n; ++i) {
		len[r[i] - l[i] + 1] = max (len[r[i] - l[i] + 1], a[i]);
	}
	
	for (int i = n; i >= 1; --i) {
		len[i] = max (len[i], len[i + 1]);
		ans += len[i];
	}
	
	cout << ans;
	
	return 0;
}