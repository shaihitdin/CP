/// izizi

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
  
const int oo = 1e9, bpr = 1e9 + 7, N = 2e5 + 100;

#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

set <int> Set;
ll ans, val;
int b[N];
int n;
int a[N];
vector <int> g[N];
int pref[N], suff[N];

inline int Find (int x) {
	auto it = Set.upper_bound (x);
	--it;
	return *it;
}

inline void add (int suffpos, int x) {
	/*
	auto it = Set.lower_bound (suffpos);
	int pss = *it;
	if (b[pss] > x)
		return;
	val -= b[pss] * 1ll * (pss - Find (suffpos - 1));
	while (1) {
		int ps = Find (suffpos);
		if (b[ps] < x) {
			int y = Find (ps - 1);
			val -= (ps - y) * 1ll * b[ps];
			Set.erase (ps);
		} else
			break;
	}
	val += b[pss] * 1ll * (pss - suffpos);
	b[suffpos] = x;
	val += b[suffpos] * 1ll * (suffpos - Find (suffpos - 1));
	*/
	for (int i = suffpos; i; --i)
		b[i] = max (b[i], x);
	val = 0;
	for (int i = 1; i <= n; ++i)
		val += b[i];
}

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	
	for (int i = 1; i < N; ++i)
		for (int j = i; j < N; j += i)
			g[j].eb (i);
	
	for (int i = 0; i < N; ++i)
		pref[i] = n + 1;
	
	for (int i = 1; i <= n; ++i) {
		for (auto x : g[a[i]]) {
			suff[x] = max (i, suff[x]);
			pref[x] = min (pref[x], i);
		}
	}
	
	b[1] = oo;
	Set.insert (1);
	Set.insert (n + 1);

	for (int i = 1; i <= n; ++i) {
		for (auto x : g[a[i]]) {
			if (pref[x] < i)
				add (n, x);
			if (suff[x] > i + 1)
				add (suff[x], x);
		}
		b[i] = oo;
		add (i + 1, oo);
		ans += val;
		ans -= oo * 1ll * (i + 1);
	}
	
	cout << ans;
	
	return 0;
}