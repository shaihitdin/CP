#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <time.h>
#include <map>
using namespace std;
#define forn(i, x, n) for(int i = int(x); i <= int(n); ++i) 
#define for1(i, n, x) for(int i = int(n); i >= int(x); --i)
#define file "linesum."
#define USE_MATH_DEFINES
#define mp make_pair 
#define F first
#define S second

typedef long long ll;
typedef unsigned int uint;
typedef pair <uint, uint> PII;

const int maxn = (1 << 24) + (1 << 20) + 500;
const int INF = 1e9 + 7;
const int max_val = 2e6;

PII segs[maxn - (1 << 20)];
uint points[maxn - (1 << 24)], value[maxn - (1 << 24)];

struct dp_sum { 
	uint n, t[maxn];
	inline void init(uint _n, uint q) {
		n = _n;
		forn(i, 1, q)
			t[points[i]] += value[i];
		forn(i, 1, n)
			t[i] += t[i - 1];	
	}            
	inline uint sum(uint l, uint r) {   
		if (l)
			return t[r] - t[l - 1]; 
		else
			return t[r];
	}
} tree;  

int n, q;

struct elem {
	uint val, type, pos, id;
	elem() {}
	elem(uint val, bool type, char pos, uint id) : val(val), type(type), pos(pos), id(id) {}
	bool operator <(const elem &b) const {
		return val < b.val;
	}
} st[maxn];

uint sz;
    	
inline void compress() {
	sort(st + 1, st + 1 + sz);
	int cl = 1;
	st[0].val = st[1].val - 1;
	forn(i, 1, sz) {  
		if (st[i].val != st[i - 1].val) ++cl;  
		if (st[i].type == 1) 
			points[st[i].id] = cl;
		else {
			if (st[i].pos == 1)
				segs[st[i].id].F = cl;	
			else
				segs[st[i].id].S = cl;
		}	
	}
}      

/*----*/
uint RAND_cur = 0;
uint RAND_p1, RAND_p2;

inline uint nextRand24() {
	RAND_cur = RAND_cur * RAND_p1 + RAND_p2;
	return RAND_cur >> 8;
}   

inline uint nextRand32() {
	uint a = nextRand24(), b = nextRand24();
	return (a << 8) ^ b;
}

inline void add(const uint &val, const bool &type, const char &pos, const uint &id) {
	++sz;
	st[sz].val = val;
	st[sz].type = type;
	st[sz].pos = pos;
	st[sz].id = id;
}

inline void generate_all() {
	forn(i, 1, n) {
		value[i] = nextRand32();
		points[i] = nextRand32();      
	//	st[++sz] = elem(points[i], 1, 0, i);
		add(points[i], 1, 0, i);
	}	
	forn(i, 1, q) {
		segs[i].F = nextRand32();
		segs[i].S = nextRand32();             
		if (segs[i].F > segs[i].S) 
			swap(segs[i].F, segs[i].S);    
	//	st[++sz] = elem(segs[i].F, 2, 1, i);
		add(segs[i].F, 0, 1, i);
	//	st[++sz] = elem(segs[i].S, 2, 2, i);
		add(segs[i].S, 0, 2, i);
	}
}
/*----*/

uint ans;
       
int main() {
	freopen(file"in", "r", stdin);
	freopen(file"out", "w", stdout);

	scanf("%d %d", &n, &q);
	scanf("%d %d", &RAND_p1, &RAND_p2);

	generate_all();
	compress();

	tree.init(maxn - 42, n);
	forn(i, 1, q) {
		ans += tree.sum(segs[i].F, segs[i].S);
	}	

	printf("%u", ans);
	    
   	return 0;
}