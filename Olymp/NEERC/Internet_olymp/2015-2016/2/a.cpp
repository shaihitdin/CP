#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

typedef long long ll;

inline int RAND () {
	return (rand () * 1ll * rand ()) % ((int)1e9);
}

int n, m;

ll a[N], b[N], rea[N], d[N];

int main () {

	freopen ("anagrams.in", "r", stdin);
	freopen ("anagrams.out", "w", stdout);

	srand (time (0));
	
	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	cin >> m;
	
	for (int i = 1; i <= m; ++i)
		cin >> b[i];
	
	for (int i = 1; i < N; ++i)
		rea[i] = RAND () + rand ();
	
	
	ll res = 0;
	
	for (int i = 1; i <= n; ++i)
		res += rea[a[i]];
		
	for (int i = 1; i <= m; ++i)
		b[i] = rea[b[i]];


	for (int i = 1; i <= m; ++i)
		d[i] = d[i - 1] + b[i];
	
	
	for (int i = 1; i + n - 1 <= m; ++i) {
		if (res == d[i + n - 1] - d[i - 1]) {
			cout << "YES\n" << i;
			return 0;
		}
	}
	
	cout << "NO\n";
	
	return 0;
}