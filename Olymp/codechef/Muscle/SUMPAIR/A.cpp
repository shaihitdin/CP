#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5;

int t;
int a[N];
bool u[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	scanf ("%d", &t);

	while (t--) {
		int n, d;
		scanf ("%d%d", &n, &d);
		for (int i = 1; i <= n; ++i)
			scanf ("%d", &a[i]);

		sort (a + 1, a + n + 1);
		
		ll sum = 0;
		
		for (int i = n, j = n; i; --i) {			
			if (u[i])
				continue;
			j = min (j, i - 1);
			while (j > 0 && a[i] - a[j] < d && u[j])
				--j;
			if (j == 0)
				continue;
			if (a[i] - a[j] >= d)
				continue;
			if (u[j])
				continue;
			sum += a[i] + a[j];
			u[j] = 1;
			u[i] = 1;
		}
		
		for (int i = 1; i <= n; ++i)
			u[i] = 0;
		
		printf ("%lld\n", sum);
	}
	
	return 0;
}