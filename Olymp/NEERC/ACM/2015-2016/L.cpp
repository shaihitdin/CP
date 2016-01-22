#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "lucky."     
#define F first                       
#define S second 
#define pb push_back   

typedef long long ll; 
typedef pair <int, int> PII;
typedef double ld;
                                                                                          
const int N = 300; 
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, m;
int a[N][N], d[4][N][N];
           
int di[] = {0, 0, -1, +1};
int dj[] = {-1, +1, 0, 0};

int main () {
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);                               

	ios_base :: sync_with_stdio (0);
	cin.tie(0);

    cin >> n >> m;
    forn(i, 1, n)
    	forn(j, 1, m)
    		cin >> a[i][j];
    
    forn(i, 1, n) {
    	forn(j, 1, m)
    		d[0][i][j] = max(d[0][i][j - 1], a[i][j]);
    	for1(j, m, 1)
    		d[1][i][j] = max(d[1][i][j + 1], a[i][j]);
    }       
    forn(i, 1, m) {
    	forn(j, 1, n)
    		d[2][j][i] = max(d[2][j - 1][i], a[j][i]);
    	for1(j, n, 1)
    		d[3][j][i] = max(d[3][j + 1][i], a[j][i]);
    }

    int ans = 0;
    forn(i, 1, n) {
    	forn(j, 1, m) {
    		int cur = 0;
    		forn(k, 0, 3) {
    			int ni = i + di[k], nj = j + dj[k];
    			cur += (a[i][j] > d[k][ni][nj]);
    		}                                                   
        	ans += cur;
    	}
    }

    cout << ans << "\n";

	return 0;         	
}
   