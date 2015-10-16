#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

int a[N];

int main () {

	memset (a, -1, sizeof (a));

	for (int i = 1; i < N; ++i)
		a[i] = -1;
	
	a[0] = 0;
	
	for (int i = 1; i < N; ++i) {
		if (a[i - 1] == 0 || a[i - (i / 2)] == 0) {
			a[i] = 1;
		} else {
			a[i] = 0;
		}
	}
	
		
	cout << a[17972] << " " << a[12514] << " " << a[17286] << " " << a[15878] << " " << a[17515];

		
	
	return 0;
}