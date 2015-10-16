#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 100;

int t[2][N];
int n;

inline void upd (const int &num, int r, const int &delta) {
	for (; r < N; r |= (r + 1))
		t[num][r] += delta;
}

inline int get (const int &num, int r) {
	int res = 0;
	for (; r >= 0; r = (r & (r + 1)) - 1)
		res += t[num][r];
	return res;
}

inline int get (const int &num, int l, int r) {
	return get (num, r) - get (num, l - 1);
}

map <int, int> Map, t_pos;
set <int> Set;

long long ans;

int main () {
	
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);


	cin >> n;

	for (int i = 1; i <= n; ++i) {
		int a, b;
		cin >> a >> b;
		if (!Map.count (a))
			Map[a] = a;
		if (!Map.count (b))
			Map[b] = b;
		swap (Map[a], Map[b]);
		Set.insert (a);
		Set.insert (b);
	}

	int i = 1;	
	
	for (auto it = Set.begin (); it != Set.end (); ++i, ++it)
		t_pos[*it] = i;

	for (auto it = Map.begin (); it != Map.end (); ++it) {
		int pos = it -> first, el = it -> second;
		if (pos > el)
			ans += (abs (pos - el) - 1 - get (0, t_pos[el] + 1, t_pos[pos] - 1));
		ans += get (1, t_pos[el] + 1, N - 1);
		upd (0, t_pos[pos], 1);
		upd (1, t_pos[el], 1);
		//cerr << pos << " " << ans << "\n";
	}
		
	//cerr << ans << " ";

	memset (t, 0, sizeof (t));
	
	for (auto it = Map.rbegin (); it != Map.rend (); ++it) {
		int pos = it -> first, el = it -> second;
		if (pos < el)
			ans += (abs (pos - el) - 1 - get (0, t_pos[pos] + 1, t_pos[el] - 1));
		//ans += get (1, t_pos[el]
		upd (0, t_pos[pos], 1);
		upd (1, t_pos[el], 1);

	}
	
	cout << ans;

	return 0;
}