#include <bits/stdc++.h>

using namespace std;

int bpr = 1e9 + 7, pr = 31;
const int N = 150000, lg = 18;

int spr_arr[] = {31, 37, 41, 43, 47, 53, 59, 61, 67, 71};
int bpr_arr[] = {1000000007, 1000000009, 1000000021, 1000000033, 1000000087, 1000000093, 1000000097, 1000000103, 1000000123, 1000000181};

int h[N][lg], nxt[N][lg];
int p_pow[N];

char a[N];

int main () {

    #ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	
	srand (time (0));
	
	bpr = bpr_arr[rand () % 10];
	pr = spr_arr[rand () % 10];
	
	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	p_pow[0] = 1;

	for (int i = 1; i < N; ++i)
		p_pow[i] = (p_pow[i - 1] * 1ll * pr) % bpr;

	int n, k;
	
	cin >> n >> k;
	
	k %= n;

	for (int i = 0; i < n; ++i)
		cin >> a[i];
	
	for (int i = 0; i < n; ++i)
		nxt[i][0] = (i + k) % n;
	
	for (int i = 0; i < n; ++i)
		h[i][0] = (a[i] - '0' + 1);
	
	for (int pw = 1; pw < 18; ++pw) {
		for (int i = 0; i < n; ++i) {
			h[i][pw] = h[i][pw - 1];
			h[i][pw] += (p_pow[1 << (pw - 1)] * 1ll * (h[nxt[i][pw - 1]][pw - 1]));
			nxt[i][pw] = nxt[nxt[i][pw - 1]][pw - 1];
		}
	}
	
	int mxp = 0;

	for (int i = 1; i < n; ++i) {
		int pos1 = mxp, pos2 = i;
		for (int pw = 17; pw >= 0; --pw) {
			if (h[pos1][pw] == h[pos2][pw]) {
				pos1 = nxt[pos1][pw];
				pos2 = nxt[pos2][pw];
			}
		}
		if (a[pos1] < a[pos2])
			mxp = i;
	}

	for (int cnt = 0, i = mxp; cnt < n; ++cnt, i = (i + k) % n)
		cout << a[i];
	
	return 0;
}