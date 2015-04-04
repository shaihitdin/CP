#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define begin hahah

const int N = 1e5 + 2;
const int inf = 2e9 + 1;

int block, n;

int ba[321][N];

ll l[N], r[N], x[N], y[N], b_num[N], a[N], b[N], m;
ll was[N], add[N], sub[N], temp[N];
int begin[N];

inline void recalc (const int &bl) {
	int i = 1;
	for (; b_num[i] != bl; ++i);
	memset (was, 0, sizeof (was));
	memset (add, 0, sizeof (add));
	memset (temp, 0, sizeof (was));
	memset (sub, 0, sizeof (add));
	for (int j = i; b_num[j] == bl; ++j) {
		was[l[j]] += x[j];
		add[l[j] + 1] += y[j];
		add[r[j] + 1] -= y[j];
		sub[r[j] + 1] += (x[j] + y[j] * 1ll * (r[j] - l[j]));
	}
	ll now = 0;
	for (int i = 1; i <= n; ++i) {
		now += add[i];
		temp[i] = was[i] - sub[i] + temp[i - 1] + now;
	}
	for (int i = 1; i <= n; ++i) {
		ba[bl][i] = min (inf * 1ll, temp[i] + ba[bl - 1][i]);
	}
	return;
}

int main () {
	freopen ("jam.in", "r", stdin);
	freopen ("jam.out", "w", stdout);
	ios_base :: sync_with_stdio (0);
	cin >> n;
	block = sqrt (n);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		cin >> b[i];

	for (int i = 1; i <= n; ++i)
		ba[0][i] = a[i];
	
	cin >> m;
	
	for (int i = 1; i <= m; ++i) {
		cin >> l[i] >> r[i] >> x[i] >> y[i];
		b_num[i] = i / block + 1;
		if (b_num[i] != b_num[i - 1])
			begin[b_num[i]] = i;
	}

	for (int i = 1; i <= b_num[m]; ++i)
		recalc (i);
	/*	
	for (int i = 0; i <= b_num[m]; ++i) {
		for (int j = 1; j <= n; ++j) {
			cerr << ba[i][j] << " ";
		}
		cerr << "\n";
	}
	*/
	for (int i = 1; i <= n; ++i) {
		if (a[i] >= b[i]) {
			cout << "0 ";
			continue;
		}
		bool flag = 0;
		for (int j = 1; j <= b_num[m]; ++j) {
			if (ba[j][i] >= b[i]) {
				flag = 1;
				ll te = ba[j - 1][i];
				int start = begin[j];
				for (; te < b[i]; ++start)
					if (l[start] <= i && i <= r[start])
						te += 1ll * x[start] + y[start] * (i - l[start]);
				--start;
				cout << start << " ";
				flag = 1;
				break;
			}
		}
		if (!flag)
			cout << "-1 ";
	}
	
	return 0;
}