#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "josephus."

typedef long long ll;

const int N = 100;

int n;

ll f(int x) {
	if (x == 1) return 1;
	ll prv = f((x + 1) / 2);                              
	if (x % 2 == 0)
		return prv * 2 - 1;
	else
		return (prv == 1 ? ((x + 1) / 2) : prv - 1) * 2 - 1;	
}
                                        	 
int main () {
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
                                       
    cin >> n;
    cout << f(n);

	return 0;         	
}