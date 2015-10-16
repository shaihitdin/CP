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

int n, s;
int a[N];
map <int, int> mp;

int main () {        
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout); 

	ios_base :: sync_with_stdio (0);                                                                                           
	cin.tie(0); 

	cin >> n >> s;
	forn(i, 1, n) {
		int tp, c;
		cin >> tp >> c;
		if (mp.count(tp) == 0)
			mp[tp] = c;
		else
			mp[tp] = min(mp[tp], c);	
	}

	n = 0;
	for (auto x : mp)
		a[++n] = x.S;

	sort(a + 1, a + 1 + n);
	int bought = 0;
	forn(i, 1, n) {
		if (bought + a[i] > s) {
			cout << i - 1 << "\n";
			return 0;
		}
		bought += a[i];	
	}
	cout << n << "\n";

    return 0;         	
}