#include <bits/stdc++.h>

using namespace std;

const int 

inline void solve () {

}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	for (int i = 1; i <= n; ++i) {
		cin >> cx[i] >> cy[i];
	}	

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i];
	}
	
	for (int i = 1; i <= n; ++i) {
		cerr << x[i] << y[i] << "\n";
	}
	
	solve ();

	swap (cx[0], cx[1]);
	swap (cy[0], cy[1]);
	
	solve ();

	cout << ans;
	
	return 0;
}