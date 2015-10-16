#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "discuss."
#define pb push_back
#define F first
#define S second
#define sz(a) int(a.size())
 
typedef long long ll;
typedef pair <int, int> PII;
typedef vector <int> bi;

const int N = 2e5;
const int INF = 1e9 + 9;
const int B = 10;
               
bi operator + (const bi &a, const bi &b) {
    bi res(max(sz(a), sz(b)) + 1, 0);
   	forn (i, 0, sz(res) - 1)
		res[i] = (i < sz(a) ? a[i] : 0) + (i < sz(b) ? b[i] : 0);
	int carry = 0;
	forn (i, 0, sz(res) - 1) {
		res[i] += carry;
		carry = res[i] / B;
		res[i] %= B;
	}                        
	if (!res.back()) res.pop_back();
	return res;
}

ostream & operator << (ostream &out, bi x) {
	for1(i, sz(x) - 1, 0)
		out << x[i];
	return out;	
}

bool lss(const bi &a, const bi &b) {
	if (sz(a) != sz(b)) 
		return sz(a) < sz(b);
	forn (i, 0, sz(a) - 1)
		if (a[i] != b[i])
			return a[i] < b[i];
	return 0;	
}

string s;
bi z, q, t[2][N];

int main () {
//	#ifdef LOCAL
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);
//	#endif
	cin >> s;
	for1(i, sz(s) - 1, 0)
		z.pb(s[i] - '0');

	t[0][0].pb(1);
	t[1][0].pb(1);
	int r = INF;
	forn(i, 1, 10000000) {
		int x = i & 1; 
		forn(j, 1, min(i, r)) {
			t[x][j] = t[x ^ 1][j - 1] + t[x ^ 1][j];	
			if (z == t[x][j]) {
				cout << i << "\n";
				return 0;
			}
			if (lss(z, t[x][j])) {
				r = min(r, j);
				break;
			}
		}
	}

	cout << s << "\n";         

	return 0;
}