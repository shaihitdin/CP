#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;
typedef long long ll;


//
inline int readChar();
template <class T> inline T readInt();

template <class T> inline void writeInt( T x );
inline void putchar_fast( int x ); // you may use putchar() instead of it
inline void flush();
//

const int N = 1e5 + 1, sz = 1 << 17;

const ll inf = 1e14;

ll t[sz + sz];

ll d[N];

int p[N];

vector <pii> g[N];

inline int get () {
	if (t[1] == inf)
		return 0;
	
	register int v = 1;

	for (; v < sz;) {
		v <<= 1;
		if (t[v] > t[v + 1])
			++v;
	}
	return v - sz;
}

inline ll smin (const ll &lhs, const ll &rhs) {
	if (lhs < rhs)
		return lhs;
	return rhs;
}
                          
inline void upd (register int pos, const ll &delta) {
	pos += sz;
	t[pos] = delta;
	for (pos >>= 1; pos; pos >>= 1)
		t[pos] = smin (t[pos << 1], t[(pos << 1) + 1]);
}

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int n, m;

	n = readInt <int> ();
	m = readInt <int> ();
	              
	for (register int i = 1; i <= m; ++i) {
		register int x = readInt <int> (), y = readInt <int> (), z = readInt <int> ();
		g[x].push_back (pii (y, z));
		g[y].push_back (pii (x, z));
	}

	for (register int i = 0; i < sz + sz; ++i)
		t[i] = inf;

	for (register int i = 0; i <= n; ++i)
		d[i] = inf;

	d[1] = 0;
	upd (1, 0);
			
	while (1) {
		register int v = get ();
		if (d[v] == inf)
			break;
		for (register auto it : g[v]) {
			register int to = it.first, pen = it.second;
			if (d[to] > d[v] + pen) {
				p[to] = v;
				d[to] = d[v] + pen;
				upd (to, d[to]);
			}
		}
		upd (v, inf);
	}
	
	
	vector <int> ans;

	for (register int v = n; v; v = p[v])
		ans.push_back (v);

	reverse (ans.begin(), ans.end());

	if (d[n] == inf)
		puts ("-1");
	else
		for (register auto it : ans)
			writeInt (it), putchar_fast (' ');
	flush ();
	return 0;
}

/** Read */

static const int buf_size = 4096;

inline int getchar_fast() { // you may use getchar() instead of it
  static char buf[buf_size];
  static int len = 0, pos = 0;
  if (pos == len)
    pos = 0, len = fread(buf, 1, buf_size, stdin);
  if (pos == len)
    return -1;
  return buf[pos++];
}

inline int readChar() {
  int c = getchar_fast();
  while (c <= 32)
    c = getchar_fast();
  return c;
}

template <class T>
inline T readInt() {
  int s = 1, c = readChar();
  T x = 0;
  if (c == '-')
    s = -1, c = getchar_fast();
  while ('0' <= c && c <= '9')
    x = x * 10 + c - '0', c = getchar_fast();
  return s == 1 ? x : -x;
}

/** Write */

static int write_pos = 0;
static char write_buf[buf_size];

inline void putchar_fast( int x ) {
  if (write_pos == buf_size)
    fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
  write_buf[write_pos++] = x;
}

inline void flush() {
  if (write_pos)
    fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
}

template <class T> 
inline void writeInt( T x ) {
  if (x < 0)
    putchar_fast('-'), x = -x;

  char s[24];
  int n = 0;
  while (x || !n)
    s[n++] = '0' + x % 10, x /= 10;
  while (n--)
    putchar_fast(s[n]);
}