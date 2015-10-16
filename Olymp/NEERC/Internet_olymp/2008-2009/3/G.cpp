#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "sequence."
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef pair <int, int> PII;

const int N = 2e5;

int x, y, z, w;
int n, k;
vector <int> v;

int main () {
//	#ifdef LOCAL
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);
//	#endif

    cin >> x >> y >> z >> w;
    cin >> n >> k;

	forn(i, 1, n) {
		v.pb(w);
		w = (w * x + y) % z;
	}
	sort(v.begin(), v.end());

	cout << v[k - 1] << "\n"; 
           
	return 0;
}