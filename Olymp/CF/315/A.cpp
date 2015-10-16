#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 100;
const double eps = 1 / 1e7;

bool p[N], pp[N];
string s, t;

inline bool palin (int x) {
	s = "";
	while (x) {
		s += (x % 10);
		x /= 10;
	}
	t = s;
	reverse (t.begin (), t.end ());
	return t == s;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	p[1] = 1;

	for (int i = 2; i * i < N; ++i)
		if (!p[i])
			for (int j = i + i; j < N; j += i)
				p[j] = 1;

	for (int i = 1; i < N; ++i)	
		pp[i] = !palin (i);
		
	int sum1 = 0, sum2 = 0;
	int p1, q1;
	
	cin >> p1 >> q1;
	
	long double coeff = p1 * 1.0 / q1;
	coeff += eps;
	int ans = -1;
	
	for (int i = 1; i < N; ++i) {
		sum1 += !p[i];
		sum2 += !pp[i];
		if (sum1 < sum2 * coeff)
			ans = i;
	}
	
	if (ans == -1) {
		cout << "Palindromic tree is better than splay tree";
	} else {
		cout << ans;
	}
	
	return 0;
}