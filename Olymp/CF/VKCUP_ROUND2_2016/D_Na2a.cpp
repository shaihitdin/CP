#include <bits/stdc++.h>

// greedisgood

#define pii pair<int, int>

#define mp make_pair
#define pb push_back

#define f first
#define s second

typedef long long ll;
typedef double ld;

using namespace std;

const int INF = (int) 1e9 + 7;
const int MAXN = (int) 1e6 + 7;

int n;
ld mx[MAXN];
ld mn[MAXN];
ld a[MAXN];
ld b[MAXN];
ld tmx[MAXN];
ld tmn[MAXN];

inline ld solve (ld a, ld b, ld c) {
	ld d = b * b - 4 * a * c;
	if (d == 0)
		return -(b / (2 * a));
	d = fabs (d);
	return max ((-b + sqrt (d)) / (2 * a), (-b - sqrt (d)) / (2 * a));
}

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  //freopen("out", "w", stdout);
  #endif // LOCAL

  ios_base::sync_with_stdio(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> mx[i];
    mx[i] += mx[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    cin >> mn[i];
  }
  for (int i = n; i > 0; i--)
    mn[i] += mn[i + 1];
  for (int i = 1; i <= n; i++)
    mn[i] -= 1;
  a[n] = 1;
  b[n] = 1;
  for (int i = 1; i < n; i++) {
    ld x;
    x = solve(1, mn[i + 1] - mx[i], mx[i]);
    //x = solve(1, mn[i + 1], mx[i]);
    a[i] = x;
    b[i] = mx[i] / a[i];
  }
  cout << fixed << setprecision (8);
  for (int i = 1; i <= n; i++) {
    cout << a[i] - a[i - 1] << ' ';
  }
  cout << "\n";
  for (int i = 1; i <= n; i++) {
    cout << b[i] - b[i - 1] << ' ';
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      tmx[max(i, j)] += (a[i] - a[i - 1]) * (b[i] - b[i - 1]);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      tmn[min(i, j)] += (a[i] - a[i - 1]) * (b[i] - b[i - 1]);
    }
  }
  cout << endl;
  for (int i = 1; i <= n; i++) {
    cout << tmx[i] << ' ' << mx[i]-mx[i-1] << endl;
  }
  for (int i= 1;i<=n;i++)mn[i] += 1;
  for (int i = 1; i <= n; i++) {
    cout << tmn[i] << ' ' << mn[i]-mn[i+1] << endl;
  }
  return 0;
}