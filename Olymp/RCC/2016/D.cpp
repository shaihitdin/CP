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
  
const int oo = 1e9, bpr = 1e9 + 7, N = 5e5 + 100;

#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

int a[N], n, m;

int d[N];

ll ans[N];

vector <int> g[N];

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		++d[a[i]];
	}	
	
	for (int i = 1; i < N; ++i)
		d[i] += d[i - 1];
	
	for (int i = 1; i < N; ++i) {
		for (int k = 1;;++k) {
			int l = (k - 1) * i + 1, r = k * i;
			r = min (r, N - 1);
			ans[i] += (d[r] - d[l - 1]) * 1ll * k;
			if (r == N - 1)
				break;
		}
	}

	for (int i = 1; i < N; ++i)
		for (int j = i; j < N; j += i)
			g[j].eb (i);
	
	while (m--) {
		int q_type;
		cin >> q_type;
		if (q_type == 1) {
			int ps;
			cin >> ps;
			for (auto dudu : g[a[ps]])
				++ans[dudu];
			++a[ps];
		} else if (q_type == 2) {
			int ps;
			cin >> ps;
			--a[ps];
			for (auto dudu : g[a[ps]])
				--ans[dudu];
		} else {
			int x;
			cin >> x;
			cout << ans[x] << "\n";
		}
	}	
	
	return 0;
}
