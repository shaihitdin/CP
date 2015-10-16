#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;

typedef long long ll;

char q_type[N];
int x[N], y[N], z[N];
int cnt[N];
int n, m;

ll lst_build_cnt[N];
int lst_build_un[N], lst_build_recruit[N];
vector <int> recruit[N], un[N];

inline void process (const int &from_q, const int &to_q, ll &now_cnt, int &now_un, int &now_recruit) {
	for (int j = from_q + 1; j < to_q; ++j) {
		if (q_type[j] == 'U' && now_un == y[j]) {
			now_un = x[j];
		} else if (q_type[j] == 'M' && now_recruit == y[j]) {
			now_recruit = x[j];
		} else if (q_type[j] == 'A' && now_un == x[j]) {
			now_cnt += z[j];
		} else if (q_type[j] == 'Z' && now_recruit == x[j]) {
			now_cnt = 0;
		}
	}
}

inline void process_f (const int &from_q, const int &to_q) {
	for (int j = from_q + 1; j < to_q; ++j) {
		if (q_type[j] == 'U') {
		
		} else if (q_type[j] == 'M') {
		
		} else if (q_type[
	}
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	scanf ("%d%d\n", &n, &m);

	int MAGIC = sqrt (m) + 2;
	int lst_end = 0;
	
	for (int i = 1; i <= n; ++i) {
		lst_build_un[i] = lst_build_recruit[i] = i;
		cnt[i] = 1;
	}
	
	for (int i = 1; i <= m; ++i) {
		scanf ("%c", &q_type[i]);
		if (q_type[i] == 'U') {
			scanf ("%d%d", &x[i], &y[i]);
			cnt[x[i]] += cnt[y[i]];
		} else if (q_type[i] == 'M') {
			scanf ("%d%d", &x[i], &y[i]);
		} else if (q_type[i] == 'A') {
			scanf ("%d", &x[i]);
			z[i] = cnt[x[i]];
		} else if (q_type[i] == 'Z') {
			scanf ("%d", &x[i]);
		} else {
		    if (i - lst_end > MAGIC) {
				for (int j = 1; j <= n; ++j)
					process (lst_end, i, lst_build_cnt[j], lst_build_un[j], lst_build_recruit[j]);
				lst_end = i;
		    }
			scanf ("%d", &x[i]);
			ll now_cnt = lst_build_cnt[x[i]];
			int now_un = lst_build_un[x[i]], now_recruit = lst_build_recruit[x[i]];
			process (lst_end, i, now_cnt, now_un, now_recruit);
			printf ("%I64d\n", now_cnt);
		}
		scanf ("\n");
	}

	return 0;
}