#include <bits/stdc++.h>

using namespace std;

const int sz = 1 << 18, N = 3e5 + 100, oo = 1e9 + 7;

int t[sz + sz];

vector <int> comp[N];
int rev_comp[N];

inline void upd (int v, const int &deltabek) {
	v += sz;
	t[v] = deltabek;
	while (v >>= 1) {
		if (t[v + v] != t[v + v + 1])
			t[v] = -1;
		else
			t[v] = t[v + v];
	}
}

inline int get_first (const int &v, const int &need) {
	if (v >= sz) {
		assert (t[v] != need);
		return v - sz;
	}
	else if (t[v + v] != need)
		return get_first (v + v, need);
	return get_first (v + v + 1, need);
}


inline int get (int l, int r) {
	l += sz, r += sz;
	int ee = t[l];
	int ee_r = -1;
	for (; l <= r; l >>= 1, r >>= 1) {
		if (l & 1) {
			if (t[l] != ee) {
				return get_first (l, ee);
			}
			++l;
		}
		if (!(r & 1)) {
			if (t[r] != ee) {
				ee_r = r;
			}
			--r;
		}
		if (l > r)
			break;
	}
	if (ee_r == -1)
		return -1;
	return get_first (ee_r, ee);
}

inline void Merge (int a, int b) {
	if (a == b)
		return;
	if (comp[a].size () < comp[b].size ())
		swap (a, b);
	for (auto it : comp[b]) {
		rev_comp[it] = a;
		comp[a].emplace_back (it);
		upd (it, a);
	}
	comp[b].clear ();
}

int main () {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int n, q;
	
	scanf ("%d%d", &n, &q);

	for (int i = 1; i <= n; ++i) {
		upd (i, i);
		comp[i].push_back (i);
		rev_comp[i] = i;
	}

	while (q--) {
		int q_type, x, y;
		scanf ("%d%d%d", &q_type, &x, &y);
		if (q_type == 1) {
			Merge (rev_comp[x], rev_comp[y]);
		} else if (q_type == 2) {
			while (1) {
				int temp = get (x, y);
				if (temp == -1)
					break;
				Merge (rev_comp[x], rev_comp[temp]);
			}
		} else {
			if (rev_comp[x] == rev_comp[y])
				puts ("YES");
			else
				puts ("NO");
		}
	}

	return 0;
}