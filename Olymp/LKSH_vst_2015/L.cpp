#include <bits/stdc++.h>

using namespace std;

set <vector <int> > Set;

inline vector <int> Transform (const string &s) {
	vector <int> word (28, 0);
	word[0] = s.front ();
	word[1] = s.back ();
	for (auto it : s)
		++word[it - 'a' + 2];
	return word;
}

int main () {

	freopen ("first-last-anagram.in", "r", stdin);
	freopen ("first-last-anagram.out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	
	int n, m;

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		Set.insert (Transform (s));
	}

	cin >> m;

	for (int i = 1; i <= m; ++i) {
		string s;
		cin >> s;
		if (Set.find (Transform (s)) == Set.end ())
			cout << "NO" << "\n";
		else
			cout << "YES" << "\n";
	}

	return 0;
}