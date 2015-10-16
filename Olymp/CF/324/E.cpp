#include <bits/stdc++.h>

using namespace std;

const int N = 3000;

int pos[N], rpos[N];
long long ans;
int a[N];

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
		int x;
		cin >> x;
		rpos[x] = i;
		a[i] = x;
	}

	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		pos[x] = i;
	}	
	vector <pair <int, int> > vans;

	for (int i = 1; i <= n; ++i) {
		for (int j = n; j >= 1; --j) {
			if (rpos[i] <= pos[j] && pos[i] >= pos[j] && rpos[j] >= pos[i] && pos[j] <= pos[i]) {
				int x = rpos[i], y = rpos[j];
				rpos[j] = x;
				rpos[i] = y;
				swap (a[x], a[y]);
				ans += abs (x - y);
				vans.emplace_back (make_pair (x, y));
			} else if (rpos[i] >= pos[j] && pos[i] <= pos[j] && rpos[j] <= pos[i] && pos[j] >= pos[i]) {
				int x = rpos[i], y = rpos[j];
				rpos[j] = x;
				rpos[i] = y;
				swap (a[x], a[y]);
				ans += abs (x - y);				
				vans.emplace_back (make_pair (x, y));
			}
		}
		int x = rpos[i], y = pos[i];
		rpos[i] = y;
		rpos[a[y]] = x;
		swap (x, y);
		ans += abs (x - y);
		vans.emplace_back (make_pair (x, y));
	}

	cout << ans << "\n";

	cout << vans.size () << "\n";

	for (auto it : vans)
		cout << it.first << " " << it.second << "\n";	
	
	return 0;
}