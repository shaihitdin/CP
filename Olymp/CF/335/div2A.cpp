#include <bits/stdc++.h>

using namespace std;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif
	
	int a, b, c, a1, b1, c1;
	
	cin >> a >> b >> c;

	cin >> a1 >> b1 >> c1;

	int can = 0, need = 0;
	
	if (a1 < a)
		can += (a - a1) / 2;
	else
		need += (a1 - a);
	if (b1 < b)
		can += (b - b1) / 2;
	else
		need += (b1 - b);
	if (c1 < c)
		can += (c - c1) / 2;
	else
		need += (c1 - c);
	
	if (need <= can)
		cout << "Yes";
	else
		cout << "No";
	
	return 0;
}