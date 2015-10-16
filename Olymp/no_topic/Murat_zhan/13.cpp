#include <bits/stdc++.h>

using namespace std;

const int N = 1e6, oo = 1e9;

int d[N];

int main () {

	
	for (int i = 1; i < N; ++i)
		d[i] = oo;
	
	d[1] = 0;

	for (int i = 1; i < N / 6; ++i)
		d[i + 1] = min (d[i + 1], d[i] + 1), d[i * 5] = min (d[i * 5], d[i] + 1);
	
	cout << d[100097];
	
	return 0;
}