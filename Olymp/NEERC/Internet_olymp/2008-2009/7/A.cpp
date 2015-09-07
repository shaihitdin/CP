#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100;

int a[N];

inline void add (string &a) {
	int p = 0;
	for (int i = a.size () - 1; i >= 0; --i) {
		int nw = (a[i] * 1ll - '0' + p) > 9;
		a[i] = '0' + ((a[i] * 1ll - '0' + p) % 10);
		p = nw;
	}
	if (p == 1) {
		a = '1' + a;
	}
}

int main () {

	freopen ("anti.in", "r", stdin);
	freopen ("anti.out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	while (1) {
		string s;

		cin >> s;
		
		if (s == "0")
			return 0;
		
		++s[s.size () - 1];
		add (s);

		while (1) {
			bool flag = 0;
			int n = s.size ();
			for (int i = n / 2, j = ((n & 1) ? (n / 2) : (n / 2 - 1)); i < s.size () && j >= 0; ++i, --j) {
				if (s[i] == s[j]) {
					++s[i];
					add (s);
					
					if (s.size () & 1)
						s.resize(s.size () + 1);
					
					if (s.size () > n) {
						for (int i = 0; i < s.size (); ++i)
							s[i] = '0';
						for (int i = n / 2 + 1; i < s.size (); ++i)
							s[i] = '1';
						s[s.size () - 1] = '0';
						s[0] = '1';
						flag = 0;
						break;
					}
					
					for (int k = i + 1; k < s.size (); ++k)
						s[k] = '0';
					flag = 1;
					break;
				}
			}
			if (!flag)
				break;
			else
				continue;
		}
		
		cout << s << "\n";
	}
	
	return 0;
}