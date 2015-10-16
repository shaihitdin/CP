#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "twoarcs."
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef pair <int, int> PII;

const int N = 2e5;

PII s1, s2, s3, s4;

bool int1(const PII &a, const PII &b) {
	return (b.F <= a.F && a.F <= b.S) || (b.F <= a.S && a.S <= b.S);
}

bool inter(const PII &a, const PII &b) {
	return int1(a, b) || int1(b, a);
}             

int main () {
//	#ifdef LOCAL
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);
//	#endif
           
    cin >> s1.F >> s1.S;
    cin >> s2.F >> s2.S;

    if (s1.S < s1.F) {
    	s3 = PII(0, s1.S);                  
    	s1 = PII(s1.F, 359);
    }
    else
    	s3 = PII(500, 500);

    if (s2.S < s2.F) {
    	s4 = PII(0, s2.S);
    	s2 = PII(s2.F, 359);
    }
    else
    	s4 = PII(1000, 1000);

    if (inter(s1, s2) || inter(s1, s4) || inter(s3, s2) || inter(s3, s4))
    	cout << "YES\n";
    else
    	cout << "NO\n";	

	return 0;
}