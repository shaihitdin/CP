#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "luigi."     
#define F first
#define S second
#define pb push_back   
#define _bits __builtin_popcount

typedef long long ll; 
typedef pair <int, int> PII;
                                                                               
const int N = 3e5;                                                                                              
const int INF = 1e9 + 9;  
const int B = 1e9 + 7;

int a, b, c, d, k;

int main () {
#ifndef machine42
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout); 
#endif	
	ios_base :: sync_with_stdio (0);                                                                                           
	cin.tie(0); 

	cin >> a >> b >> c >> d >> k;
	if (a < b) swap(a, b);
	if (c < d) swap(c, d);

	int need = ((a % k) + (c % k)) % k;
	if (need > (a - b) + (c - d)) {
		cout << -1 << "\n";
		return 0;
	}

	int k = min(a - b, need);
	cout << a - k << " ";
	need -= k;

	k = min(c - d, need);
	cout << c - k << "\n";

    return 0;         	
}