#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned int ui;

using namespace std;
class Flee {
    
	public:
	inline double getDist (const int &a, const int &b, const int &x, const int &y) {
		return sqrt ((x - a) * 1.0 * (x - a) + (b - y) * 1.0 + (b - y));
	}
	
	public:
	inline double getSafety (const int &a, const int &b, const vector <int> &x, const vector <int> &y) {
		double res = 0;
		for (int i = 0; i < x.size (); ++i) {
			res = max (res, getDist (a, b, x[i], y[i]));
		}
		return res;
	}
    public:
    bool inside (const int &x, const int &y) {
    	return 1 <= x && x < add + add && 1 <= y && y < add + add;
    }
    public:
    double maximalSafetyLevel(vector <int> x, vector <int> y) {
    	const int add = 1100;
    	int dx[] = {0, 1, 0, -1};
    	int dy[] = {-1, 0, 1, 0};
    	double dist[add + add][add + add];
    	
    	set <pair <double, pair <int, int> > > Set;
    	for (int i = 0; i < x.size (); ++i)
    		x[i] += add, y[i] += add;
    	for (int i = 0; i < add + add; ++i) {
    		for (int j = 0; j < add + add; ++j) {
    			dist[i][j] = -1;
			}
		}
    	dist[1 + add][0 + add] = getSafety (1 + add, 0 + add, x, y);
    	Set.insert (make_pair (dist[1 + add][0 + add], make_pair (1 + add, 0 + add)));
    	while (Set.size ()) {
    		int v = Set.rbegin () -> second -> first;
    		int u = Set.rbegin () -> second -> second;
    		Set.erase (Set.rbegin ());
			for (int i = 0; i < 4; ++i) {
				int nv = v + dx[i], nu = u + dx[i];
				double tmp = max (dist[v][u], getSafety (nv, nu, x, y));
				if (inside (nv, nu) && dist[nv][nu] < tmp) {
					Set.erase (make_pair (dist[nv][nu], make_pair (nv, nu)));
					dist[nv][nu] = tmp;
					Set.insert (make_pair (dist[nv][nu], make_pair (nv, nu)));
				}
			}
    	}
    	double ans = 1e100;
    	for (int i = 0; i < add + add; ++i) {
    		ans = min (ans, min (dist[1][i], dist[i][1]));
    	}
    	for (int i = 0; i < add + add; ++i) {
    		ans = min (ans, min (dist[i][add + add - 1], dist[add + add - 1][i]));
    	}
    	return ans;
    }

};

#ifdef LOCAL
int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	cin >> n;

	vector <int> a;
	
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		a.push_back (x);
	}

	return 0;
}
#endif