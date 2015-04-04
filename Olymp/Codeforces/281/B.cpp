#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
#define ah return 0;
long long n, x, sum[3];
vector <long long> v[3];
int main () {
	scanf ("%I64d", &n);
	++n;
	while (--n) {
		scanf ("%I64d", &x);
		if (x < 0) {
			v[2].push_back ((-x));
			sum[2] += (-x);
		}
		else {
			v[1].push_back (x);
			sum[1] += x;
		}
	}
	if (sum[1] > sum[2]) {
		cout << "first";
		ah
	}
	if (sum[1] < sum[2]) {
		cout << "second";	
		ah
	}
	if (v[1] > v[2]) {
		cout << "first";	
		ah
	}
	if (v[1] < v[2]) {
		cout << "second";	
		ah
	}
	if (x > 0) {
		cout << "first";
		ah
	}
	else {
		cout << "second";
		ah
	}
} 