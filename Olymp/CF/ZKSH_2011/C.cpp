#include <bits/stdc++.h>

using namespace std;

const int N = 2000;

int n;

char a[N];
int ans = N;
int cnt;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	for (int i = 0; i < n; ++i)
		if (a[i] == 'H')
			++cnt;
	
	int cnt2 = n - cnt;
	
	for (int i = 0; i < n; ++i) {
		int tmp = 0;
		for (int j = 0; j < cnt; ++j)
			if (a[(i + j) % n] == 'H')
				++tmp;
		ans = min (ans, cnt - tmp);
	}
	
	for (int i = 0; i < n; ++i) {
		int tmp = 0;
		for (int j = 0; j < cnt2; ++j)
			if (a[(i + j) % n] == 'T')
				++tmp;
		ans = min (ans, cnt2 - tmp);
	}
	
	cout << ans;
	
	return 0;
}