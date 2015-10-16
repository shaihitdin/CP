#include <bits/stdc++.h>

#define llong long long

using namespace std;

typedef vector<int> big;

const int MAXN = (int) 2e6 + 7;

const int MOD1 = (int) 1e9 + 7;
const int MOD2 = (int) 1e9 + 3;

int n, m, pos;
int a[MAXN];

string f, s;

long long hx[MAXN], hy[MAXN];
long long px[MAXN], py[MAXN];

int main() {
  #ifndef ONLINE_JUDGE
  freopen("in", "r", stdin);
  #endif

  ios_base::sync_with_stdio(0);

  cin >> n >> m;
  cin >> s;
  for (int i = 1; i <= n; i++)
    f.push_back('?');

  px[0] = py[0] = 1;
  for (int i = 1; i <= n; i++) {
    px[i] = (px[i - 1] * 31LL) % MOD1;
    py[i] = (py[i - 1] * 37LL) % MOD2;
  }
  for (int i = 1; i <= m; i++) {
    cin >> a[i]; --a[i];
    for (int j = max(a[i], pos); j < a[i] + s.size(); j++) {
      f[j] = s[j - a[i]];
      pos++;
    }
  }  
  hx[0] = hy[0] = (f[0] - 'a' + 1);
  for (int i = 1; i < n; i++) {
    hx[i] = (hx[i - 1] + 1ll * (f[i] - 'a' + 1) * px[i]) % MOD1;
    hy[i] = (hy[i - 1] + 1ll * (f[i] - 'a' + 1) * py[i]) % MOD2;
  }
  long long n1 = 0, n2 = 0;
  for (int i = 0; i < s.size(); i++) {
    n1 = (n1 + 1ll * (s[i] - 'a' + 1) * px[i]) % MOD1;
    n2 = (n2 + 1ll * (s[i] - 'a' + 1) * py[i]) % MOD2;
  }
  n1 = (n1 * px[n]) % MOD1;
  n2 = (n2 * py[n]) % MOD2;
  for (int i = 1; i <= m; i++) {
    long long h1 = hx[a[i] + s.size() - 1];
    if (a[i]) h1 -= hx[a[i] - 1];
    long long h2 = hy[a[i] + s.size() - 1];
    if (a[i]) h2 -= hy[a[i] - 1];
    if (h1 < 0) h1 += MOD1;
    if (h2 < 0) h2 += MOD2;
    h1 = (h1 * px[n - a[i]]) % MOD1;
    h2 = (h2 * py[n - a[i]]) % MOD2;
    if (h1 != n1 || h2 != n2) {
      printf("0");
      return 0;
    }
  }
  int ans = 1;
  for (int i = 0; i < n; i++) 
    if (f[i] == '?') 
      ans = (ans * 26LL) % MOD1;
  
  cout << ans;
  return 0;
}