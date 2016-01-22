#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned int ui;

using namespace std;

const int bpr = 1e9 + 7;
const int N = 7000;

ll d[N];

class ClassicProblem {
	
	public:
    ll maximalValue(vector <int> cnt, vector <int> w, vector <int> v, int limit) {
    	int n = cnt.size ();
    	int limit = min (limit, n * 80);
    	for (int i = 0; i <= limit; ++i)
    		d[i] = 0;
    	for (int i = 0; i < n; ++i) {
    		int zz = 0;
    		for (int j = 1; j + zz <= cnt; zz += j, j <<= 1) {
    			for (int k = 0; k + w[i] * j <= limit; ++k)
    				d[k + w[i] * j] = max (d[k] + v[i] * 1ll * j, d[k + w[i] * j]);
    		}
    	}
    }

};

#ifdef LOCAL
int main () {
	
	return 0;
}
#endif