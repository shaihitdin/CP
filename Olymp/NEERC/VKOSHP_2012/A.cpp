#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
using namespace std;
#define forn(i, x, n) for(int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for(int i = int(n); i >= int(x); --i)
#define file "billboard."

typedef long long ll;

const int maxn = 128;
const int INF = 2e9 + 7;

int n, m, k;

set < vector <char> > st;
vector <char> a[maxn][maxn];

char c;

int main() {
    freopen(file"in", "r", stdin);
    freopen(file"out", "w", stdout);

    scanf("%d %d %d\n", &k, &n, &m);
    forn(q, 1, k) {
    	forn(i, 1, n) {
    		forn(j, 1, m) {
    			c = getchar();
    			a[i][j].push_back(c);// = (c == '*');
    		}     
    		getchar();	
    	}         
    }

    forn(i, 1, n)
    	forn(j, 1, m)
    		st.insert(a[i][j]);
    		        
    printf("%d", st.size());
                       
    return 0;
}
