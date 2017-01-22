/// Forever

#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1);
  
const int oo = 1e9, bpr = 1e9 + 7, N = 2e5 + 100;

#define mp make_pair

char s[N];
int d[N];
int n;

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> s[i];
	
	for (int i = 1; i <= n; ++i)
		cin >> d[i];
	
	for (int i = 1; i <= n; ++i)
		if (s[i] == '<')
			d[i] = -d[i];
	
	for (int i = 1, j = 1; i <= n + n; ++i) {
		j += d[j];
		if (j < 1 || j > n) {
			cout << "FINITE";
			return 0;
		}
	}
	
	
	cout << "INFINITE";

	return 0;
}