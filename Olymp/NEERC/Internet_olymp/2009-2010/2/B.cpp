#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 120;

int n, m;
ll p;
int s[N], r[N];
ll done[N];

int main () {

	freopen ("budget.in", "r", stdin);
	freopen ("budget.out", "w", stdout); 

	cin >> m >> n >> p;

	for (int i = 1; i <= m; ++i)
		cin >> s[i];
	
	for (int i = 1; i <= n; ++i)
		cin >> r[i];
	
	for (int i = 1; i <= m; ++i)
		s[i] = ((p + s[i] - 1) / s[i]) - 1;
		
	sort (s + 1, s + m + 1);
	sort (r + 1, r + n + 1);

	ll l_mid = -1, r_mid = 1e16;

	while (r_mid - l_mid > 1) {
		ll mid = (r_mid + l_mid) >> 1;
		for (int i = 1; i <= m; ++i)
			done[i] = mid + 1;
		for (int i = n; i >= 1; --i) {
			int mxpos = 1;
			for (int j = 1; j <= m; ++j)
				if (done[mxpos] - (s[mxpos] + 1) < done[j] - (s[j] + 1))
					mxpos = j;
			if (done[mxpos] - (s[mxpos] + 1) < r[i]) {
				l_mid = mid;
				break;
			} else {
				done[mxpos] -= (s[mxpos] + 1);
			}
		}
		if (l_mid != mid)
			r_mid = mid;
	}

	cout << r_mid;
	
	return 0;
}