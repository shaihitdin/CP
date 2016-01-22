#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned int ui;

using namespace std;

const int bpr = 1e9 + 7;

class VampireTree {
	
	public:
    int maxDistance(vector <int> num) {
    	int n = num.size ();
    	sort (num.begin (), num.end ());
    	int ans = -1;
    	if (num[0] != 1)
    		return ans;
    	for (int i = 0; i < n; ++i) {
    		for (int j = 0; j < n; ++j)
    			g[j].clear ();
    		available[0] = 1;
    		for (int j = 1; j < n; ++j) {
    			if (i == j)
    				continue;
    			if (num[j] > 1)
    				break;
    			available[j] = 1;
    		}
    		for (int j = 0; j < n; ++j) {
    			if (i == j || num[j] == 1)
    				continue;
    			for (int k = 0; k < j; ++k) {
    				
    			}
    		}
    	}
    }

};

#ifdef LOCAL
int main () {
	
	return 0;
}
#endif