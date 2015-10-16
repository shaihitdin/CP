#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "parts."     
#define F first
#define S second
#define pb push_back   
#define _bits __builtin_popcount

typedef long long ll; 
typedef pair <int, int> PII;
                                                                               
const int N = 3e5;                                                                                              
const int INF = 1e9 + 9;  
const int B = 1e9 + 7;

int n;
ll l, r;

bool bit (ll mask, int pos) {
	return mask & (1LL << pos);
}

int main () {
#ifndef machine42
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout); 
#endif	
	ios_base :: sync_with_stdio (0);                                                                                           
	cin.tie(0); 

    int ans = 0;
    cin >> n;
    ll minl = 0, maxr = 0;
    forn(i, 1, n) {
    	cin >> l >> r;
    	minl += l;
    	maxr += r;
    }

    l = minl, r = maxr;
    forn(p, 0, 50) {
    	if (bit(l, p) || bit(r, p)) {
    		++ans;
    		continue;
    	}	
    	ll nxt = l + (1LL << p) - (l % (1LL << p));
    	if (nxt <= r) ++ans;
    }
   
    cout << ans << "\n";
                     
	return 0;         	
}