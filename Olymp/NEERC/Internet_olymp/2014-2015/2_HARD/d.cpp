#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define pb push_back

typedef int ll;

const int N = 5e3 + 120;
const ll INF = 1e9 + 9;
    
int main () {
	freopen ("tree.in", "r", stdin);
	freopen ("tree.out", "w", stdout);

	cin >> n; 
	
	if (n == 1) {
		cout << "1 1\n";
		return 0;
	}
	if (n == 2) {
		cout << "3 1 1 3\n";
		return 0;
	}
	if (n == 3) {
		cout << " 2 4 2 1 1 4\n";
		return 0;
	}

	vector <int> v;

	if (n % 2 == 1) {
		v.pb(n + 1);
		for (int i = n - 2; i >= 1; i -= 2)
			v.pb(i);
		for (int i = 1; i <= n - 2; i += 2)
			v.pb(i);          
	   v.pb(2);
	   v.pb(n + 1);
	   v.pb(2);
	}
	else {
		v.pb(n - 1);
		v.pb(n + 1);
		for (int i = n - 3; i >= 1; i -= 2)
			v.pb(i);
		for (int i = 1; i <= n - 3; i += 2)
			v.pb(i); 
		v.pb(n - 1);
		v.pb(2);
		v.pb();
	}


	for (auto x : v)
		cout << x << " ";
	cout << "\n";	

	return 0;
}
        