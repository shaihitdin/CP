#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "repair."
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef pair <int, int> PII;

const int N = 2e6;
const int INF = 1e9 + 9;               

int n, a, b;
int x[N], u[N];

bool in(int x, int y, int z) {
	bool ans = 1;
	--u[x], --u[y], --u[z];
	if (u[x] < 0 || u[y] < 0 || u[z] < 0)
		ans = 0;
	++u[x], ++u[y], ++u[z];
	return ans;
}

void tryit(int x) {
	int k = b / x;
	for (int i = 1; i * i <= k; ++i) {
		if (k % i != 0) continue;
		int y = i, z = k / i;      
		if (x + y + z == a) {                         
			if (!in(x, y, z)) continue;
			cout << x << " " << y << " " << z << "\n";
			exit(0);
		}
	}
}        

int main () {
//	#ifdef LOCAL
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);
//	#endif

	ios_base :: sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> a >> b;                                                       
    forn(i, 1, n) {
    	cin >> x[i];
    	++u[x[i]];
    }  

    for (int i = 1; i * i <= b; ++i) {
    	if (b % i != 0) continue;
    	tryit(i);
    	tryit(b / i);    	
    }

    cout << -1 << "\n";
	
	return 0;
}
