#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100, oo = 1e9;

int n;

int main () {

	#ifdef LOCAL
	freopen ("in", "w", stdout);
	#endif
	
	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cout << (n = 1000) << "\n";
	
	for (int i = 1; i <= n; ++i) {
		cout << rand () << " " << rand () << " " << rand () << "\n";
	}
	
	return 0;
}