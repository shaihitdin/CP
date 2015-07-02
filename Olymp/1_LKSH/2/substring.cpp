#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;

const int N = 5002, bpr = 1e9 + 7, pr = 257, alpha = 256;

int l_occur[alpha];
int p_pow[N];
string a, b;
vector <int> h[N];
int h_t[N];

int main () {
	freopen ("substring.in", "r", stdin);
	freopen ("substring.out", "w", stdout);

	ios_base :: sync_with_stdio (0);

	p_pow[0] = 1;

	for (int i = 1; i < N; ++i)
		h[i].resize (N - i);
	
	for (int i = 1; i < N; ++i)
		p_pow[i] = (p_pow[i - 1] * 1ll * pr) % bpr;
	
	cin >> a >> b;

	int n1 = a.size (), n2 = b.size ();
	
	a = "#" + a, b = "#" + b;

	for (int i = 1; i <= n2; ++i) {
		for (int j = 0; j < 256; ++j)
			l_occur[j] = i - 1;
		for (int j = i, k = 1; j <= n2; ++j, ++k) {
			h[i][k] = ((j - l_occur[(int)b[j]]) * 1ll * p_pow[k]) % bpr;
			h[i][k] += h[i][k - 1];
			h[i][k] %= bpr;
			l_occur[(int)b[j]] = j;
		}
	}
	
	
	int ans, ans1, ans2;
	ans = ans1 = ans2 = 1;

	for (int i = 1; i <= n1; ++i) {
		for (int j = 0; j < 256; ++j)
			l_occur[j] = i - 1;
		memset (h_t, 0, sizeof (h_t));
		
		for (int j = i, k = 1; j <= n1; ++j, ++k) {
			h_t[k] = ((j - l_occur[(int)a[j]]) * 1ll * p_pow[k]) % bpr;
			h_t[k] += h_t[k - 1];
			h_t[k] %= bpr;
			l_occur[(int)a[j]] = j;
		}

		for (int j = 1; j <= n2; ++j) {
			int l = ans, r = min (n1 - i + 2, n2 - j + 2);
			if (h_t[l] != h[j][l])
				continue;
			while (r - l > 1) {
				int mid = (r + l) >> 1;
				if (h_t[mid] == h[j][mid])
					l = mid;
				else
					r = mid;
			}
			if (ans < l) {
				ans = l;
				ans1 = i;
				ans2 = j;
			}
		}
	}
	
	for (int i = ans1; i < ans + ans1; ++i)
		cout << a[i];
	cout << "\n";
	for (int i = ans2; i < ans + ans2; ++i)
		cout << b[i];
	cout << "\n";	

	return 0;
}