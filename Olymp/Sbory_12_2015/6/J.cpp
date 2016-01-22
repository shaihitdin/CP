#include <bits/stdc++.h>

using namespace std;

const int N = 2e4 + 100;

struct address {
	string login, domain;
	address (string a, string b) {
		login = a;
		domain = b;
	}
};

inline bool operator < (const address &a, const address &b) {
	if (a.login == b.login)
		return a.domain < b.domain;
	return a.login < b.login;
}

inline bool operator == (const address &a, const address &b) {
	return (a.login == b.login && a.domain == b.domain);
}

map <address, vector <int> > Map;
int n;
string or_s[N];

int main () {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	cin >> n;

	for (int i = 1; i <= n; ++i) {
	    cin >> or_s[i];
		string s;
		s = or_s[i];
		string tmp_login, tmp_domain;
		for (auto &it : s)
			if ('A' <= it && it <= 'Z')
				it = 'a' + (it - 'A');
		int j = 0;
		while (j < s.size () && s[j] != '@')
			++j;
		for (int k = j + 1; k < s.size (); ++k)
			tmp_domain += s[k];
		for (int k = 0; k < j; ++k)
			tmp_login += s[k];
		if (tmp_domain == "bmail.com") {
			string tmp_login2;
			for (int j = 0; j < tmp_login.size (); ++j) {
				if (tmp_login[j] == '.')
					continue;
				if (tmp_login[j] == '+')
					break;
				tmp_login2 += tmp_login[j];
			}
			Map[address (tmp_login2, tmp_domain)].emplace_back (i);
		} else {
			Map[address (tmp_login, tmp_domain)].emplace_back (i);
		}
	}

	cout << Map.size () << "\n";
	
	for (auto it : Map) {
		cout << it.second.size () << " ";
		for (auto it2 : it.second)
			cout << or_s[it2] << " ";
		cout << "\n";
	}

	return 0; 
}