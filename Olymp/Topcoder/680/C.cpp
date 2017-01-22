/// Oh, my dear

#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned int ui;

using namespace std;

const int bpr = 1e9 + 7, N = 2500;

struct state {
	bool a[N];
	ll res;
} cur, nxt, best;

int best = bpr;
vector <int> cost_c;

inline void calc (state &cur) {
	int no_pair = -1;
	cur.res = 0;
	for (int i = 0; i < n; ++i) {
		if (cur.a[i])
			continue;
		cur.res += cost_c[i];
		if (no_pair == -1) {
			no_pair = i;
		} else {
			cur.res += 100 * (i - no_pair);
		}
	}
}


class BearPairs {
	
	public:
    int minCost(string s, vector <int> cost, int k) {
    	cost_c = cost;
    	for (int i = 0; i < 
    }

};

#ifdef BROKEN
int main () {
	
	return 0;
}
#endif