#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline ll sol1 (ll x) {
	ll res = 0;
	while (x > 1) {
		res += x / 5;
		x /= 5;
	}
	return res;
}

inline ll sol2 (ll x) {
	ll res = 0;
	ll deg = 0, q = 1;
	while(q * 5 <= x){
		q *= 5;
		++deg;
	}
	q = 1;
	for(int i = 1; i < deg; ++i){
		q *= 4;
		res += q * (deg - i);
	}

	return res;
}

int main () {
	
	srand (214245900);

	cerr << sol1 (10) << " " << sol2 (10) << "\n";
	
	for (int cnt = 1; cnt <= 100; ++cnt) {
		ll x = rand () * 1ll * rand () * rand () * rand ();
		assert (sol1 (x) == sol2 (x) && "VALID INVALID");
	}

	return 0;
}