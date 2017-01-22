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

vector <int> dd;

inline void convert (int x) {
	dd.clear ();
	while (x) {
		dd.eb (x % 10);
		x /= 10;
	}
}

int cnt[10];

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	string s, t;
	
	cin >> s;
	
	if (s == "01" || s == "10") {
		cout << 0;
		return 0;
	}
	
	cin >> t;

	for (auto it : s)
		++cnt[it - '0'];
/*
	for (auto it : t)
		--cnt[it - '0'];
*/
	int len = -1;
	
	for (int i = 1; i <= 1e6; ++i) {
		convert (i);
		for (int x : dd)
			--cnt[x];
		bool flag1 = 0, flag2 = 0;
		for (int j = 0; j < 10; ++j)
			flag1 |= (cnt[j] < 0);
		for (int j = 1; j < 10; ++j)
			flag2 |= (cnt[j] > 0);
		int sum = 0;
		for (int j = 0; j < 10; ++j)
			sum += cnt[j];
		if (!(flag1 || !flag2) && sum /*+ t.size ()*/ == i)
			len = max (len, i);
		for (int x : dd)
			++cnt[x];
	}	
	
	assert (len != -1);

	convert (len);
	
	for (int x : dd)
		--cnt[x];
	
	for (auto it : t)
		--cnt[it];
	++cnt[t[0]];
	
	string ans;

	for (int i = 1; i < 10; ++i) {
		if (cnt[i]) {
			ans += char ('0' + i);
			--cnt[i];
			break;
		}
	}	
	
	int kk = 0;
	
	for (; kk < t.size () && t[kk] != t[0]; ++kk);
		
	for (int i = 0; i < 10; ++i) {
		while (cnt[i]) {
			ans += char ('0' + i);
			--cnt[i];
		}
	}

	for (int i = 0; i < ans.size ();) {
		int j = i;
		
		while (j < ans.size () && ans[j] == ans[i])	++j;
		
		if (t[0] != ans[i]) {
			i = j;
			continue;
		}
		if (j == ans.size () && kk == t.size ()) {
			ans.insert ()
		} else if (j == ans.size ()) {
		
		} else if (kk == t.size ()) {
		
		} else {
		
		}
		i = j;
	}
	
	string anst;

	for (int i = (t[0] == '0'); i + 1 < ans.size (); ++i) {
		if (mp (ans[i], ans[i + 1]) >= mp (t[0], (t.size () == kk) ? (t[0]) : (t[kk]))) {
			for (int j = 0; j < i; ++j)
				anst += ans[j];
			anst += t;
			for (int j = i; j < ans.size (); ++j)
				anst += ans[j];
			break;
		}
	}
	
	if (!anst.size ())
		anst = ans + t;
	
	cout << anst;
	return 0;
}
