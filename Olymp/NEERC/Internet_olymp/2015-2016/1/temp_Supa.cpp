#include <bits/stdc++.h>

using namespace std;

	#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "contest."     
#define F first
#define S second
#define pb push_back   
#define _bits __builtin_popcount

typedef long long ll; 
typedef unsigned long long ull;
typedef pair <int, int> PII;
                                                                               
const int N = 3e5;                                                                                              
const int INF = 1e9 + 9;  
const int B = 1e9 + 7;

int n, k;
int a[N];                    

int rate() {
	int ans = 0;
	forn(i, 1, n)
		ans += a[i] / 10;
	return ans;	
}

int main () {
#ifdef machine42
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout); 
#endif	
	ios_base :: sync_with_stdio (0);                                                                                           
	cin.tie(0); 

	set <PII> st;

	cin >> n >> k;
	forn(i, 1, n) {
		cin >> a[i];                             
		st.insert(PII((10 - (a[i] % 10)) % 10, i));
	}	
                           
	for (auto x : st) {    
		if (k < x.F) {
			cout << rate() << "\n";
			return 0;
		}
		k -= x.F;
		a[x.S] += x.F;
	}

	int ans = rate() + (k / 10);
	cout << min(ans, n * 10) << "\n";

    return 0;         	
}