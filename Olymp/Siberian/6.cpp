#include <bits/stdc++.h>

using namespace std;

int main () {

	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	int n;

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;

	while (n--) {
		float x, y, z;
		cin >> x >> y >> z;
	
		if (x + y + z <= 9) {
			cout << "NO\n";
			continue;
		}
		
		float coeff = x * y * z;
		float sx = y * z + x * z + x * y;

		if (sx < coeff) {
			cout << "YES\n";
			continue;
		}
		
	}

	return 0;
}