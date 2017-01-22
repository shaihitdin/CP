#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main () {

	#ifdef BROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	ll a, b;

	cin >> a >> b;

	cout << sum (b) - sum (a - 1);

	return 0;
}