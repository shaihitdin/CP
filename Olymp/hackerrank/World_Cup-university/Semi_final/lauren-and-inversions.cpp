#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

const int MAXN = (int) 7e6 + 100;

int n;
vector <int> a;

int ans = -1;

int ansL = -1;
int ansR = -1;

pair <int, int> t[MAXN];
int d[MAXN];

inline void push (const int &v) {
	if (d[v] != 0) {
		t[v].first += d[v];
		d[v << 1] += d[v];
		d[(v << 1) | 1] += d[v];
    	d[v] = 0;
	}
}

inline void build (const int &v, const int &l, const int &r) {
	d[v] = 0;
	t[v] = make_pair (0, l);
	if (l == r) {
		return;
	}
	int m = (l + r) >> 1;
	build ((v << 1) | 1, m + 1, r);
	build (v << 1, l, m);
}

inline void add (const int &v, const int &Tl, const int &Tr, const int &l1, const int &r1, const int &val) {
	push(v);
	if (Tl == l1 && Tr == r1) {
		d[v] += val;
		push (v);
		return;
	}
  	int mid = (Tl + Tr) / 2;
  	if (l1 <= mid) {
  		add (v << 1, Tl, mid, l1, min (r1, mid), val);
  	} else {
    	push (v << 1);
	}
  	if (r1 > mid) {
  		add ((v << 1) | 1, mid + 1, Tr, max (l1, mid + 1), r1, val);
  	} else {
    	push ((v << 1) | 1);
  	}
  	if (t[v << 1].first > t[(v << 1) | 1].first)
  		t[v] = t[v << 1];
  	else if (t[v << 1].first < t[(v << 1) | 1].first)
  		t[v] = t[(v << 1) | 1];
  	else {
  		if (t[v << 1].second < t[(v << 1) | 1].second)
  			t[v] = t[v << 1];
  		else
  			t[v] = t[(v << 1) | 1];
  	}
}

int main() {

	#ifdef LOCAL
	freopen("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

  	ios_base :: sync_with_stdio (0);
  	cin.tie (0);
  	
  	cin >> n;

	a.resize(n);

  	vector<int> pref(n);
  	vector<int> suff(n);
  	for (int i = 0; i < n; i++) {
  		cin >> a[i];
   		a[i]--;
  	}
  	for (int i = 0; i < n - 1; i++) {
    	if (a[i] > a[i + 1]) {
      		ans = 0;
      		ansL = i + 1;
      		ansR = i + 2;
    	}
  	}
  	if (ans == -1) {
    	cout << "Cool Array";
    	return 0;
  	}
  	vector<int> l, r, lv, rv;
  	for (int i = 0; i < n; i++)
    	pref[i] = max(i == 0 ? 0 : pref[i - 1], a[i]);
 	for (int i = n - 1; i >= 0; i--)
    	suff[i] = min(i == n - 1 ? n : suff[i + 1], a[i]);
  	for (int i = 0; i < n; i++) {
    	if (a[i] == suff[i]) {
      		r.emplace_back (i);
      		rv.emplace_back (a[i]);
    	}
    	if (a[i] == pref[i]) {
      		l.emplace_back (i);
      		lv.emplace_back (a[i]);
    	}
  	}
  	vector<vector<pair <int, int>>> st((int) l.size());
  	vector<vector<pair <int, int>>> en((int) l.size());
  	for (int i = 0; i < n; i++) {
    	if (a[i] == pref[i] || a[i] == suff[i]) {
    	  continue;
    	}
    	int r1 = lower_bound(r.begin(), r.end(), i) - r.begin();
    	int r2 = lower_bound(rv.begin(), rv.end(), a[i]) - rv.begin() - 1;
    	if (r1 > r2)
    	  continue;
    	int l1 = lower_bound(lv.begin(), lv.end(), a[i]) - lv.begin();
    	int l2 = lower_bound(l.begin(), l.end(), i) - l.begin() - 1;
    	if (l1 > l2)
    	  continue;
    	st[l1].emplace_back (make_pair(r1, r2));
    	en[l2].emplace_back (make_pair(r1, r2));
  	}
  	int cnt = 0;
  	build(1, 0, (int) r.size() - 1);
  	for (int i = 0; i < l.size(); i++) {
  		for (int j = 0; j < st[i].size(); j++) {
      		cnt++;
      		add (1, 0, (int) r.size() - 1, st[i][j].first, st[i][j].second, 1);
    	}
    	if (t[1].first > ans) {
    	  ans = t[1].first;
    	  ansL = l[i] + 1;
    	  ansR = r[t[1].second] + 1;
    	} else if (t[1].first == ans && make_pair (ansL, ansR) > make_pair (l[i] + 1, r[t[1].second] + 1)) {
    	  ansL = l[i] + 1;
    	  ansR = r[t[1].second] + 1;
    	}
    	for (int j = 0; j < en[i].size(); j++) {
    	  cnt--;
    	  add (1, 0, (int) r.size() - 1, en[i][j].first, en[i][j].second, -1);
    	}
  	}
  	cout << ansL << " " << ansR << "\n";
	return 0;
}