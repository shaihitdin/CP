#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;

int ans[N];
int n, k;

inline void get_sol (int n, const int &k) {
	for (int i = 1; i <= k; ++i)
		ans[i] = 1;
	n -= k;
	ans[1] += n / 2;
	ans[2] += n / 2;
	for (int i = 1; i <= k; ++i)
		cout << ans[i] << " ";
	exit (0);
}

int main () {
	freopen ("partition.in", "r", stdin);
	freopen ("partition.out", "w", stdout);
	
	cin >> n >> k;
	
	if (k == 1)
		goto here;
	if (n & 1)
		goto here;
	if (n < k)
		goto here;
	if (!(k & 1))
		get_sol (n, k);
	if (k == 3) {
		int cnt = 0;
		for (int i = n; i; --i) {
			for (int j = n - i; j; --j) {
				++cnt;
				int k = n - (i + j);
				if ((i ^ j ^ k) == 0 && k) {
					cout << i << " " << j << " " << k;
					exit (0);
				}
				if (cnt > 1e9)
					goto here;
			}
		}
		goto here;

	}
	if ((k & 1) && n > 6 && n - 6 >= k - 3) {
		cout << "1 2 3 ";
		get_sol (n - 6, k - 3);
	}
	here:;
	cout << "-1";
	return 0;
}