/**
	Oh, my dear
**/

#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned int ui;

using namespace std;

const int bpr = 1e9 + 7;

class FleetFunding {
	
	public:
    int maxShips(int m, vector <int> k, vector <int> a, vector <int> b) {
    	int n = k.size ();
    	int l = 0, r = 1e8;
    	auto k_c = k;
    	while (r - l > 1) {
    		int mid = (r + l) >> 1;
    		k = k_c;
    		bool flag = 1;
    		for (int i = 1; i <= m; ++i) {
    			int have = 0;
    			while (have < mid) {
    				int mn_val = 1e9, id = -1;
    				for (int j = 0; j < n; ++j) {
    					if (k[j] > 0 && a[j] <= i && i <= b[j] && mn_val > b[j]) {
    						mn_val = b[j];
    						id = j;
    					}
    				}
    				if (id == -1)
    					break;
    				int need = min (mid - have, k[id]);
    				k[id] -= need;
    				have += need;
    			}
    			if (have != mid) {
    				flag = 0;
    				break;
    			}
    		}
    		if (flag)
    			l = mid;
    		else
    			r = mid;
    	}
    	return l;
    }

};

#ifdef BROKEN
int main () {
	
	return 0;
}
#endif