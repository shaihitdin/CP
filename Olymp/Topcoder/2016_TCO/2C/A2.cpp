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

const int oo = 1e9, bpr = 1e9 + 7, N = -1;

class BearBall {
    
	inline ll dist (ll x, ll y) {
		return x * x + y * y;
	}
    
    ll gcd (ll a, ll b) {
		return b ? gcd (b, a % b) : a;
	}
    
    inline pair <pair <int, int>, pair <ll, ll> > line (pair <int, int> a, pair <int, int> b) {
    	if (a.fe > b.fe)
    		swap (a, b);
    	pair <int, int> slope = mp (b.se - a.se, b.fe - a.fe);
    	
    	if (slope.se == 0)
    		return mp (mp (0, 0), mp (a.fe, 1));

    	int g = gcd (slope.fe, slope.se);
    	slope.fe /= g, slope.se /= g;
    	pair <ll, ll> delta = mp (slope.fe * 1ll * a.fe, slope.se);
    	delta.fe = a.se * 1ll * slope.se - delta.fe;/*a.fe * 1ll * a.se - delta.fe;*/
    	g = gcd (delta.fe, delta.se);
    	delta.fe /= g, delta.se /= g;
    	
    	return mp (slope, delta);
    }
    
    public:
    int countThrows(vector <int> x, vector <int> y) {
    	int n = x.size ();
    	int ans = 0;
    	for (int i = 0; i < n; ++i)
    		for (int j = i + 1; j < n; ++j)
    			if (x[i] > x[j] || (x[i] == x[j] && y[i] > y[j]))
    				swap (x[i], x[j]), swap (y[i], y[j]);
    	for (int i = 0; i < n; ++i) {
    		map <pair <pair <int, int>, pair <ll, ll> >, int> Map;    		
    		int tmpres = 0;
    		for (int j = i + 1; j < n; ++j)
    			tmpres += ++Map[line (mp (x[i], y[i]), mp (x[j], y[j]))];
    		ans += tmpres * 2;
    	}
    	return ans;
    }

};

#ifdef LOCAL
int main() {


}
#endif