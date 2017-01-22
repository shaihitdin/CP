#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define int ll

const int N = 3e5 + 100;

int s, x;

inline int bit (int mask, int pos) {
	return (mask >> pos) & 1;
}

int dp[50][2][2][2][2];
bool part1lbit[50], part1rbit[50], part2lbit[50], part2rbit[50];
int part1l, part1r, part2l, part2r;

inline bool tryto (bool flag1, bool flag2, bool tries, bool real1, bool real2) {
	if (flag1 == 1 && flag2 == 1) {
		return real1 <= tries && tries <= real2;
	} else if (flag1 == 1) {
		return real1 <= tries;
	} else if (flag2 == 1) {
		return tries <= real2;
	} else {
		return 1;
	}
}

inline pair <bool, bool> tryto2 (bool flag1, bool flag2, bool tries, bool real1, bool real2) {
	if (flag1 == 1 && flag2 == 1) {
		return make_pair (!(real1 < tries), !(tries < real2));
	} else if (flag1 == 1) {
		return make_pair (!(real1 < tries), 0);
	} else if (flag2 == 1) {
		return make_pair (0, !(tries < real2));
	} else {
		return make_pair (0, 0);
	}
}

inline int calc (int pos, bool flag1, bool flag2, bool flag3, bool flag4) {
	if (pos == -1)
		return 1;
	if (dp[pos][flag1][flag2][flag3][flag4] != -1)
		return dp[pos][flag1][flag2][flag3][flag4];
	int res = 0;
	if (bit (x, pos)) {
		cerr << "TYPE1 ";
		cerr << pos << " " << flag1 << " " << flag2 << " " << flag3 << " " << flag4 << " ";
		if (tryto (flag1, flag2, 0, part1lbit[pos], part1rbit[pos]) && tryto (flag3, flag4, 1, part2lbit[pos], part2rbit[pos])) {
			cerr << "OK1\n";
			auto nval1 = tryto2 (flag1, flag2, 0, part1lbit[pos], part1rbit[pos]);
			auto nval2 = tryto2 (flag3, flag4, 1, part2lbit[pos], part2rbit[pos]);
			res += calc (pos - 1, nval1.first, nval1.second, nval2.first, nval2.second);
		}
		if (tryto (flag1, flag2, 1, part1lbit[pos], part1rbit[pos]) && tryto (flag3, flag4, 0, part2lbit[pos], part2rbit[pos])) {
			auto nval1 = tryto2 (flag1, flag2, 1, part1lbit[pos], part1rbit[pos]);
			auto nval2 = tryto2 (flag3, flag4, 0, part2lbit[pos], part2rbit[pos]);
			res += calc (pos - 1, nval1.first, nval1.second, nval2.first, nval2.second);
		}
	} else {
		cerr << "TYPE2 ";
		cerr << pos << " " << flag1 << " " << flag2 << " " << flag3 << " " << flag4 << "\n";
		if (tryto (flag1, flag2, 0, part1lbit[pos], part1rbit[pos]) && tryto (flag3, flag4, 0, part2lbit[pos], part2rbit[pos])) {
			auto nval1 = tryto2 (flag1, flag2, 0, part1lbit[pos], part1rbit[pos]);
			auto nval2 = tryto2 (flag3, flag4, 0, part2lbit[pos], part2rbit[pos]);
			res += calc (pos - 1, nval1.first, nval1.second, nval2.first, nval2.second);
		}		
		if (tryto (flag1, flag2, 1, part1lbit[pos], part1rbit[pos]) && tryto (flag3, flag4, 1, part2lbit[pos], part2rbit[pos])) {
			cerr << "OK3";			
			auto nval1 = tryto2 (flag1, flag2, 1, part1lbit[pos], part1rbit[pos]);
			auto nval2 = tryto2 (flag3, flag4, 1, part2lbit[pos], part2rbit[pos]);
			res += calc (pos - 1, nval1.first, nval1.second, nval2.first, nval2.second);
		}		
	}
	return dp[pos][flag1][flag2][flag3][flag4] = res;
}

main () {

	#ifdef UNBROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> s >> x;

	part1l = 1, part1r = s / 2;
	part2l = (s + 1) / 2, part2r = s - 1;

	cerr << part1l << " " << part1r << " " << part2l << " " << part2r << "\n";
	
	for (int i = 0; i <= 42; ++i) {
		part1lbit[i] = bit (part1l, i);
		part1rbit[i] = bit (part1r, i);
		part2lbit[i] = bit (part2l, i);
		part2rbit[i] = bit (part2r, i);
	}
	
	memset (dp, -1, sizeof (dp));
	
	cout << calc (42, 1, 1, 1, 1) * 2;
	
	return 0;
}