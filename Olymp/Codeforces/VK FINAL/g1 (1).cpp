#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <bitset>
#include <set>
#include <map>
#include <assert.h>
#include <math.h>
#include <vector>
#include <time.h>
#include <queue>

using namespace std;

#define forn(i, x, n) for(int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for(int i = int(n); i >= int(x); --i)
#define file ""
#define pb push_back
#define F first
#define S second               
#define _bits __builtin_popcount                                                                                                          

typedef long long ll;         
typedef pair <int, int> PII;    
typedef const int c_i;

const int maxn = 2e6;                                    
const int INF = 1e9 + 9;

int n, m;
int s1, s2;
PII a[maxn], b[maxn];
int amaxs[maxn], bmaxs[maxn];
int x[maxn];

void MAX() { 
	printf("Max\n");
	exit(0);
}

void MIN() {
	printf("Min\n");
	exit(0);
}

int main() {
#ifdef machine42
	freopen(file"in", "r", stdin);
	freopen(file"out", "w", stdout);                     
#endif
	scanf("%d %d", &n, &m);
	scanf("%d %d", &s1, &s2);
	///s1, s2 - not used
	forn(i, 1, n)
		scanf("%d %d", &a[i].F, &a[i].S);
	forn(i, 1, m)
		scanf("%d %d", &b[i].F, &b[i].S);

	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + m);

	for1(i, n, 1)
		amaxs[i] = max(a[i].S, amaxs[i + 1]);
	for1(i, m, 1)
		bmaxs[i] = max(b[i].S, bmaxs[i + 1]);
	
	bool f1 = 0, f2 = 0;
	forn(i, 1, m) {
		if (b[i].F > a[n].F) f1 = 1;
		if (b[i].S > amaxs[1]) f2 = 1;                      	
	}

	if (f1 && f2) MIN();
	else MAX();
    
    return 0;                                   
}                                          	
