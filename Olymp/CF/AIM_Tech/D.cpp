/**
	Oh, my dear
**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 110;
const int MAGIC = 900;
const double eps = 1 / 1e12;

double from[MAGIC * N], to[MAGIC * N];
int n, a[N];

int main () {
	#ifdef BROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	sort (a + 1, a + n + 1);
	reverse (a + 1, a + n + 1);

	to[0] = 1;

	for (int i = 1; i <= n; ++i) {
		double prob = (a[i] / 100.0);
		for (int j = 0; j < MAGIC * N; ++j)
			from[j] = to[j], to[j] = 0;
		for (int j = 0; j < MAGIC * N; ++j) {
			double prob2 = prob;
			for (int k = 1; from[j] * prob2 > eps; ++k, prob2 *= prob) {
				to[j + k] += from[j] * prob2;
			}
		}
	}
	double ans = 0;
	for (int i = 0; i < MAGIC * N; ++i) {
		ans += to[i] * i;
	}
	cout << fixed;
	cout << setprecision (9);
	cout << ans;
	return 0;
}