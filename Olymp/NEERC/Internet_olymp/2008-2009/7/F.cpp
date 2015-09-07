#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "paper."

typedef long long ll;

const int N = 1e5 + 100;

int n, m;
int d[N];

int calc(int x) {
	d[1] = 0;
	forn(i, 2, x)
		d[i] = d[(i + 1) / 2] + 1;
}

int main () {
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	scanf("%d %d\n", &n, &m);
	calc(max(n, m));
	printf("%d\n", d[n] + d[m]);

	return 0;
}