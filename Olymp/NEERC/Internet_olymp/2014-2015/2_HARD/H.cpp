#include <bits/stdc++.h>

using namespace std;
                                                 
int n, m, k;

int main () {

	freopen ("run.in", "r", stdin);
	freopen ("run.out", "w", stdout);

    cin >> n >> m >> k;
    int mn = 1e9 + 9;
    for (int i = 1; i <= m; ++i) {
    	int a, b, c;
    	cin >> a >> b >> c;
    	mn = min(mn, c);
    }    

    cout << mn * (k - 1) << "\n";
	
	return 0;
}
