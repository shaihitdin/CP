#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e6 + 1;
const ll bp = 1e9 + 7;

int mxnum = '0', mxcnt = 0;
ll res = 1, n, cnt[256];
string s;

inline int getm (const char &c) {
	if (cnt[mxnum] == cnt[c]) {
		++mxcnt;
	}
	else if (cnt[mxnum] < cnt[c]) {
		mxnum = c;
		mxcnt = 1;
	}
}

inline ll bin_pow (const ll &num, const ll &power) {
	if (!power)
		return 1;
	if (power & 1)
		return (bin_pow (num, power - 1) * num) % bp;
	ll b = bin_pow (num, power / 2);
	return (b * b) % bp; 
}

int main () {
	#ifndef ONLINE_JUDGE	
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	ios_base :: sync_with_stdio (0);
	cin >> n;
	cin >> s;
	for (char it : s) {
		++cnt[it];
	}
	getm ('A');
	getm ('C');
	getm ('G');
	getm ('T');
	cout << bin_pow (mxcnt, n);
	
	return 0;
}