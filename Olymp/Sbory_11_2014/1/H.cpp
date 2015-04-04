#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
using namespace std;
#define forn(i, x, n) for(int i = int(x); i <= int(n); ++i) 
#define for1(i, n, x) for(int i = int(n); i >= int(x); --i)
#define file ""            
#define mp make_pair 
#define F first
#define S second

typedef long long ll;
typedef pair <int, int> PII;

double CURRENT_TIME() {
	return double(clock()) / double(CLOCKS_PER_SEC);
}

const int maxn = 300100;
const int INF = 1e9 + 7;     
const int base = 360000;

int n;
int clock1[maxn], clock2[maxn];
int a[maxn], b[maxn];
int s[maxn * 3], z[maxn * 3], sz;

bool digit(char &ch) {
	return ('0' <= ch && ch <= '9');
}

void read_int (int &x) {
	x = 0;
	char ch = 0;
	for(;;) {
		ch = getchar();
		if (!digit(ch)) break;
		x = x * 10 + (ch - '0');
	}     
}
    
int main() {
//	freopen(file"in", "r", stdin);
//	freopen(file"out", "w", stdout);

//	scanf("%d", &n);
    read_int(n);               
	forn(i, 1, n)              
		//scanf("%d", &clock1[i]);  
 		read_int(clock1[i]);         
 	forn(i, 1, n)               
		//scanf("%d", &clock2[i]); 
		read_int(clock2[i]);       

	sort(clock1 + 1, clock1 + 1 + n);        
	forn(i, 1, n - 1)
		a[i] = clock1[i + 1] - clock1[i];
	a[n] = clock1[1]  + base - clock1[n];
	
	sort(clock2 + 1, clock2 + 1 + n);
	forn(i, 1, n - 1)
		b[i] = clock2[i + 1] - clock2[i];
	b[n] = clock2[1]  + base - clock2[n];	
    
               
	forn(i, 1, n) 	
		s[sz++] = a[i];
	s[sz++] = -1;
	forn(i, 1, n)
		s[sz++] = b[i];
	forn(i, 1, n)
		s[sz++] = b[i];
	     
	int l = -1, r = - 1;
	forn(i, 1, sz - 1) {             
		if (i < r) z[i] = min (z[i - l], r - i + 1);
		while (i + z[i] < sz && s[z[i]] == s[i + z[i]]) ++z[i];
		if (i + z[i] - 1 > r)
			l = i, r = i + z[i] - 1;
		if (i > n && z[i] == n) {
			printf("possible");
			return 0;
		}
	}                                              
	
	printf("impossible");

	return 0;
}