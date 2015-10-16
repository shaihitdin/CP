#include <bits/stdc++.h>

using namespace std;

const int N = 31;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)

int n;
int a[N][N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	
	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cout << 628 << "\n";
	cout << "aa\naz\n";
	int cnt = 2;
	forn(i, 'b', 'y') {
		forn(j, 'a', 'y') {
			cout << char(i) << char(j) << "\n";
			++cnt;
		}	
	}
	forn(i, 'a', 'z')
		cout << 'z' << char(i) << "\n";
	cnt += 26;
	cerr << cnt;

	return 0;
}