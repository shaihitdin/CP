#include <bits/stdc++.h>

using namespace std;

const int N = 100;

vector <int> all_c[N];
vector <int> a;
int n;
bool u[N];


inline bool cmp (const vector <int> &x, const vector <int> &y) {
	return x[0] < y[0];
}

inline void do_it (vector <int> &a) {
	
	int cnt_c = 0;
	
	memset (u, 0, sizeof (u));
	
	for (int i = 0; i < a.size (); ++i) {
		if (u[i])
			continue;
		++cnt_c;
		all_c[cnt_c].resize (0);
		for (int j = i; !u[j]; j = a[j]) {
			u[j] = 1;
			all_c[cnt_c].push_back (j);
		}
	}
	for (int i = 1; i <= cnt_c; ++i) {
		int pos = 0;
		for (int j = 0; j < all_c[i].size (); ++j)
			if (all_c[i][j] > all_c[i][pos])
				pos = j;
		vector <int> ne;
		ne.push_back (all_c[i][pos]);
		for (int j = (pos + 1) % all_c[i].size (); j != pos; j = (j + 1) % all_c[i].size ())
			ne.push_back (all_c[i][j]);
		all_c[i] = ne;
	}
	sort (all_c + 1, all_c + cnt_c + 1, cmp);
	for (int i = 1, j = 0; i <= cnt_c; ++i)
		for (auto it : all_c[i])
			a[j++] = it;

}



int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> n;
	
	a.resize (n + 1);

	for (int i = 1; i <= n; ++i) {
		a[i] = i;
	}

	int cnt = 1;
	do_it (a);

	while (1) {
		bool flag = 1;
		for (int i = 1; i <= n; ++i) {
			if (a[i] != i) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			break;
		}
		do_it (a);
	}
	
	cout << cnt;

	return 0;
}