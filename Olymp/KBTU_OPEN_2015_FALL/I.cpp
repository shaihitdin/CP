#include <bits/stdc++.h>         	

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "road-to-work."
#define pb push_back
#define F first
#define S second
 
typedef long long ll;      
typedef pair <ll, ll> PII;
typedef long double ld;
           
const int N = 4e5;
const int INF = 1e9 + 9;               

#define left(i) (i << 1)
#define right(i) ((i << 1) | 1)

struct SegTree {
	int n, sz, t[4 * N];
	
	void recalc(int i) {
		t[i] = max(t[left(i)], t[right(i)]);
	}

	void init(int _n, int *a) {
		n = _n;
		for (sz = 1; sz < n; sz <<= 1);
		--sz;
		forn(i, 1, n)
			t[i + sz] = a[i];
		for1(i, sz, 1)
			recalc(i);	
	}

	void upd(int x, int val) {
		t[x += sz] = val;
		for (; x >= 1; x >>= 1)
			recalc(x);	
	}

	int get(int x) {
		if (x > sz) return x - sz;
		if (t[left(x)] >= t[right(x)])
			return get(left(x));
		else
			return get(right(x));	
	}
} t;

int n;
int a[N];    
ll ans;  
bool down[N];

main () {
//	#ifdef LOCAL
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);
//	#endif
	ios_base :: sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	n *= 2;    
	forn(i, 1, n)
		cin >> a[i];      
	t.init(n, a);

	vector <PII> res;
	res.pb(PII(0, 0));

	int h = 0;
	forn(i, 1, n) {
		t.upd(i, -INF);
		if (down[i]) {
			res.pb(PII(i, --h));
			continue;
		}	                           		
		int x = t.get(1);
		down[x] = 1;
		t.upd(x, -INF);
		ans += a[i]; 
		res.pb(PII(i, ++h)); 
	}                      

	cout << ans << "\n";
	for (auto x : res)
		cout << x.F << " " << x.S << "\n";

	return 0;
}                                        
