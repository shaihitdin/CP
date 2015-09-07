#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100;

int a, b;

int main () {
	freopen ("treasure.in", "r", stdin);
	freopen ("treasure.out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> a >> b;

	cout << __gcd (a, b);
	
	return 0;
}