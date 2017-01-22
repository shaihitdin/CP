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
#define mk_pr make_pair
#define _bits __builtin_popcount                                                                                                          

typedef long long ll;                           
typedef long double ld;
typedef pair <int, int> PII;    

const int maxn = 300100;                
const int INF = 1e9 + 9;  

int n, m, t;
int a[maxn];

int ans, link[maxn];
int color[maxn];

int find_root(const int &i) {
	return link[i] == i ? i : link[i] = find_root(link[i]);
}

void prepare_answer() {      
    int cnt = 0;
    forn(i, 1, n)
    	find_root(i);
    forn(i, 1, n)
    	if (link[i] == i)
    		color[i] = ++cnt;
    forn(i, 1, n)
    	color[i] = color[link[i]];
	assert(cnt == ans);
}   
              
int time2sec(const int &hr, const int &mn, const int &sec) {
	return 24 * hr + 60 * mn + sec;
}

int min_l, max_r;
vector <int> starts[maxn];  

void ScanLine() {
	ans = n;
	bool eql_m = 0;
	set <PII> st;
	forn(i, 1, n) 
		link[i] = i;
	forn(i, min_l, max_r) {
		while (st.begin() -> F < i && st.size())
			st.erase(st.begin());	
		while (starts[i].size()) {
			st.insert(PII(i + t, starts[i].back()));
		    starts[i].pop_back();
		}                                    

		if (!st.size()) continue;

		if (st.size() >= m) eql_m = 1;
		PII rightest = *st.rbegin();
		st.erase(st.find(*st.rbegin()));
		                  
		while (st.size() > m - 1) {
			--ans;
			int cur = st.rbegin() -> S;
			link[cur] = rightest.S;
			st.erase(st.find(*st.rbegin()));
		}	
		                   
		st.insert(rightest);	
	}

	if (!eql_m) {
		printf("No solution\n");
		exit(0);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen(file"in", "r", stdin);
	freopen(file"out", "w", stdout);                          
#endif
	min_l = INF, max_r = -INF;
	scanf("%d %d %d", &n, &m, &t);
	forn(i, 1, n) {
		int hr = 0, mn = 0, sec = 0;
		scanf("%d:%d:%d", &hr, &mn, &sec);
		a[i] = time2sec(hr, mn, sec);
		starts[a[i]].pb(i);
		min_l = min(min_l, a[i]);
		max_r = max(max_r, a[i] + t);
	}

    ScanLine();      
    prepare_answer();
                    
    printf("%d\n", ans);
    forn(i, 1, n)
    	printf("%d\n", color[i]);

    return 0;                                   
}   