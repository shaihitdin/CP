#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100;

int a[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> a[0] >> a[1];

	int turn = 0, now = 1;

	while (1) {
		if (a[turn] < now) {
			if (turn == 0)
				puts ("Vladik");
			else
				puts ("Valera");
			return 0;
		}
		a[turn] -= now++;		
		turn ^= 1;
	}
	
	
	return 0;
}