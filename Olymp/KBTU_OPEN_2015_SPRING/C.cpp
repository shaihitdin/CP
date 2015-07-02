#include <bits/stdc++.h>

using namespace std;

int n, x;
map <int, int> mp;

int main () {

	scanf ("%d", &n);

	for (int i = 1; i <= n; ++i) {
		scanf ("%d", &x);
		++mp[x];
	}

	for (auto it : mp)
		if (it.second & 1)
			printf ("%d\n", it.first);
	
	return 0;
}