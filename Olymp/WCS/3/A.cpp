#include <bits/stdc++.h>

using namespace std;

inline vector <int> shift (vector <int> a, int x) {
	vector <int> b;
	for (int i = 0; i < x; ++i)
		b.emplace_back (0);
	for (int i = 0; i < a.size (); ++i)
		b.emplace_back (a[i]);
	return b;
}

inline vector <int> operator + (vector <int> a, const vector <int> &b) {
	a.resize (max (a.size (), b.size ()));
	for (int i = 0; i < b.size (); ++i)
		a[i] += b[i];
	return a;
}

inline vector <int> operator - (vector <int> a, const vector <int> &b) {
	a.resize (max (a.size (), b.size ()));
	for (int i = 0; i < b.size (); ++i)
		a[i] -= b[i];
	return a;
}

int cnt;

inline vector <int> operator * (const vector <int> &a, const vector <int> &b) {
	assert (a.size () == b.size () && __builtin_popcount (a.size ()) == 1);
	++cnt;
	if (a.size () <= 100) {
		vector <int> c;
		c.resize (a.size () + b.size () - 1);
		for (int i = 0; i < a.size (); ++i)
			for (int j = 0; j < b.size (); ++j)
				c[i + j] += a[i] * b[j];
		return c;
	}
	int to_shift = a.size () / 2;
	vector <int> calc1, calc2, calc3, calc4, part1, part2, part3, part4;
	for (int i = 0; i < to_shift; ++i)
		part1.emplace_back (a[i + to_shift]), part2.emplace_back (a[i]), part3.emplace_back (b[i + to_shift]), part4.emplace_back (b[i]);
	
	calc1 = part1 * part3; //ax
	calc2 = part2 * part4; //by
	calc3 = (part1 + part2) * (part3 + part4); //(a + b) (x + y)
	return shift (calc1, to_shift * 2) + calc2 + shift (calc3 - (calc1 + calc2), to_shift);
}

/*
inline vector <int> operator * (const vector <int> &a, const vector <int> &b) {
	vector <int> c;
	c.resize (a.size () + b.size ());
	for (int i = 0; i < a.size (); ++i)
		for (int j = 0; j < b.size (); ++j)
			c[i + j] += a[i] * b[j];
	return c;
}
*/
int main () {

	#ifdef UNBROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	vector <int> a, b;
	int n, m;

	a.resize (1 << 15);
	b.resize (1 << 15);
	
	cin >> n;	

	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		++a[x];
	}

	cin >> m;

	for (int i = 1; i <= m; ++i) {
		int x;
		cin >> x;
		++b[x];
	}
	
	vector <int> c = a * b;
	
	for (int i = 0; i < c.size (); ++i)
		if (c[i])
			cout << i << " " << c[i] << "\n";

	return 0;
}