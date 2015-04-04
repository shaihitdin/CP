#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
#define forn(i, x, n) for(int i = int(x); i <= int(n); ++i) 
#define for1(i, n, x) for(int i = int(n); i >= int(x); --i)
#define file ""
#define USE_MATH_DEFINES
#define mp make_pair 
#define F first
#define S second

typedef long long ll;
typedef pair <int, int> PII;

const int maxn = 300100;
const int INF = 1e9 + 7;
const int max_val = 2e6;
        
struct Gamer {
	int wins;
	int a1, b1, a2, b2;
} G, E;
        
int main() {
//	freopen(file"in", "r", stdin);
//	freopen(file"out", "w", stdout);

	scanf("%d %d %d %d", &G.a1, &G.b1, &G.a2, &G.b2);
	scanf("%d %d %d %d", &E.a1, &E.b1, &E.a2, &E.b2);

	forn(i, G.a1, G.b1) {
		forn(j, G.a2, G.b2) {
			forn(k, E.a1, E.b1) {
				forn(l, E.a2, E.b2) {
					if (i + j > k + l) ++G.wins;
					if (i + j < k + l) ++E.wins;
				}
			}
		}
	}

	printf(G.wins == E.wins ? "Tie" : (G.wins > E.wins ? "Gunnar" : "Emma"));

	return 0;
}