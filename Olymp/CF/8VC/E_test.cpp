#include <bits/stdc++.h>

using namespace std;

const int limit = 40;

int main () {

	#ifdef Geodsso
	freopen ("in", "r", stdin);
	#endif

	for (int i = 0; i <= limit; ++i) {
		for (int j = i + 1; j <= limit; ++j) {
			for (int k = j + 1; k <= limit; ++k) {
				double sum1 = fabs ((i + j + k) / 3.0 - j);
				for (int k2 = k + 1; k2 <= limit; ++k2) {
					for (int k3 = k2 + 1; k3 <= limit; ++k3) {       
						double sum2 = fabs ((i + j + k + k2 + k3) / 5.0 - k);
						if (sum1 < sum2) {
							cerr << i << " " << j << " " << k << " " << k2 << " " << k3 << " $ " << sum1 << " " << sum2 << "\n";
							cout << "WRONG";
							return 0;
						}
					}
				}
			}
		}
	}

	cout << "NOT WRONG";
	
	return 0;
}