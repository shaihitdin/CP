#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector <ll> v1, v2;

inline int begg (const int &pos) {
	return pos == len_n ? 1 : 0;
}

vector <int> ch;
int ch_cnt;

int main () {

	freopen ("division.in", "r", stdin);
	freopen ("division.out", "w", stdout);

	ll n, m;
	
	cin >> n >> m;

	ll saved = n;
	
	pw[0] = 1;

	int len_n = 0;
	
	for (int i = 1; i <= 12; ++i)
		pw[i] = pw[i - 1] * 10;
	
	for (int len_n = 1; m <= pw[len_n]; ++len_n);

	--len_n;
	
	ch_cnt = len_n + 1;
	
	for (int i = 0; saved; ++i) {
		rem[i] = saved % 10;
		saved /= 10;
	}

	for (int i = 0; i <= len_n; ++i)
		rem[i] = (rem[i] * pw[i]) % m;

	ll sum = 0;
	
	for (int i = 0; i <= len_n; ++i)
		sum = (sum + rem[i]) % m;
	
	if (sum == 0) {
		cout << n;
		return 0;
	}
	
	for (int mask = 0; mask < (1 << (len_n + 1)); ++mask) {
		int zz = __builtin_popcount (mask);
		
		if (zz == 1) {
			for (int i = 0; i <= len_n; ++i) {
				if (bit (mask, i)) {
					sum -= rem[i];
					sum += m;
					sum %= m;
					for (int j = begg (i); j <= 9; ++j) {
						if ((sum + pw[i] * j) % m == 0) {
							if (ch_len > 1) {
								ch_len = 1;
								for (int k = 0; k <= len_n; ++k)
									
							}
						}
					}
					sum += rem[i];
					sum %= m;
				}
			}
		}

		v1.clear ();
		v2.clear ();
		
		for (int i = 0; i <= len_n; ++i) {
		
		}
	}
	
	return 0;
}