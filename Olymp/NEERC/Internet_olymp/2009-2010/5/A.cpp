#include <bits/stdc++.h>

using namespace std;

const int N = 50000;

pair <vector <int>, vector <int> > v1[N], v2[N];
int n;
int m1, m2;
int a[11], b[11];
int l;
vector <pair <int, int> > g1[11], g2[11];

int main () {

	freopen ("ampm.in", "r", stdin);
	freopen ("ampm.out", "w", stdout);

	scanf ("%d", &n);
	
	scanf ("%d", &m1);

	for (int i = 1; i <= m1; ++i)
		scanf ("%d", &a[i]);
	
	scanf ("%d", &m2);

	for (int i = 1; i <= m2; ++i)
		scanf ("%d", &b[i]);
	
	scanf ("%d", &l);

	for (int i = 1; i <= l; ++i) {
		int t1, t2, min1, min2;
		char c11, c12, c21, c22;
		char read_eq;
		scanf ("%02d:%02d%c", &t1, &min1, &c11);
		scanf ("%c", &c12);
		scanf ("%c", &read_eq);
		assert (read_eq == '=');
		scanf ("%02d:%02d%c", &t2, &min2, &c21);
		scanf ("%c\n", &c22);
		if (c11 == c21) {
			if (t1 != t2 || min1 != min2 || c22 != c12) {
				puts ("Inconsistent");
				exit (0);
			}
			continue;
		}
		if (c11 == 'B') {
			swap (t1, t2);
			swap (min1, min2);
			swap (c12, c22);
		}
		g1[c12 - 'A' + 1].emplace_back (make_pair (t1 * 60 + min1, i));
		g2[c22 - 'A' + 1].emplace_back (make_pair (t2 * 60 + min2, i));
	}
	
	int perm[11];
	
	for (int i = 1; i <= m1; ++i) {
		perm[i] = i;
	}

	int type1_cnt = 0, type2_cnt = 0;
	
	for (;;) {
		vector <int> tmp, tmp2;
		tmp.resize (l + 1);
		tmp2.resize (m1 + 1);
		int prev_sum = 0;
		bool flag = 0;
		for (int i = 1; i <= m1; ++i) {
			for (auto it : g1[perm[i]]) {
				tmp[it.second] = it.first + prev_sum;
				flag |= (it.first >= a[perm[i]] * 60);
			}
			prev_sum += 60 * a[perm[i]];
			tmp2[i] = perm[i];
		}
		if (flag) {
			if (!next_permutation (perm + 1, perm + m1 + 1))
				break;
			continue;
		}
		v1[++type1_cnt] = make_pair (tmp, tmp2);
		if (!next_permutation (perm + 1, perm + m1 + 1))
			break;
	}
	
	for (int i = 1; i <= m2; ++i)
		perm[i] = i;
	
	for (;;) {
		vector <int> tmp, tmp2;
		tmp.resize (l + 1);
		tmp2.resize (m2 + 1);
		int prev_sum = 0;
		bool flag = 0;
		for (int i = 1; i <= m2; ++i) {
			for (auto it : g2[perm[i]]) {
				tmp[it.second] = it.first + prev_sum;
				flag |= (it.first >= b[perm[i]] * 60);
			}
			prev_sum += 60 * b[perm[i]];
			tmp2[i] = perm[i];
		}
		if (flag) {
			if (!next_permutation (perm + 1, perm + m2 + 1))
				break;
			continue;
		}
		v2[++type2_cnt] = make_pair (tmp, tmp2);
		if (!next_permutation (perm + 1, perm + m2 + 1))
			break;		
	}
	
	sort (v1 + 1, v1 + type1_cnt + 1);
	sort (v2 + 1, v2 + type2_cnt + 1);

	vector <int> ans, ans1;
	
	for (int i = 1, j = 1; i <= type1_cnt && j <= type2_cnt; ++i) {
		while (j <= type2_cnt && v2[j].first < v1[i].first)
			++j;
		if (j > type2_cnt)
			continue;
		if (v1[i].first == v2[j].first) {
			if (j == type2_cnt || v2[j + 1].first != v1[i].first) {
				if (ans.size ()) {
					puts ("Ambiguous");
					exit (0);
				}
				ans = v1[i].second;
				ans1 = v2[j].second;
			} else if (j != type2_cnt && v2[j + 1].first == v1[i].first) {
				puts ("Ambiguous");
				exit (0);
			}
		}
	}
	
	if (!ans.size ()) {
		puts ("Inconsistent");
		exit (0);
	}
	
	printf ("Alde system: ");

	for (int i = 1; i <= m1; ++i)
		printf ("%d ", ans[i]);
	
	printf ("\n");

	printf ("Baran system: ");

	for (int i = 1; i <= m2; ++i)
		printf ("%d ", ans1[i]);
	
	return 0;
}