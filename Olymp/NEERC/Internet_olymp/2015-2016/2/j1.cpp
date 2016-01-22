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

const int N = 2e5;
const int INF = 1e9 + 9;               

int n;
int x;
int timer, t[N * 4];

void upd(int i, int val) {
	for (; i <= n; i |= (i + 1))
		t[i] = max(t[i], val);
}

int get(int i) {
	int ans = 0;
	for (; i > 0; i = (i & (i + 1)) - 1)
		ans = max(ans, t[i]);
	return ans;
}

int main () {
//	#ifdef LOCAL
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);
//	#endif

	ios_base :: sync_with_stdio(0);
	cin.tie(0);
                      
	cin >> n;
	int cnt = 0;
	forn(i, 1, n) {
		cin >> x;
		if (x == 0) {                 
		    upd(x, 0);
		    --cnt;
		//	st.erase(st.begin());
		}
		if (x > 0) {  

		    upd(x, ++timer);
		 // st.insert(PII(t[x], x));
		}                                                                                                                                                          
		if (x < 0) {	
			x = -x;            
		    if (timer[x] != 0) {
		    	++ 
		    	upd(x, 0);
			}
		//	st.erase(PII(t[x], x));
		}    
		int z = get(1e5), pos = 0;
		int l = 1, r = 1e5, mid = 0;
		while (l < r) {
			mid = (l + r) >> 1;
			if (get(mid) < z) l = mid + 1;
	    	else r = mid;
		}                           
		cout << (z ? l : 0) << "\n";
	}
      
	return 0;
}