#include <bits/stdc++.h>

using namespace std;

int main () {

	int n = 1000;
	long long ans = 0;
	
	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; ++j)
			for (int k = i; k < j; ++k)
				for (int l = 0; l < k - i; ++l)
					++ans;
	cout << ans;
	
	return 0;
}