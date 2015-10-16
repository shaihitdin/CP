#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define x first
#define y second

typedef long long ll;
typedef pair <int, int> PII;
typedef double ld;
typedef pair <ld, ld> pnt;

ostream & operator << (ostream &out, pnt a) {
	out << a.x << " " << a.y;
	return out;
}

struct segmen {
	pnt a, b;
	segmen() {}
	segmen(const pnt &_a, const pnt &_b) : a(_a), b(_b) {}
};

struct vec {
	ld x, y;
	vec() {}
	vec(ld x, ld y) : x(x), y(y) {}
	vec(pnt a, pnt b) : x(b.x - a.x), y(b.y - a.y) {}
};

ld cp(vec a, vec b) {
	return a.x * b.y - a.y * b.x;
};

bool dif(const segmen &s1, const segmen &s2) {
	vec v1(s1.a, s1.b), v2(s1.a, s2.a), v3(s1.a, s2.b);
	return (cp(v1, v2) * cp(v1, v3)) < 0;
}

bool crosses(const segmen &s1, const segmen &s2) {
	return dif(s1, s2) && dif(s2, s1);
}

const int N = 3e5 + 100;

char a[10][10], og[10][10];
pnt p[6];              

int main () {

	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	
	ios_base :: sync_with_stdio (0);
	cin.tie (0);                     
	
	forn(i, 1, 5)
		forn(j, 1, 5)
			cin >> og[i][j];
			       
	forn(i, 1, 5)                // {
		forn(j, 1, 5)            		//{
			a[i][j] = og[5 - i + 1][j];   // cerr << a[i][j];}cerr << "\n";}

	int ans = 0;
	segmen res(pnt(1, 1), pnt(1, 1));

	forn(_, 1, 1) {
		forn(s_pos, 4, 4) {
	    	pnt s(5 * _ + 0.5, s_pos - 0.5);
			forn(ti, 2, 2) {
				forn(tj, 1, 1) {
					if (og[ti][tj] != 'A') continue;
					pnt to(ti + 1 - 0.5, tj - 0.5);
					segmen worm(s, to);
					int cnt = 0, poisoned = 0;   
					forn(i, 1, 5) {
						forn(j, 1, 5) {  
							bool cr = 0;
							p[1] = pnt(i + 1, j);
							p[2] = pnt(i - 1 + 1, j);
							p[3] = pnt(i - 1 + 1, j - 1);
							p[4] = pnt(i + 1, j - 1);
							p[5] = p[1];
							forn(i, 1, 4) {
								segmen side(p[i], p[i + 1]);
								if (crosses(worm, side)) {
									cr = 1;
									break;
								}	
							}
							if (!cr) continue;
							cerr << i << " " << j << "\n";
							if (og[i][j] == 'P') {
								poisoned = 1;
								break;
							}	
							if (og[i][j] == 'A')
								++cnt;
						}
						if (poisoned) break;
					}
					cerr << "-\n";
					if (poisoned) continue;
					if (ans < cnt) {
						ans = cnt;
						res = segmen (
							pnt(5 * _ + 1, s_pos),
							pnt(ti + 1, tj)
						);
					}
				}
			}
		}
	}

	assert(ans);
	cout << ans << "\n";
	cout << res.a << "\n" << res.b << "\n";
			    
	return 0;
}