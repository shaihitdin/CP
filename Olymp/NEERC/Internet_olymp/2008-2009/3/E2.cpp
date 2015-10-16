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
const int P = 101;
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
ll sh[N];

bool is_prime(int x) {
	for (int i = 2; i * i <= x; ++i)
		if (x % i == 0)
			return 0;
	return 1;	
}   

ll h(const ll &hsh, char c) {
	return ((hsh * P) % B + (c - Fc)) % B;
}

map <int, int> d;
             
int dp(int hsh, int len, string rep = "") {
	if (d.count(hsh)) return d[hsh];
	cerr << hsh  << " " << len << " " << rep << "\n";
	d[hsh] = 0;            
	forn(i, 1, n)
		if (hsh == sh[i] && len == s[i].size()) { //cerr << i << "\n";
			return 1;                            }
	forn(c, 33, 126) {
		ll h1 = h(hsh, c);                                 
		if (mp.g(h1) && !dp(h1, len + 1, rep + char(c))) {
	cerr << hsh  << " " << len << " " << rep << " " << 1 << "\n";
			return d[hsh] = 1;                          }
		h1 = (((c - Fc) * pw[len]) % B + hsh) % B;
		if (mp.g(h1) && !dp(h1, len + 1, char(c) + rep)) {
	cerr << hsh  << " " << len << " " << rep << " " << 1 << "\n";
			return d[hsh] = 1;                           }
	}
	cerr << hsh  << " " << len << " " << rep << " " << d[hsh] << "\n";
	return d[hsh];
}

int main () {
//	#ifdef LOCAL
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);
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
	//		  	cerr << i << " " << l << " " << r << " - " << hsh << "\n";       
				mp.insert(hsh);
				if (l == 0 && r == s[i].size() - 1)
					sh[i] = hsh;
			}
		}
	}

	vector <char> res;

    forn(i, 33, 126) {                    
       	ll hsh = h(0, char(i));         
        if (i == 'h')
      		cerr << dp(hsh, 1, "h") << "\n";
    //    string t;
    //    t.pb(i);
    //	if (mp.g(hsh) && !dp(hsh, 1, t))
    //		res.pb(i);
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