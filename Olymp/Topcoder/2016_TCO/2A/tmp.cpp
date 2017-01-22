/// izizi

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
  
const int oo = 1e9, bpr = 1e9 + 7, N = 0;

#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

class LCMGCD {
    public:
    string isPossible(vector <int> x, int t) {
    	vector <int> c1 (x.size ()), c2 (x.size ());
    	int d[110][50][50];
    	memset (d, 0, sizeof (d));
    	for (int i = 0; i < x.size (); ++i) {
    		int ss = x[i];
    		int cnt1 = 0, cnt2 = 0;
    		while (ss % 2 == 0) {
    			++cnt1;
    			ss /= 2;
    		}
    		while (ss % 3 == 0) {
    			++cnt2;
    			ss /= 3;
    		}
    		c1[i] = cnt1;
    		c2[i] = cnt2;
    	}
    	d[1][cnt1][cnt2] = 1;
    	for (int i = 1; i < x.size (); ++i) {
    		for (int j = 0; j < 50; ++j) {
    			for (int k = 0; k < 50; ++k) {
    				d[i + 1][min (j, c1[i])][min (k, c2[i])] |= d[i][j][k];
    				d[i + 1][max (j, c1[i])][max (k, c2[i])] |= d[i][j][k];
    			}
    		}
    	}
    	int cnt1 = 0, cnt2 = 0;
    	while (t % 2 == 0)
    		++cnt1, ss /= 2;
    	while (t % 3 == 0)
    		++cnt2, ss /= 3;
    	if (d[x.size ()][cnt1][cnt2])
    		return "Possible";
    	else
    		return "Impossible";
    }

};

#ifdef LOCAL
int main () {


}
#endif