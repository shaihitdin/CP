#include <bits/stdc++.h>

using namespace std;


int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	cin >> t;

	while (t--) {
		int n, k;
		string s;
		cin >> n >> k;
		cin >> s;
		int cnt0, cnt1;
		cnt0 = cnt1 = 0;
		for (int i = 0; i < s.size (); ++i)
			if (s[i] == '1')
				++cnt1;
			else
				++cnt0;
		memset (u, 0, sizeof (u));
		u[cnt0][cnt1] = 1;
		for (int total = n; total > k; --total)
			for (int zero = 
	}

	return 0;
}