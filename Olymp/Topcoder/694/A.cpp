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

class TrySail {
    public:
    int get(vector <int> strength) {
    	nx[0][0][0] = 1;
    	for (int i = 0; i < strength.size (); ++i) {
    		memcpy (pre, nx, sizeof (nx));
    		memset (nx, 0, sizeof (nx));
    		for (int i1 = 0; i1 < N; ++i1)
    		for (int i2 = 0; i2 < N; ++i2)
    		for (int i3 = 0; i3 < N; ++i3) {
    			if (!pre[i1][i2][i3])
    				continue;
    			nx[i1 ^ strength[i]][i2][i3] = 1;
    			nx[i1][i2 ^ strength[i]][i3] = 1;
    			nx[i1][i2][i3 ^ strength[i]] = 1;
    		}
    	}
    	int ans = 0;
    	for (int i1 = 0; i1 < N; ++i1)
    	for (int i2 = 0; i2 < N; ++i2)
    	for (int i3 = 0; i3 < N; ++i3)
    		if (nx[i1][i2][i3])
				ans = max (ans, i1 + i2 + i3);
    	return ans;
    }
};

#ifdef LOCAL
int main() {


}
#endif