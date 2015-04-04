/*
ID: shaihit1
PROG: crypt1
LANG: C++11
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int b[60];

int ans, a[1001];
bool u[101];

inline bool to_str (int x, const int &base, const int &i) {
	int j = 0;
	while (x) {
		if (!u[x % base])
			return 0;
		x /= base;
		++j;
		if (j > i)
			return 0;
	}
	return 1;
}

int n;

inline void rec (const int &lvl) {
	if (lvl == 6) {
		int digit1, digit2;
		digit1 = b[1] * 100 + b[2] * 10 + b[3];
		digit2 = b[4] * 10 + b[5];
		if (to_str (digit1 * b[5], 10, 3) && to_str (digit1 * b[4], 10, 3) && to_str (digit1 * digit2, 10, 4))
			++ans;
		return;
	}
	
	for (int i = 1; i <= n; ++i) {
		b[lvl] = a[i];
		rec (lvl + 1);
	}
}

int main() {

	freopen ("crypt1.in", "r", stdin);
	freopen ("crypt1.out", "w", stdout);
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf ("%d", &a[i]);
	for (int i = 1; i <= n; ++i)
		u[a[i]] = 1;
	rec (1);
	printf ("%d\n", ans);
	return 0;
}
