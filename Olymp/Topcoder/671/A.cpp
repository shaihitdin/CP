#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned int ui;

using namespace std;
class BearCries {
	
	public:
    int count(string message) {
    	int bpr = 1e9 + 7;
    	int n = message.size ();
    	int d[n + 10][n + 10][n + 10];
    	memset (d, 0, sizeof (d));
    	d[0][0][0] = 1;
    	for (int i = 0; i < n; ++i) {
    		for (int j = 0; j < n; ++j) {
    			for (int k = 0; k <= j; ++k) {
    				if (message[i] == '_') {
    					d[i + 1][j][k] = (d[i + 1][j][k] + ((d[i][j][k] * 1ll * (j - k)) % bpr)) % bpr;
    					if (k)
    						d[i + 1][j][k - 1] = (d[i + 1][j][k - 1] + ((d[i][j][k] * 1ll * k) % bpr)) % bpr;
    				} else {
    					d[i + 1][j + 1][k + 1] = (d[i + 1][j + 1][k + 1] + d[i][j][k]) % bpr;
    					if (j)
    						d[i + 1][j - 1][k] = (d[i + 1][j - 1][k] + (d[i][j][k] * 1ll * (j - k))) % bpr;
    				}
    			}
    		}
    	}
    	return d[n][0][0];
    }

};

#ifdef LOCAL
int main () {
	
	return 0;
}
#endif