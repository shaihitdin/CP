#include <iostream>

typedef long long ll;
typedef unsigned int ui;

using namespace std;
class KitayutaMart2 {
    public:
    ll numBought (ll K, ll T) {
    	ll now_cost = K;
        ll sum = 0;
        for (ll i = 1;; ++i, now_cost *= 2) {
        	sum += now_cost;
        	if (sum == T) {
        		return i;
        	}
        }
    }

};

// BEGIN CUT HERE
int main() {


}
// END CUT HERE