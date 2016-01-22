#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <ctime>
#include <cassert>

#define pii pair<int, int>

#define pb emplace_back
#define mp make_pair

#define f first
#define s second

using namespace std;

typedef long long ll;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1);

const int INF = (int) 1e9 + 7;
const int MAXN = (int) 2e4 + 7;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int n;

vector<pii> g[MAXN];
//vector<pii> a[MAXN];

int q[MAXN];
int qh, qt;

pii p[MAXN];

int d[MAXN];
int mx[MAXN];
int timer;
int used[MAXN];
char came[MAXN];

int main() {
  #ifdef LOCAL
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
  #endif

  scanf("%d", &n);
  for (int i = 0; i + 1 < n; i++) {
    int u, v;
    char ch;
    scanf("%d %d %c", &u, &v, &ch);
    g[u].pb(make_pair (v, ch - 'a'));
    g[v].pb(make_pair (u, ch - 'a'));
  }
  for (int i = 1; i <= n; i++) {
    timer++;
    memset(mx, 0, sizeof (mx));
    qh = qt = 0;
    q[qt++] = i;
    d[i] = 0;
    used[i] = timer;
    auto ans = make_pair (0, 0);
    memset (came, 0, sizeof (came));
    while (qh < qt) {
      int v = q[qh++];
      if (came[v] != mx[d[v]])
      	continue;
      ans = max(ans, mp(d[v], v));
      for (auto e : g[v]) {
        if (used[e.first] != timer) {
          used[e.first] = timer;
          d[e.first] = d[v] + 1;
          q[qt++] = e.first;
          mx[d[e.first]] = max(mx[d[e.first]], e.second);
          came[e.first] = e.second;
        }
      }
    }
    printf("%d ", ans.s);
  }

  return 0;
}