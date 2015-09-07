#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "balance."

typedef long long ll;

const int N = 2e5;

int n;
int a[N];

int back(int i) {
	return (i == 1) ? n : i - 1;
}

int forw(int i) {
	return (i == n) ? 1 : i + 1;
}

int dist(int f, int t) {
	if (f > t) swap(f, t);
	return min(t - f, f + n - t);
}
   	 
int main () {
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
                                       
    int sum = 0;
    scanf("%d", &n);
    forn(i, 1, n) {
    	scanf("%d", &a[i]);
    	sum += a[i];
    }                                      

    if (sum % n != 0) {
    	printf("-1\n");
    	return 0;
    }
    int need = sum / n;
    ll ans = 0;
    forn(i, 1, n) {
    	int prv = back(i), nxt = forw(i);
    	while (a[i] < need)	{
    		if (a[prv] > need) {         
    			int shift = min(need - a[i], a[prv] - need);
                a[prv] -= shift, a[i] += shift;
     			ans += dist(i, prv) * shift;
    		}
    		if (a[nxt] > need) {             
    			int shift = min(need - a[i], a[nxt] - need);
                a[nxt] -= shift, a[i] += shift;
     			ans += dist(i, nxt) * shift;
    		}
    		prv = back(prv), nxt = forw(nxt);
    	}
	}

	cout << ans << "\n";

	return 0;         	
}