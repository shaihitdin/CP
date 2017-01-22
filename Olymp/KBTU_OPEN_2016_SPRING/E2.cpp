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
  
const int oo = 1e9, bpr = 1e9 + 7, N = 5050;

#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fe first
#define se second

int cnt[N];

inline int min_divisor (int x) {
	for (int i = 2; i * i <= x; ++i)
		if (x % i == 0)
			return i;
	return x;
}
/*
int ans;
vector <vector <pair <int, int> > > ansc;
vector <pair <int, int> > cc;

inline void rec (int n) {
 	for (int i = 1; i < N; ++i) {
		if (!cnt[i])
			continue;
		if (n == 1) {
			if (ans > i) {
				ansc.clear ();
				ans = i;
			}
			ansc.eb (cc);
			return;
		}
		--cnt[i];
		for (int j = i; j < N; ++j) {
			if (!cnt[j])
				continue;
			--cnt[j];
			++cnt[min_divisor (i + j)];
			cc.eb (mp (i, j));
			rec (n - 1);
			cc.pop_back ();
			--cnt[min_divisor (i + j)];
			++cnt[j];
		}
		++cnt[i];
	}
}
*/
int main() {

	freopen ("erase-challenge.in", "r", stdin);
	freopen ("erase-challenge.out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
/*	
	for (int n = 1; n <= 10; ++n) {
		fclose (stderr);
		char name[10] = "bad";
		name[3] = '0' + n;
		freopen (name, "w", stderr);
		memset (cnt, 0, sizeof (cnt));
		for (int i = 1; i <= n; ++i)
			cnt[i] = 1;
		for (int step = 1; step < n; ++step) {
			for (int i = N - 1; i >= 0; --i) {
				if (!cnt[i])
					continue;
				--cnt[i];
				for (int j = i; j >= 0; --j) {
					if (!cnt[j])
						continue;
					--cnt[j];
					++cnt[min_divisor (i + j)];
					goto end;
				}
			}
			end:;
		}
		for (int i = 1; i < N; ++i)
			if (cnt[i])
				cerr << i;		
	}
*/	
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cnt[i] = 1;
	
	vector <pair <int, int> > cc;
	
	for (int step = 1; step < n; ++step) {
		for (int i = N - 1; i >= 1; --i) {
			if (!cnt[i])
				continue;
			--cnt[i];
			for (int j = i; j >= 1; --j) {
				if (!cnt[j])
					continue;
				--cnt[j];
				cc.eb (mp (i, j));
				++cnt[min_divisor (i + j)];
				goto end;
			}
		}
		end:;
	}
	
	for (int i = 1; i < N; ++i)
		if (cnt[i])
			cout << i;
	
	cout << "\n";

	for (auto it : cc)
		cout << it.fe << " " << it.se << "\n";
	
	return 0;
}