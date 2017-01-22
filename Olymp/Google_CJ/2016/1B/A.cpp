/// izizi

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
  
const int oo = 1e9, bpr = 1e9 + 7, N = 0;

#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

int cnt2[10][256];
string tt[10];
int order[10];

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	int t;

	cin >> t;

	tt[0] = "ZERO";
	tt[1] = "ONE";
	tt[2] = "TWO";
	tt[3] = "THREE";
	tt[4] = "FOUR";
	tt[5] = "FIVE";
	tt[6] = "SIX";
	tt[7] = "SEVEN";
	tt[8] = "EIGHT";
	tt[9] = "NINE";
	
	for (int i = 0; i < 10; ++i) {
		for (auto it : tt[i])
			++cnt2[i][it];
	}
	
	order[0] = 0;
	order[1] = 2;
	order[2] = 6;
	order[3] = 8;
	order[4] = 3;
	order[5] = 7;
	order[6] = 5;
	order[7] = 4;
	order[8] = 9;
	order[9] = 1;
	
	for (int test_num = 1; test_num <= t; ++test_num) {
		cout << "Case #" << test_num << ": ";
		string s;
		cin >> s;
		int cnt[256];
		memset (cnt, 0, sizeof (cnt));
		for (auto it : s)
			++cnt[it];
		string ans;
		for (int k = 0; k < 10; ++k) {
			int i = order[k];
			while (1) {
				bool flag = 1;
				for (int j = 0; j < 256; ++j)
					flag &= (cnt2[i][j] <= cnt[j]);
				if (flag) {
					ans += char (i + '0');
					for (int j = 0; j < 256; ++j)
						cnt[j] -= cnt2[i][j];
				} else {
					break;
				}
			}
		}
		sort (ans.begin (), ans.end ());
		cout << ans;
		cout << "\n";
	}
	
	return 0;
}