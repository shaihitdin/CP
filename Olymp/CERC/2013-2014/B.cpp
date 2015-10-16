#include <bits/stdc++.h>

using namespace std;

const int N = 200;

vector <string> t;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	
	int test;
	
	cin >> test;

	string s;
	getline (cin, s);

	while (test--) {
		s.clear ();
		while (1) {
			char c;
			c = getchar ();
			if (c < 32)
				break;
			s += c;
		}
		
		string tmp;
		t.clear ();
		for (int i = 0; i < s.size ();) {
			tmp = "";
			int j = i;
			for (; j < s.size () && s[j] != ' '; ++j) {
				tmp += s[j];
			}

			t.emplace_back (tmp);

			while (j < s.size () && s[j] == ' ')
				++j;
		
			i = j;
		}

		while (1) {
			string s1, s2, s3;
			cin >> s1 >> s2 >> s3;
			if (s2 == "does") {
				cin >> s1 >> s2;
				char c = getchar ();
				break;
			} else {
				vector <string> nt;
				for (auto it : t)
					if (it != s3)
						nt.emplace_back (it);
				t = nt;
			}
		
		}


		for (auto it : t)
			cout << it << " ";

		cout << "\n";
	}

	return 0;
}