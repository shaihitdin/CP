#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "competition."
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef pair <int, int> PII;
typedef double ld;

const int N = 2e3;

int a[N][N];

int prv(int x, int B) {
	return x == 0 ? B - 1 : x - 1;
}

int main () {
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);

	int n, k;
	cin >> n >> k;
             
    int B = 0;
    forn(i, 4, 11) {
    	if (n % i == 0) {
    		B = i;
    		break;
    	}           
    }

	if (B > 0) {
		forn(i, 0, n - 1) {
			forn(j, 0, k - 1)
				cout << (i + j) % B << " ";
			cout << "\n";
		}	
		return 0;
	}	
                  

    int cnt = 0;
    int x = n % 11;
    a[0][0] = 0;
	forn(i, 0, n - 1) {
		if (i > 0) {
			if (cnt == (11 - x))
				a[i][0] = (a[i - 1][0] + 1) % 11;
    		else {
    			if (a[i - 1][0] < 7) {
    				a[i][0] = (a[i - 1][0] + 2) % 11;
    				++cnt;
    			}	
    			else
    				a[i][0] = (a[i - 1][0] + 1) % 11;
    		}
    	}
    	forn(j, 1, k - 1)
			a[i][j] = (a[i][j - 1] + 1) % 11;		
	}         

	forn(i, 0, n - 1) {
		forn(j, 0, k - 1)
			cout << a[i][j] << " ";
		cout << "\n";	
	}
        
	return 0;             
}       
