#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
const int N = 8001;
long long s[N];
int n, a[10];
int main () {
	freopen ("in" ,"r", stdin);
	freopen ("out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= 9; ++i) {
		a[i] = i * i * i;
	}
	for (int i = 1; i < N; ++i) {
		for (int j = 1; j <= 12; ++j)
			s[i] = 1e16;
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 1; j <= 9; ++j) {
			if (i + a[j] < N && s[i] * 10 + j < s[i + a[j]]) {
				s[i + a[j]] = s[i] * 10 + j;
			}
		}
	}
	cout << s[n];
	return 0;
}