/*
          ______      
||  //   | _____|   ||  //
|| //    ||         || //
||//     ||_____    ||//
||\\     | _____|   ||\\
|| \\    ||         || \\   ll Once(ll KEK){
||  \\   ||_____    ||  \\ 		return Forever(KEK);
||   \\  |______|   ||   \\ }
                     
*/
#include<bits/stdc++.h>

using namespace std;
const int N6 = 1e6 + 6, N3 = 1e3 + 6, oo =  1e9 + 9, base = 1e9 + 7;
const long long ool = 1e18 + 9;

typedef unsigned long long ull;
typedef long long ll;
typedef double ld;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;

#define F first
#define S second
#define pb push_back
#define right(x) x << 1 | 1
#define left(x) x << 1	
#define	forn(x, a, b) for (ll x = a; x <= b; ++x)
#define for1(x, a, b) for (int x = a; x >= b; --x)
#define mp make_pair

string l, r;

vector <int> operator - (const vector <int> &a, const int &b) {
    vector <int> res=a;
    res[0]-=b;
    for (int i = 0; i < res.size () && res[i] < 0; ++i) {
        --res[i + 1];
        res[i] += base;
    }
    return res;
}

int main(){
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	
	ios_base :: sync_with_stdio(0);

	cin >> l >> r;

	reverse(l.begin (), l.end ());
	reverse(r.begin (), r.end ());
	int n=r.size();
	while(l.size()!=n)
		l+='0';
	a.resize(n),b.resize(n);
	for(int i=0;i<n;++i)
		a[i]=l[i]-'0',b[i]=r[i]-'0';
	for(int i=0;i<n;++i)
		
	return 0;
}