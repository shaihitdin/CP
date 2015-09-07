#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "frac."

typedef long long ll;

const int N = 1e7;

int n;
int a[N];

void f(int p, int q) {
	if (p == 1) {
		a[++n] = q;
		return;
	}
	swap(p, q);
	a[++n] = p / q;
	p %= q;
	if (p) f(p, q);	
}
                                        	 
int main () {
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
                                       
	int p, q;
	cin >> p >> q;
	
	n = 1;
	a[1] = p / q;
	p %= q;
	if (p) f(p, q);
	
	cout << n << "\n";
	forn(i, 1, n)
		cout << a[i] << " ";

	return 0;         	
}