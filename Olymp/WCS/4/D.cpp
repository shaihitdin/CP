#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main () {

	#ifdef BROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	ld a, b;

	cin >> a >> b;

	cout << fixed;
	cout << setprecision (6);

	cout << min (a / 2, b / 2);

	return 0;
}