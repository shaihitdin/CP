#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "jumps."
#define pb push_back
#define F first
#define S second
 
typedef long long ll;      
typedef pair <ll, ll> PII;
              
#define int ll

const int N = 2e6;
const int INF = 1e9 + 9;               

int du(int a, int b) {
	return (a + b - 1) / b;
}

void NO() {
	cout << "NO\n";
	exit(0);
}

int int1(const PII &a, const PII &b) {
	if (b.F <= a.F && a.F <= b.S)
		return a.F;
	if (b.F <= a.S && a.S <= b.S)
		return a.S;
	return -1;	
}

int inter(const PII &a, const PII &b) {
	int q = int1(a, b); 
	if (q > -1) return q;
	return int1(b, a);
}             

int a, b, c, d, x, y;
   
main () {
//	#ifdef LOCAL
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);
//	#endif

	ios_base :: sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b >> c >> d >> x >> y;     

	for (int i = 1; i * i <= y; ++i) {
	   	int l = du(x, i);
		int r = y / i;   
		if (r < l) continue;

		int z = inter(PII(l, r), PII(c, d));
		if (z != -1 && a <= i && i <= b) {    
			cout << "YES\n";
			cout << i << " " << z << "\n";
	   		return 0;
		}                   
		               
		int k = inter(PII(l, r), PII(a, b));                                                                     
		if (k != -1 && c <= i && i <= d) {                            
			cout << "YES\n";
			cout << k << " " << i << "\n";
	   		return 0;
	   	}              
	}                
	
	NO();

	return 0;
}
