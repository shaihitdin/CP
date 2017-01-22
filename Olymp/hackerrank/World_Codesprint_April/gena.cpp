#include <bits/stdc++.h>

using namespace std;

const int N = (1 << 20) + 4543, oo = 1e9;


int d[N];
int st[N], stq, enq;
int a[20];
int mn[4];
int ps[20];
int n;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	cin >> n;

	int state = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
	}

	for (int i = n - 1; i >= 0; --i) {
		state <<= 2;
		state |= a[i];
	}
	
	st[enq++] = state;
	
	d[state] = 1;

	while (stq != enq) {
		int v = st[stq++];
		for (int i = 0; i < 4; ++i)
			mn[i] = oo;
		int v2 = v;
		for (int i = 0; i < n; ++i) {
			ps[i] = v2 % 4;
			mn[v2 % 4] = min (mn[v2 % 4], i);
			v2 /= 4;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 4; ++j) {
				if (mn[j] != i)
					continue;
				for (int k = 0; k < 4; ++k) {
					if (mn[k] > i) {
						int v3 = 0;
						for (int kk = n - 1; kk >= 0; --kk) {
							v3 <<= 2;
							if (kk == i)
								v3 |= k;
							else
								v3 |= ps[kk];
						}
						if (!d[v3]) {
							d[v3] = d[v] + 1;
							st[enq++] = v3;
						}
					}
				}
			}
		}
	}
	
	cout << d[0] - 1;
	
	return 0;
}