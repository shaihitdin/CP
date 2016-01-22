#include <bits/stdc++.h>

using namespace std;

int main () {

	freopen ("sensor.in", "r", stdin);
	freopen ("sensor.out", "w", stdout);

	int n;
	
	cin >> n;

	cout << n - ((n - 1) / 6);

	return 0;
}