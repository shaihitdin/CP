#include <bits/stdc++.h>

using namespace std;

struct pt {
	int *x, y;
};

const int N = 5e5 + 100, K = 52;

vector <pt> st;

int p[K][N + N], h[K][N + N];
pair <int, int> e[N];
vector <int> t[4 * N + 100];
int q_col[N], nxt[N], e_num[N], pre[N], done[N], prev_q[N];
int q;

inline int get_p (int k, int v) {
	if (p[k][v] == v)
		return v;
	int x = get_p (k, p[k][v]);
	st.push_back ({&p[k][v], p[k][v]});
	return p[k][v] = x;
}

inline void Merge (int col, int x, int y) {
	x = get_p (col, x), y = get_p (col, y);
	if (x == y)
		return;
	if (h[col][x] > h[col][y])
		swap (x, y);
	st.push_back ({&p[col][x], p[col][x]});
	p[col][x] = y;
	if (h[col][x] == h[col][y]) {
		st.push_back ({&h[col][y], h[col][y]});
		++h[col][y];
	}
}

inline void add_edge (int v, int Tl, int Tr, int l, int r, int qwe) {
	if (Tl > r || Tr < l)
		return;
	if (l <= Tl && Tr <= r) {
		t[v].emplace_back (qwe);
		return;
	}
	int mid = (Tl + Tr) >> 1;
	add_edge (v + v, Tl, mid, l, r, qwe);
	add_edge (v + v + 1, mid + 1, Tr, l, r, qwe);
}

inline void solve (int v, int Tl, int Tr) {
	int saved_val = st.size ();
	for (auto it : t[v]) {
		Merge (q_col[it], e[e_num[it]].first * 2, e[e_num[it]].second * 2 + 1);
		Merge (q_col[it], e[e_num[it]].first * 2 + 1, e[e_num[it]].second * 2);
	}
	if (Tl == Tr) {
		int x = get_p (q_col[Tl], e[e_num[Tl]].first * 2), y = get_p (q_col[Tl], e[e_num[Tr]].second * 2);
		if (x != y) {
			if (nxt[Tl])
				add_edge (1, 1, q, Tl + 1, nxt[Tl] - 1, Tl);
			else
				add_edge (1, 1, q, Tl + 1, q, Tl);
			done[Tl] = Tl;
			cout << "YES\n";
		} else {
			if (nxt[Tl]) {
				if (prev_q[Tl] && done[prev_q[Tl]])
					add_edge (1, 1, q, Tl + 1, nxt[Tl] - 1, done[prev_q[Tl]]);
			} else {
				if (prev_q[Tl] && done[prev_q[Tl]])
					add_edge (1, 1, q, Tl + 1, q, done[prev_q[Tl]]);			
			}
			done[Tl] = done[prev_q[Tl]];
			cout << "NO\n";
		}
		
		while (st.size () > saved_val) {
			auto x = st.back ();
			*(x.x) = x.y;
			st.pop_back ();
		}
		return;
	}
	int mid = (Tl + Tr) >> 1;
	solve (v + v, Tl, mid);
	solve (v + v + 1, mid + 1, Tr);
	while (st.size () > saved_val) {
		auto x = st.back ();
		*(x.x) = x.y;
		st.pop_back ();
	}
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int n, m, k;
	
	cin >> n >> m >> k >> q;

	for (int i = 1; i <= m; ++i)
		cin >> e[i].first >> e[i].second;
	
	for (int i = 1; i <= q; ++i) {
		cin >> e_num[i] >> q_col[i];
	}

	for (int j = 1; j <= k; ++j)
		for (int i = 1; i <= n * 2 + 5; ++i)
			p[j][i] = i;
	
	for (int i = 1; i <= q; ++i) {
		if (pre[e_num[i]]) {
			nxt[pre[e_num[i]]] = i;
			prev_q[i] = pre[e_num[i]];
		}
		pre[e_num[i]] = i;
	}
	
	solve (1, 1, q);

	return 0;
}