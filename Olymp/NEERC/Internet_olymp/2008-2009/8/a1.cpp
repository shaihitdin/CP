#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "balance."
#define F first
#define S second

typedef long long ll;
typedef pair <int, int> PII;          

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

PII p[N];
   	 
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
    int sz = 0;
    forn(i, 1, n) {
    	if (a[i] >= need) continue;
    	forn(j, 1, n) {
    		if (a[j] <= need) continue;
    		int id = i * n + (j - 1);
    		p[++sz] = PII(dist(i, j), id);
    	}
	}

	sort(p + 1, p + 1 + sz);

	forn(i, 1, sz) {
		int f = p[i].S / n, t = (p[i].S % n) + 1;
		if (a[f] >= need || a[t] <= need) continue;
		int shift = min(need - a[f], a[t] - need);
		a[f] += shift, a[t] -= shift;
		ans += dist(f, t) * shift;
	}

	cout << ans << "\n";

	return 0;         	
}