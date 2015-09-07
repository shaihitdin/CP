#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <bitset>
#include <set>
#include <map>
#include <assert.h>
#include <math.h>
#include <vector>
#include <time.h>
#include <queue>

using namespace std;

#define forn(i, x, n) for(int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for(int i = int(n); i >= int(x); --i)
#define file ""
#define pb push_back
#define F first
#define S second               
#define _bits __builtin_popcount                                                                                                          

typedef long long ll;         
typedef pair <int, int> PII;    
typedef const int c_i;

const int maxn = 2e6;                                    
const int INF = 1e9 + 9;

int n;
int a[maxn];
int d[maxn];
            
int lp[maxn];
vector <ll> pr;

void Eratothenes() {
	forn(i, 2, 1e6) {                
	    if (!lp[i]) {
	    	lp[i] = i;
	    	pr.pb(i);
	    }
		for (int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] * 1LL <= 1e6; ++j)
			lp[i * pr[j]] = pr[j];
	}
}

int main() {
#ifdef machine42
	freopen(file"in", "r", stdin);
	freopen(file"out", "w", stdout);                     
#endif
	scanf("%d", &n);
	forn(i, 1, n)
		scanf("%d", &a[i]);

	//sort(a + 1, a + 1 + n);
	Eratothenes();

	vector <int> divs;
	int ans = 0;
	forn(i, 1, n) {
		d[a[i]] = 1;
		int x = a[i];
		divs.clear();
		while (x > 1) {
			divs.pb(lp[x]);
			x /= lp[x]; 
		}                           
		for (auto z : divs)
			d[a[i]] = max(d[a[i]], d[a[i] / z] + 1);
		ans = max(ans, d[a[i]]);
	//	cerr << a[i] << " " << d[a[i]] << "\n";
	}

	printf("%d\n", ans);

    return 0;                                   
}                                          	
