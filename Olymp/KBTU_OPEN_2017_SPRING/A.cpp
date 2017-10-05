#include <bits/stdc++.h>

using namespace std;


const int N = 510;

int a[N], b[N][N], p[N];

int main () {

	freopen ("darecosystem.in", "r", stdin);
	freopen ("darecosystem.out", "w", stdout);

	int n, d, k;
	cin >> n >> d >> k;

	for (int i = 1; i <= d; ++i)
		cin >> a[i];

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= d; ++j)
			cin >> b[i][j];
		cin >> p[i];
	}

	
	vector <pair <double, int> > s;
	for (int i = 1; i <= n; ++i) {
		double val = 0;
		for (int j = 1; j <= d; ++j) {
			val += (a[j] - b[i][j]) * 1ll * (a[j] - b[i][j]);
		}
		s.emplace_back (make_pair (val, -i));
	}
	sort (s.begin (), s.end ());
    
    
    double ans = 0;
	
	for (int i = 0; i < k; ++i) {
		ans += p[-s[i].second];
	}	
	
	ans /= k;
	cout << fixed;
	cout << setprecision (6);
	cout << ans;	
	
	
	return 0;
}