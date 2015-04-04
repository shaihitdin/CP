/*
ID: shaihit1
PROG: preface
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int num[] = {1000, 500, 100, 50, 10, 5, 1};
char num1[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
int ans[7];

inline vector <int> get (int x) {
	vector <int> res;
	for (int i = 0; i < 7; i += 2) {
		if (x / num[i] == 0)
			continue;
		else if (x / num[i] <= 3) {
			for (int j = 0; j < x / num[i]; ++j)
				res.push_back (i);
		}
		else if (x / num[i] == 4) {
			res.push_back (i);
			res.push_back (i - 1);
		}
		else if (x / num[i] <= 8) {
			res.push_back (i - 1);
			for (int j = 0; j < x / num[i] - 5; ++j)
				res.push_back (i);
		}
		else if (x / num[i] == 9) {
			res.push_back (i - 2);
			res.push_back (i);
		}
		x -= ((x / num[i]) * num[i]);
	}
	return res;
}

inline void plus_ans (vector <int> && temp) {
	for (auto it : temp)
		++ans[it];
}

int main() {
	
	freopen ("preface.in", "r", stdin);
	freopen ("preface.out", "w", stdout);
	int n;
	
	cin >> n;

	for (int i = 1; i <= n; ++i)
		plus_ans (get (i));
	for (int i = 6; i >= 0; --i)
		if (ans[i])
			cout << num1[i] << " " << ans[i] << "\n";
	return 0;
}
