/*
ID: shaihit1
PROG: pprime
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e8;
int a, b;
int powers[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
vector <int> primes, answers;

inline bool check_prime (const int &x) {
	for (int i = 0; i < primes.size() && primes[i] * primes[i] <= x; ++i)
		if (!(x % primes[i]))
			return 0;
	return 1;
}

inline void rec (const int &length, const int &num, const int &result) {
	if (length - num < num) {
		if (a <= result && result <= b && check_prime (result))
			answers.push_back (result);
		return;
	}
	if (num == 0)
		for (int i = 1; i <= 9; i += 2)
			if (length != num)
				rec (length, num + 1, result + i * powers[length] + i * powers[0]);
			else
				rec (length, num + 1, result + i * powers[0]);
	else
		for (int i = 0; i <= 9; ++i)
			if (length - num != num)
				rec (length, num + 1, result + i * powers[length - num] + i * powers[num]);
			else
				rec (length, num + 1, result + i * powers[num]);
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
	
	if (a <= 2 && 2 <= b)
		answers.push_back (a);

	for (int len = 0; len < 7; ++len)
		rec (len, 0, 0);
		
	for (int it : answers)
		printf ("%d\n", it);
	return 0;
}
