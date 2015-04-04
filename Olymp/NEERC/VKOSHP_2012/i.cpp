#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;
#define forn(i, x, n) for(int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for(int i = int(n); i >= int(x); --i)
#define file "python."

typedef long long ll;

const int maxn = 128;
const int INF = 2e9 + 7;

int a, b;

int main() {
    freopen(file"in", "r", stdin);
    freopen(file"out", "w", stdout);                                                               

    scanf("%d %d", &a, &b);
    if(a < b){
    	printf("0\n0");
    	return 0;
    }
    printf("%d\n%d", (a) / (b + 1), a / b);

}
