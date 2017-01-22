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
  
const int oo = 1e9, bpr = 1e9 + 7, N = 5e5 + 100, sz = 1 << 19;

#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

int n, m, p;
char a[N];
int nxt[N], pre[N];

inline void upd (int x) {
	int val1 = pre[x], val2 = nxt[x];
	nxt[val1] = val2;
	pre[val2] = val1;
}

inline int find_next (int x) {
	return nxt[x];
}

inline int find_prev (int x) {
	return pre[x];
}

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	cin >> n >> m >> p;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	nxt[0] = 1;
	for (int i = 1; i <= n; ++i)
		nxt[i] = i + 1, pre[i] = i - 1;
	pre[n + 1] = n;
	while (m--) {
		char q_type;
		cin >> q_type;
		if (q_type == 'L') {
			p = find_prev (p);
		} else if (q_type == 'R') {
			p = find_next (p);
		} else {
			upd (p);
			if (a[p] == '(') {
				int balance = 1;
				p = find_next (p);
				for (; balance != 0; p = find_next (p)) {
					if (a[p] == '(')
						++balance;
					else
						--balance;
					upd (p);
				}
				if (p == n + 1)
					p = find_prev (p);
			} else {
				int balance = -1;
				p = find_prev (p);
				for (; balance != 0; p = find_prev (p)) {
					if (a[p] == '(')
						++balance;
					else
						--balance;
					upd (p);
				}
				p = find_next (p);
				if (p == n + 1)
					p = find_prev (p);
			}
		}
	}
	
	for (int i = nxt[0]; i < n + 1; i = nxt[i]) {
		cout << a[i];
	}
	
	return 0;
}