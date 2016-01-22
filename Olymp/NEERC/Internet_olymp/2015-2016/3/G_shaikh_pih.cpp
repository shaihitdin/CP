#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 100;

typedef long long ll;

inline void fmax (int &x, const int &y) {
	if (x < y)
		x = y;
}

int main () {

	freopen ("maxxor.in", "r", stdin);
	freopen ("maxxor.out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n;

	register int a[N / 10], d[N / 10];
	register int f[N];
	int st[N / 10], sz, l[N / 10], r[N / 10];

	memset (f, 0, sizeof (f));
	
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
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
		int s[6];
		s[0] = s[1] = s[2] = s[3] = s[4] = s[5] = 0;
		int z;
		for (int l_ = l[i]; l_ <= i; ++l_) {
			z = d[l_ - 1];
			for (int r_ = i; r_ + 5 <= r[i]; r_ += 6) {
				fmax (s[0], d[r_] ^ z);
				fmax (s[1], d[r_ + 1] ^ z);
				fmax (s[2], d[r_ + 2] ^ z);
				fmax (s[3], d[r_ + 3] ^ z);
				fmax (s[4], d[r_ + 4] ^ z);
				fmax (s[5], d[r_ + 5] ^ z);
			}
			for (int r_ = max (r[i] - 5, i); r_ <= r[i]; ++r_)
				fmax (s[0], d[r_] ^ d[z]);
		}
		fmax (s[0], s[1]);
		fmax (s[0], s[2]);
		fmax (s[0], s[3]);
		fmax (s[0], s[4]);
		fmax (s[0], s[5]);
		fmax (f[a[i]], s[0]);
	}
	
	ll ans = 0;
	
	for (int i = 1; i < N; ++i)
		fmax (ans, f[i] * 1ll * i);
	
	cout << ans;

	//cerr << clock () * 1000 / CLOCKS_PER_SEC;
	
	return 0;
}