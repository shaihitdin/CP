#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "easy."     
#define F first                       
#define S second 
#define pb push_back   

typedef long long ll; 
typedef pair <int, int> PII;
typedef double ld;
                                                                                          
const int N = 300; 
const int INF = 1e9 + 9;
const int B = 1e9 + 7;             

int main () {
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);                               

	ios_base :: sync_with_stdio (0);
	cin.tie(0);

	string s, t;
	if ('0' <= cin.peek() && cin.peek() <= '9')
		s.pb('+'); 
	cin >> t;
	s = s + t;

	forn(i, 0, s.size() - 1) {
		if (s[i] == '+') {
			while (i < s.size() - 1 && '0' <= s[i + 1] && s[i + 1] <= '9')
			    putchar(s[i++]); 
			putchar(s[i]);
			continue;
		}
		else {
			putchar(s[i]);
			putchar(s[i + 1]);
			i += 2;
			while (i < s.size() && s[i] == '0') {
				putchar('+');
				putchar(s[i++]);
			}	                
			if ('0' <= s[i] && s[i] <= '9') {
				putchar('+');
				while (i < s.size() && '0' <= s[i] && s[i] <= '9')
					putchar(s[i++]);
			}
			--i;
		}	
	}

	return 0;         	
}
   