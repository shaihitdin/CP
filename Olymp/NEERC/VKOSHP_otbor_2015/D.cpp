#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "delivery."     
#define F first                       
#define S second 
#define pb push_back   

typedef long long ll; 
typedef pair <int, int> PII;
typedef double ld;
                                                                                          
const int N = 2e6; 
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n, k, t;
int a[N], s[N];

int main () {
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);                               

	ios_base :: sync_with_stdio (0);
	cin.tie(0);

    cin >> n >> k >> t;
    forn(i, 1, n)
    	cin >> a[i];
   	forn(i, 1, n)
   		cin >> s[i];    

   	ll cur = 0;
   	forn(i, 1, n) {
   		cur += a[i];
   		if (cur + k < s[i])
   			cur += k;
   		else
   			cur += max(0ll, s[i] - cur) + t;	
   	}

   	cout << cur << "\n";

	return 0;         	
}
   