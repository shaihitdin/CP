#include <bits/stdc++.h>

using namespace std;

const int N = 3501;
bool u[N];

int main () {

	for (int i = 2; i < N; i += 2)
		u[i] = 1;
	
	for (int i = 3; i < N; i += 3)
		u[i] = 1;
	
	for (int i = 5; i < N; i += 5)
		u[i] = 1;
	
	for (int i = 7; i < N; i += 7)
		u[i] = 1;
	
	
	int ans = 0;

	for (int i = 1; i < N; ++i)
		if (!u[i])
			++ans;
	
	cout << ans;
	
	return 0;
}