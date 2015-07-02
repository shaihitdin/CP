#include <bits/stdc++.h>

using namespace std;

const int N = 5000;

int a[N];

int ans;
multiset <int> Set;

inline void do_it (const int &penalty) {
	int res = penalty;
	for (; res < ans; ++res) {
		int pancake = *Set.rbegin();
		ans = min (ans, res + pancake);
		Set.erase (Set.find (pancake));
		Set.insert (pancake / 2);
		pancake -= pancake / 2;
		Set.insert (pancake);
	}	
	ans = min (ans, res + *Set.rbegin ());
}

int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	int test;

	scanf ("%d", &test);

	for (int t = 1; t <= test; ++t) {		
		int n;		
		scanf ("%d", &n);
		int mx = 0;		
		for (int i = 1; i <= n; ++i)
			scanf ("%d", &a[i]), mx = max (mx, a[i]);
		ans = 1e9;
		for (int i = 0; i <= mx; ++i) {
			Set.clear ();
			for (int j = 1; j <= n; ++j)
				Set.insert (a[j] - i);
			do_it (i);
		}
		printf ("Case #%d: %d\n", t, ans);
	}
	
	return 0;
}