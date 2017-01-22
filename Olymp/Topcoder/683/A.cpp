#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;

const ll oo = 1e18;

int n;
vector <int> d;

ll solve (vector <int> c) {
	ll ans = oo;
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		d.clear ();
		for (int j = i, cnt = 0; cnt < n; j = (j + 1) % n, ++cnt) {
			d.emplace_back (c[j]);
		}
		ll need = 0;
		for (int j = 0; j < n; ++j) {
			sum += d[j];
			need += abs (sum);
		}
		ans = min (ans, need);	
	}
	return ans;
}

using namespace std;
class MoveStones {
    public:
    long long get(vector <int> a, vector <int> b) {
    	ll sum = 0;
    	for (int i : a)
    		sum += i;
    	for (int i : b)
    		sum -= i;
    	if (sum)
    		return -1;
		n = a.size ();
		ll ans = oo;
		auto c = a;
		for (int i = 0; i < n; ++i)
			c[i] -= b[i];
		ans = min (ans, solve (c));
		reverse (c.begin (), c.end ());
    	ans = min (ans, solve (c));
    	return ans;
    }

};

// BEGIN CUT HERE
int main() {


}
// END CUT HERE