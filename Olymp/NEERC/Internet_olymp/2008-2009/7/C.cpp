#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)

typedef long long ll;

const int N = 1e5 + 100;

bool bit(int mask, int pos) {
	return (mask) & (1 << pos);
}

int a[N] = {0, 1, 2, 3, 5, 8, 14, 25, 45, 85, 162, 310, 595, 1165, 2285, 4485,};
//int a[N];  

int main () {

	freopen ("chipmunks.in", "r", stdin);
	freopen ("precalc.out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n;  
	cin >> n;
	cout << a[n];
	                           
    forn(n, 16, 20) {     
    	forn(x, a[n - 1] + 1, 1e9) {
    		a[n] = x;
    		bool ok = 1;                     
    	    set <ll> st[21];
    		forn(mask, 1, (1 << n) - 1) {
    			ll sum = 0;
    			int sz = 0;
    			forn(i, 1, n) {
    				if (!bit(mask, i - 1)) continue;
    				sum += a[i], ++sz;
    			}	
    			if (!(st[sz].insert(sum).second)) {
    				ok = 0;
    				break;
    			}
    		}
    		if (ok) break;
    	}    
    	forn(i, 1, n) printf("%d, ", a[i]);
    	printf("\n");
    	cerr << n << " digits are already done, a[n] = " << a[n] << "\n";  	
    }                        
            
	return 0;
}