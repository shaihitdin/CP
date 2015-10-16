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
		forn(j, 1, n) {			
			pnt v2 = vec(p1, p[j]);
			if (cp(v1, v2) >= 0) continue;
			ld ang = atan2(cp(v2, v1), dp(v2, v1));
			pnt v3 = ccw(v1, ang);
			p[j] = pnt(p1.x + v3.x, p1.y + v3.y);
			cerr << j << " " << ang * 180 / M_PI << " " << atan2(cp(v1, v3), dp(v1, v3)) * 180 / M_PI << "\n";
		}	      
	}

	cout << fixed << setprecision(2);

	forn(i, 1, n)
		cout << p[i].x << " " << p[i].y << "\n";

    return 0;         	
}
