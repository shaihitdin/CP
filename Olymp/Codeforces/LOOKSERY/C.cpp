#include <bits/stdc++.h>

using namespace std;

int n, k;
int cnt[3];

inline void print (const int &turn) {
	if (turn == 1) {
		cout << "Stannis";
	} else {
		cout << "Daenerys";
	}
	exit (0);
}

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out1", "w", stdout);
	#endif
	
	ios_base :: sync_with_stdio (0);

	cin >> n >> k;

	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		++cnt[x & 1];
	}

	int turns = n - k;

	if (turns == 0)
		print (cnt[1] & 1);
	
	if (cnt[1] <= turns / 2)
		print (0);
	
	if (cnt[0] == 0)
		print (abs (turns - cnt[1]) & 1);
	
	
	if (!((cnt[1] + cnt[0]) & 1))
		print (!(abs (turns - cnt[1]) & 1));
	
		
	if (cnt[1] & 1) {
		int mm = 3;
		for (int even = 2; even + 2 <= cnt[0]; mm += 4, even += 2);
		if (turns <= mm)
			print (!(abs (turns - cnt[1]) & 1));
		else
			print (abs (turns - cnt[1]) & 1);
	}
	else {
		int mm = 1;
		for (int even = 1; even + 2 <= cnt[0]; mm += 4, even += 2);
		if (turns <= mm)
			print (abs (turns - cnt[1]) & 1);	
		else
			print (!(abs (turns - cnt[1]) & 1));
	}
	
	return 0;
}