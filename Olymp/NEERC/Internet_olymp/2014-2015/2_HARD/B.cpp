#include <bits/stdc++.h>

using namespace std;

long long x, y, z, k;      

int main () {

	freopen ("genom.in", "r", stdin);
	freopen ("genom.out", "w", stdout);

	cin >> x >> y >> z >> k;
	if (k % 2 == 0)
		cout << x - y << "\n";
	else
		cout << y - x << "\n";	

	return 0;
}
