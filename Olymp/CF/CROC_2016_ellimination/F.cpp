#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 100, bpr = 1e9 + 7;

#define pb push_back

int cnt[N];
int n, k, q;
int ans;
int f[N], frev[N];
int phi[N];

vector <int> di[N];

inline int bin_pow (int x, int y) {
	if (!y)
		return 1;
	if (y & 1)
		return (bin_pow (x, y - 1) * 1ll * x) % bpr;
	int c = bin_pow (x, y / 2);
	return (c * 1ll * c) % bpr;
}

inline void add (int &x, int y) {
	x += y;
	if (x >= bpr)
		x -= bpr;
	x += bpr;
	if (x >= bpr)
		x -= bpr;
}

inline int calc (int n, int k) {
	if (k > n)
		return 0;
	int val = f[n];
	val = (val * 1ll * frev[k]) % bpr;
	val = (val * 1ll * frev[n - k]) % bpr;
	return val;
}

void add(int x) {
	/*
	vector<int> p;
	int t = x;
	while (t > 1) {
		int val = di[t][1];
		while (t % val == 0)
			t /= val;
		p.pb (val);
	}
	*/
	int delta = 0;
	for (auto d : di[x]) {
		/*
		int cc = 0;
		for (int mask = 0; mask < (1 << p.size()); mask++) {
			int dudu = d;
			for (int i = 0; i < p.size(); i++) {
				if ((mask >> i) & 1) dudu *= p[i];
			}
			if (x % dudu != 0) continue;
			if (__builtin_popcount(mask) & 1)
				add (cc, -calc(cnt[dudu], k - 1));
			else
				add (cc, calc(cnt[dudu], k - 1));
		}
		//cerr << d << " => " << cc << endl;		
		add (delta, cc * 1ll * d % bpr);
		*/
		int cc = calc (cnt[d], k - 1);
		add (delta, (cc * 1ll * phi[d]) % bpr);
	}
	for (auto d : di[x])
		cnt[d]++;
	add (ans, delta);
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);

	cin >> n >> k >> q;
	
	for (int i = 1; i < N; ++i)
		for (int j = i; j < N; j += i)
			di[j].emplace_back (i);
	                    	
	f[0] = 1;
	for (int i = 1; i < N; ++i)
		f[i] = (f[i - 1] * 1ll * i) % bpr;
	frev[N - 1] = bin_pow (f[N - 1], bpr - 2);
	for (int i = N - 2; i >= 0; --i)
		frev[i] = (frev[i + 1] * 1ll * (i + 1)) % bpr;
	
	phi[1] = 1;

	for (int i = 2; i < N; ++i) {
		if (i % (di[i][1] * 1ll * di[i][1]) == 0)
			phi[i] = phi[i / di[i][1]] * di[i][1];
		else
			phi[i] = phi[i / di[i][1]] * (di[i][1] - 1);
	}
	
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		add (x);
	}

	//cerr << ans << "\n";
	
	for (int i = 1; i <= q; ++i) {
		int x;
		cin >> x;
		add (x);
		cout << ans << "\n";
	}
	
	return 0;
}