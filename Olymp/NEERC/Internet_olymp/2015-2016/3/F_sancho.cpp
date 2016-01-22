#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef pair <int, int> PII;
typedef double ld;

const int N = 2e6;

PII q(int k, int b) {
	cout << 0 << " " << k << " " << b << "\n";
	fflush(stdout);
	PII res(0, 0);
	cin >> res.F;
	if (res.F == 1)
		cin >> res.S;
	return res;		
}

const int C = 5e3;

int main () {
//	ios_base :: sync_with_stdio(0);

	PII start = q(0, 0);
	if (start.F == 1) {
		///NOT HORIZONTAL
		PII ans(0, 0);

		int l = 0, r = 0, mid = 0;
		
		l = -C, r = C;
		while (l < r) {
			mid = (l + r) >> 1;
			PII p = q(0, mid);
			assert(p.F == 1);
			if (p.S == -1) r = mid;
			else l = mid + 1;
		}
		
		ans.S = -l;                        
		int b0 = 1 - ans.S;

		l = -C, r = C;
		while (l < r) {
			mid = (l + r) >> 1;
			PII p = q(mid, b0);
			if (p.F != 1) {
				ans.F = -mid;
				cout << 1 << " " << ans.F << " " << ans.S << "\n";
				fflush(stdout);
				return 0;
			}
			if (p.S == -1) r = mid;
			else l = mid + 1;
		}

		ans.F = 1 - l;
		cout << 1 << " " << ans.F << " " << ans.S << "\n";
		fflush(stdout);
		return 0;
	} 	
	else {
		///HORIZONTAL
		PII ans(0, 0);

		int l = 0, r = 0, mid = 0;
		
		l = -C, r = C;
		while (l < r) {
			mid = (l + r + 1) >> 1;
			PII p = q(1, mid);
			assert(p.F == 1);
			if (p.S == -1) l = mid;
			else r = mid - 1;
		}
		
		ans.S = -l;
		cout << 1 << " " << ans.F << " " << ans.S << "\n";
		return 0;
	}

	return 0;             
}
    