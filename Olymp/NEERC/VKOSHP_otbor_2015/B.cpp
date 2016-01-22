#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "birthday."     
#define F first                       
#define S second 
#define pb push_back   

typedef long long ll; 
typedef pair <int, int> PII;
typedef double ld;
                                                                                          
const int N = 2e6; 
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n;
PII a[N]; 

ostream & operator << (ostream &out, PII x) {
	out << "(" << x.F << " " << x.S << ")";
	return out;
}

int main () {
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);                               

	ios_base :: sync_with_stdio (0);
	cin.tie(0);
                            
    cin >> n;
    forn(i, 1, n)
    	cin >> a[i].F >> a[i].S;
    vector <PII> v(1, PII(0, 0));
    forn(i, 1, n) {
    	int cnt1 = 0, cnt2 = 0;
    	forn(j, 1, n) {
    		if (a[i].F == a[j].F)
    			++cnt1;
    		if (a[i].F == a[j].S)
    			++cnt2;	
    	}
    	if (cnt1 == 1 || cnt2 == 1) continue;
    	v.pb(a[i]);
    }	
                                 
    set <int> st;
    forn(i, 1, v.size() - 1) {
    //    cerr << v[i] << "\n";
    	forn(j, 1, v.size() - 1) {
    		if (v[i].F == v[j].F) continue;
    		if (v[i].S == v[j].S)
    			st.insert(v[i].S);
    	}
    }
                       /*
    for (auto x : st)
    	cerr << x << "\n";
    	             */
    forn(i, 1, v.size() - 1) {
    	if (st.find(v[i].S) == st.end()) {
    		cout << v[i].F << " " << v[i].S << "\n";
    		return 0;
    	}                                                                   
    }

    assert(0);

	return 0;         	
}
   