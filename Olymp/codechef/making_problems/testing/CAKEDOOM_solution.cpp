#include <bits/stdc++.h>

using namespace std;


int main (int argc, char * argv[]) {

	freopen (argv[1], "r", stdin);
	freopen ((string (argv[1]) + ".a").c_str (), "w", stdout);

	ios_base :: sync_with_stdio (0);

	int test;

	cin >> test;

	for (int t = 1; t <= test; ++t) {
		int k;
		string s;
		cin >> k >> s;
		
		if (k == 2) {
			
			bool flag = 1;
			
			int pos = -1;
			
			for (int i = 0; i < s.size (); ++i)
				if (s[i] != '?')
					pos = i;
			
			if (pos == -1)
				s[0] = '0', pos = 0;
			
			for (int i = pos - 1; i >= 0; --i)
				if (s[i] == '?')
					s[i] = s[i + 1] ^ 1;
				else if (s[i] == s[i + 1])
					flag = 0;
			
			for (int i = pos + 1; i < s.size (); ++i)
				if (s[i] == '?')
					s[i] = s[i - 1] ^ 1;
				else if (s[i] == s[i - 1])
					flag = 0;
			
			if (s.size () > 1 && s.size () & 1)
				flag = 0;
			
			if (!flag)
				s = "NO";
			
			cout << s << "\n";
			
			continue;
		}

		bool flag = 1;
		
		for (int i = 0; i + 1 < s.size (); ++i)
			if (s[i] != '?' && s[i] == s[i + 1])
				flag = 0;
		
		if (s.size () > 1 && s.front () != '?' && s.back () == s.front ())
			flag = 0;
		else if (s.size () == 1 && s[0] == '?')
			s[0] = '0';

		for (char i = '0'; i < '0' + k; ++i)
			if (s[0] == '?' && i != s.back () && i != s[1])
				s[0] = i;
		if (s[0] == '?')
			flag = 0;
		
		for (int i = 1; i + 1 < s.size (); ++i) {
			for (char j = '0'; j < '0' + k; ++j)
				if (s[i] == '?' && s[i - 1] != j && s[i + 1] != j)
					s[i] = j;
			if (s[i] == '?')
				flag = 0;
		}
		
		if (s.size () > 1) {
			for (char j = '0'; j < '0' + k; ++j)
				if (s[s.size () - 1] == '?' && s[s.size () - 2] != j && s[0] != j)
					s[s.size () - 1] = j;
			if (s[s.size () - 1] == '?')
				flag = 0;
		}
		
		if (!flag)
			s = "NO";
		cout << s << "\n";
	}

	return 0;
}