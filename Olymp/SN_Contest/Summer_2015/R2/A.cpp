#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 100;

char c[N];
bool u[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int n, m;
	
	scanf ("%d\n%d\n", &n, &m);

	for (int i = 1; i <= n; ++i)
		scanf ("%c\n", &c[i]);
	
	for (int i = 1; i <= m; ++i) {
		char ch;
		int len;
		scanf ("%c %d\n", &ch, &len);
		if (u[len])
			continue;
		if (ch >= c[len]) {
			u[len] = 1;
		}
	}
	
	int ans = 0;
	
	for (int i = 1; i <= n; ++i)
		ans += u[i];
	
	printf ("%d", ans);

	return 0;
}