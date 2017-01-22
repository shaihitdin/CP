#include <bits/stdc++.h>

using namespace std;

long long n, a[20];

int main () {

    for (int i = 1; i < 20; ++i)
    	a[i] = 2e9;

    cin >> n >> a[1] >> a[2] >> a[3];

	a[2] = min (a[2], a[1] + a[1]);
	a[3] = min (a[3], a[2] + a[1]);
	
	for (int i = 4; i < 20; ++i) {
		for (int j = 1; j <= 3; ++j) {
			a[i] = min (a[i], a[i - j] + a[j]);
		}
	}
    
   	for (int i = 1; i < 20; ++i)
   		a[i % 4] = min (a[i % 4], a[i]);
   	
   	n %= 4;

   	cout << a[(4 - n) % 4]; 
	
	return 0;
}