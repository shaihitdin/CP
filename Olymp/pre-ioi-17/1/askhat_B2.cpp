#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
 
using namespace std;
 
#define f first
#define s second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define ll long long
#define ld double
#define ull unsigned long long
#define PI pair < int, int > 
 
const int N = 3e5 + 123;
const int M = 123;
const ld Pi = acos(-1);
const ll Inf = 1e18;
const int inf = 1e9;
const int mod = 1e9 + 7;
const int Sz = 501;
const int MOD = 1e9 + 7;
 
void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
int mult(int a, int b) {
  return 1ll * a * b % mod;
}
int sum(int a, int b) {
  add(a, b);
  return a;
}
 
int n, m, l, r, a[N], ans[N], f[N], s[N];
pair < int, int > dp[N];
 
void solve() { 
  cin >> n >> l >> r >> m;
  int res = 0;
  for (int i = 1;i <= m;i++) {
    int x, y; cin >> x >> y;
    a[x] = y;
    res = max(res, y);
  }
  for (int i = 1;i <= n;i++) f[i] = inf;
  for (int i = 1;i <= n;i++) {
    if (a[i]) {
      f[a[i]] = min(f[a[i]], i);
      s[a[i]] = i;
    }
  }
  for (int i = 1;i <= n;i++) {
    if (a[i]) {
      int len = s[i] - f[i] + 1;
      assert(len <= r);
    }
  }
  dp[0] = mp(0, 0);
  bool ok = 0;
  for (int i = 1;i <= n;i++) {
    int need = max(l, s[i] - f[i] + 1);
    assert(dp[i - 1].f < f[i]);
    dp[i].f = max(dp[i - 1].f + need, s[i]);
    dp[i].s = min(dp[i - 1].s, f[i] - 1) + r;
    assert(dp[i].f <= dp[i].s);
    if (i >= res) {
      if (dp[i].s >= n) {
        res = i;
        ok = 1;
        break;
      }
    }
  }
  assert(ok);
  for (int i = res, ptr = n;i;i--) {
    assert(ptr >= dp[i].f && ptr <= dp[i].s);
    int need = max(l, s[i] - f[i] + 1);
    int tmp = min(ptr - need + 1, dp[i - 1].s + 1);
    tmp = min(tmp, f[i]);
    tmp = max(tmp, 1);
    for (int j = tmp;j <= ptr;j++) ans[j] = i;
    int len = ptr - tmp + 1;
    assert(len >= l && len <= r);
    ptr = tmp - 1;
  }
  cout << res << endl;
  for (int i = 1;i <= n;i++) {
    if (a[i]) assert(a[i] == ans[i]);
    cout << ans[i] << " ";
  }
  cout << endl;
}