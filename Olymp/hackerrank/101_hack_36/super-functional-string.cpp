/// Forever

#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1);
  
const int oo = 1e9, bpr = 1e9 + 7, N = 1e5 + 300;

#define mp make_pair

inline void build_array (string s, int p[], int lcp[], int n) {
	int c[n + 300], pn[n + 300], cnt[n + 300], cn[n + 300];
	memset (c, 0, sizeof (c));
	memset (pn, 0, sizeof (pn));
	memset (cnt, 0, sizeof (cnt));
	memset (cn, 0, sizeof (cn));
	for (int i = 0; i < n; ++i)
		p[i] = lcp[i] = 0;
	for(int i = 0; i < (int)n; ++i) {
		++cnt[(int)s[i]];
	}
	for(int i = 1; i < 256; ++i)
		cnt[i] += cnt[i-1];
	for(int i = 0; i < (int)n; ++i)
		p[--cnt[(int)s[i]]] = i;
	c[0] = 0;
	for(int i = 1; i < (int)n; ++i)
		if(s[p[i]] != s[p[i-1]])
			c[p[i]] = c[p[i-1]]+1;
		else
			c[p[i]] = c[p[i-1]];
	for(int k = 0; (1 << k) < (int)n; ++k) {
		for(int i = 0; i < (int)n; ++i)
			pn[i] = (p[i]-(1 << k)+(int)n)%n;
		
		for(int i = 0; i < (int)n; ++i)
			cnt[i] = 0;
		for(int i = 0; i < (int)n; ++i)
			++cnt[c[pn[i]]];
		for(int i = 1; i < (int)n; ++i)
			cnt[i] += cnt[i-1];
		for(int i = n-1; i >= 0; --i)
			p[--cnt[c[pn[i]]]] = pn[i];
		cn[p[0]] = 0;
		for(int i = 1; i < (int)n; ++i) {
			int x = p[i], y = p[i-1], k1 = 1 << k;
			if(c[x] != c[y] || c[(x+k1)%(int)n] != c[(y+k1)%(int)n])
				cn[p[i]] = cn[p[i-1]]+1;
			else
				cn[p[i]] = cn[p[i-1]];
		}
		for(int i = 0; i < (int)n; ++i)
			c[i] = cn[i];
	}
	int p2[n + 300];
	memset (p2, 0, sizeof (p2));
	for (int i = 0; i < n; ++i)
		p2[p[i]] = i;
	for (int i = 0, k = 0; i < n; ++i) {
		int pos = p2[i];
		if (pos == 0) {
			k = 0;
			lcp[i] = 0;
			continue;
		}
		k = max (0, k - 1);
		int j = p[pos - 1];
		while (i + k < n && j + k < n && s[i + k] == s[j + k])	++k;
		lcp[i] = k;
	}
}

int p[N], lcp[N]; 

inline ll nn (int x) {
	return x * 1ll * (x + 1) / 2;
}

int nxt[N][26], lst[26];
string s;

inline void add (int &x, int y) {
	x += y;
	if (x >= bpr)
		x -= bpr;
	x += bpr;
	if (x >= bpr)
		x -= bpr;
}

inline int bin_pow (int x, int y) {
	if (!y)
		return 1;
	if (y & 1)
		return bin_pow (x, y - 1) * 1ll * x % bpr;
	int c = bin_pow (x, y / 2);
	return c * 1ll * c % bpr;
}

int sum[30][N];

inline int calc (int l, int r) {
	//cerr << l << " " << r << ":\n";
	if (l > r)
		return 0;
	set <int> Set;
	for (int i = 0; i < 26; ++i)
		Set.insert (nxt[l][i]);
	Set.insert (N);
	int res = 0;
	for (int lst = l - 1, k = 0; Set.size (); ++k) {
		int ps = *Set.begin ();
		Set.erase (Set.begin ());
		ps = min (ps, r + 1);
		int tmp = sum[k][((ps - 1) - l + 1)];
		add (tmp, -sum[k][lst - l + 1]);
		//cerr << lst << " " << ps << " " << tmp << "\n";
		if (k != 0)
			add (res, tmp);
		lst = ps - 1;
	}
	return res;
}

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	
	for (int i = 0; i < 30; ++i)
		for (int j = 1; j < N; ++j)
			sum[i][j] = (sum[i][j - 1] + bin_pow (j, i)) % bpr;
	
	int t;

	cin >> t;

	while (t--) {
		cin >> s;    
		s += '#';
		for (int i = 0; i < 26; ++i)
			lst[i] = s.size () - 1;
		for (int i = s.size () - 2; i >= 0; --i) {
			lst[s[i] - 'a'] = i;
			for (int j = 0; j < 26; ++j)
				nxt[i][j] = lst[j];
		}
		build_array (s, p, lcp, s.size ());
		int ans = 0;
		//cerr << "ADD ";
		add (ans, calc (p[1], s.size () - 2));
		for (int i = 2; i < s.size (); ++i) {
			int x = p[i];
			//cerr << "ADD ";
			add (ans, calc (x, s.size () - 2));
			//cerr << "SUBSTRACT ";
			add (ans, -calc (x, x + lcp[x] - 1));
		}
		cout << ans << "\n";
	}
	
	return 0;
}
