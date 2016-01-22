#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 100, sz = 1 << 18;

struct node {
	int pref, suff, upd;
	int cnt[10][10];
	node () {
		pref = suff = upd = -1;
		memset (cnt, 0, sizeof (cnt));
	}
	node (node x, node y) {
		pref = x.pref;
		suff = y.suff;
		upd = -1;
		for (int i = 0; i < 10; ++i)
			for (int j = 0; j < 10; ++j)
				cnt[i][j] = x.cnt[i][j] + y.cnt[i][j];
		cnt[y.pref][x.suff] += 1;
	}
};

node t[N * 4];
char a[N];

inline void push (int v, int Tl, int Tr) {
	if (t[v].upd == -1)
		return;
	if (Tr != Tl) {
		t[v + v].pref = t[v + v].suff = t[v + v + 1].pref = t[v + v + 1].suff = t[v].upd;
		t[v + v].upd = t[v + v + 1].upd = t[v].upd;
		memset (t[v + v].cnt, 0, sizeof (t[v + v].cnt));
		memset (t[v + v + 1].cnt, 0, sizeof (t[v + v + 1].cnt));
		t[v + v].cnt[t[v].upd][t[v].upd] = (Tl + Tr) / 2 - Tl;
   		t[v + v + 1].cnt[t[v].upd][t[v].upd] = Tr - Tl - ((Tl + Tr) / 2 - Tl + 1);
		t[v] = node (t[v + v], t[v + v + 1]);
	} else {
		t[v].pref = t[v].suff = t[v].upd;
		memset (t[v].cnt, 0, sizeof (t[v].cnt));
	}
	t[v].upd = -1;
}

inline void upd (int v, int Tl, int Tr, int l, int r, int val) {
	if (Tl > r || Tr < l)
		return;
	push (v, Tl, Tr);
	if (l <= Tl && Tr <= r) {
		t[v].upd = val;
		push (v, Tl, Tr);
		return;
	}
	int mid = (Tl + Tr) >> 1;
	upd (v + v, Tl, mid, l, r, val);
	upd (v + v + 1, mid + 1, Tr, l, r, val);
	t[v] = node (t[v + v], t[v + v + 1]);
}

inline void calc (int v, int Tl, int Tr) {
	if (Tl == Tr) {
		t[v] = node ();
		t[v].suff = t[v].pref = a[Tl];
		return;
	}
	int mid = (Tl + Tr) >> 1;
	calc (v + v, Tl, mid);
	calc (v + v + 1, mid + 1, Tr);
	t[v] = node (t[v + v], t[v + v + 1]);
}

int pos[26];

int main () {
    
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	
	ios_base :: sync_with_stdio (0);
	cin.tie (0), cout.tie (0);

	int n, m, k;
	
	cin >> n >> m >> k;
	
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] -= 'a';
	}
	
	calc (1, 1, n);
	
	while (m--) {
		int q_type;
		cin >> q_type;
		if (q_type == 1) {
			int l, r;
			char c;
			cin >> l >> r >> c;
			c -= 'a';
			upd (1, 1, n, l, r, c);
		} else {
			for (int j = 1; j <= k; ++j) {
				char x;
				cin >> x;
				pos[x - 'a'] = j;
			}
			int ans = 1;
			push (1, 1, n);
			for (int i = 0; i < k; ++i) {
				for (int j = i; j < k; ++j) {
					if (pos[i] <= pos[j])
						ans += t[1].cnt[i][j];
					else
						ans += t[1].cnt[j][i];
				}
			}
			cout << ans << "\n";
		}
	}
	
	return 0;
}