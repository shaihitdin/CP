#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "mushrooms."
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef pair <int, int> PII;

const int N = 2e6;
const int INF = 1e9 + 9;               
                         
int a[20];
int b[20][20], res[20];

void NO() {
	cout << "NO\n";
	exit(0);
}

int main () {
//	#ifdef LOCAL
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);
//	#endif

	ios_base :: sync_with_stdio(0);
	cin.tie(0);

	int sum = 0;
    forn(i, 1, 10) {
    	cin >> a[i];
    	sum += a[i];
    }	
    if (sum % 4 != 0)
    	NO();       
    sum /= 4;

    int ptr = 0;
    forn(i, 1, 5)
    	forn(j, i + 1, 5)
    		b[i][j] = b[j][i] = a[++ptr];

    forn(i, 1, 5) {
    	int x = 0;
    	forn(j, 1, 5)
    		x += b[i][j];
    	if (x < sum || (x - sum) % 3 != 0) 
    		NO();
    	res[i] = (x - sum) / 3;
    }

    int x = 0;
    forn(i, 1, 5)
    	x += res[i];
    if (x != sum) NO();
    cout << "YES\n";	

	return 0;
}
