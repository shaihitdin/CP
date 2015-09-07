#include <bits/stdc++.h>

using namespace std;

const int N = 2e5;

int x[N], y[N];
bool c[N];
int n, m;

set <pair <int, int> > Set;

typedef long long ll;


inline ll triangle_area (const int &p1, const int &p2, const int &p3) {
	return abs ((x[p2] - x[p1]) * 1ll * (y[p3] - y[p1]) - (y[p2] - y[p1]) * 1ll * (x[p3] - x[p1]));
}

inline bool inside (const int &p1, const int &p2, const int &p3, const int &p4) {
	return (triangle_area (p1, p2, p4) + triangle_area (p1, p3, p4) + triangle_area (p2, p3, p4)) == triangle_area (p1, p2, p3);
}

inline void print_edge (const int &p1, const int &p2) {
	if (Set.find (make_pair (p1, p2)) != Set.end ())
		return;
	if (c[p1] == 0)
		cout << p1 << " " << p2 << " g\n";
	else
		cout << p1 - n << " " << p2 - n << " r\n";
	Set.insert (make_pair (p1, p2));
	Set.insert (make_pair (p2, p1));
}

inline void rec (const vector <int> &v, const int &p1, const int &p2, const int &p3) {
	/*	
	cerr << p1 << " " << p2 << " " << p3 << " IS A TRIANGLE\n";

	cerr << "LIST OF POINTS INSIDE OF THEM: ";

	for (auto it : v)
		cerr << it << " ";
	
	cerr << "\n";

	*/

	print_edge (p1, p2);
	
	if (v.size () == 0)
		return;
	
	int chosen_point = -1;
	bool flag1 = 0, flag2 = 0;
	for (auto it : v) {
		if (c[it] == c[p3])
			if (chosen_point == -1 /*|| rand () & 1 */)
				chosen_point = it;
		if (c[it] == c[p1])
			flag1 = 1;
		else
			flag2 = 1;
	}
	
	if (flag1 ^ flag2 == 1) {
		if (flag1 == 1)
			for (auto it : v)
				print_edge (it, p1);
		else
			for (auto it : v)
				print_edge (it, p3);
		return;
	}

	vector <int> part[3];
	
	for (auto it : v) {
		if (it == chosen_point)
			continue;
		if (inside (p3, chosen_point, p2, it))
			part[0].emplace_back (it);
		else if (inside (p3, chosen_point, p1, it))
			part[1].emplace_back (it);
		else
			part[2].emplace_back (it);
	}
	rec (part[0], p3, chosen_point, p2);
	rec (part[1], p3, chosen_point, p1);
	rec (part[2], p1, p2, chosen_point);
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i];
		c[i] = 0;
	}

	cin >> m;

	for (int i = n + 1; i <= n + m; ++i) {
		cin >> x[i] >> y[i];
		c[i] = 1;
	}
	
	int p1 = n + 1, p2 = n + 2, p3 = 1, p4 = 2; /// p1 = (0, 0), p2 = (s, 0), p3 = (0, s), p4 = (s, s);
	
	vector <int> f_s, s_s;

	for (int i = 1; i <= n + m; ++i) {
		if (i == 1 || i == 2 || i == n + 1 || i == n + 2)
			continue;
		if (inside (p1, p2, p3, i))
			f_s.emplace_back (i);
		else
			s_s.emplace_back (i);
	}
	
	rec (f_s, p1, p2, p3);
	rec (s_s, p3, p4, p2);
	
	return 0;
}