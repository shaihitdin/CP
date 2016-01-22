#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "journey."     
#define F first                       
#define S second 
#define pb push_back   

typedef long long ll; 
typedef pair <int, int> PII;
typedef double ld;
                                                                                          
const int N = 2e5; 
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

#define int ll

int n, t;
int p[N];
int a[N], d[N];

int dp(int k) {
	multiset <int> st;
	st.insert(d[0]);
	forn(i, 1, n) {
		d[i] = *st.begin() + a[i];
		st.insert(d[i]);
		if (i >= k)
			st.erase(st.find(d[i - k]));
	}
	return d[n];
}

int bin_search() {
	int l = 1, r = n, mid = 0;
	while (l < r) {
		mid = (l + r) >> 1;           
		if (dp(mid) <= t) r = mid;
		else l = mid + 1;
	}
	return l;
}

main () {
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);                               

	ios_base :: sync_with_stdio (0);
	cin.tie(0);

	cin >> n >> t;
	--n;
	t -= n;
	forn(i, 1, n)
		cin >> p[i];
	for1(i, n - 1, 1)
		p[i] = min(p[i], p[i + 1]);      
	forn(i, 1, n - 1)
		cin >> a[i];
	a[n] = 0;

	int range = bin_search();
	cout << p[range] << "\n";	

	return 0;         	
}
   