/// izizi

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
  
const int oo = 1e9, bpr = 1e9 + 7, N = 5;

#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

int a[N][N];
int cnt1[N][N], cnt2[N][N], cnt4[N][N], cnt3[N][N][N];
vector <int> b[3], best[3];
int J, P, S, k;

inline void rec (int x, int k1, int k2) {
	if (x > S) {
		if (best[0].size () < b[0].size ())
			for (int i = 0; i < 3; ++i)
				best[i] = b[i];
		return;
	}
	for (int i = k1; i <= J; ++i) {
		for (int j = ((i == k1) ? (k2) : (1)); j <= P; ++j) {
			if (cnt1[x][i] < k && cnt2[i][j] < k && cnt4[x][j] < k && !cnt3[x][i][j]) {
				++cnt1[x][i];
				++cnt2[i][j];
				++cnt4[x][j];
				++cnt3[x][i][j];
				b[2].pb (x);
				b[0].pb (i);
				b[1].pb (j);
				rec (x, i, j);
				--cnt1[x][i];
				--cnt2[i][j];
				--cnt4[x][j];				
				--cnt3[x][i][j];
				b[0].pop_back ();
				b[1].pop_back ();
				b[2].pop_back ();
			}
		}
	}
	rec (x + 1, 1, 0);
}

int main() {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	int test_num;

	cin >> test_num;

	for (int test = 1; test <= test_num; ++test) {
		cout << "Case #" << test << ": ";
		cin >> J >> P >> S >> k;
		cerr << test << "\n";
		for (int i = 0; i < 3; ++i)
			best[i].clear ();
		rec (1, 1, 0);
		cout << best[0].size () << "\n";
		for (int i = 0; i < (int)best[0].size (); ++i) {
			for (int j = 0; j < 3; ++j)
				cout << best[j][i] << " ";
			cout << "\n";
		}
	}
	
	return 0;
}