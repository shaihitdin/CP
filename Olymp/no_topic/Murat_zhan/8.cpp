#include <bits/stdc++.h>

using namespace std;

const int N = 3501;
bool u[N];

int main () {

	int ans = 0;
	for (int i = 1; i <= 20; ++i)
		for (int j = 1; j <= 20; ++j)
			if ((i + j) % 5 == 0)
				++ans;
	
	cout << ans;
	
	return 0;
}