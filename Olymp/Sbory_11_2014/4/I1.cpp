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
#define file "relocation."
#define FastMin(a, b) (a < b ? a : b)
#define mp make_pair 
#define F first
#define S second

typedef long long ll;
typedef pair <short, short> PII;

const short maxn = 42;
const short INF = 42;

short tests_num;
short c1, c2, n;
short a[maxn], id[maxn];

short solve() { 
	short pos = 1;
	short w1 = 0, w2 = 0, ans = 0;
	while (pos <= n) {
		++ans, w1 = 0, w2 = 0;                       
		while (pos <= n && w1 + a[id[pos]] <= c1)
			w1 += a[id[pos++]];
		while (pos <= n && w2 + a[id[pos]] <= c2)
			w2 += a[id[pos++]];       
	}
	return ans;
}

bool digit(char &ch) {
	return ('0' <= ch && ch <= '9');
}

void read_int (short &x) {
	x = 0;
	char ch = 0;
	for(;;) {
		ch = getchar();
		if (!digit(ch)) break;
		x = x * 10 + (ch - '0');
	}     
}

short ans;                   

int main() {
	freopen(file"in", "r", stdin);
	freopen(file"out", "w", stdout);

//	scanf("%d", &tests_num);
    read_int(tests_num);
	forn(_, 1, tests_num) {                    
	    printf("Scenario #%d:\n", _);
//		scanf("%d %d %d", &n, &c1, &c2);
        read_int(n), read_int(c1), read_int(c2);
		forn(i, 1, n) {
			//scanf("%d", &a[i]);
			read_int(a[i]);
			id[i] = i;
		}	
		ans = INF;
		for (;;) {
			ans = FastMin(ans, solve());
			if (!next_permutation(id + 1, id + 1 + n))
				break;
		} 
		printf("%d\n\n", ans);
	}
	
	return 0;
}