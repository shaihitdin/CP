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

int fignya[4][13][32][25][61];

inline int parse (int year, int month, int day, int minute, int second) {
    year -= 2013;
    //cerr << year << " " << month << " " << day << " " << minute << " " << second << "\n";
    return fignya[year][month][day][minute][second];
}

int mnth[13];

main() {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	int test;

	scanf ("%d", &test);

	mnth[1] = 31;
	mnth[2] = 28;
	mnth[3] = 31;
	mnth[4] = 30;
	mnth[5] = 31;
	mnth[6] = 30;
	mnth[7] = 31;
	mnth[8] = 31;
	mnth[9] = 30;
	mnth[10] = 31;
	mnth[11] = 30;
	mnth[12] = 31;

	int pp = 0;
    for (int i1 = 0; i1 < 4; ++i1)
    for (int i2 = 1; i2 < 13; ++i2)
    for (int i3 = 1; i3 <= mnth[i2] + (i2 == 2 && i1 == 3); ++i3)
    for (int i4 = 0; i4 < 24; ++i4)
    for (int i5 = 0; i5 < 60; ++i5)
        fignya[i1][i2][i3][i4][i5] = ++pp;

	while (test--) {
        int n, k;
        scanf ("%d%d\n", &n, &k);
        map <int, int> add;
        for (int i = 1; i <= n; ++i) {
            scanf ("%*s ");
            int y_in, m_in, d_in, min_in, sec_in;
            int y_out, m_out, d_out, min_out, sec_out;
            scanf ("%d-%d-%d %d:%d ", &y_in, &m_in, &d_in, &min_in, &sec_in);
            scanf ("%d-%d-%d %d:%d\n", &y_out, &m_out, &d_out, &min_out, &sec_out);
            /*
            min_in %= 24;
            min_out %= 24;
            */
            ++add[parse (y_in, m_in, d_in, min_in, sec_in)];
            --add[parse (y_out, m_out, d_out, min_out, sec_out) + k];
        }
        int now = 0, mx = 0;
        for (auto it : add) {
            now += it.se;
            mx = max (mx, now);
        }
        printf ("%d\n", mx);
	}

	return 0;
}