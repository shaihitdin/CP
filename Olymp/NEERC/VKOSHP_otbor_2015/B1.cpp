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
                          
    vector <PII> v(1, PII(0, 0));
    vector <PII> w(1, PII(0, 0));
         
    cin >> n;
    forn(i, 1, n)
    	cin >> a[i].F >> a[i].S;
    forn(i, 1, n) {
    	int cnt1 = 0;
    	forn(j, 1, n) 
    		if (a[i].F == a[j].F) ++cnt1;	
    	if (cnt1 == 1) continue;
    	v.pb(a[i]);
    }	


    set <int> st;       
    set <int> banned_days;       
    forn(i, 1, n) {
    	forn(j, 1, n) {
    		if (i == j) continue;
    		if (a[i].S == a[j].S)
    			st.insert(a[i].S);
    	}
    }
    forn(i, 1, v.size() - 1) {
    	if (st.find(v[i].S) == st.end())
    		banned_days.insert(v[i].F);
    }
    forn(i, 1, v.size() - 1) {
       	if (banned_days.find(v[i].F) == banned_days.end()) {
    		w.pb(v[i]);
    	}	
    }

             
    st.clear();       
    forn(i, 1, w.size() - 1) {
    	forn(j, 1, w.size() - 1) {
    		if (i == j) continue;
    		if (w[i].F == w[j].F)
    			st.insert(w[i].F);
    	}
    	cerr << w[i] << "\n";
    }      
 	vector <PII> preans, ans;
    forn(i, 1, w.size() - 1) {
    	if (st.find(w[i].F) == st.end())
    		preans.pb(w[i]);                                                                                 
    }
    forn(i, 1, preans.size() - 1) {
        cerr << preans[i] << "\n";
    	int cnt2 = 0;
    	forn(j, 1, preans.size() - 1)
    		if (preans[i].S == preans[j].S) ++cnt2; 	
    	if (cnt2 == 1) ans.pb(preans[i]);
    }

    assert(ans.size() <= 1);
    cout << ans[0].F << " " << ans[0].S << "\n";
    //assert(0);

	return 0;         	
}
   