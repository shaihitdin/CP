#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

inline int readChar();
template <class T> inline T readInt(); 

const int N = 1e6;

int n, q, a[3 * N], go[2 * N];

inline int cor( int a ) {
  while (a >= n)
    a -= n;
  return a;
}

int main() {
  n = readInt<int>();
  q = readInt<int>();
  forn(i, n)
    a[2 * n + i] = a[n + i] = a[i] = readInt<int>();
  while (q--) {
    ll b = readInt<ll>();
    {
      int r = 0;
      ll sum = 0;
      forn(l, 2 * n) {
        while (r - l < n && sum + a[r] <= b)
          sum += a[r++];
        go[l] = r;
        sum -= a[l];
      }
    }
    int k = n, mi = 0, l = 0, r = 0, len = 0, cnt = 0;
    forn(i, 2 * n) {
      len += go[r] - r, r = cor(go[r]), cnt++;
      if (go[r] - r < go[mi] - mi)
        mi = r;
      if (len >= n) {
        k = min(k, cnt);
        len -= go[l] - l, l = cor(go[l]), cnt--;
      }
    }
    for (int x = mi; x <= go[mi]; x++) {
      cnt = 0;
      for (int start = cor(x), i = start; i < start + n; i = go[i]) {
        cnt++;
      }
      k = min(k, cnt);
    }          
    printf("%d\n", k);
  }
  return 0;
}