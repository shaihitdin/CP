#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

long long st[N], ptr;
long long add[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		string q_type;
		cin >> q_type;
		if (q_type == "push") {
			long long x;
			cin >> x;
			st[++ptr] = x;
		} else if (q_type == "pop") {
			--ptr;
		} else {
			int x, y;
			cin >> x >> y;
			add[x] += y;
		}
		if (ptr != 0) {
			st[ptr] += add[ptr];
			add[ptr - 1] += add[ptr];
			add[ptr] = 0;
		}
		if (ptr == 0)
			cout << "EMPTY\n";
		else
			cout << st[ptr] << "\n";
	}

	return 0;
}