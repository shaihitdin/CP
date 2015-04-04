#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll l, r;


inline ll calc (const ll &x) {
    p = 1;
	while (p
}

int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	cin >> l >> r;

	cout << calc (r) - calc (l - 1);

	return 0;

}