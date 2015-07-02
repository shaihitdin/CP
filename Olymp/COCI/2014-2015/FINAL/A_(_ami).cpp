/*
	????????????
*/

#include <bits/stdc++.h>

#define sz(c) ((int)(c).size())
#define vec vector

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;

int const inf = 1e9;

vec<pii> xy;
vec<pii> yx;
vec<vec<pii>> adj;
vec<int64> cnt;
vec<int64> sub;
vec<int64> ans;

int lastBit(int n) {
  if (n == 0) return inf;
  return n & ~(n - 1);
}

void addAll(int x, int y) {
  while (x > 0 && y > 0) {
    xy.emplace_back(x, y);
    yx.emplace_back(y, x);
    int a = lastBit(x);
    int b = lastBit(y);
    assert(a != b);
    if (a < b) {
      x -= a;
    } else {
      y -= b;
    }
  }
  while (x > 0) {
    xy.emplace_back(x, y);
    yx.emplace_back(y, x);
    x -= lastBit(x);
  }
  while (y > 0) {
    xy.emplace_back(x, y);
    yx.emplace_back(y, x);
    y -= lastBit(y);
  }
}

void calcSub(int v) {
  for (auto e : adj[v]) {
    int u = e.first;
    int w = e.second;
    calcSub(u);
    sub[v] += sub[u] + cnt[u] * w;
    cnt[v] += cnt[u];
  }
}

void calcAns(int v) {
  for (auto e : adj[v]) {
    int u = e.first;
    int w = e.second;
    ans[u] = ans[v] + (cnt[0] - 2 * cnt[u]) * w;
    calcAns(u);
  }
}

string str(pii p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vec<pii> a(n);
  for (int i = 0; i < n; ++i) 
    cin >> a[i].first >> a[i].second;

  xy.emplace_back(0, 0);
  yx.emplace_back(0, 0);
  for (int i = 0; i < n; ++i)
    addAll(a[i].first, a[i].second);

  sort(xy.begin(), xy.end());
  xy.erase(unique(xy.begin(), xy.end()), xy.end());
  sort(yx.begin(), yx.end());
  yx.erase(unique(yx.begin(), yx.end()), yx.end());

  assert(sz(xy) == sz(yx));
  map<pii,int> id;
  for (int i = 0; i < sz(xy); ++i) id[xy[i]] = i;

  adj = vec<vec<pii>>(sz(xy));
  for (int i = 1; i < sz(xy); ++i) {
    pii q = xy[i - 1];
    pii p = xy[i];
    if (p.first == q.first && lastBit(p.first) > lastBit(p.second)) {
      adj[i - 1].emplace_back(i, p.second - q.second);
    }
  }
  for (int i = 1; i < sz(yx); ++i) {
    pii q(yx[i - 1].second, yx[i - 1].first);
    pii p(yx[i].second, yx[i].first);
    if (p.second == q.second && lastBit(p.first) < lastBit(p.second)) {
      adj[id[q]].emplace_back(id[p], p.first - q.first);
    }
  }

  for (int i = 0; i < sz(xy); ++i)
    assert(sz(adj[i]) <= 2);

  cnt = vec<int64>(sz(xy));
  for (int i = 0; i < n; ++i) cnt[id[a[i]]] += 1;

  sub = vec<int64>(sz(xy));
  calcSub(0);
  ans = vec<int64>(sz(xy));
  ans[0] = sub[0];
  calcAns(0);

  int64 result = ans[0];
  for (int i = 0; i < sz(xy); ++i)
    result = min(result, ans[i]);

  cout << result << endl;

  return 0;
}