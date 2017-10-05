/// Stupido del problemo

#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1);
  
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

const int oo = 1e9, bpr = 1e9 + 7, N = 20010;

vector <pair <int, char> > g[N];

inline bool get (int v, int pp, int dest, string &s) {
	if (v == dest)
		return 1;
	for (auto it : g[v]) {
		if (it.fe == pp)
			continue;
		if (get (it.fe, v, dest, s)) {
			s += it.se;
			return 1;
		}
	}
	return 0;
}

inline void get_cnt (int v, int pp, const string &s, int len, bool is_smaller, int& ans) {
	if (is_smaller) {
		for (auto it : g[v]) {
			if (it.fe == pp)
				continue;
			++ans;
			get_cnt (it.fe, v, s, len + 1, 1, ans);
		}
	} else {
		if (len == s.size ())
			return;
		for (auto it : g[v]) {
			if (it.fe == pp)
				continue;
			if (s[len] < it.se) {
				continue;
			}
			else if (s[len] > it.se) {
				++ans;
				get_cnt (it.fe, v, s, len + 1, 1, ans);
			}				
			else {
				if (len + 1 != s.size ()) {
					++ans;
				}
				get_cnt (it.fe, v, s, len + 1, 0, ans);
			}
		}
	}

}

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	

	int n, q;
		
    cin >> n >> q;
   
   	for (int i = 1; i < n; ++i) {
   		int x, y;   		
   		cin >> x >> y;
   		char z;
   		cin >> z;
   		g[x].eb (mp (y, z));
   		g[y].eb (mp (x, z));
   	}
   	
    while (q--) {
    	int x, y;
    	cin >> x >> y;
    	string s;
    	get (x, x, y, s);
    	reverse (s.begin (), s.end ());
		int ans = 0;
		get_cnt (x, x, s, 0, 0, ans);
		cout << ans << "\n";
    }
  	
  	return 0;
}