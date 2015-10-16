#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned int ui;


using namespace std;
class BearDarts {
	
	public:
	int gcd (const int &x, const int &y) {
		return y ? gcd (y, x % y) : x;
	}
	
	public:
    long long count(vector <int> w) {
    	int n = w.size ();
    	map <pair <int, int>, ll> cnt;
    	ll ans = 0;
    	for (int r = n - 1; r >= 1; --r) {
    		for (int l = 0; l < r; ++l)
    			ans += cnt[make_pair (w[l] / gcd (w[l], w[r]), w[r] / gcd (w[l], w[r]))];
    		for (int r2 = r + 1; r2 < n; ++r2)
    			++cnt[make_pair (w[r2] / gcd (w[r2], w[r]), w[r] / gcd (w[r2], w[r]))];
    	}
	
		return ans;
	}

};

#ifdef LOCAL
int main () {
	
	return 0;
}
#endif