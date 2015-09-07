#include "scales.h"
#include <bits/stdc++.h>

using namespace std;

const int n = 6, N = 10;

bool can[1000];
int a[N], pos[N];

void init (int T) {
	srand (time (0));
	//freopen ("err", "wt", stderr);
}

// type = 1 -> heaviest, type = 2 -> lightest, type = 3 -> median, type = 4 -> nextlightest

inline double check (int type, int x, int y, int z, int zz, int out) {
	for (int i = 0; i < n; ++i)
		a[i] = i + 1;
	int j = 0, res = 0;
	int spos[3];
	do {
		if (!can[j]) {
			++j;
			continue;
		}
		for (int i = 0; i < n; ++i)
			pos[a[i]] = i;
		spos[0] = pos[x];
		spos[1] = pos[y];
		spos[2] = pos[z];
		sort (spos, spos + 3);	
		if (type == 1) {
			if (spos[2] == pos[out])
				++res;
		} else if (type == 2) {
			if (spos[0] == pos[out])
				++res;
		} else if (type == 3) {
			if (spos[1] == pos[out])
				++res;
		} else {
			if (pos[zz] < spos[0]) {
				if (spos[0] == pos[out])
					++res;
			} else if (pos[zz] < spos[1]) {
				if (spos[1] == pos[out])
					++res;
			} else if (pos[zz] < spos[2]) {
				if (spos[2] == pos[out])
					++res;
			} else {
				if (spos[0] == pos[out])
					++res;
			}
		}
		++j;
	} while (next_permutation (a, a + n));
	return double (res);
}

inline void process (int type, int x, int y, int z, int zz, int out) {
	for (int i = 0; i < n; ++i)
		a[i] = i + 1;
	int j = 0;
	int spos[3];
	do {
		if (!can[j]) {
			++j;
			continue;
		}
		for (int i = 0; i < n; ++i)
			pos[a[i]] = i;
		spos[0] = pos[x];
		spos[1] = pos[y];
		spos[2] = pos[z];
		sort (spos, spos + 3);	
		if (type == 1) {
			if (spos[2] != pos[out])
				can[j] = 0;
		} else if (type == 2) {
			if (spos[0] != pos[out])
				can[j] = 0;
		} else if (type == 3) {
			if (spos[1] != pos[out])
				can[j] = 0;
		} else {
			if (pos[zz] < spos[0]) {
				if (spos[0] != pos[out])
					can[j] = 0;
			} else if (pos[zz] < spos[1]) {
				if (spos[1] != pos[out])
					can[j] = 0;
			} else if (pos[zz] < spos[2]) {
				if (spos[2] != pos[out])
					can[j] = 0;
			} else {
				if (spos[0] != pos[out])
					can[j] = 0;
			}
		}
		++j;
	} while (next_permutation (a, a + n));	
}

void orderCoins() {
    
    
    srand (time (0));
    
    for (int i = 0; i < 720; ++i)
    	can[i] = 1;

    int move_cnt = 0;
    for (; move_cnt <= 8; ++move_cnt) {
    	//assert (move_cnt != 7);
    	double now = 0;
    	for (int i = 0; i < 720; ++i)
			now += ((can[i] == 1) ? 1.0 : 0.0);
    	//cerr << now << "\n";
    	if (now == 1.0)
    		break;
    	int x = 0, y = 0, z = 0, zz = 0, type = 0;
    	double tmp = 0;
    	for (int i = 1; i <= n; ++i) {
    		for (int j = i + 1; j <= n; ++j) {
    			for (int k = j + 1; k <= n; ++k) {
    				double mx;
   					mx = now - check (1, i, j, k, 0, i);
   					mx = min (mx, now - check (1, i, j, k, 0, j));
					mx = min (mx, now - check (1, i, j, k, 0, k));
					if (tmp <= mx) {
						tmp = mx;
						x = i;
						y = j;
						z = k;
						type = 1;
					}
   					mx = now - check (2, i, j, k, 0, i);
   					mx = min (mx, now - check (2, i, j, k, 0, j));
					mx = min (mx, now - check (2, i, j, k, 0, k));
					if (tmp <= mx) {
						tmp = mx;
						x = i;
						y = j;
						z = k;
						type = 2;
					}
   					mx = now - check (3, i, j, k, 0, i);
   					mx = min (mx, now - check (3, i, j, k, 0, j));
					mx = min (mx, now - check (3, i, j, k, 0, k));
					if (tmp <= mx) {
						tmp = mx;
						x = i;
						y = j;
						z = k;
						type = 3;
					}
					for (int l = 1; l <= n; ++l) {
						if (l == i || l == j || l == k)
							continue;
						mx = now - check (4, i, j, k, l, i);
						mx = min (mx, now - check (4, i, j, k, l, j));
						mx = min (mx, now - check (4, i, j, k, l, k));
						if (tmp <= mx) {
							tmp = mx;
							x = i;
							y = j;
							z = k;
							zz = l;
							type = 4;
						}
					}
    			}
    		}
    	}
    	//cerr << tmp << " ";
    	if (type == 1) {
    		process (type, x, y, z, zz, getHeaviest (x, y, z));
    	} else if (type == 2) {
    		process (type, x, y, z, zz, getLightest (x, y, z));
    	} else if (type == 3) {
    		process (type, x, y, z, zz, getMedian (x, y, z));
    	} else {
    		process (type, x, y, z, zz, getNextLightest (x, y, z, zz));
    	}
    }
    
    for (int i = 0; i < n; ++i)
    	a[i] = i + 1;
    
    int ans[6], j = 0;
    
    do {
    	if (!can[j]) {
    		++j;
    		continue;
    	}
    	for (int i = 0; i < n; ++i)
    		ans[i] = a[i];
    	++j;
    } while (next_permutation (a, a + n));
    
    
    answer (ans);
}
