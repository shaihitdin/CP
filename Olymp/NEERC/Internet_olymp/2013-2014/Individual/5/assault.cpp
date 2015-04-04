#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <ll, ll> PLL;

const int N = 1e5 + 10, sz = (1 << 17);

ll t[sz * 8], t1[sz * 8];

ll n, a[N], d[N], p[N], ti[N];

inline void upd (int x, const ll &to, const ll &pos) {
	x += sz;
	if (to > t[x]) {
		t[x] = to;
		t1[x] = pos;
	}
	for (x >>= 1; x; x >>= 1) {	
		if (t[x << 1] > t[(x << 1) + 1]) {
			t[x] = t[x << 1];
			t1[x] = t1[x << 1];
		}
		else {
			t[x] = t[(x << 1) + 1];
			t1[x] = t1[(x << 1) + 1];
		}
	}
}

inline PLL get (int l, int r) {
	ll res = 0, res1 = 0;
	for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
		if (l & 1) {
			if (res < t[l]) {
				res1 = t1[l];
				res = t[l];
			}
			++l;
		}
		if (!(r & 1)) {
			if (res < t[r]) {
				res1 = t1[r];
				res = t[r];
			}
			--r;
		}
		if (l > r)
			break; 
	}
	return make_pair (res, res1);
}

int main () {

	freopen ("assault.in", "r", stdin);
	freopen ("assault.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		cin >> ti[i];

	for (int i = 1; i <= n; ++i) {
		auto temp = get (0, ti[i] - 1);		
		d[i] = temp.first + a[i];
		p[i] = temp.second;
		upd (ti[i], d[i], i);
	}
	long long anspos = 0, ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (ans < d[i]) {
			ans = d[i];
			anspos = i;
		}
	}
	vector <int> ansv;
	while (anspos) {
		ansv.push_back (anspos);
		anspos = p[anspos];
	}
	cout << ans << "\n" << ansv.size() << "\n";
	reverse (ansv.begin(), ansv.end());
	for (int it : ansv)
		cout << it << " ";
	return 0;
}