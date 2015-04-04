#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 8e7;
bool u[N];
int main () {
	freopen ("out", "w", stdout);
	for (int i = 4; i < N; i += 2) {
		u[i] = 1;
	}
	for (int i = 3; i * i < N; i += 2) {
		if (!u[i]) {
			for (int j = i * i; j < N; j += (2 * i) ) {
				u[j] = 1;				
			}
		}
	}
	for (int i = 4000001; i < N; ++i)
		if(!u[i]) {
			cout << i;
			return 0;
		}
	return 0;
}