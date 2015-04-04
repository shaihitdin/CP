#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <time.h>
using namespace std;
#define forn(i, x, n) for(int i = int(x); i <= int(n); ++i) 
#define for1(i, n, x) for(int i = int(n); i >= int(x); --i)
#define file "minsum."
#define USE_MATH_DEFINES
#define mp make_pair 
#define F first
#define S second

typedef long long ll;
typedef pair <int, int> PII;

const int maxn = 200100;
const int INF = 1e9 + 7;
inline int get_min1 (const int &x, const int &y) {
	if (x < y) {
		return x;
	}
	return y;
}
struct Segment_tree {
    int n, sz;
    int min_t[maxn * 4], id[maxn * 4];
    int left(int &i) {
        return i << 1;
    }
    int right(int &i) {
        return (i << 1) + 1;
    }
    void recalc(int &x) {
        min_t[x] = get_min1(min_t[left(x)], min_t[right(x)]);
    	id[x] = (min_t[left(x)] < min_t[right(x)] ? id[left(x)] : id[right(x)]);
    }
    void init(int &_n, int *a) {
        n = _n;
        for(sz = 1; sz < n; sz <<= 1);
        --sz;                     
        forn(i, 1, n)
            min_t[i + sz] = a[i], id[i + sz] = i;
        for1(i, sz, 1)            
            recalc(i);                           
    }  
    int get_min(int l, int r) {
        l += sz, r += sz;
        int ans = INF, index = 0;
        while (l <= r) {
            if (l & 1) {
                if (ans > min_t[l]) index = id[l];	
            	ans = get_min1(ans, min_t[l]);
            }
            if (!(r & 1)) {
                if (ans > min_t[r]) index = id[r];
            	ans = get_min1(ans, min_t[r]);
            }
            l = (l + 1) >> 1, r = (r - 1) >> 1;
        }             
        return index;
    }
} tree; 

int n;      
int a[maxn];

int left_bs(int &x) {
	int mid = 0, l = 1, r = x;
	while (l < r) {           
		mid = (l + r) >> 1;
		if (tree.get_min(mid, x) != x) 
			l = mid + 1;
		else
			r = mid;	
	}             
	return l;
}

int right_bs(int &x) {
	int mid = 0, l = x, r = n;            
	while (l < r) {           
		mid = (l + r + 1) >> 1;            
		if (tree.get_min(x, mid) == x) 
			l = mid;
		else
			r = mid - 1;		
	}
	return l;
}

ll l, r;
ll ans;
       
int main() {
	freopen(file"in", "r", stdin);
	freopen(file"out", "w", stdout);

	scanf("%d", &n);
	forn(i, 1, n)
		scanf("%d", &a[i]);
	
	tree.init(n, a);
                
	forn(i, 1, n) {
		l = left_bs(i), r = right_bs(i);       
		cerr<<l<<" "<<r<<"\n";
		ans += (a[i] * 1LL) * ((i - l + 1LL) * (r - i + 1LL));
	}
	
	printf("%I64d", ans);

	return 0;
}