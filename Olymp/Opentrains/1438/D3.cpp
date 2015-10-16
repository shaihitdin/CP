#include <bits/stdc++.h>

using namespace std;

const int N = 31;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define pb push_back

int n;
ll k;
string og;

const int mlen = 101;
const ll mnum = 1e16;
const int alph = 30;
                                                                                                                                          
ll s[mlen][alph];
ll d[mlen][alph][alph];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	
	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n >> k;
	cin >> og;
     
    d[0][0] = 1;
    forn(i, 1, mlen - 1) {
    	forn(j, 1, n) {
    		forn(k, 1, 26) {
    			char c = 'a' + k - 1;
    			forn(q, 0, j - 1)
    				if (c == og[q])
    					d[i][j][k] += d[i - 1][j][26];
    			if (c == og[j - 1])
    				d[i][j][k] += d[i - 1][j - 1][26];	
    			d[i][j][k] += d[i][j][k - 1];
    		}
    	}
    }

    forn(len, 1, mlen - 1) {
    	if (k > d[len][n][26]) {
    		k -= d[len][n][26];
    		continue;
    	}
    	string ans;
    	for1(i, len, 1) {
    		
    	}
    }

	return 0;
}
