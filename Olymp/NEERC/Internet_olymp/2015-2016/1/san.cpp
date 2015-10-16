#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "knumbers."     
#define F first
#define S second
#define pb push_back   
#define _bits __builtin_popcount

typedef long long ll; 
typedef pair <int, int> PII;
typedef double ld;
                                                                               
const int N = 2e6;                                                                                              
const int INF = 1e9 + 9;  
const int B = 1e9 + 7;

int n, m, x;
ld a[N], b[N], v[N];                            
set <pair <ld, ld> > s;
int main () {
#ifndef machine42
	freopen (file"in", "r", stdin);                                                                         
	freopen (file"out", "w", stdout); 
#endif	
	ios_base :: sync_with_stdio (0);                                                                                           
	cin.tie(0); 

	cin >> n >> m >> x;

	for (int i = 1; i <= n; ++i) {
		ld l, r;
		cin >> a[i] >> b[i] >> v[i];
		if (a[i] < b[i]) {
			b[i] = min(b[i], x);
			if (a[i] > x) continue;
			l = (x - b[i]) / v[i];
			r = (x - a[i]) / v[i];
		}
		else {
			b[i] = max(b[i], x);
			if (a[i] < x) continue;
			l = (b[i] - x) / v[i];
			r = (a[i] - x) / v[i];
		}
		
		while (1) {
			auto it = s.lower_bound (make_pair (l, -1));
			if (it == s.begin ())
				break;
			--it;
			if (it -> second <= l) {
				l = min (l, it -> first);
				r = max (r, it -> second);
				s.erase (it);
			}
			else {
				break;
			}
		}		
		while (1) {
			auto it = s.lower_bound (make_pair (l, -1));
			if (it == s.end ())
				break;
			if (it -> first <= r) {
				l = min (l, it -> first);
				r = max (r, it -> second);
				s.erase (it);
			} else {
				break;
			}
		}
		s.insert (make_pair (l, r));
	}
                     
	for (int i = 1; i <= m; ++i) {
		ld t;
		cin >> t;
		auto it = s.upper_bound (t);
		if (it == s.begin ()) {
			cout << t << "\n";
		} else {
			--it;
			cout << it.second << "\n";
		}
	}
	
	return 0;         	
}