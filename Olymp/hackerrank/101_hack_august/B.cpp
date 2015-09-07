#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

int n, k, t;
string s;
int lst[N], lst_pos[N];
set <int> Set;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> n >> k >> t;

	cin >> s;

	for (int i = 0; i < k; ++i) {
		lst[i] = i, lst_pos[i] = i;
		Set.insert (i);
	}	
	
	while (Set.size () && *Set.begin () < n) {
		int pos = *Set.begin ();
		Set.erase (Set.begin ());
		int need = pos % k;
		lst_pos[need] = max (lst_pos[need], pos);
		for (; lst_pos[need] < n && s[lst_pos[need]] != '1'; lst_pos[need] += k);
		if (lst_pos[need] >= n)
			continue;
		int i = lst_pos[need];
		if (t < (i - lst[i % k]) / k) {
			lst[i % k] += k;
		} else {
			swap (s[i], s[lst[i % k]]);
			t -= (i - lst[i % k]) / k;
			lst[i % k] += k;
		}
		Set.insert (lst[i % k]);
	}
	
	cout << s;
	
	return 0;
}