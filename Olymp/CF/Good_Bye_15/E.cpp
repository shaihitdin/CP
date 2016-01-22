#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int bpr = 1e9 + 7, oo = 1e9, N = 2e5 + 100;

int b[3], n;

multiset <int> Set;

inline int bit (int mask, int pos) {
	return (mask >> pos) & 1;
}

inline int ss (int x) {
	int res = oo;
	for (int i = 0; i < 8; ++i) {
		if (__builtin_popcount (i) == 2) {
			int sum = 0;
			for (int j = 0; j < 3; ++j)
				sum += b[j] * bit (i, j);
			if (sum < x)
				continue;
			res = min (res, sum);
		}
	}
	return res;
}

inline int findlower (int x) {
	auto it = Set.upper_bound (x);
	if (it == Set.begin ())
		return oo;
	--it;
	return *it;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;

	cin >> b[0] >> b[1] >> b[2];
	
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		Set.insert (x);
	}	
	
	sort (b, b + 3);

	if (*Set.rbegin () > b[0] + b[1] + b[2]) {
		cout << -1;
		return 0;
	}
	
	int ans = 0;
	
	while (Set.size ()) {
		++ans;
		int x = *Set.rbegin ();
		Set.erase (Set.find (*Set.rbegin ()));
		if (b[0] >= x) {
			int it = findlower (b[1]);
			if (it != oo)
				Set.erase (Set.find (it));
			it = findlower (b[2]);
			if (it != oo)
				Set.erase (Set.find (it));
		} else if (b[1] >= x) {
			int it = findlower (b[0]);
			if (it != oo)
				Set.erase (Set.find (it));
			it = findlower (b[2]);
			if (it != oo)
				Set.erase (Set.find (it));		
		} else if (b[2] >= x) {
			int tmp = findlower (b[1]);
			if (tmp == oo) {
				tmp = findlower (b[1] + b[0]);
				if (tmp != oo)
					Set.erase (Set.find (tmp));
			} else {
				Set.erase (Set.find (tmp));
				int tmp2 = findlower (b[0]);
				if (tmp2 == oo) {
					Set.insert (tmp);
					tmp2 = findlower (b[0] + b[1]);
					if (tmp2 != oo)
						Set.erase (Set.find (tmp2));
				} else {
					Set.erase (Set.find (tmp2));
				}
			}
		} else if (ss (x) != oo) {
			int q = b[0] + b[1] + b[2] - ss (x);
			int it = findlower (q);
			if (it != oo)
				Set.erase (Set.find (it));
		}
	}
	
	cout << ans;
	
	return 0;
}