#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned int ui;

using namespace std;
class Similars {

    public:
    int maxsim (int l, int r) {
    	
    	char a[30];
    	
    	bool can[2500];
		
		for (int i = 0; i < 2500; ++i)
			can[i] = 0;
			
		int ans = 0;
    	
    	for (int i = l; i <= r; ++i) {
    		
    		memset (a, 0, sizeof (a));	

    		sprintf (a, "%d", i);

    		int res = 0;

			int n = strlen (a);
    		
    		for (int j = 0; j < n; ++j)
    			res |= (1 << (a[j] - '0'));
			
			for (int j = res; j; j = res & (j - 1))
    			if (can[j])
    				ans = max (ans, __builtin_popcount (j));
    		can[res] = 1;
    	}
    	return ans;
    }

};
