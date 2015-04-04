#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <map> 
#include <time.h>
#include <assert.h>     
using namespace std;
#define forn(i, x, n) for(int i = int(x); i <= int(n); ++i) 
#define for1(i, n, x) for(int i = int(n); i >= int(x); --i)
#define file "tricks."
#define FastMin(a, b) (a < b ? a : b)
#define mp make_pair 
#define F first
#define S second

typedef long long ll;
typedef pair <int, int> PII;

const int maxn = 300100;
const int INF = 1e9 + 7;
                         
int divs[maxn], sz;          

void factorize(ll x) {
	sz = 0;
	for (ll i = 2; i * i <= x; ++i) {
		while (x % i == 0) {
			divs[++sz] = i, x /= i;
		}
	}
	if (x > 1) divs[++sz] = x;
}

int tests_num;
ll base, n;

ll solve() {
	factorize(base);
	base = divs[sz];
	ll round = base, st = 1;
	for(;round <= n; round *= base) ++st;
	round /= base, --st;
	ll ans = 0, used = 0;
	while (round > 1) {
		ll divs = n / round;
		ans += (divs - used) * st;	                                  
		--st, used = divs, round /= base;
	}	
	return ans;
}

ll ans;
       
int main() {
	freopen(file"in", "r", stdin);
	freopen(file"out", "w", stdout);

	scanf("%d", &tests_num);
	forn(_, 1, tests_num) {
	    printf("Scenario #%d:\n", _);
		scanf("%I64d %I64d", &base, &n);
		ans = solve();
		printf("%I64d\n\n", ans);
	}
	
	return 0;
}