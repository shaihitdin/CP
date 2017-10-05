


const int sz = (1 << 20);
int t[sz + sz + 100];

inline void upd (int x, int val) {
	t[x += sz] = val;
	while (x >>= 1)
		t[x] = min (t[x << 1], t[(x << 1) | 1]);
}

inline int get (int l, int r) {
	int res = 1e9;
	for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
		if (l & 1)
			res = min (res, t[l++]);
		if (!(r & 1))
				res = min (res, t[r--]);
		if (l > r)
			break;
	}
	return res;
}