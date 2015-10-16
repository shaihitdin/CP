#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "game."
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef pair <int, int> PII;

const int N = 2e5;
const int P = 31;
const ll B = (1LL << 31) - 1;
const int MpB = 4e6;
const char Fc = 32;

struct HashMap {
	ll t[MpB];

	void insert(ll val) {
		int key = val % MpB;
		while (t[key] && t[key] != val) {
			++key;
			if (key == MpB) key = 0;
		}	
		t[key] = val;
	}

	bool g(ll val) {
		int key = val % MpB;       
		while (t[key] && t[key] != val) {
			++key;
			if (key == MpB) key = 0;
		}	
		return (t[key] == val);
	}
} mp;

ll pw[N];

int n;             
string s[N];

bool is_prime(int x) {
	for (int i = 2; i * i <= x; ++i)
		if (x % i == 0)
			return 0;
	return 1;	
}   

ll h(const ll &hsh, char c) {
	return ((hsh * P) % B + (c - Fc)) % B;
}

int d[MpB], u[MpB];
             
int dp(ll hsh, int len) {
	if (u[hsh]) return d[hsh];
	u[hsh] = 1;
	cerr << hsh << " ";
	forn(c, 33, 126) {
		ll h1 = h(hsh, c);
		if (mp.g(h1) && !dp(h1, len + 1)) 
			return d[hsh] = 1;
		h1 = (((c - Fc) * pw[len]) % B + hsh) % B;
		if (mp.g(h1) && !dp(h1, len + 1)) 
			return d[hsh] = 1;
	}
	cerr << "\n";
	return d[hsh];
}

int main () {
//	#ifdef LOCAL
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);
	freopen ("err", "w", stderr);
//	#endif
	pw[0] = 1;
	forn(i, 1, N - 1)
		pw[i] = (pw[i - 1] * P) % B;
             
	cin >> n;
	forn(i, 1, n) {
		cin >> s[i];
		forn(l, 0, s[i].size() - 1) {
			ll hsh = 0;
			forn(r, l, s[i].size() - 1) {
			    hsh = h(hsh, s[i][r]);          
				mp.insert(hsh);
			}
		}
	}

	vector <char> res;

    forn(i, 33, 126) {                    
       	ll hsh = h(0, char(i));         
    	if (mp.g(hsh) && dp(hsh, 1))
    		res.pb(i);
    }	

    if (res.size()) {
    	cout << "First\n";
    	for (auto c : res)
    		cout << c;
    }    
    else
    	cout << "Second\n";

	return 0;
}