#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 100;

string s;

int bpr, pr;

int ans[N], z[N];

int spr_arr[] = {31, 37, 41, 43, 47, 53, 59, 61, 67, 71};
int bpr_arr[] = {1000000007, 1000000009, 1000000021, 1000000033, 1000000087, 1000000093, 1000000097, 1000000103, 1000000123, 1000000181};
int p_pow[N];

int fjgjg, h[N];

inline int to_pow (const int &hash, const int &deg) {
	return (hash * 1ll * p_pow[N - 1 - deg]) % bpr;
}


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

	cin >> s;

	for (int i = 0; i < s.size (); ++i) {
		h[i] = ((s[i] - 'a' + 1) * 1ll * p_pow[i]) % bpr;
		if (i > 0)
			h[i] += h[i - 1];
	}
	
	for (int i = 0; i < s.size (); ++i) {
		if (ans[i] == 0) {
			ans[i] = i + 1;
			for (int j = i + 1 + i; j < s.size (); j += i + 1) {
				int h1 = (h[j] - h[j - (i + 1)] + bpr) % bpr;
				int h2 = h[i];
				h1 = to_pow (h1, j - i);
				h2 = to_pow (h2, 0);
				
				if (h1 != h2) {
					break;
				}
				if (!ans[j])
					ans[j] = i + 1;
			}
		}
	}
	
	for (int i = 0; i < s.size (); ++i)
		cout << ans[i] << " ";
	
	return 0;
}