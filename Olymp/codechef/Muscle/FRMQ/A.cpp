#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;

//
inline int readChar();
template <class T> inline T readInt();

template <class T> inline void writeInt( T x );

inline void putchar_fast( int x ); // you may use putchar() instead of it
inline void flush();

//

inline int smax (const int &x, const int &y) {
	return x > y ? x : y;
}

inline int smin (const int &x, const int &y) {
	return x > y ? y : x;
}

int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	register int b[17][N];

	short lg[N];
	int m, x, y, n;
	long long sum;
	register int lg_rev[17];

	n = readInt <int> ();

	for (int i = 0; i < n; ++i)
		b[0][i] = readInt <int> ();

	for ( int i = 2; i <= n; ++i)
		lg[i] = lg[i >> 1] + 1;

	m = readInt <int> (), x = readInt <int> (), y = readInt <int> ();
	
	for ( int i = n - 1; i >= 0; --i)
		for ( int j = 1; i + (1 << j) - 1 <= n; ++j)
			b[j][i] = smax (b[j - 1][i], b[j - 1][i + (1 << (j - 1))]);

	register int Tl, Tr;
	
	char t;

	for (int j = 1; j < 17; ++j)
		lg_rev[j] = (1 << j) - 1;
    
    ++m;

	for (; --m;) {
		
		if (x < y)
			Tl = x, Tr = y;
		else
			Tl = y, Tr = x;
		
		t = lg[Tr - Tl + 1];
		
		sum += smax (b[t][Tl], b[t][Tr - lg_rev[t]]);
		
		x += 7;
		y += 11;
		while (x >= n - 1)
			x -= (n - 1);
		while (y >= n)
			y -= n;
	}

	writeInt (sum);

	flush ();
	
	fprintf (stderr, "%d", clock () * 1000 / CLOCKS_PER_SEC);

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