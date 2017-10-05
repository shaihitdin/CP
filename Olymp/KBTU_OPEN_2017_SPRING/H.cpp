#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;


int ans[N], l[N], r[N];

int main () {
	freopen ("collect.in", "r", stdin);
	freopen ("collect.out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n, s;
	cin >> n >> s;
	
	int amount = 0;	
	vector <pair <int, int> > q1;
	vector <int> need;	
	for (int i = 1; i <= n; ++i) {
		cin >> l[i] >> r[i];
		if (l[i] == 1) {
			q1.emplace_back (make_pair (r[i], i));
		} else {
			need.emplace_back (i);
			++amount;		
		}
	}

	if (amount > 29) {
		cout << "NO";
		return 0;
	}
	
	
	vector <int> divisor;
	
	for (int i = 1; i * i <= s; ++i) {
		if (s % i == 0) {
			divisor.emplace_back (i);
			divisor.emplace_back (s / i);
		}
	}
	sort (divisor.begin (), divisor.end ());
	divisor.resize (unique (divisor.begin (), divisor.end ()) - divisor.begin ());

	sort (q1.begin (), q1.end ());
	reverse (q1.begin (), q1.end ());
	
	for (int i = 0; i < q1.size () && i < 29; ++i) {
		need.emplace_back (q1[i].second);
	}
	
	
	sort (need.begin (), need.end ());

	
	vector <int> dp[100];

	for (int i = 0; i < 100; ++i)
		dp[i].resize (divisor.size ());

	dp[0][0] = 1;

   	for (int i = 0; i < need.size (); ++i) {
   		for (int j = 0; j < divisor.size (); ++j) {
   			if (dp[i][j] == 0)
   				continue;
   			for (int k = j; k < divisor.size (); ++k) {
   				if (divisor[k] % divisor[j] != 0)
					continue;   					
   				int x = divisor[k] / divisor[j];
   				if (l[need[i]] <= x && x <= r[need[i]]) {
   					dp[i + 1][k] = x;
   				}
   			}
   		}
   	}
	
	if (!dp[need.size ()][divisor.size () - 1]) {
		cout << "NO";
		return 0;
	}

	cout << "YES\n";

	int ps = need.size (), prod = s;

	while (ps) {
		ans[need[ps - 1]] = dp[ps][lower_bound (divisor.begin (), divisor.end (), prod) - divisor.begin ()];
		prod /= dp[ps][lower_bound (divisor.begin (), divisor.end (), prod) - divisor.begin ()];
		ps--;
	}

	for (int i = 1; i <= n; ++i) {
		if (!ans[i])
			ans[i] = 1;
		cout << ans[i] << " ";
	}
	
	return 0;
}