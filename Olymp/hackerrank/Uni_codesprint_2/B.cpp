#include <bits/stdc++.h>

using namespace std;

long long la = 0;

inline bool rec (const string &s, long long ps, long long lst, long long now) {
	if (s.size () == ps) {
		return (lst != -1 && now == lst + 1);
	}
	long long nw = now * 10 + s[ps];
	if ((now == 0 && nw == 0))
		return 0;
	if (lst == -1) {
		if (rec (s, ps + 1, nw, 0)) {
			la = nw;
			return 1;
		}
		if (rec (s, ps + 1, -1, nw))
			return 1;
	} else {
		if (nw == lst + 1 && rec (s, ps + 1, nw, 0))
			return 1;
		if (rec (s, ps + 1, lst, nw))
			return 1;
	}
	return 0;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif
	long long q;
	cin >> q;

	while (q--) {
		string s;
		cin >> s;
		for (auto &it : s)
			it -= '0';
		if (rec (s, 0, -1, 0))
			cout << "YES " << la << "\n";
		else
			cout << "NO\n";
	}


	return 0;
}