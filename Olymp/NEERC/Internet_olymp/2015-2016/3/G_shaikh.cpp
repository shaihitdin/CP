#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
		d[i] = d[i - 1] ^ a[i];

	sz = 0;
	
	for (int i = 1; i <= n; ++i) {
		while (sz && a[st[sz]] < a[i])
			--sz;
		if (sz)
			l[i] = st[sz] + 1;
		else
			l[i] = 1;
		st[++sz] = i;
	}
	
	sz = 0;
	
	for (int i = n; i >= 1; --i) {
		while (sz && a[st[sz]] <= a[i])
			--sz;
		if (sz)
			r[i] = st[sz] - 1;
		else
			r[i] = n;
		st[++sz] = i;
	}

	for (int i = 1; i <= n; ++i) {
		int x = a[i];
		
	}

	
	return 0;
}