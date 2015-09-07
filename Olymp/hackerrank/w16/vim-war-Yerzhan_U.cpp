#include <bits/stdc++.h>

using namespace std;

#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

typedef long long ll;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(s) s.begin(), s.end()
#define sz(s) (int(s.size()))
#define fname "a"
#define ms(a,x) memset(a, x, sizeof(a))
#define forit(it,s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); ++it)
#define MOD 1000000007
#define MAXN 200002
#define MAXM 21

inline int add(int a, int b)
{
	a += b;
	if (a >= MOD)
		a -= MOD;
	return a;
}

inline int sub(int a, int b)
{
	a -= b;
	if (a < 0)
		a += MOD;
	return a;
}

inline int mult(int a, int b)
{
	return (1LL * a * b) % MOD;
}

inline int power(int a, int b)
{
	int r = 1;
	while(b)
	{
		if (b & 1) r = mult(r, a);
		a = mult(a, a);
		b >>= 1;
	}
	return r;
}


int n, m;
int a[MAXN];
int d[1 << MAXM];
char s[MAXM];

int main()
{
	#ifdef LOCAL
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	#endif

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", s);
		a[i] = 0;
		for (int j = 0; j < m; ++j)
			if (s[j] == '1')
				a[i] |= (1 << j);
	}

	scanf("%s", s);
	int target = 0;
	for (int j = 0; j < m; ++j)
		if (s[j] == '1')
			target |= (1 << j);

	for (int i = 0; i < n; ++i)
		if ((target | a[i]) == target)
			++d[a[i]];
	
	for (int i = 0; i < m; i++)
	 	for (int mask = 0; mask < (1 << m); mask++)
	 		if ((mask >> i) & 1)
	 			d[mask] += d[mask & ~(1 << i)];
	
	for (int mask = 0; mask < (1 << m); mask++)
	 	d[mask] = sub(power(2, d[mask]), 1);

	for (int i = 0; i < m; i++)
	 	for (int mask = 0; mask < (1 << m); mask++)
	 		if ((mask >> i) & 1)
	 			d[mask] = sub(d[mask], d[mask & ~(1 << i)]);

	printf("%d\n", d[target]);

	return 0;
}
