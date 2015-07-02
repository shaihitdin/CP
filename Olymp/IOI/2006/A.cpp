#include <bits/stdc++.h>

using namespace std;

const int N = 3e6 + 100;

char b[N];

int cnt1[256], cnt2[256];

int main () {
    #ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	
	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int n, m;
	
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		char x;
		cin >> x;
		++cnt1[x - 'A'];
	}

	if (n > m) {
		cout << 0;
		return 0;
	}
	
	for (int i = 1; i <= m; ++i)
		cin >> b[i];
	
	for (int i = 1; i <= min (n, m); ++i) {
		++cnt2[b[i] - 'A'];
	}
		
	int ans = 0;
	
	for (int i = 1;; ++i) {
		bool flag = 1;
		for (int j = 0; j <= 'z' - 'A' + 1; ++j) {
			if (cnt2[j] != cnt1[j]) {
				flag = 0;
				break;
			}
		}
		ans += flag;
		--cnt2[b[i] - 'A'];
		if (b[i + n] < 'A')
			break;
		else
			++cnt2[b[i + n] - 'A'];
	}
	
	cout << ans;

	return 0;
}