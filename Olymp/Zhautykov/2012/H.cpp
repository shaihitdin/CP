#include <iostream>
#include <set>
#include <stdio.h>
using namespace std;
typedef long long ll;
const ll mod = (1e9) + 7;
const ll prime = 29;
const int N = (1e5) + 20;
long long h[N];
long long h_table[6e7];
int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	ios_base::sync_with_stdio(0);
	for (int i = 0; i < N; ++i)
		p_pow[i] = 
	while (cin >> s) {
		len = s.size();
		for (int i = 0; i < s.size(); ++i) {
			h[i] = (s[i] - 'A' + 1) * p_pow[i];
			if (i > 0)
				h[i] += h[i - 1];
		}
		
	}
	return 0;
}