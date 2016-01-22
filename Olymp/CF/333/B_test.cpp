#include <bits/stdc++.h>

using namespace std;

int main () {

	int x = 1e8;
	set <int> Set;

	for (int i = 1; i <= 1e5; ++i) {
		Set.insert (x / i);
	}

	cout << Set.size ();
	
	return 0;
}