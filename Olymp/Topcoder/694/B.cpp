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

const int oo = 1e9, bpr = 1e9 + 7, N = 256;
bool nx[N][N][N], pre[N][N][N];


class DistinguishableSetDiv1 {
    inline bool bit (int mask, int pos) {
    	return (mask >> pos) & 1;
    }
    
    public:
    int count(vector <string> answer) {
    	int n = answer.size ();
    	int m = answer[0].size ();
    	int d[1 << 20];
    	memset (d, 0, sizeof (d));
    	for (int i = 0; i < n; ++i) {
    		for (int j = i + 1; j < n; ++j) {
    			int tmm = (1 << m) - 1;
    			for (int k = 0; k < m; ++k) {
    				if (answer[i][k] != answer[j][k])
    					tmm ^= (1 << k);
    			}
    			++d[tmm];
    		}
    	} 
    	for (int i = 0; i < m; ++i) {
    		for (int mask = 0; mask < (1 << m); ++mask) {
    			if (bit (mask, i))
    				d[mask ^ (1 << i)] += d[mask];
    		}
    	}
    	int ans = 0;
    	for (int i = 0; i < (1 << m); ++i) {
    		if (d[i] != n * (n - 1) / 2)
    			++ans;
    	}
    	return ans;
    }
};

#ifdef LOCAL
int main() {


}
#endif