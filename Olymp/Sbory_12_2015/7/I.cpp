#include <bits/stdc++.h>

using namespace std;

int cnt[26];
int d[2610][2610];
string s;
string ans, anss, tmp;

inline int calc (int l, int r) {
	if (l > r)
		return 0;
	if (d[l][r])
		return d[l][r];
	if (s[l] == s[r])
		d[l][r] = max (d[l][r], calc (l + 1, r - 1) + ((l == r) ? 1 : 2));
	d[l][r] = max (d[l][r], calc (l + 1, r));
	d[l][r] = max (d[l][r], calc (l, r - 1));
	return d[l][r];
}

inline void restore (int l, int r) {
	if (l > r || ans.size () + ans.size () == 100) {
		anss = ans;
		reverse (ans.begin (), ans.end ());
		anss += ans;
		tmp = anss;
		reverse (anss.begin (), anss.end ());
		assert (tmp == anss);
		cout << anss;
		exit (0);
	}
	if (l == r) {
		anss = ans + s[l];
		reverse (ans.begin (), ans.end ());
		anss += ans;
		tmp = anss;
		reverse (anss.begin (), anss.end ());
		assert (tmp == anss);
		cout << anss;	
		exit (0);
	}
	if (s[l] == s[r] && d[l][r] == calc (l + 1, r - 1) + ((l == r) ? 1 : 2)) {
		ans += s[l];
		restore (l + 1, r - 1);
	} else if (d[l][r] == calc (l + 1, r)) {
		restore (l + 1, r);
	} else {
		restore (l, r - 1);
	}
	assert (0);
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	cin >> s;

	if (s.size () >= 2600) {
		for (int j = 0; j < s.size (); ++j)
			++cnt[s[j] - 'a'];
		int mxa = 0;
		for (int i = 0; i < 26; ++i)
			if (cnt[mxa] < cnt[i])
				mxa = i;
		assert (cnt[mxa] >= 100);		
		for (int i = 0; i < 100; ++i)
			cout << char (mxa + 'a');
		return 0;
	}

	calc (0, s.size () - 1);
	restore (0, s.size () - 1);	
	
	return 0;
}