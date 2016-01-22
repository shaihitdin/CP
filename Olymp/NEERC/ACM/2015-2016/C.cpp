#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "concatenation."     
#define F first                       
#define S second 
#define pb push_back   

typedef long long ll; 
typedef pair <int, int> PII;
typedef double ld;
                                                                                          
const int N = 8e5; 
const int INF = 1e9 + 9;
const int B = 1e9 + 7;
const int alph = 150;

struct SufArray {
	int p1[N], p2[N];
	int cl_eq1[N], cl_eq2[N];
	int cnt[N], l[N], classes;

	void clear(int n) {
		classes = 0;
		forn(i, 0, max(alph, n)) {
			p1[i] = p2[i] = l[i] = 0;
			cl_eq1[i] = cl_eq2[i] = cnt[i] = 0;
		}	                               
	}

	void build(string s) {
		///preproc
		clear(N - 1);
		s.pb(0);           
	    int n = s.size();                    
		forn(i, 0, n - 1)
			cl_eq1[i] = s[i], p1[i] = i;                                 
		///building the array                             
		for (int k1 = 1; (k1 >> 1) < n; k1 <<= 1) {
			int k = (k1 >> 1);
			///count sort
			forn(i, 0, max(alph, classes)) 
				cnt[i] = 0;
			forn(i, 0, n - 1) 
				++cnt[cl_eq1[i] + 1];
			forn(i, 1, max(alph, classes)) 
				cnt[i] += cnt[i - 1];
			forn(i, 0, n - 1) {
				int shift = (p1[i] - k + n) % n;
				p2[cnt[cl_eq1[shift]]++] = shift;
			}
			///calculating cl_eq2
			classes = 0;
			cl_eq2[p2[0]] = 0;
			forn(i, 1, n - 1) {
				classes += (cl_eq1[p2[i]] != cl_eq1[p2[i - 1]]                                                      
							|| cl_eq1[(p2[i] + k) % n] != cl_eq1[(p2[i - 1] + k) % n]);
				cl_eq2[p2[i]] = classes;
			}
			forn(i, 0, n - 1)
				p1[i] = p2[i], cl_eq1[i] = cl_eq2[i];    
		}	         
		forn(i, 0, n - 1)
			p2[p1[i]] = i;   
		///calculating LCP
		int lcp = 0;       
		forn(i, 0, n - 1) {
			int cur = p2[i];      
			if (cur == n - 1) continue;
			while (lcp < n && s[(p1[cur] + lcp)] == s[(p1[cur + 1] + lcp)])
				++lcp;
			l[cur] = lcp;
			lcp = max(lcp - 1, 0);
		}                                     
	}

	SufArray (string s) { 
		build(s);
	}
};

int st[N], sz;
int l[N], r[N];     
int lcp[N];

ll solve(string s) {
	int n = s.size();
	SufArray sa(s);
	forn(i, 1, n - 1)
		lcp[i] = sa.l[i];
			
	sz = 0;
	st[0] = 0;
	forn(i, 1, n - 1) {
		while (sz && lcp[st[sz]] >= lcp[i]) --sz;
		l[i] = st[sz] + 1;
		st[++sz] = i;
	}
	sz = 0;
	st[0] = n;        
	for1(i, n - 1, 1) {
		while (sz && lcp[st[sz]] > lcp[i]) --sz;
		r[i] = st[sz] - 1;
		st[++sz] = i;
	}                            

	ll ans = 0;
	forn(i, 1, n - 1)            
		ans += 1ll * lcp[i] * (r[i] - l[i] + 1);
	return ans;
}

int main () {
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);                               

	ios_base :: sync_with_stdio (0);
	cin.tie(0);

	string s, t, mrg;
	cin >> s;
	cin >> t;                             
	ll n = s.size(), m = t.size();
	s = s.substr(1);
	t.pop_back();
	string q;                             
	q.pb('z' + 1);
	mrg = s + q + t;	            	
	ll same = solve(mrg) - solve(s) - solve(t);
	cout << n * m - same << "\n";       

	return 0;         	
}
   