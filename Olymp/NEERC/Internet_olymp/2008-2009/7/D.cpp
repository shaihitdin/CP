#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "factory."

typedef long long ll;

const int N = 2e6;

ll q, m, k, a;
ll d[N];

int calc(int n) {
	forn(i, 1, n) 
		d[i] = d[(i / m * k) + (i % m)] + (i / m * k);
}

int main () {
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
                    
	scanf("%d %d %d", &q, &m, &k);
	calc(1e6);
	forn(i, 1, q) {
		scanf("%d", &a);  
		printf("%I64d ", a + d[a]);
	}                        

	return 0;         	
}