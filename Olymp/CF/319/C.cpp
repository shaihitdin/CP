#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 100;

int n;

struct dotss {
	int id, x, y;
};

typedef long long ll;

dotss a[N];

inline bool cmp (const dotss &lhs, const dotss &rhs) {
	if (lhs.x == rhs.x)
		return lhs.y < rhs.y;
	return lhs.x < rhs.x;
}

inline ll check (const vector <int> &b) {
	ll res = 0;
	for (int i = 1; i < b.size (); ++i)
		res += abs (a[b[i - 1]].x - a[b[i]].x) + abs (a[b[i - 1]].y - a[b[i]].y);
	return res;
}

inline vector <int> rec (vector <dotss> sf, vector <dotss> tf, const int &lx, const int &rx) {
	vector <int> ans, tmp;
	ll res1 = 0, res2 = 0;
	
	if (!sf.size ())
		return ans;

	if (rx - lx <= 5) {
		for (auto it : sf)
			ans.emplace_back (it.id);
		return ans;
	}
	
	int mid = (lx + rx) / 2;

	vector <dotss> part1, part2, part1t, part2t;

	for (auto it : sf) {
		if (it.x <= mid)
			part1.emplace_back (it);
		else
			part2.emplace_back (it);
	}
	
	for (auto it : tf) {
		if (it.x <= mid)
			part1t.emplace_back (it);
		else
			part2t.emplace_back (it);
	}
	
	vector <int> ans1;
	tmp = rec (part1, part1t, lx, mid);
	ans1 = rec (part2, part2t, mid + 1, rx);
	
	if (!tmp.size () || !ans1.size ())
		ans = tmp.size () ? tmp : ans1;
	
	for (auto it : ans1)
		tmp.emplace_back (it);
	
	res2 = check (tmp);
	
	ans = tmp;
	res1 = res2;
		
	tmp.resize (0);

	for (auto it : sf)
		tmp.emplace_back (it.id);
	
	res2 = check (tmp);
	
	if (res2 < res1)
		res1 = res2, ans = tmp;

	tmp.resize (0);
	
	for (auto it : tf)
		tmp.emplace_back (it.id);
	
	res2 = check (tmp);
	
	if (res2 < res1)
		res1 = res2, ans = tmp;
	
	return ans;
}

inline void print (const vector <int> &b) {
	for (int i = 0; i < b.size (); ++i)
		cout << b[i] << "\n";
	exit (0);
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i].x >> a[i].y;

	for (int i = 1; i <= n; ++i)
		a[i].id = i;
	
	vector <dotss> arr, arr2;
	
	for (int i = 1; i <= n; ++i)
		arr.emplace_back (a[i]);
	
	sort (arr.begin (), arr.end (), cmp);
	
	arr2 = arr;

	for (int i = 0; i < n; ++i)
		swap (arr2[i].x, arr2[i].y);
	
	sort (arr2.begin (), arr2.end (), cmp);
	
	for (int i = 0; i < n; ++i)
		swap (arr2[i].x, arr2[i].y);
	
	print (rec (arr, arr2, 0, int (1e6)));
	
	return 0;
}