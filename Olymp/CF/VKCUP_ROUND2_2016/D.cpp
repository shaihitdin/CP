/// Forever

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1);
  
const int oo = 1e9, bpr = 1e9 + 7, N = 2e5 + 100;

#define mp make_pair

inline ld solve (ld a, ld b, ld c) {
	ld d = b * b - 4 * c;
	if (d == 0)
		return -(b / 2);
	d = fabs (d);
	cerr << d << " " << (-b + sqrt (d)) / 2 << " " << (-b - sqrt (d)) / 2 << "\n";
	return max ((-b + sqrt (d)) / 2, (-b - sqrt (d)) / 2);
}

ld a[N], b[N];

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	int n;

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	ld prob = 0;
	
	vector <ld> ans1;
	
	for (int i = 1; i <= n; ++i) {
		auto val = solve (1, 2 * prob, -a[i]);
		ans1.emplace_back (val);
		prob += val;
	}
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			b[max (i, j) + 1] += ans1[i] * ans1[j];
		}
	}

	cerr << fixed << setprecision (8);
	
	for (int i = 1; i <= n; ++i)
		cerr << a[i] << " ";
	
	cerr << "\n";
	
	for (int i = 1; i <= n; ++i)
		cerr << b[i] << " ";
	
	cerr << "\n";

	cout << fixed << setprecision (8);
	
	ld sum = 0;
	for (auto it : ans1) {
		sum += it;
		cout << it << " ";
	}
	cout << "\n";
	for (auto it : ans1)
		cout << it << " ";	

	return 0;
}