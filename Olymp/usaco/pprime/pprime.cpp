/*
ID: shaihit1
PROG: pprime
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e8;
int a, b;

vector <int> primes, answers;

inline bool check_palindrome (const vector <char> && s) {
	for (int i = 0, j = int (s.size()) - 1; i <= s.size() / 2; ++i, --j)
		if (s[i] != s[j])
			return 0;
	return 1;
}

inline vector <char> to_str (int x, const int &base) {
	vector <char> res;
	res.resize(0);
	while (x) {
		res.push_back (x % base);
		x /= base;
	}
	reverse (res.begin (), res.end());
	return res;
}

inline bool check_prime (const int &x) {
	for (int i = 0; i < primes.size() && primes[i] * primes[i] <= x; ++i)
		if (!(x % primes[i]))
			return 0;
	return 1;
}

inline void rec (const int &res, const int &base) {
	int new_val = 0;		
	for (int i = 1; i <= 9; ++i) {
		new_val = res + base * i;
		if (a <= new_val && new_val <= b && check_palindrome (to_str (new_val, 10)) && check_prime (new_val))
			answers.push_back (new_val);
	}
	for (int i = 0; i <= 9; ++i) {
		new_val = res + base * i;
		if (new_val > b || base == MAXN)	break;
		rec (new_val, base * 10);
	}	
}

int main() {
	
	freopen ("pprime.in", "r", stdin);
	freopen ("pprime.out", "w", stdout);
	
	for (int i = 2; i * i <= MAXN; ++i) {
		bool flag = 0;
		for (int j = 2; j * j <= i; ++j)
			if (!(i % j))
				flag = 1;
		if (!flag)
			primes.push_back (i);
	}
	
	scanf ("%d%d", &a, &b);
	
	rec (0, 1);

	sort (answers.begin(), answers.end());
	
	for (int it : answers)
		printf ("%d\n", it);
	return 0;
}
