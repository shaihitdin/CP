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

const int N = 7e5;
const int P1 = 107;
const int P2 = 109;
const int B =  1e9 + 7;//(1LL << 31) - 1;
const int MpB = 7e6;
const char Fc = 32;

struct HashMap {
	int t1[MpB], t2[MpB];

	HashMap() {
		forn(i, 0, MpB - 1)
			t1[i] = t2[i] = -1;
	}

	int insert(PII val) {
		int key = val.F % MpB;
		while (t1[key] != -1 && (t1[key] != val.F || t2[key] != val.S)) {
			++key;
			if (key == MpB) key = 0;
		}	
		t1[key] = val.F, t2[key] = val.S;
		return key;
	}

	int g(PII val) {
		int key = val.F % MpB;
		while (t1[key] != -1 && (t1[key] != val.F || t2[key] != val.S)) {
			++key;
			if (key == MpB) key = 0;
		}	
		if (t1[key] == val.F && t2[key] == val.S)
			return key;
		else
			return -1;	                                           
	}
} mp;

ll pw1[N], pw2[N];

int n;             
string s[N];
             
int h1(const ll &hsh, char c) {
	return ((hsh * P1) % B + (c - Fc)) % B;
}

int h2(const ll &hsh, char c) {
	return ((hsh * P2) % B + (c - Fc)) % B;
}

int d[MpB], u[MpB];
vector <char> g[MpB];
int used[256], timer;
             
int dp(PII hsh, int len = 1) {
    ++timer;
	int id = mp.g(hsh);
	if (u[id]) return d[id];
	u[id] = 1, d[id] = 0;              
	for (auto c : g[id]) {
		if (used[c] == timer) continue;
		used[c] = timer;

		int hsh1 = h1(hsh.F, c);                                 
		int hsh2 = h2(hsh.S, c);
		if (mp.g(PII(hsh1, hsh2)) != -1 && !dp(PII(hsh1, hsh2), len + 1)) 
			return d[id] = 1;
		hsh1 = (((c - Fc) * pw1[len]) % B + hsh.F) % B;
		hsh2 = (((c - Fc) * pw2[len]) % B + hsh.S) % B;
		if (mp.g(PII(hsh1, hsh2)) != -1 && !dp(PII(hsh1, hsh2), len + 1)) 
			return d[id] = 1;
	}
	return d[id];
}

main () {
//	#ifdef LOCAL
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);
	freopen ("err", "w", stderr);
//	#endif
	pw1[0] = 1;
	forn(i, 1, N - 1)                
		pw1[i] = (pw1[i - 1] * P1) % B;
	pw2[0] = 1;
	forn(i, 1, N - 1)                
		pw2[i] = (pw2[i - 1] * P2) % B; 
             
	cin >> n;
	forn(i, 1, n) {
		cin >> s[i];
		forn(l, 0, s[i].size() - 1) {
			int hsh1 = 0, hsh2 = 0;
			forn(r, l, s[i].size() - 1) {
			    hsh1 = h1(hsh1, s[i][r]);
				hsh2 = h2(hsh2, s[i][r]);
				int id = mp.insert(PII(hsh1, hsh2));
				if (l > 0)
					g[id].pb(s[i][l - 1]);
				if (r < s[i].size() - 1)
					g[id].pb(s[i][r + 1]);
				if (l == 0 && r == s[i].size() - 1) 
					u[id] = 1, d[id] = 1;	
			}
		}
	}

	vector <char> res;

    forn(i, 33, 126) {                    
       	ll hsh1 = h1(0, char(i));         
       	ll hsh2 = h2(0, char(i)); 
    	if (mp.g(PII(hsh1, hsh2)) != -1 && !dp(PII(hsh1, hsh2)))
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
