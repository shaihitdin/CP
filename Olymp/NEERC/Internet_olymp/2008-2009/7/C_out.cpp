#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)

typedef long long ll;

const int N = 1e5 + 100;

bool bit(int mask, int pos) {
	return (mask) & (1 << pos);
}

int a[N] = {0, 1, 2, 3, 5, 8, 14, 25, 45, 85, 162, 310, 595, 1165, 2285, 4485, 8808, 17306, 34302, 68009, 134853};
//int a[N];  

int main () {

	freopen ("chipmunks.in", "r", stdin);
	freopen ("chipmunks.out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n;  
	cin >> n;

	cout << a[n];

	return 0;
}