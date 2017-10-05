#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	int t;
	cin >> t;

	while (t--) {
		string s;	
	   	cin >> s;
	   	int cnt[256];
	   	memset (cnt, 0, sizeof (cnt));
		bool ok = 1;
		for (auto it : s) {
			if (it == 'C') {
				if (cnt['E'] || cnt['S'])
					ok = 0;
			} else if (it == 'E') {
				if (cnt['S'])
					ok = 0;
			}
			++cnt[it];
		}
	   	puts (ok ? "yes" : "no");
	}
	return 0;
}