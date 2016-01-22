#include <bits/stdc++.h>

using namespace std;

const int N = 2100, bpr = 1e9 + 7, p1 = 31, p2 = 131;

typedef unsigned long long ull;

vector <ull> Map, tmp, tmp2;
vector <int> Map2;
vector <ull> cnt[12];
int l[11], r[11];
string p[11];
int n;
string s;

inline int exist (const vector <ull> &ee, const ull &el) {
	int pos = lower_bound (ee.begin (), ee.end (), el) - ee.begin ();
	if (pos == ee.size () || el != ee[pos])
		return -1;
	return pos;
}

inline vector <ull> Find_Union (const vector <ull> &a, const vector <ull> &b) {
	vector <ull> res, resa;
	res.resize (a.size () + b.size ());
	merge (a.begin (), a.end (), b.begin (), b.end (), res.begin ());
	for (int i = 1; i < res.size (); ++i)
		if (res[i] == res[i - 1])
			resa.emplace_back (res[i]);
	return resa;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	cin >> s;
	
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> p[i] >> l[i] >> r[i];
		
	for (int i = 0; i < s.size (); ++i) {
		ull h1 = 0, h2 = 0;
		for (int j = i; j < s.size (); ++j) {
			h1 = (h1 * p1 + (s[j] - 'a' + 1));
			cnt[0].emplace_back (h1);
		}
	}
	
	sort (cnt[0].begin (), cnt[0].end ());
	cnt[0].resize (unique (cnt[0].begin (), cnt[0].end ()) - cnt[0].begin ());
	
	for (int i = 1; i <= n; ++i) {
		Map.resize (0);
		for (int j = 0; j < p[i].size (); ++j) {
			ull h1 = 0, h2 = 0;
			for (int k = j; k < p[i].size (); ++k) {
				h1 = (h1 * p1 + (p[i][k] - 'a' + 1));
				Map.emplace_back (h1);
			}
		}
		
		sort (Map.begin (), Map.end ());
		
		Map2.resize (0); Map2.resize (Map.size ());
				
		tmp.clear ();
		
		tmp.emplace_back (Map[0]);
		
		Map2[0] = 1;
		
		for (int j = 1, k = 0; j < Map.size (); ++j) {
			if (Map[j] != tmp.back ())
				tmp.emplace_back (Map[j]);
			++Map2[tmp.size () - 1];
		}
		
		Map2.resize (tmp.size ());
		
		Map = tmp;
		
		tmp.clear ();
		
		for (int j = 0; j < Map.size (); ++j)
			if (l[i] <= Map2[j] && Map2[j] <= r[i])
				tmp.emplace_back (Map[j]);
		
		cnt[i] = Find_Union (cnt[i - 1], tmp);

		if (l[i] == 0) {
			tmp2 = cnt[i];
			tmp.resize (0);
			int jj = 0, kk = 0;
			for (int jj = 0; jj < cnt[i - 1].size (); ++jj) {
				while (kk < Map.size () && Map[kk] < cnt[i - 1][jj])
					++kk;
				if (kk == Map.size () || cnt[i - 1][jj] != Map[kk])
					tmp.emplace_back (cnt[i - 1][jj]);			
			}
			cnt[i].resize (tmp2.size () + tmp.size ());
			merge (tmp2.begin (), tmp2.end (), tmp.begin (), tmp.end (), cnt[i].begin ());
		}
		cnt[i - 1].clear ();
		cnt[i - 1].shrink_to_fit ();
	}
	
	cout << cnt[n].size ();
	
	return 0;
}