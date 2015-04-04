#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 2;

int pr[N], nx[N], p[N];
string s, t;


int main () {
	freopen ("censor.in", "r", stdin);
	freopen ("censor.out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	
	cin >> s >> t;

	s = t + '#' + s;

	int n = s.size(), start = t.size();
	for (int i = 1; i < start; ++i) {
		int j = p[i - 1];
		while (j && s[i] != s[j])
			j = p[j - 1];
		if (s[i] == s[j])
			++j;
		p[i] = j;
	}		
	for (int i = start; i < n; ++i)
		nx[i] = i + 1, pr[i] = i - 1;
	for (int i = start + 1; i < n; i = nx[i]) {
		int j = p[pr[i]];
		while (j && s[i] != s[j])
			j = p[j - 1];
		if (s[i] == s[j])
			++j;
		p[i] = j;
		if (j == start) {
			int temp = i, it = j;
			for (; it; temp = pr[temp], --it);
			nx[temp] = i + 1;
			pr[i + 1] = temp;
			i = temp;
		}
	}
	for (int i = nx[start]; i < n; i = nx[i])
		cout << s[i];
	return 0;
}