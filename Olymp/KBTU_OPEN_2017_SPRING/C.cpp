#include <bits/stdc++.h>

using namespace std;



char b[100][4];

int main () {

	freopen ("lumberjack.in", "r", stdin);
	freopen ("lumberjack.out", "w", stdout);

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= 3; ++j)
			cin >> b[i][j];

	int st;
	
	if (b[n][1] == 'o')	
		st = 1;
	else
		st = 3;

	long long ans = 0;
	long long now = 1;
	string ans_s;
	for (int i = n; i >= 1; --i) {
		if (b[i - 1][st] != 'x') {
			ans += now;
			now += now;
		} else {
			i++;
			ans += (now = 1);
			now += now;
			if (st == 1)
				st = 3;
			else
				st = 1;
		}
		if (st == 1)
			ans_s += 'L';
		else
			ans_s += 'R';
	}	
	cout << ans << "\n";
	cout << ans_s;
	return 0;
}