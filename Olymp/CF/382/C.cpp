#include <bits/stdc++.h>

using namespace std;

#define eb emplace_back

int main () {

	cin >> n >> k;

	for (int i = 1; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].eb (y);
		g[y].eb (x);
	}

	

	return 0;
}