#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 100;

inline int myrand (const int &x) {
	return (((rand () * 1ll) << 10) ^ (rand ())) % x;
}

int n, m, a[N], b[N];
vector <int> ans;

inline bool rec (const int &now, const int &lvl) {

	if (now == 0 || now == n + 1 || a[lvl - 1] == now)
		return 0;
	
	if (lvl == m + 1) {
		for (int i = 0; i < ans.size (); ++i)
			printf ("%d\n", ans[i]);
		return 1;
	}
	ans.push_back (now - 1);
	if (rec (now - 1, lvl + 1))
		return 1;
	else
		ans.pop_back ();
	ans.push_back (now + 1);
	if (rec (now + 1, lvl + 1))
		return 1;
	else
		ans.pop_back ();
	return 0;

}

int main () {
	/*
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	*/
	srand (time (0));

	scanf ("%d%d", &n, &m);

	for (int i = 1; i <= n; ++i)
		b[i] = i;

	random_shuffle (b + 1, b + n + 1, myrand);


	int till = min (n, 5000);

	for (int i = 1; i <= m; ++i)
		scanf ("%d", &a[i]);

	if (m <= 10) {
		for (int i = 1; i <= n; ++i) {
			if (i == a[1])
				continue;
			ans.push_back (i);
			if (rec (i, 2)) {
				return 0;
			}
			ans.pop_back ();
		}
		puts ("menyerah");
		return 0;
	}
	
	for (int it = 1; it <= till; ++it) {
		int pos = b[it];
		if (pos == a[1])
			continue;
		ans.resize (0);
		ans.push_back (pos);
		bool flag = 0;
		for (int i = 2; i <= m; ++i) {
			if (pos == 1) {
				if (pos + 1 <= n && a[i] != pos + 1) {
					++pos;
					ans.push_back (pos);
				} else {
					flag = 1;
					break;
				}
			} else if (pos == n) {
				if (pos - 1 >= 1 && a[i] != pos - 1) {
					--pos;
					ans.push_back (pos);
				} else {
					flag = 1;
					break;
				}
			} else {
				if (rand () & 1 && a[i] != pos + 1) {
					++pos;
					ans.push_back (pos);
				} else if (a[i] != pos - 1) {
					--pos;
					ans.push_back (pos);
				} else {
					flag = 1;
					break;
				}
			}
		}
		if (!flag) {
			for (int i = 0; i < ans.size (); ++i)
				printf ("%d\n", ans[i]);
			return 0;
		}
	}

	puts ("menyerah");

	return 0;
}