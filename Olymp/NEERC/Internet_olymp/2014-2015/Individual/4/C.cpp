#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 1;

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
	for (int i = 0; i < s.size(); ++i) {
		d[i + 1] = min (d[i + 1], d[i] + a);
		
		long long till = min (z[i + 1], 1ll * i + 1);
		/*
		for (int j = i + 1; j <= i + till; ++j)
			d[j] = min (d[i] + b, );
		*/
		
		
		for (int j = i + 1; j <= min (i + 1000 * 1ll, i + till); ++j)
			d[j] = min (d[i] + b + (c * ((i + 1) - (j - i))), d[j]);
		/*
		for (int j = i + till; j >= max (i + 1 * 1ll, i + till - 1000); --j)
			d[j] = min (d[i] + b + (c * ((i + 1) - (j - i))), d[j]);
		*/
	}
		
	cout << d[n - 1];
    
    return 0;
}