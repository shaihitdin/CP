#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "circles2."

typedef long long ll;

const int N = 100;

int n;
int a[100] = {	1, 2, 4, 8, 14, 24, 40, 64, 100, 154, 232, 344, 504, 728, 1040, 1472, 2062, 2864, 3948, 5400, 7336, 9904, 13288, 17728, 23528, 31066, 40824, 53408, 69568, 90248, 116624, 150144, 192612, 246256, 313808, 398640, 504886, 637592, 802936, 1008448};
                                        	 
int main () {
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
                                       
    cin >> n;
    assert(n <= 39);
    cout << a[n] << "\n";

	return 0;         	
}