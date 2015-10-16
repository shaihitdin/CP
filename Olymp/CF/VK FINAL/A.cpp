#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100, big_N = 8e5 + 100;

vector <int> lcp_l[big_N], lcp_r[big_N], res[big_N];

pair <string, int> s[N];
string a[N], b[N];
int t[N], p[N];

inline bool check (const int &i, const int &j, const char &aa) {
	if (j - 1 >= a[i].size () || a[i][j - 1] < aa)
		return 0;
	return 1;
}

inline bool check2 (const int &i, const int &j, const char &aa) {
	if (j - 1 < a[i].size () && a[i][j - 1] == aa)
		return 1;
	return 0;
}

inline void upd (int r, const int &delta) {
	for (; r < N; r = r | (r + 1))
		t[r] += delta;
}

inline int get (int r) {
	int res = 0;
	for (; r >= 0; r = (r & (r + 1)) - 1)
		res += t[r];
	return res;
}


inline int get (int l, int r) {
	return get (r) - get (l - 1);
}

bool ok[N];
int sum;


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n;

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> s[i].first;
		s[i].second = i;
	}

	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
	}
	
	sort (s + 1, s + n + 1);

	for (int i = 1; i <= n; ++i)
		a[i] = s[i].first;

	for (int i = 1; i <= n; ++i) {
		lcp_l[i].resize (b[i].size ());
		lcp_r[i].resize (b[i].size ());
		lcp_l[i][0] = 1;
		lcp_r[i][0] = n;
		res[0].emplace_back (i);
		ok[i] = 1;
		for (int j = 1; j <= b[i].size (); ++j) {
			int l = lcp_l[i][j - 1] - 1, r = lcp_r[i][j - 1] + 1;
			while (r - l > 1) {
				int mid = (r + l) >> 1;
				if (!check (mid, j, b[i][j - 1]))
					l = mid;
				else
					r = mid;
			}
			if (!check (r, j, b[i][j - 1]))
				break;
			lcp_l[i][j] = r;
			l = r;
			r = lcp_r[i][j - 1] + 1;
			while (r - l > 1) {
				int mid = (r + l) >> 1;
				if (check2 (mid, j, b[i][j - 1]))
					l = mid;
				else
					r = mid;
			}
			lcp_r[i][j] = l;
			res[j].emplace_back (i);
		}
	}
	
	for (int i = 1; i <= n; ++i)
		upd (i, 1);
	
	for (int i = big_N - 1; i >= 0; --i) {
		for (auto it : res[i]) {
			if (!ok[it])
				continue;
			if (!get (lcp_l[it][i], lcp_r[it][i]))
				continue;
			cerr << get (lcp_l[it][i], lcp_r[it][i]) << "\n";
			cerr << it << " " << lcp_
			int l = lcp_l[it][i] - 1, r = lcp_r[it][i];
			while (r - l > 1) {
				int mid = (r + l) >> 1;
				if (get (lcp_l[it][i], mid))
					r = mid;
				else
					l = mid;
			}
			ok[it] = 0;
			p[it] = r;
			//cerr << r << " " << it << "\n";
			upd (r, 0);
			sum += i;
		}
	}
	
	cout << sum << "\n";
	
	for (int i = 1; i <= n; ++i) {
		cout << s[p[i]].second << " " << i << "\n";
	}
	
	return 0;
}