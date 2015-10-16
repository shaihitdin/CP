#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)

typedef long long ll;
typedef pair <int, int> PII;

const int N = 3e5 + 100;

int d, n, len;
ll a[N], res[N];

int main () {

	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	
	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> d >> n >> len;
	forn(_, 1, d) {
		ll sum = 0;
		forn(i, 1, n) {
			cin >> a[i];
			sum += a[i];
			if (i >= len) {	
			    res[i - len + 1] += sum;
				sum -= a[i - len + 1];	
			}	
		}	
	}

	int ans = 1;
	forn(i, 2, n - len + 1)
		if (res[ans] < res[i])
			ans = i;
	
	cout << ans << " " << res[ans] << "\n";	
	
	return 0;
}