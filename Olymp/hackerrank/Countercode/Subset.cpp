#include <bits/stdc++.h>

using namespace std;

const int MAGIC = 400;
const int N = 2e5 + 10;

string q_type[N];
int x[N];
int cnt[1 << 16], d[1 << 16];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int q;
	cin >> q;
	
	int lst_upd = 0;
	
	for (int q_num = 1; q_num <= q; ++q_num) {
		cin >> q_type[q_num] >> x[q_num];
		if (q_type[q_num][0] == 'a') {
			++cnt[x[q_num]];
		} else if (q_type[q_num][0] == 'd') {
			--cnt[x[q_num]];
		} else {
			int ans = d[x[q_num]];
			for (int i = lst_upd + 1; i < q_num; ++i) {
				if (q_type[i][0] == 'a' && ((x[i] & x[q_num]) == x[i]))
					++ans;
				else if (q_type[i][0] == 'd' && ((x[i] & x[q_num]) == x[i]))
					--ans;
			}
			cout << ans << "\n";
		}
		if (q_num - lst_upd == MAGIC) {
			memcpy (d, cnt, sizeof (cnt));
			for (int i = 0; i < 16; ++i)
				for (int j = 0; j < (1 << 16); ++j)
					if (!((j >> i) & 1))
						d[j | (1 << i)] += d[j];
			lst_upd = q_num;
		}
	}

	return 0;
}