#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct line {
	ll a, b;
};

const int N = 3e5 + 100, sz = 1 << 19;
const ll oo = 1e18;

inline bool operator < (const line &lhs, const line &rhs) {
	if (lhs.a == rhs.a)
		return lhs.b < rhs.b;
	return lhs.a > rhs.a;
}

inline double intersection (const line &x, const line &y) {
	if (x.a == y.a)
		assert (0);
	return (y.b - x.b) /  double (x.a - y.a);
}

map <line, double> t1[sz + sz + 100];
map <double, line> t2[sz + sz + 100];

inline bool del (const line &ahs, const line &lhs, const line &rhs) {
	if (lhs.a == rhs.a) {
		return 1;
	}
	return intersection (ahs, lhs) < intersection (ahs, rhs);
}

inline void insert_line (const int &v, const line &a) {

	if (!t1[v].insert (make_pair (a, -1000000)).second)
		return;

	auto it4 = t1[v].upper_bound (a);
	auto it3 = t1[v].find (a);
	
	if (it4 != t1[v].end ()) {
		if ((*it4).first.a == (*it3).first.a) {
			t2[v].erase ((*it4).second);
			t1[v].erase (it4);
		}
	}
	
	auto it2 = it3;
	
	if (it2 != t1[v].begin ()) {
		--it2;
		if ((*it2).first.a == (*it3).first.a) {
			t1[v].erase (it3);
			return;
		}
	}

	if (it3 != t1[v].begin () && it4 != t1[v].end ()) {
		it2 = it3;
		--it2;
		if (del ((*it2).first, (*it3).first, (*it4).first)) {
			t1[v].erase (it3);
			return;
		}
	}

	
	while (1) {
		it3 = t1[v].find (a);
		it2 = it3;
		if (it3 == t1[v].begin ())
			break;
		--it2;
		auto it1 = it2;
		if (it2 == t1[v].begin ())
			break;
		--it1;
		if (del ((*it1).first, (*it2).first, (*it3).first)) {
			t2[v].erase ((*it2).second);
			t1[v].erase (it2);
		} else {
			break;
		}
	}


	while (1) {
		it3 = t1[v].find (a);
		it4 = it3;
		++it4;
		if (it4 == t1[v].end ())
			break;
		auto it5 = it4;
		++it5;
		if (it5 == t1[v].end ())
			break;
		if (del ((*it3).first, (*it4).first, (*it5).first)) {
			t2[v].erase ((*it4).second);
			t1[v].erase (it4);
		} else {
			break;
		}
	}
	
	it3 = t1[v].find (a);
	it2 = it3;

	if (it3 != t1[v].begin ()) {
		--it2;
		t2[v][intersection ((*it2).first, (*it3).first)] = (*it2).first;
	}	

	it4 = t1[v].find (a);
	it3 = it4;
	if (it3 != t1[v].end ()) {
		++it4;
		t2[v][intersection ((*it3).first, (*it4).first)] = (*it3).first;
	}
}

ll p[N], a[N], h[N], d[N], n;

inline void upd (int v, const line &a) {
	for (v += sz; v; v >>= 1) {
		insert_line (v, a);
	}
}

inline ll get2 (const int &v, const ll &a) {
    if (!t2[v].size ())
		return oo;
	auto it = t2[v].upper_bound (a);
	if (it == t2[v].end () || it == t2[v].begin ())
		return oo;
	--it;
	return a * (*it).second.a + (*it).second.b;
}

inline ll get (int l, int r, const ll &a) {
	ll res = oo;
	for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
		if (l & 1) {
			res = min (res, get2 (l, a));
			++l;
		}
		if (~r & 1) {
			res = min (res, get2 (r, a));
			--r;
		}
		if (l > r)
			break;
	}
	return res;
}


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
	}

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	for (int i = 1; i <= n; ++i) {
		cin >> h[i];
	}
	
	d[1] = a[1];
	
	upd (1, {-2 * h[1], d[1] + h[1] * h[1]});
	
	
	d[1] = a[1];
	
	for (int i = 2; i <= n; ++i) {
		d[i] = get (1, p[i], h[i]) + a[i] + h[i] * h[i];
		upd (p[i], {-2 * h[i], d[i] + h[i] * h[i]});
	}
	
	/// d[i] = (min j < i (d[j] + (h[i] - h[j]) ^ 2)) + a[i] 
	
	/// ==> (min j < i (d[j] + h[i] ^ 2 + h[j] ^ 2 - 2 * h[i] * h[j])) + a[i]

	/// ==> (min j < i (- (2 * h[j] * h[i]) + (d[j] + h[j] ^ 2))) + a[i] + h[i] ^ 2

	/// ==> (min j < i (- (ax) + b)) + a[i] + h[i] ^ 2, where a = -2 * h[j] and b = d[j] + h[j] ^ 2
	
	cout << d[n];
	

	return 0;
}