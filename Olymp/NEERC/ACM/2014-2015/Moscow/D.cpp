#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int s[3];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int a, b;

	cin >> a >> b;

	for (int i = 1; i <= 10000; ++i) {
		s[0] = a;
		s[1] = b;
		s[2] = i;
		sort (s, s + 3);
		if (s[2] * s[2] == s[0] * s[0] + s[1] * s[1]) {
			cout << "YES";
			return 0;
		}
	}
	
	cout << "NO";
	
	return 0;
}