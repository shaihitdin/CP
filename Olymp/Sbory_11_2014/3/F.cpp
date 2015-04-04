#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <set> 
#include <map>
#include <time.h>
#include <assert.h>     
using namespace std;
#define forn(i, x, n) for(int i = int(x); i <= int(n); ++i) 
#define for1(i, n, x) for(int i = int(n); i >= int(x); --i)
#define FastMin(a, b) (a < b ? a : b)
#define mp make_pair 
#define F first
#define S second

typedef long long ll;
typedef pair <int, int> PII;

const int maxn = 1024;
const double eps = 0.00001;
const int INF = 1e9 + 7;
               
int n;
double probability;
int d[maxn][maxn];

map <int, int> cnt;
map <int, int> :: iterator it;    

void Floyd() {
	forn(k, 1, n)
		forn(i, 1, n)
			forn(j, 1, n)                   
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	forn(i, 1, n)
		forn(j, 1, n)            
			if (d[i][j] < INF && i != j)
				++cnt[d[i][j]];                                       
}                                                                     

double calc_probability(double x) {
	return x / double(n * (n - 1));
}

bool eql(double a, double b) {
	return fabs(a - b) < eps;
}

bool grter(double a, double b) {
	return a - b > eps;
}

int Calc() {
	Floyd();                                    
	int ans = 0;
	double cur = 0;
	for (it = cnt.begin(); it != cnt.end(); ++it) {
		cur += calc_probability(it -> second);
		if (eql(cur, probability) || grter(cur, probability)) 
			return it -> first;         
    }                      
}

int ans;
int tests_num;

int main() {
	freopen("military.in", "r", stdin);
	freopen("military.out", "w", stdout);

	scanf("%d", &tests_num);
	forn(_, 1, tests_num) {
	    printf("Scenario #%d:\n", _);
		cin >> probability;
		probability /= 100;     
		scanf("%d", &n);
		forn(i, 1, n) {
			forn(j, 1, n) {
				scanf("%d", &d[i][j]);
				if (d[i][j] == -1) d[i][j] = INF;
			}
		}			
		ans = Calc();
		printf("%d\n\n", ans);
		cnt.clear();
		memset(d,0,sizeof(d));
	}
	
	return 0;
}