#include <bits/stdc++.h>

using namespace std;

inline int myrand () {
	return (rand () << 13) ^ (rand ());
}

int main () {
	
	freopen ("in", "w", stdout);

	int n = 1e5, m = 1e8;

	cout << n << "\n";

	for (int i = 1; i <= n; ++i)
		cout << myrand () << " ";

	cout << "\n";

	cout << m << " " << 0 << " " << 3;

	return 0;
}