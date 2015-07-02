#include <bits/stdc++.h>

using namespace std;

const int N = 101;

typedef long long ll;

int a[N][N][N];

ll ans;

int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	ios_base :: sync_with_stdio (0);

	int n;
	
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		
		int temp = (a[x][0][0] + a[0][y][0] + a[0][0][z] - a[x][y][0] - a[x][0][z] - a[0][y][z] + a[x][y][z]); 
		
		temp += - (a[x][y][0] + a[x][0][z] + a[0][y][z] - 3 * a[x][y][z] + a[x][y][z]);
		
		ans += temp;
		
		++a[x][0][0];
		++a[0][y][0];
		++a[0][0][z];
		++a[x][y][0];
		++a[x][0][z];
		++a[0][y][z];
		++a[x][y][z];
	}

	cout << ans;
	return 0;
}