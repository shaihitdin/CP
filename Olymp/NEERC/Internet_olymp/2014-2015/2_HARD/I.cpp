#include <bits/stdc++.h>

using namespace std;

string s, sx, sy;

vector <int> v;

int main () {

	freopen ("oddoreven.in", "r", stdin);
	freopen ("oddoreven.out", "w", stdout);

	cin >> s >> sx >> sy;
	int x, y;
	if (sx[0] == 'O')
		x = 1;
	else
		x = 2;
	if (sy[0] == 'O')
		y = 1;
	else
		y = 2;

	s = "+" + s;
	for (int i = 0; i < s.size(); ++i) {
		int ptr = i + 1;
		int num = 0;
		for (; ptr < s.size() && s[ptr] != '+' && s[ptr] != '-' && s[ptr] != '*'; ++ptr) {
			if (isalpha(s[ptr]))
				num = (s[ptr] == 'x' ? x : y);
			else
				num = (s[ptr] - '0');
		}
		num = 2 - (num & 1);
		if (s[i] == '*')
			v.back() *= num;
		else
			v.push_back(num);	
		i = ptr - 1;                    	
	}	

	int cur = 0;
	for (auto x : v) {
		cur += x;
	}	
	cout << (cur & 1 ? "Odd\n" : "Even\n");

	return 0;
}
