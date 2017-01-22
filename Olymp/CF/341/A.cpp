/**
	Oh, my dear
**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector <int> g;
ll sum;

int main () {
	#ifdef BROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		if (x % 2 == 1)
			g.emplace_back (x);
		else
			sum += x;
	}
	sort (g.begin (), g.end ());
	reverse (g.begin (), g.end ());
	for (int i = 0; i + 1 < g.size (); i += 2)
		sum += g[i] + g[i + 1];
	cout << sum;
	return 0;
}