#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


vector <int> s[5];

inline vector <int> parse (int x) {
	if (x == 0) {
		return {0};
	}
	vector <int> a;
	while (x) {
		a.emplace_back (x % 10);
		x /= 10;
	}
	reverse (a.begin (), a.end ());
	return a;
}


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n;

	cin >> n;

	s[0].resize (n);
	for (int i = 0; i < n; ++i) {
		char x;
		cin >> x;
		x -= '0';
		s[0][i] = x;
	}
	
	int sum = 0;

	for (int it = 1; it <= 3; ++it) {
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			sum += s[it - 1][i];
			cout << s[it - 1][i];
			if (i + 1 != n)
				cout << "+";
		}
		cout << "\n";
		s[it] = parse (sum);
		n = s[it].size ();
	}
	
		
	
	return 0;
}