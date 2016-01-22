#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 100;
const int sz = 1 << 19;


int len[N];
vector <int> g[N];


int main () {

	freopen ("tesseract.in", "r", stdin);
	freopen ("tesseract.out", "w", stdout);

	string s, t;
	
	cin >> s;

	t += '#';
	for (int i = 0; i < s.size (); ++i) {
		t += s[i];
		t += '#';
	}

	long long ans = 0;
	
	//cerr << t << "\n";
	
	int i = 0, l = -1, r = -1;
	for (; i < t.size (); ++i) {
		if (i <= r)
			len[i] = min (r - i + 1, len[l + (r - i)]);
		while (i + len[i] < t.size () && i - len[i] >= 0 && t[i + len[i]] == t[i - len[i]])
			++len[i];
		if (i + len[i] - 1 > r) {
			l = i - len[i] + 1;
			r = i + len[i] - 1;
		}
		if (t[i] == '#') {
			if (len[i] > 1)
				ans += len[i] / 2 - 1;
			else
				continue;
		} else {
			ans += (len[i] + 1) / 2 - 1;
		}
		g[i - len[i] + 1].emplace_back (i + len[i] - 1);
	}

	set <int> Set;
	
	for (int i = 0; i < t.size (); ++i) {
		sort (g[i].begin (), g[i].end ());
		reverse (g[i].begin (), g[i].end ());
		for (auto it : g[i]) {
			if (Set.lower_bound (it) != Set.end ())
				++ans;
			else
				Set.insert (it);
		}
	}
	
	cout << ans;
	
	return 0;
}