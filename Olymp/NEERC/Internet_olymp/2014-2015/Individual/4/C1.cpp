#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;

string s;
long long a, b, c, n, d[N], z[N];

int main () {

	freopen ("webbuy.in", "r", stdin);
	freopen ("webbuy.out", "w", stdout);

	cin >> n;

	cin >> s;
	

	cin >> a >> b >> c;

	z[0] = 0;	
	for (int i = 1, l = 0, r = 0; i < s.size(); ++i) {
		if (i < r)
			z[i] = min (r - i + 1 * 1ll, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			++z[i];
		if (i + z[i] - 1 > r)
			l = i, r = i + z[i] - 1;
	}	

	for (int i = 0; i < s.size(); ++i)
		d[i] = n * a;

	d[0] = a;
	if (s[0] == s[1])
		z[0] = 1;
	
	for (int i = 0; i < s.size(); ++i) {
		d[i + 1] = min (d[i + 1], d[i] + a);
		d[i + z[i + 1]] = min (d[i + z[i + 1]], d[i] + b);
	
	}
		
	cout << d[n - 1];
    
    return 0;
}