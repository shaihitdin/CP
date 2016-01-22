#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "game."
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef pair <int, int> PII;

int gcd(int a, int b) {
	return (b ? gcd(b, a % b) : a);
}

int a, b, c;              

int main () {
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);

	cin >> a >> b >> c;
	if (gcd(a, b) == 1) {
		cout << "Second\n";
		return 0;
	}	

	vector <int> v1, v2;
	for (int i = 2; i * i <= a && i <= c; ++i) {
		while (a % i == 0) {
			v1.pb(i);
			a /= i;
		}
	}	
	if (a > 1 && a <= c) {
		v1.pb(a);
		a /= a;
	}	

	for (int i = 2; i * i <= b && i <= c; ++i) {
		while (b % i == 0) {
			v2.pb(i);
			b /= i;
		}
	}
	if (b > 1 && b <= c) {
		v2.pb(b);
		b /= b;
	}		

	int n = v1.size(), m = v2.size();
	if (gcd(a, b) == 1)
		--n, --m;
	if (n > m)
		cout << "First\n";
	else
		cout << "Second\n";		

	return 0;             
}       
