#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned int ui;

using namespace std;

const int N = 51, bpr = 1e9 + 7;


int p[N];

class Autogame {

	public:
	int bin_pow (int base, int p) {
		if (!p)
			return 1;
		if (p & 1)
			return (base * 1ll * bin_pow (base, p - 1)) % bpr;
		int b = bin_pow (base, p >> 1);
		return (b * 1ll * b) % bpr;
	}
	
	public:
	void find_cycle (int finish, int start) {
		int now = 1;
		for (; start != finish; start = p[start])
			++now;
		return now;
	}

	public:
	int dfs (int v) {
		if (p[to[v]])
			return find_cycle (to[v], v);
		p[to[v]] = v;
		return dfs (to[v]);
	}

    public:
    int wayscnt (vector <int> a, int k) {
		int n = a.size ();
		for (int i = 0; i < n; ++i)
			to[i] = a[i];
		int len = dfs (0);
		f[0] = 1;
		for (int i = 1; i < N; ++i)
			f[i] = (f[i - 1] * 1ll * i) % bpr;
		for (int i = 0; i < N; ++i)
			rf[i] = bin_pow (rf[i], bpr - 2);

		int ans = 0;
		
		int can_use = max (0, (n - len) - k);

		for (int i = 0; i <= len; ++i) {
			int now = (f[len] * 1ll * rf[i]) % bpr;
			now = (now * 1ll * rf[len - i]) % bpr;
			
		}

    }

};
