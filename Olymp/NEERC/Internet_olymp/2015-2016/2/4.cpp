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
   
int bp2() {
	int bot = a, top = b, mid = 0;
	while (bot < top) {
		mid = (bot + top + 1) >> 1;
		if (y / mid < c) top = mid - 1;
		else bot = mid;
	}
	return top;
}

main () {
//	#ifdef LOCAL
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);
//	#endif

	ios_base :: sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b >> c >> d >> x >> y;
	int l = du(x, a);
	int r = max(l, y / a);
                  
	if (r < c) NO();
	
	int bot = a, top = b, mid = 0;
	while (bot < top) {
		mid = (bot + top) >> 1;
		if (du(x, mid) > d) bot = mid + 1;
		else top = mid;
	}                          

	top = bp2();       
	if (bot > top) NO();                   
	if (du(x, bot) > d) NO();
	if (y / top < c) NO();       

	int q = y / bot;
	cerr << q << "\n"; 
	int need = 0;
	if (x > bot * q)
		need = du((x - bot * q), q);
	bot += need;         
	if (bot > top) NO();
		
	for (; bot <= top; --top) {
		l = du(x, top);
		r = y / top; 
		if (r < l) continue;
		int z = inter(PII(l, r), PII(c, d));
		cout << "YES\n";
		cout << top << " " << z << "\n";
	   	return 0;
	}               

	cout << "NO\n";

	return 0;
}
