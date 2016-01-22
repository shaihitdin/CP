#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1200;

vector <pair <pair <ll, ll>, int> > Exist;
map <int, ll> r_val, r_val2;

ll a[N], b[N];
ll d1[N], d2[N], d1_1[N], d2_1[N];

inline ll RAND () {
	return (rand () * 1ll * rand ()) % (1 << 30);
}

int main () {

	freopen ("anagrams2.in", "r", stdin);
	freopen ("anagrams2.out", "w", stdout);

	srand (time (0));
	
	int n, m;
	
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		r_val[a[i]] = r_val2[a[i]] = 0;
	}
	
	cin >> m;

	for (int i = 1; i <= m; ++i) {
		cin >> b[i];
		r_val[b[i]] = r_val2[b[i]] = 0;
	}
	
	for (auto it = r_val.begin (); it != r_val.end (); ++it) {
		it -> second = RAND() + rand ();
	}
	
	for (auto it = r_val2.begin (); it != r_val2.end (); ++it) {
		it -> second = RAND() + rand ();
	}
	
	for (int i = 1; i <= n; ++i) {
		d1[i] = d1[i - 1] + r_val[a[i]];
		d1_1[i] = d1_1[i - 1] + r_val2[a[i]];
	}
	
	for (int i = 1; i <= m; ++i) {
		d2[i] = d2[i - 1] + r_val[b[i]];
		d2_1[i] = d2_1[i - 1] + r_val2[b[i]];
	}

	for (int len = min (n, m); len >= 1; --len) {
		Exist.resize (0);
		for (int i = 1; i + len - 1 <= n; ++i)
			Exist.emplace_back (make_pair (make_pair (d1[i + len - 1] - d1[i - 1], d1_1[i + len - 1] - d1_1[i - 1]), i));

		sort (Exist.begin (), Exist.end ());
		for (int i = 1; i + len - 1 <= m; ++i) {
			int pos = lower_bound (Exist.begin (), Exist.end (), make_pair (make_pair (d2[i + len - 1] - d2[i - 1], d2_1[i + len - 1] - d2_1[i - 1]), -1)) - Exist.begin ();
			if (pos != Exist.size () && Exist[pos].first == make_pair (d2[i + len - 1] - d2[i - 1], d2_1[i + len - 1] - d2_1[i - 1])) {
				cout << len << " " << Exist[pos].second << " " << i;
				return 0;
			}
		}
	}
	
	cout << "0 -1 -1";

	return 0;
}