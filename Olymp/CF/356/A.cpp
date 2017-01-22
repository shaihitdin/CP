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

const int oo = 1e9, bpr = 1e9 + 7, N = -1;

inline bool is_prime (int x) {
	cout << x << endl;
	fflush (stdout);
	string s;
	cin >> s;
	return (s == "yes");
}

inline bool is_prime2 (int x) {
	for (int i = 2; i * i <= x; ++i)
		if (x % i == 0)
			return 0;
	return 1;
}

inline void pr () {
	cout << "prime\n";
	fflush (stdout);
	exit (0);
}

inline void co () {
	cout << "composite\n";
	fflush (stdout);
	exit (0);
}


int main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	int now = 1;
	int pp = 0;

	for (int i = 2; i <= 10; ++i) {
		while (is_prime2 (i) && is_prime (i * now)) {
			now *= i;
			++pp;
			if (pp > 1) {
				co ();
			}
		}
	}
	
	if (pp == 0) {
		pr ();
		return 0;
	}
	
	for (int i = 11; i * now <= 100; ++i) {
		if (pp > 1) {
			co ();
			return 0;
		}
		if (is_prime2 (i) && is_prime (i))
			++pp;
	}
	
	if (pp == 1) {
		pr ();
		return 0;
	}
	
	co ();

	return 0;
}