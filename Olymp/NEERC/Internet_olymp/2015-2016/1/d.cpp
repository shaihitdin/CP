#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "knumbers."     
#define F first
#define S second
#define pb push_back   
#define _bits __builtin_popcount

typedef long long ll; 
typedef pair <int, int> PII;
                                                                               
const int N = 2e6;                                                                                              
const int INF = 1e9 + 9;  
const int B = 1e9 + 7;

int r;
char t[N];
int s[N];
int cnt[10];

int main () {
#ifndef machine42
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout); 
#endif	
	ios_base :: sync_with_stdio (0);                                                                                           
	cin.tie(0); 

	cin >> r;
	cin >> t;
	int n = strlen(t);
	for1(i, n, 1)
		s[i] = t[i - 1] - '0';

	int dif = 0;
	forn(i, 1, n) {
		if (!cnt[s[i]])
			++dif;
		cnt[s[i]]++;
	}

	if (dif <= r) {
		forn(i, 1, n)
			cout << s[i];
		cout << "\n";
		return 0;	
	}

	for1(i, n - 1, 0) {
	    --cnt[s[i + 1]];
		if (!cnt[s[i + 1]]) --dif;
		if (dif > r || s[i + 1] == 9) continue;

		cerr << i << "\n";
		if (dif == r) {       
			cerr << i << "\n";
            forn(j, s[i + 1] + 1, 9) {
				if (!cnt[j]) continue;
				forn(k, 1, i)
					cout << s[k];
				cout << j;	 
				forn(j1, 0, 9) {
					if (!cnt[j1] && j1 != j) continue; 
					forn(k, 1, n - i - 1)
						cout << j1;
					break;
				}	
				cout << "\n";	
				return 0;
			}                     
		}
		
		if (dif == r - 1) {   
			if ((cnt[s[i + 1] + 1] != 0) || cnt[0]) {
				forn(k, 1, i) 
					cout << s[k];
				cout << s[i + 1] + 1;
				forn(k, 1, n - i - 1)
					cout << 0;
				cout << "\n";
				return 0;			
			}
			else {
				forn(j, 0, 9) {
					if (!cnt[j] && j != s[i + 1] + 1) continue;
					forn(k, 1, i) 
						cout << s[k];
					cout << s[i + 1] + 1;
					forn(k, 1, n - i - 1)
						cout << j;
					cout << "\n";	
					return 0;
				}
			}               	
		}
		
		if (dif <= r - 2) {
			forn(k, 1, i)
				cout << s[k];
			cout << s[i + 1] + 1;
			forn(k, 1, n - i - 1)
				cout << 0;
			return 0;
		}
	}

	assert(0);
                     
	return 0;         	
}