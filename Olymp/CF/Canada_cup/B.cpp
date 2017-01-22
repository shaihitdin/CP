#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define int ll

main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	
	string s;

	cin >> s;
	int n = 0, ans = 0;
	for (int i = 0; i + 1 < s.size (); ++i) {
		n = n * 10 + (s[i] - '0');
	}
	--n;	
	
	int x = s.back () - 'a';
	int calc[6];
	calc[5] = 1;
	calc[4] = 2;
	calc[3] = 3;
	calc[0] = 4;
	calc[1] = 5;
	calc[2] = 6;
	x = calc[x];

	if (n % 4 == 2 || n % 4 == 3)
		ans += n - 2;
	else
		ans += n;
	
	ans += n / 4 * 2 * 6;
	if (n % 2 == 1)
		ans += 6;
	ans += x;
	cout << ans;
	return 0;
}