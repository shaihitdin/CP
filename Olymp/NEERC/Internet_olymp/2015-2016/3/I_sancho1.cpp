#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (ll i = ll(x); i <= ll(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "queue."
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef pair <ll, ll> PII;
typedef double ld;

const int N = 2e5;

#define int ll

int n, m, k, last;
int t[N], h[N], ans[N];

int serve(int g_time) {
	return max(g_time, last);
}

main () {
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);

	ios_base :: sync_with_stdio(0);
	cin.tie(0);

	set <PII> all;
	queue <PII> q;

	cin >> n >> m >> k;
	forn(i, 1, n) {
		cin >> t[i] >> h[i];
		all.insert(PII(t[i], i));
	}

	last = -k;
	while (all.size()) {
		int i = all.begin() -> S;
		all.erase(all.begin());          
		while (q.size() && serve(q.front().F) + h[q.front().S] <= t[i]) {
			int x = q.front().S;
			q.pop();
			ans[x] = serve(t[x]) + h[x];
			last = ans[x];
		}
		assert(q.size() <= m);
		if (q.size() == m) {
		    t[i] += k;
			all.insert(PII(t[i], i));
		}	
		else 
			q.push(PII(t[i], i));
	}	    
	while (q.size()) {
		int x = q.front().S;
		q.pop();
		ans[x] = serve(t[x]) + h[x];
		last = ans[x];
	}

	forn(i, 1, n)
		cout << ans[i] << "\n";

	return 0;             
}       
