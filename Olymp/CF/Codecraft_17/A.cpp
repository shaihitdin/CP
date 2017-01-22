/**
	Mom, I'm on someone's monitor!
**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100;

string s, t;
int cnt1[256], cnt2[256];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> s;
	t = "Bulbasaur";
	for (auto it : s) {
		cnt1[it]++;
	}
	for (auto it : t) {
		cnt2[it]++;
	}
	int ans = 1e9;	
	for (int i = 0; i < 256; ++i) {
		if (!cnt2[i])
			continue;
		ans = min (ans, cnt1[i] / cnt2[i]);
	}

	cout << ans;
	return 0;
}