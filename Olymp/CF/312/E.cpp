#include <bits/stdc++.h>

using namespace std;

const int BL_SZ = 350, N = 1e5 + 100, oo = 1e9;

int cnt[BL_SZ][27];
int s_type[BL_SZ];
int tmp_cnt[27];
int b_st[BL_SZ], b_end[BL_SZ];
string s;
int block;
int b[N];

inline void nxt (int &x, const int &type) {
	while (!tmp_cnt[x]) {
		if (type == 0)
			++x;
		else
			--x;
	}
}


inline void push (const int &b_num) {
	if (s_type[b_num] == -1)
		return;
	memset (tmp_cnt, 0, sizeof (tmp_cnt));
	for (int i = 0; i < 26; ++i)
		tmp_cnt[i] = cnt[b_num][i];
	int it;
	if (s_type[b_num] == 0)
		it = 0;
	else
		it = 'z' - 'a';
	for (int i = b_st[b_num]; i <= b_end[b_num]; ++i) {
		nxt (it, s_type[b_num]);
		s[i] = 'a' + it;
		--tmp_cnt[it];
	}
	s_type[b_num] = -1;
}

inline void upd (const int &l, const int &r, const int &type) {
	push (b[l]);
	push (b[r]);
	if (b[l] == b[r]) {
		sort (s.begin () + l, s.begin () + r + 1);
		if (type == 1)
			reverse (s.begin () + l, s.begin () + r + 1);
		return;
	}
	memset (tmp_cnt, 0, sizeof (tmp_cnt));
	int i = l;
	for (; b[i] == b[l]; ++i) {
		++tmp_cnt[s[i] - 'a'];
		--cnt[b[i]][s[i] - 'a'];
	}
	for (; b[i] != b[r]; i += block) {
		for (int j = 0; j < 26; ++j) {
			tmp_cnt[j] += cnt[b[i]][j];
			cnt[b[i]][j] = 0;
		}
	}
	for (; i <= r; ++i) {
		++tmp_cnt[s[i] - 'a'];
		--cnt[b[i]][s[i] - 'a'];
	}
	int it = 0;
	if (type == 0)
		it = 0;
	else
		it = 'z' - 'a';
	i = l;
	for (; b[i] == b[l]; ++i) {
		nxt (it, type);
		s[i] = 'a' + it;
		++cnt[b[i]][it];
		--tmp_cnt[it];
	}
	for (; b[i] != b[r]; i += block) {
		int need = block;
		while (need) {
			nxt (it, type);
			int add = min (need, tmp_cnt[it]);
			cnt[b[i]][it] += add;
			tmp_cnt[it] -= add;
			need -= add;
		}
		s_type[b[i]] = type;
	}
	for (; i <= r; ++i) {
		nxt (it, type);
		s[i] = 'a' + it;
		++cnt[b[i]][it];
		--tmp_cnt[it];
	}
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n, q;
	
	cin >> n >> q;

	cin >> s;

	s = '#' + s;

	block = sqrt (n) + 1;

	for (int i = 1; i <= n; ++i)
		b[i] = i / block + 1;
	
	for (int i = 1; i < BL_SZ; ++i)
		b_st[i] = oo, b_end[i] = 0;

	for (int i = 1; i <= n; ++i) {
		b_st[b[i]] = min (b_st[b[i]], i);
		b_end[b[i]] = max (b_end[b[i]], i);
	}

	for (int i = 1; i <= n; ++i)
		++cnt[b[i]][s[i] - 'a'];
	
	memset (s_type, -1, sizeof (s_type));
	
	while (q--) {
		int l, r, q_type;
		cin >> l >> r >> q_type;
		q_type ^= 1;
		upd (l, r, q_type);
	}
	
	for (int i = 1; i <= n; ++i)
		push (b[i]);
	
	for (int i = 1; i <= n; ++i)
		cout << s[i];

	return 0;
}