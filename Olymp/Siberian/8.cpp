#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "luigi."     
#define F first
#define S second
#define pb push_back   
#define _bits __builtin_popcount

typedef long long ll; 
typedef pair <int, int> PII;
                                                                               
const int N = 3e5;                                                                                              
const int INF = 1e9 + 9;  
const int B = 1e9 + 7;

int n, s;
PII a[N];      
int d[2][N], nd[2][N];

int main () {        
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout); 

	ios_base :: sync_with_stdio (0);                                                                                           
	cin.tie(0); 

	cin >> n >> s;
	forn(i, 1, n) 
		cin >> a[i].F >> a[i].S;

	sort(a + 1, a + 1 + n);
	/*forn(i, 1, n)
		cerr << a[i].F << " " << a[i].S << "\n";   
    */   
    forn(i, 1, s)
    	d[0][i] = nd[0][i] = -INF;
    forn(i, 1, n) {
    	int xi = i & 1;
    //	cerr << i << ": ";
    	forn(j, 1, s) {
    		d[xi][j] = d[xi ^ 1][j];
    		if (j < a[i].S) continue;
    		if (a[i - 1].F != a[i].F)
    			d[xi][j] = max(d[xi][j], d[xi ^ 1][j - a[i].S] + 1);
    		else	
    			d[xi][j] = max(d[xi][j], nd[xi ^ 1][j - a[i].S] + 1);	
    	}	
    	forn(j, 1, s) {
    		nd[xi][j] = nd[xi ^ 1][j];
    		if (j < a[i].S) continue;
    		if (a[i - 1].F != a[i].F)
    			nd[xi][j] = max(nd[xi][j], d[xi ^ 1][j - a[i].S]);
    		else	
    			nd[xi][j] = max(nd[xi][j], nd[xi ^ 1][j - a[i].S]);	
    	}
    /*	forn(j, 1, s)
    		cerr << "(" << j << " " << d[xi][j] << ") ";
    	cerr << "\n";	
    */}
          
    int ans = max(d[n & 1][s], nd[n & 1][s]);
    if (ans <= 0)
    	cout << "Impossible\n";
    else
    	cout << ans << "\n";	

    return 0;         	
}