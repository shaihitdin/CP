#include <bits/stdc++.h>

using namespace std;

const int sz = 1e6 + 107, bpr = 1e9 + 7, pr1 = 107, pr2 = 109;

int key[sz], key2[sz], value[sz], value2[sz], state[sz];

int p1[pr1], p2[pr1];

vector <int> goes[sz];

inline pair <int, int> Find (const int &val, const int &val2) {
	int i = val % sz;
	while (key[i] != -1) {
		if (key[i] == val && key2[i] == val2)
			return make_pair (value[i], value2[i]);
		if (++i == sz)
			i = 0;
	}
	return make_pair (-1, -1);
}

inline void Add (const int &val, const int &val1, const int &val2, const int &val3) {
	int i = val % sz;
	while (key[i] != -1)
		if (++i == sz)
			i = 0;
	key[i] = val;
	key2[i] = val1;
	value[i] = val2;
	value2[i] = val3;
}

// 0 - lose, 1 - win

inline void dfs (const int &hash1, const int &hash2, const int &v, const int &len) {
	if (state[v] != -1)
		return;

	for (char z : goes[v]) {
		int n_hash1, n_hash2;
		n_hash1 = (hash1 * 1ll * pr1 + (z - 32)) % bpr;
		n_hash2 = (hash2 * 1ll * pr2 + (z - 32)) % bpr;
		auto it = Find (n_hash1, n_hash2);
		if (it.first != -1) {
			dfs (n_hash1, n_hash2, it.first, it.second);
			if (state[it.first] == 0)
				state[v] = 1;
		}
		n_hash1 = (hash1 + p1[len] * 1ll * (z - 32)) % bpr;
		n_hash2 = (hash2 + p2[len] * 1ll * (z - 32)) % bpr;
		it = Find (n_hash1, n_hash2);
		if (it.first != -1) {
			dfs (n_hash1, n_hash2, it.first, it.second);
			if (state[it.first] == 0)
				state[v] = 1;
		}
	}
	if (state[v] == -1)
		state[v] = 0;
}

string s[300];

int main () {

	freopen ("game.in", "r", stdin);
	freopen ("game.out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	memset (key, -1, sizeof (key));
	memset (key2, -1, sizeof (key2));
	memset (state, -1, sizeof (state));
	memset (value, -1, sizeof (value));
	memset (value2, -1, sizeof (value2));
	
	p1[0] = 1;
	p2[0] = 1;
	
	for (int i = 1; i < pr1; ++i) {
		p1[i] = (p1[i - 1] * 1ll * pr1) % bpr;
		p2[i] = (p2[i - 1] * 1ll * pr2) % bpr;
	}	

	int n;

	cin >> n;

	int cnt = 0;
	
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
		for (int j = 0; j < s[i].size (); ++j) {
			int hash1 = 0, hash2 = 0;
			for (int k = j; k < s[i].size (); ++k) {
				hash1 = (hash1 + p1[k - j] * 1ll * (s[i][k] - 32)) % bpr;
				hash2 = (hash2 + p2[k - j] * 1ll * (s[i][k] - 32)) % bpr;
				auto it = Find (hash1, hash2);
				int now = 0;
				if (it.first == -1) {
					Add (hash1, hash2, ++cnt, k - j + 1);
					now = cnt;
				} else {
					now = it.first;
				}
				if (j == 0 && k + 1 == s[i].size ())
					state[now] = 1;
				if (j != 0)
					goes[now].emplace_back (s[i][j - 1]);
				if (k + 1 != s[i].size ())
					goes[now].emplace_back (s[i][k + 1]);
			}
		}
	}

	vector <char> ans;
	
	for (char i = 33; i <= 126; ++i) {
		auto it = Find (i - 32, i - 32);
		if (it.first != -1) {
			dfs (i - 32, i - 32, it.first, 1);
			if (state[it.first] == 0)
				ans.push_back (i);
		}
	}
	
	if (ans.size ()) {
		cout << "First\n";
		for (auto it : ans)
			cout << it;
	} else {
		cout << "Second";
	}
	
	return 0;
}