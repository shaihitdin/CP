#include <bits/stdc++.h>

using namespace std;

string a[4][7] = {
{"ilnT", "imNs", "imOT", "jMms", "jMnT", "jNNs", "jNOT", },
{"ilnU", "imNt", "imOU", "jMmt", "jMnU", "jNNt", "jNOU", },
{"ilnV", "imNu", "imOV", "jMmu", "jMnV", "jNNu", "jNOV", },
{"ilnW", "imNv", "imOW", "jMmv", "jMnW", "jNNv", "jNOW", },
};

int main () {

	freopen ("hash.in", "r", stdin);
	freopen ("hash.out", "w", stdout);

	int k;

	cin >> k;

	for (int i1 = 0, cnt = 0; i1 < 7; ++i1) {
		for (int i2 = 0; i2 < 7; ++i2) {
			for (int i3 = 0; i3 < 7; ++i3) {
				for (int i4 = 0; i4 < 7; ++i4, ++cnt) {
					if (cnt == k)
						return 0;
					cout << a[0][i1] + a[1][i2] + a[2][i3] + a[3][i4] << "\n";
				}
			}
		}
	}
	
	return 0;
}