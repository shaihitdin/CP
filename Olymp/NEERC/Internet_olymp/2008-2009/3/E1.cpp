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

#define int ll

const int N = 7e5;
const int P = 131;
const int B =  1e9 + 7;//(1LL << 31) - 1;
const int MpB = 7e6;
const char Fc = 32;

struct HashMap {
	ll t[MpB];

	HashMap() {
		forn(i, 0, MpB - 1)
			t[i] = -1;
	}

	void insert(ll val) {
		int key = val % MpB;
		while (t[key] != -1 && t[key] != val) {
			++key;
			if (key == MpB) key = 0;
		}	
		t[key] = val;
	}

	bool g(ll val) {
		int key = val % MpB;       
		while (t[key] != -1 && t[key] != val) {
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
             
ll h(const ll &hsh, char c) {
	return ((hsh * P) % B + (c - Fc)) % B;
}

map <int, int> d;
             
int dp(int hsh, int len/*, string rep = ""*/) {
	if (d.count(hsh)) return d[hsh];
	//cerr << hsh  << " " << len << " " << rep << "\n";
	d[hsh] = 0;            
	forn(i, 1, n)
		if (hsh == sh[i] && len == s[i].size()) {// cerr << i << "\n";
			return d[hsh] = 1;                            }
	//cerr << hsh  << " " << len << " " << rep << "\n";
	forn(c, 33, 126) {
		ll h1 = h(hsh, c);                                 
		if (mp.g(h1) && !dp(h1, len + 1/*, rep + char(c)*/)) 
			return d[hsh] = 1;
		h1 = (((c - Fc) * pw[len]) % B + hsh) % B;
		if (mp.g(h1) && !dp(h1, len + 1/*, char(c) + rep*/)) 
			return d[hsh] = 1;
	}
	return d[hsh];
}

main () {
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
    //    if (i == 'b')
    //  	cerr << dp(hsh, 1, "b") << "\n";
    	if (mp.g(hsh) && !dp(hsh, 1))
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
