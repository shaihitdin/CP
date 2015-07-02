#include <bits/stdc++.h>

using namespace std;

const int N = 60001;

int n, a[N];
float sum[N], segment[N];
vector <int> ansl, ansr;

int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	scanf ("%d", &n);
	
	for (int i = 1; i <= n; ++i) {
		scanf ("%d", &a[i]);
		a[i] += 1;
	}

	for (int i = 1; i <= n; ++i)
		sum[i] = sum[i - 1] + sqrt ((float)i);
	
	for (int i = 1; i <= n - 1; ++i)
		segment[i] = sqrt ((float)a[i]) + sqrt ((float)a[i + 1]);

	for (int len = 3; len <= n; ++len) {
		for (int i = 1; i + len - 1 <= n; ++i) {
			segment[i] += sqrt ((float)a[i + len - 1]);
			if (a[j] > a[i] && segment[i] == sum[a[j]] - sum[a[i] - 1]) {
				ansl.push_back (i);
				ansr.push_back (i + len - 1);
				i += len - 1;
				break;
			}
		}
	}
	
	printf ("%d\n", ansl.size ());

	for (int i = 0; i < ansl.size (); ++i)
		printf ("%d %d\n", ansl[i], ansr[i]);
	
	return 0;
}