/// Stupido del problemo

#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1);
  
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

const int oo = 1e9, bpr = 1e9 + 7, N = 2e5;

string s;
int n, k;

inline int change (int x, int xx, int val) {
	return (s[x] != (val + '0')) + (s[xx] != (val + '0'));
}

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	cin >> n >> k;

	cin >> s;

	int polube = 0;

	for (int i = 0; i < n / 2; ++i)
		polube += (s[i] != s[n - 1 - i]);
	
	if (polube > k) {
		cout << -1;
		return 0;
	}

	for (int i = 0; i < n / 2; ++i) {
		polube -= (s[i] != s[n - 1 - i]);
		if (s[i] == '9' && s[n - 1 - i] == '9')
			continue;
		if (polube + 2 <= k && max (s[i], s[n - 1 - i]) != '9') {
			s[i] = s[n - 1 - i] = '9';
			k -= 2;
		} else if (polube + 1 <= k && s[i] != s[n - 1 - i]) {
			int val = max (s[i], s[n - 1 - i]);
			s[i] = s[n - 1 - i] = val;
			k -= 1;
		}
		/*
		for (int j = 9; j >= 0; --j) {
			if (polube + change (i, n - 1 - i, j) <= k) {
				k -= change (i, n - 1 - i, j);
				s[i] = s[n - 1 - i] = j + '0';
			}
		}
		*/
	}
	
	if (k > 0 && n % 2 == 1)
		s[n / 2] = '9', --k;

	cout << s;
	
	return 0;
}