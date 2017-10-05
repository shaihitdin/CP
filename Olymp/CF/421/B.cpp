#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100;


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n;
	double a;
	cin >> n >> a;

	double sum = 180ll * (n - 2);

	double ang = sum / n;
	double sub_ang = ang / (n - 2);

	double ans = -1e9;
	int p3 = 0;
	
	for (int i = 3; i <= n; ++i) {
		if (abs (ans - a) > abs (sub_ang * (i - 2) - a)) {
			ans = sub_ang * (i - 2);
			p3 = i;
		}
	}
	
	cout << 2 << " " << 1 << " " << p3;	
	return 0;
}