/*
ID: shaihit1
PROG: fracdec
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 1;

#define left abacaba

int n, d, left, sz, a[N], u[N];
char temporary[11];


int main() {
	
	freopen ("fracdec.in", "r", stdin);
	freopen ("fracdec.out", "w", stdout);

	cin >> n >> d;
	left = n % d;
	sprintf (temporary, "%d.", n / d);
	printf ("%s", temporary);
	if (left == 0)
		cout << 0;
	while (1) {
		left *= 10;
		if (u[left] || left == 0)
			break;
		u[left] = ++sz;
		a[sz] = left / d;
		left %= d;
	}
	int flag = 0;
	if (left == 0) {
		for (int i = 1; i <= sz; ++i) {
			if (i != 1 && (i + flag + strlen (temporary)) % 76 == 1)
				putchar ('\n');
			cout << a[i];
		}
	} else {
		for (int i = 1; i <= sz; ++i) {
			if (i != 1 && ((i + flag + strlen (temporary))) % 76 == 1)
				putchar ('\n');
			if (i == u[left]) {
				cout << "(";
				flag = 1;
			}
			cout << a[i];
		}
		cout << ")";
	}
	cout << "\n";
	return 0;
}
