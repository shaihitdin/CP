#include <bits/stdc++.h>

using namespace std;

const int N = 1100;

inline bool bit (int mask, int pos) {
	return (mask >> pos) & 1;
}

int res[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n;

	vector <int> ans;
	
	cin >> n;

	if (n == 0) {
		cout << "+";
		return 0;
	}
	
	int nn = 1 << n;
	
	for (int i = nn / 2 + 1; i <= nn; ++i) {
		res[i] = 1;
	}
	
	for (int cnt = 1; cnt <= nn; ++cnt) {
		for (int j = 1; j <= nn; ++j) {
			if (res[j] == 1)
				cout << '+';
			else
				cout << '*';
		}
		cout << "\n";
	}
	
	return 0;
}