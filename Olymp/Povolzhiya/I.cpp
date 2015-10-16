#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)

typedef long long ll;
typedef pair <int, int> PII;

const int N = 3e5 + 100;

int n, bo;
int w, l;

int main () {

	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	
	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> bo >> n;
	w = bo, l = n - bo;
	int a = 0, b = 0;
	int ans = 0;
	forn(i, 1, n) {
		char c;
		int pos = 0;
		cin >> c;
		//int last = n - i;
		//a++
		if (i != n) {
			if (a + 1 < w) ++pos;
			if (b + 1 < w) ++pos;
		}
		else {
			if (a == b) pos = 2;		
		}
		assert(pos);
		if (pos == 2) ++ans;
		if (c == '0')
			++a;
		else
			++b;
		if ((a < b && a == l) || (b < a && b == l)) break;
	}

	cout << ans << "\n";
	
	return 0;
}