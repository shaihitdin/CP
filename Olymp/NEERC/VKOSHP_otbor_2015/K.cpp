#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "traffic."     
#define F first                       
#define S second 
#define pb push_back   

typedef long long ll; 
typedef pair <int, int> PII;
typedef double ld;
                                                                                          
const int N = 3e2 + 1; 
const int C = 1e5 + 1;
const ll INF = 1e18;
const int B = 1e9 + 7;

int n, k;                   
ll a[N];
ll c[N][N], d[N][N];
int p[N][N];

ll cur[C];

ll s(ll x) {
	return (x <= 0 ? 0 : x * (x - 1) / 2);
}

int main () {
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);                               

	ios_base :: sync_with_stdio (0);
	cin.tie(0);
                            
    cin >> n >> k;
    ll mx = 0;
    forn(i, 1, n) {
    	cin >> a[i];
    	mx = max(mx, a[i]);
    }	
    forn(i, 1, k) {
    	forn(j, 1, mx) {
    		if (j > i)                       
				cur[j] = cur[j - i] + s(j - i);	
			else
				cur[j] = 0;
    	}
    	forn(j, 1, n)
    		c[j][i] = cur[a[j]];  		
    }

    forn(i, 1, k)
    	d[0][i] = INF;
    forn(i, 1, n) {
    	d[i][0] = INF;
    	forn(j, 1, k) {
    		d[i][j] = INF;
    		forn(q, 1, j) {
    			if (d[i - 1][j - q] + c[i][q] < d[i][j]) {
    				d[i][j] = d[i - 1][j - q] + c[i][q];
    				p[i][j] = q;
    			}	
    		}
    	}
    }

    vector <int> ans;
    cout << d[n][k] << "\n";
    int cur = k;
    for1(i, n, 1) {
    	ans.pb(p[i][cur]);
    	cur -= p[i][cur]; 
    	if (i > 1)
    		assert(cur);
    }
    for1(i, n - 1, 0)
    	cout << ans[i] << " ";
    cout << "\n";	

	return 0;         	
}
   