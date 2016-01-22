#include <bits/stdc++.h>

using namespace std;

string res;

inline bool g_try (const string &x) {
	cout << x << "\n";
	fflush (stdout);
	string ans;
	cin >> ans;
	if (ans == "Success")
		exit (0);
	return ans[0] - '0';
}

inline int Find (const string &ss) {
	int l = 0, r = ss.size ();
	while (r - l > 1) {
		int mid = (r + l) >> 1;
		if (g_try (ss.substr (0, mid)))
			l = mid;
		else
			r = mid;
	}
	return l;
}

int main () {

	int n;

	cin >> n;

	if (!g_try ("0")) {
		for (int i = 0; i < n; ++i)
			cout << 1;
		cout << "\n";
		return 0;
	}
	
	res = "0";
	
	int l = 1, r = n + 1;

	while (r - l > 1) {
		int mid = (r + l) >> 1;
		string s(mid, '0');
		if (g_try (s))
			l = mid;
		else
			r = mid;
	}
	
	res = string (l, '0');
	int cnt (0);
	
	while (res.size () < n && cnt <= l) {
		if (g_try (res + '1')) {
			res += '1';
			cnt = 0;
		} else {
			res += '0';
			++cnt;
		}
	}

	res = res.substr (0, Find (res));
	
	while (res.size () < n) {
		if (g_try ('0' + res)) {
			res = '0' + res;
		} else {
			res = '1' + res;
		}
	}
	
	g_try (res);

	assert (0);

	return 0;
}