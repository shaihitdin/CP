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

int cnt[256];

class LCMGCD {
    
	bool rec (int lvl, int nw, int nw2) {
		if (lvl == 3)
			return nw == 1 && nw2 == 1;
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (!cnt[i * 3 + j])
					continue;
				--cnt[i * 3 + j];
				if (lvl == 0) {
					if (rec (lvl + 1, i, j))
						return 1;
				} else {
					if (rec (lvl + 1, max (i, nw), max (j, nw2)))
						return 1;
					if (rec (lvl + 1, min (i, nw), min (j, nw2)))
						return 1;
				}
				++cnt[i * 3 + j];
			}
		}
		return 0;
	}
    
    public:
    string isPossible(vector <int> x, int t) {
    	vector <int> c1 (x.size ()), c2 (x.size ());
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
    	int cnt1 = 0, cnt2 = 0;
    	while (t % 2 == 0)
    		++cnt1, t /= 2;
    	while (t % 3 == 0)
    		++cnt2, t /= 3;
    	memset (cnt, 0, sizeof (cnt));
    	for (int i = 0; i < x.size (); ++i) {
    		int statex, statey;
    		if (c1[i] < cnt1)
    			statex = 0;
    		else if (c1[i] == cnt1)
    			statex = 1;
    		else
    			statex = 2;
    		if (c2[i] < cnt2)
    			statey = 0;
    		else if (c2[i] == cnt2)
    			statey = 1;
    		else
    			statey = 2;
    		++cnt[statex * 3 + statey];
    	}
    	if (x.size () == 1) {
    		if (c1[0] == cnt1 && c2[0] == cnt2)
    			return "Possible";
    		return "Impossible";
    	}
    	if (x.size () == 2) {
    		if (max (c1[0], c1[1]) == cnt1 && max (c2[0], c2[1]) == cnt2)
    			return "Possible";
    		if (min (c1[0], c1[1]) == cnt1 && min (c2[0], c2[1]) == cnt2)
    			return "Possible";    	
    		return "Impossible";
    	}
    	if (rec (0, -1, -1)) {
    		return "Possible";
    	}

    	return "Impossible";
    }

};

#ifdef LOCAL
int main () {


}
#endif