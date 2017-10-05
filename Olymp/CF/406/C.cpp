/// Stupido del problemo

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
#include <iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1);
  
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

const int oo = 1e9, bpr = 1e9 + 7, N = 1e5 + 100;

int enc[N], nx[N], a[N], n;

struct node {
	int x;
	node *l, *r;
	node () {
		l = r = 0;
		x = 0;
	}
	node (node *Tl, node *Tr) {
		l = Tl;
		r = Tr;
		x = Tl -> x + Tr -> x;
	}
	node (int xx) {
		x = xx;
		l = r = 0;
	}
};

inline node * upd (node *t, int Tl, int Tr, int x, int val) {
	if (Tl > x || Tr < x)
		return t;
	if (Tl == x && Tr == x)
		return new node (val);
	int mid = (Tl + Tr) / 2;
	return new node (upd (t -> l, Tl, mid, x, val), upd (t -> r, mid + 1, Tr, x, val));
}

inline int get_kth (node *t, int Tl, int Tr, int k) {
	if (Tl == Tr && k < t -> x)
		return Tl - 1;
	if (Tl == Tr)
		return Tl;
	int mid = (Tl + Tr) / 2;
	if (t -> l -> x > k)
		return get_kth (t -> l, Tl, mid, k);
	return get_kth (t -> r, mid + 1, Tr, k - (t -> l -> x));
}

inline int get (node *t, int Tl, int Tr, int x) {
	if (Tl > x || Tr < x)
		return 0;
	if (Tl == x && Tr == x)
		return t -> x;
	int mid = (Tl + Tr) / 2;
	return get (t -> l, Tl, mid, x) + get (t -> r, mid + 1, Tr, x);
}

inline node * Build (int Tl, int Tr) {
	if (Tl == Tr)
		return new node ();
	int mid = (Tl + Tr) / 2;
	return new node (Build (Tl, mid), Build (mid + 1, Tr));
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
	
	for (int i = 1; i <= n; ++i)
		enc[i] = n + 1;
	for (int i = n; i >= 1; --i)
		nx[i] = enc[a[i]], enc[a[i]] = i;
	
	node * t[N];

	t[0] = Build (1, n);	
	
	for (int i = 1; i <= n; ++i)
		t[0] = upd (t[0], 1, n, enc[i], 1);
	
	t[1] = t[0];
    
    for (int i = 2; i <= n; ++i) {
    	t[i] = upd (t[i - 1], 1, n, i - 1, 0);
    	t[i] = upd (t[i], 1, n, nx[i - 1], 1);
    }

	for (int i = 1; i <= n; ++i) {
		int ans = 0;
		for (int j = 1; j <= n; ++j, ++ans) {
			j = get_kth (t[j], 1, n, i);
		}
		cout << ans << " ";
	}    
    
    return 0;
}