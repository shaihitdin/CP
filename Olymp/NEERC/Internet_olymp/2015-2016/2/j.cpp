#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "road."
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef pair <int, int> PII;

const int N = 2e6;
const int INF = 1e9 + 9;               

int n;
int x;
int u[N], was[N];
int st[N], sz;

int main () {
//	#ifdef LOCAL
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);
//	#endif

	ios_base :: sync_with_stdio(0);
	cin.tie(0);

	cin >> n;                                                       
	forn(i, 1, n) {
		cin >> x;
		if (x == 0) {
			if (sz)
				--sz;
		}
		if (x > 0) {
			was[x] = 1;
			st[++sz] = x;
		}                                                                                                                                                          
		if (x < 0) {	
			x = -x;
			if (was[x])        
				u[x] = 1;
		}                           
		while (sz && u[st[sz]]) --sz;
		if (sz == 0)
			cout << "0\n";
		else
			cout << st[sz] << "\n";
	}
      
	return 0;
}
