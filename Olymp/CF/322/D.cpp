#include <bits/stdc++.h>

using namespace std;

const int N = 400;

char u[N][N];

pair <int, pair <int, int> > p[5];
int t_sz;

inline bool bit (const int &mask, const int &pos) {
	return (mask >> pos) & 1;
}

inline int calc (int num) {
	t_sz = 0;
	if (!bit (num, 2)) {
		t_sz += p[0].second.first;
	} else {
		//t_sz += p[0].second.second;
	}
	if (!bit (num, 1)) {
		t_sz += p[1].second.first;
	} else {
		//t_sz += p[1].second.second;
	}
	if (!bit (num, 0)) {
		t_sz += p[2].second.first;
	} else {
		//t_sz += p[2].second.second;
	}
	return t_sz;
}

inline bool doit (const int &sz) {
	memset (u, 0, sizeof (u));
	int cnt = 0;
	for (int i = 1; i <= sz; ++i) {
		for (int j = 1; j <= sz; ++j) {
			if (!u[i][j]) {
				if (cnt == 3)
					return 0;
				if (i + p[cnt].second.first - 1 <= sz && j + p[cnt].second.second - 1 <= sz) {
					for (int k1 = i; k1 <= i + p[cnt].second.first - 1; ++k1)
						for (int k2 = j; k2 <= j + p[cnt].second.second - 1; ++k2)
							if (u[k1][k2])
								return 0;
							else
								u[k1][k2] = 'A' + p[cnt].first;
				} else {
					return 0;
				}
				++cnt;
			}
		}
	}
	return cnt == 3;
}

inline bool make_try () {
	calc (0);
	if (doit (t_sz))
		return 1;
	calc (1);
	if (doit (t_sz))
		return 1;
	calc (2);
	if (doit (t_sz))
		return 1;
	calc (3);
	if (doit (t_sz))
		return 1;
	calc (4);
	if (doit (t_sz))
		return 1;
	calc (5);
	if (doit (t_sz))
		return 1;
	calc (6);
	if (doit (t_sz))
		return 1;
	calc (7);
	if (doit (t_sz))
		return 1;
	return 0;
}

inline void rec (const int &lvl) {
	if (lvl == 3) {
		if (make_try ()) {
			cout << t_sz << "\n";
			for (int i = 1; i <= t_sz; ++i) {
				for (int j = 1; j <= t_sz; ++j) {
					cout << u[i][j];
				}
				cout << "\n";
			}
			exit (0);
		}
		return;
	}
	swap (p[lvl].second.first, p[lvl].second.second);
	rec (lvl + 1);
	swap (p[lvl].second.first, p[lvl].second.second);
	rec (lvl + 1);
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> p[0].second.first >> p[0].second.second >> p[1].second.first >> p[1].second.second >> p[2].second.first >> p[2].second.second;

	p[0].first = 0;
	p[1].first = 1;
	p[2].first = 2;

	sort (p, p + 3);

	for (;;) {
		rec (0);
		if (!next_permutation (p, p + 3))
			break;
	}

	cout << -1;
	
	return 0;
}