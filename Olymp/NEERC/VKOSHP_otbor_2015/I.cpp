#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100;

ll n;            

int main () {

	//#ifdef LOCAL
	freopen ("sapsan.in", "r", stdin);
	freopen ("sapsan.out", "w", stdout);
	//#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;

	cout <<  4 * (n / 6) << "\n";
	
	return 0;
}