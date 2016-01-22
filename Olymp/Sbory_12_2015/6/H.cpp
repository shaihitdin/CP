#include <bits/stdc++.h>

using namespace std;

const int N = 120;

char s[N];
int pre[N], nxt[N];

inline vector <int> calc (string t) {
	int cp = 0, w = 1;
	vector <int> cnt;
	cnt.resize (10);
	
	for (int i = 0; i < t.size (); ++i)
		nxt[i] = i + 1, pre[i] = i - 1;

	while (t.size ()) {
		if (cp < 0 || cp == t.size ())
			return cnt;
		if (t[cp] >= '0' && t[cp] <= '9') {
			++cnt[t[cp] - '0'];
			if (t[cp] == '0') {
				int s = pre[cp], g = nxt[cp];
				nxt[s] = g;
				pre[g] = s;
			} else {
				--t[cp];
			}
			if (w == 1)
				cp = nxt[cp];
			else
				cp = pre[cp];
		} else {
			if (t[cp] == '<')
				w = -1;
			else
				w = 1;
			int old_cp = cp;
			if (w == 1)
				cp = nxt[cp];
			else
				cp = pre[cp];
			if (cp < 0 || cp == t.size ()) {
				return cnt;
			} else {
				if (t[cp] == '<' || t[cp] == '>') {
					int s = pre[old_cp], g = nxt[old_cp];
					nxt[s] = g;
					pre[g] = s;
				}
			}
		}
	}
	return cnt;
}


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	int n, q;
	
	cin >> n >> q;

	for (int i = 1; i <= n; ++i)
		cin >> s[i];

	while (q--) {
		int l, r;
		cin >> l >> r;
		string t;
		for (int j = l; j <= r; ++j)
			t += s[j];
		vector <int> ret_val;
		ret_val = calc (t);
		for (auto it : ret_val)
			cout << it << " ";
		cout << "\n";
	}

	return 0;
}