#include <bits/stdc++.h>

using namespace std;

const int N = 6e5 + 100;

int st[N], sz, ok[N], qq;
int n;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;

	n += n;
	int ans = 0;
	while (n--) {
		string q;
		cin >> q;
		if (q == "add") {
			int x;
			cin >> x;
			st[++sz] = x;
		} else {
			++qq;
			if (!(st[sz] == qq || ok[sz])) {
				++ans;
				ok[sz] = 1;
			}
			ok[sz - 1] |= ok[sz];
			ok[sz--] = 0;
		}
	}
	cout << ans;
	return 0;
}