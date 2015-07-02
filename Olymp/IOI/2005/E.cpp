#include <bits/stdc++.h>

using namespace std;

#define bug(x) cerr << #x << " " << x << "\n";

inline int Find (int x, const int &y) {
	while ((x & 1) && x != 1)
		x >>= 1;
	for (int n_val = (x << 1) + 1; n_val <= y; x = n_val, n_val = (x << 1) + 1);
	return x;
}

inline bool can (const int &oldx, const int &oldy, const int &nx, const int &ny) {
	if (oldx == nx && oldy == ny)
		return 0;
	if (oldx != nx && oldy != ny)
		return 0;
	else if (oldx != nx)
		return nx < oldx && nx + nx >= oldx;
	else
		return ny < oldy && ny + ny >= oldy;
		
}

int main () {
	while (1) {
		int x, y;
		cin >> x >> y;
		
		if (x == -1 && y == -1)
			return 0;
		if (can (x, y, x, Find (x, y)))
			cout << "H " << Find (x, y) << "\n";
		else if (can (y, x, y, Find (y, x)))
			cout << "V " << Find (y, x) << "\n";
		else
			cout << "V " << 1000000000 << "\n";

		cout.flush ();
	}

}