/// Stupido del problemo

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
#include <iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1);
  
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

const int oo = 1e9, bpr = 1e9 + 7, N = 33000;

int a[N];
int n;

int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		assert (a[i] < 2);
	}	
	a[n + 1] = 2;

	for (int i = 1; i <= n; ++i) {
		if (a[i] == 0)
			continue;
		int end = i;
		while (end <= n && a[end] == a[i])
			++end;
		--end;
		if (end == n)
			break;
		int end2 = end + 1;
		while (end2 <= n && a[end2] == !a[i])
			++end2;
		--end2;
		reverse (a + i, a + end2 + 1);
		cout << i << " " << end2 << "\n";
	}

/*	
	while (1) {
		int cnt = 0;
		for (int i = -1, j = 1; i != n + 1;) {
			i = j + 1;
			while (a[i - 1] >= a[i])	++i;
			
			bool flag = 1;

			for (int kk = j; kk < i; ++kk)
				flag &= (a[kk] == a[j]);
			
			if (flag) {
				cnt += i - j;
				j = i;
				continue;
			}
			cout << j << " " << i - 1 << "\n";
			reverse (a + j, a + i);
			j = i;
		}
		if (cnt == n)
			break;
	}	
*/
	return 0;
}