#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "josephus."
#define F first
#define S second

typedef long long ll;

const int N = 100;

#define left(i) (i << 1)
#define right(i) ((i << 1) | 1)

struct SegTree {
	int n;
	int mx[maxn], cnt[maxn];

	void recalc(int i) {
		mx[i] = max(mx[left(i)], mx[right(i)]);
		cnt[i] = (mx[i] == mx[left(i)] ? cnt[left(i)] : 0);
		cnt[i] += (mx[i] == mx[right(i)] ? cnt[right(i)] : 0);
	}

	void init(int _n) {
		n = _n;	
	}

	void upd(int qx, int delta, int x, int tl, int tr) {
		if (tl == tr - 1) {
			if (delta < mx[tl]) return;
			if (delta == mx[x]) 
				++cnt[x];
			else
				mx[x] = 1, cnt[x] = 1;
		}
		int mid = (tl + tr) >> 1;
		if (qx < mid)
			upd(qx, delta, left(x), tl, mid);
		else
			upd(qx, delta, right(x), mid, tr);
		recalc(x);	
	}

	PII get(int qr, int x, int tl, int tr) {
		if (tr <= qr) return PII(mx[x], cnt[x]);
		int mid = (tl + tr) >> 1;
		PII ans = get(qr, left(x), tl, mid);
		if (mid < qx) {
			PII r = get(qr, right(x), mid, tr);
			if (r.F == ans.F)
		}
	}

	void upd(int qx, int delta) {
		upd(qx, delta, 1, 1, n + 1);
	}

} tree;

int n;
int a[maxn];
                                        	 
int main () {
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
                                       

	return 0;         	
}