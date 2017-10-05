#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define int ll

const int N = 3e5 + 100;

int a[N];

main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	priority_queue <pair <int, int> > Set;

	int ans = 0;

	vector <int> ansv;
	ansv.resize (n + 1);
		
	for (int i = 1, sum = 0; i <= k + n; ++i, ans += sum) {
		if (i <= n) {
			Set.push (make_pair (a[i], i));
			sum += a[i];
		}
		if (k < i) {
			auto it = Set.top ();
			ansv[it.second] = i;
			sum -= it.first;
			Set.pop ();
		}
	}		
	
	cout << ans << "\n";

	for (int i = 1; i <= n; ++i)
		cout << ansv[i] << " ";
	
	return 0;
}