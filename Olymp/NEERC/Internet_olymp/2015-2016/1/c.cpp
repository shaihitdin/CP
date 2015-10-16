#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 1000;

typedef long long ll;

ll h1[N], h2[N];

string s;
int n;
int p[N];

int main () {

	freopen ("kdivision.in", "r", stdin);
	freopen ("kdivision.out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> s;

	n = s.size ();
	
	s = "#" + s;

	vector <int> ans;
	
	for (int len = 1; len <= n; ++len) {
		if (n % len == 0) {
			string t;
			bool flag = 1;
			for (int i = 1; i <= len; ++i) {
				t += s[i];
			}
			string t2;
			for (int i = len + 1; i <= n; i += len) {
				t2 = "";
				for (int j = i; j <= i + len - 1; ++j) {
					t2 += s[j];
				}
				t2 += t2;
				t2 = t + "#" + t2;
				for (int j = 1; j < t2.size (); ++j) {
					int k = p[j - 1];
					while (k && t2[j] != t2[k])
						k = p[k - 1];
					if (t2[j] == t2[k])
						++k;
					p[j] = k;
				}
				bool flag2 = 0;
				for (int j = t.size (); j < t2.size (); ++j)
					flag2 |= p[j] == len;
				flag &= flag2;
			}
			if (flag)
				ans.emplace_back (n / len);
		}
	}

	reverse (ans.begin (), ans.end ());
	
	cout << ans.size () << "\n";

	for (auto it : ans)
		cout << it << " ";

	return 0;
}