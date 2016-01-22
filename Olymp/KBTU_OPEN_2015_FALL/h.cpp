#include <bits/stdc++.h>

using namespace std;

string s;


inline bool isDigit (char a) {
	return '0' <= a && a <= '9';
}

inline pair <int, int> readInt (const int &b) {
	int r = b;
	int result = 0, mult = 1;
	if (!isDigit (s[r]))
		return make_pair (0, b);
	while (r < s.size ()) {
		if (isDigit (s[r])) {
			result *= 10;
			result += (s[r] - '0');
		} else {
			break;
		}
		++r;
	}
	return make_pair (result, r - 1);
}

inline pair <int, int> rec (const int &l) {
	if (s[l] == '+' || s[l] == '-') {
		auto it = rec (l + 1);
		if (s[l] == '-')
			return make_pair (it.first * -1, it.second);
		else
			return it;
	}
	if (isDigit (s[l])) {
		auto tmp = readInt (l);
		return tmp;		
	}
	if (s[l + 1] == 'a') {
		auto it = rec (l + 4);
		auto it2 = rec (it.second + 2);
		return make_pair (max (it.first, it2.first), it2.second + 1);
	} else if (s[l + 1] == 'i') {
		auto it = rec (l + 4);
		auto it2 = rec (it.second + 2);
		return make_pair (min (it.first, it2.first), it2.second + 1);
	} else {
		assert (0);
	}
}

int main () {

	freopen ("maxmin.in", "r", stdin);
	freopen ("maxmin.out", "w", stdout);

	cin >> s;

	cout << rec (0).first;
	
	return 0;
}