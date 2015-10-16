#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file "luigi."     
#define x first
#define y second
#define pb push_back   
#define _bits __builtin_popcount
#define USE_MATH_DEFINES

typedef long long ll; 
typedef pair <int, int> PII;
typedef double ld;
typedef pair <ld, ld> pnt;
                                                                            
const int N = 3e5;                                                                                              
const int INF = 1e9 + 9;  
const int B = 1e9 + 7;
                     
int n, q;
pnt p[N];

pnt vec(pnt a, pnt b) {
	return pnt(b.x - a.x, b.y - a.y);
}

pnt ccw(pnt a, ld ang) {
	return pnt (
		a.x * cos(ang) - a.y * sin(ang),
		a.x * sin(ang) + a.y * cos(ang)
	);	
}

ld dp(pnt a, pnt b) {
	return a.x * b.x + a.y * b.y;
}
 
ld cp(pnt a, pnt b) {
	return a.x * b.y - a.y * b.x;
}           

ld dist(pnt a, pnt b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main () {        
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout); 

	ios_base :: sync_with_stdio (0);                                                                                           
	cin.tie(0); 

	cin >> n >> q;
	forn(i, 1, n)
		cin >> p[i].x >> p[i].y;
	
	forn(i, 1, q) {
		pnt p1, p2;
		cin >> p1.x >> p1.y;
		cin >> p2.x >> p2.y;
		pnt v1 = vec(p1, p2);
		ld d = dist(p1, p2);
        pnt v_ccw (-v1.y / d, v1.x / d);

		forn(j, 1, n) {			
			pnt v2 = vec(p1, p[j]);
			if (cp(v1, v2) >= 0) continue;
			
			pnt va = vec(p[j], p1);
			pnt vb = vec(p[j], p2);
			ld dj = fabs(cp(va, vb) / d);  
			pnt shift (v_ccw.x * 2 * dj, v_ccw.y * 2 * dj);
                      
			p[j] = pnt(p[j].x + shift.x, p[j].y + shift.y);
		}	      
	}

	cout << fixed << setprecision(12);

	forn(i, 1, n)
		cout << p[i].x << " " << p[i].y << "\n";

    return 0;         	
}
