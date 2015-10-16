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
const int INF = 2e9 + 9;  
const int B = 1e9 + 7;
                      
int n, k;
ll l[N], r[N];
vector <PII> g[N];

void no() {
	cout << "NO\n";
	exit(0);
}

int main () {        
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout); 

	ios_base :: sync_with_stdio (0);                                                                                           
	cin.tie(0); 

	cin >> n >> k;
	forn(i, 1, k)
		l[i] = -INF, r[i] = INF;
	forn(i, 1, n) {
		int strict, tp1, a, tp2, b;
		cin >> strict >> tp1 >> a >> tp2 >> b;
		if (!tp1 && !tp2) {              
			g[a].pb(PII(b, strict));
		}
		if (!tp1 && tp2) {
			b -= strict;
			if (b < l[a]) no();
			r[a] = min(r[a], b);
		}
		if (tp1 && !tp2) {
		    a += strict;
		    if (a > r[b]) no();
		    r[b] = max(r[b], a);
		}
		if (tp1 && tp2) {
			if (b - a - strict < 0) no();
		}
	}



    return 0;         	
}