#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 100;

int c[N], d[N], n;
vector <int> a, b;

int main () {

	#ifdef UNBROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> c[i];
	for (int i = 0; i < n; ++i)
		cin >> d[i];
	
	int st = -1;
	
	for (int i = 0; i < n; ++i)
		if (c[i] == 1)
			st = i;
	
	for (int i = st, cnt = 0; cnt < n; i = (i + 1) % n, ++cnt)
		if (c[i] != 0)
			a.emplace_back (c[i]);

	for (int i = 0; i < n; ++i)
		if (d[i] == 1)
			st = i;
	
	for (int i = st, cnt = 0; cnt < n; i = (i + 1) % n, ++cnt)
		if (d[i] != 0)
			b.emplace_back (d[i]);
			
	if (a == b) {
		cout << "YES";
	} else {
		cout << "NO";
	}
	
	return 0;
}