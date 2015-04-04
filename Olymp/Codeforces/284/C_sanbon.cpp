#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <bitset>
#include <map>
#include <set>
#include <assert.h>
#include <math.h>
#include <vector>
#include <time.h>
using namespace std;           
#define forn(i, x, n) for(int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for(int i = int(n); i >= int(x); --i)    
#define file ""
#define pb push_back
#define F first
#define S second
#define lld "%I64d" 

typedef long long ll;
typedef long double ld;
typedef pair <int, int> PII;
                                             
const int maxn = 512;
const int INF = 1e9 + 9;

const double eps = 1e-7;
typedef double Angle;

bool eql(double a, double b) {
	return fabs(a - b) < eps;
}

bool lss(double a, double b) {
	return b - a > eps;
}

bool grter(double a, double b) {
	return a - b > eps;
}

struct Point {
	double x, y;
	Point() {}
	Point(double x, double y) : x(x), y(y) {}
	bool operator <(const Point &b) const {
		return eql(x, b.x) ? lss(y, b.y) : lss(x, b.x);	
	}
};

void printPoint(Point &p) {
	printf("%d %d \n", p.x, p.y);
}

struct Vector {
	double x, y;
	Vector() {}
	Vector(double x, double y) : x(x), y(y) {}
	Vector(Point a, Point b) {
		x = b.x - a.x, y = b.y - a.y;
	}
	Vector operator * (double b) {
		return Vector(x * b, y * b);
	}
	Vector operator + (Vector v2) {
		return Vector(x + v2.x, y + v2.y);
	}
};

struct Line {
	double a, b, c;
	Line() {}
	Line (Point p1, Point p2) {
		a = p1.y - p2.y;
		b = p2.x - p1.x;
		c = p1.x * p2.y - p2.x * p1.y;
	}
	Point getPoint(int z) {          
		if (!eql(a, 0))         
			return getPointByY(z);          
		else                        
			return getPointByX(z); 
	}
	Point getPointByX(int x) {
		if (!eql(b, 0))
			return Point(x, (-a * x - c) / b);
	}
	Point getPointByY(int y) {
		if (!eql(a, 0))                   
			return Point((-b * y - c) / a, y); 
	}
};      

double pointDistance(Point &a, Point &b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double vectorLength(Vector &a) {
	return sqrt(a.x * a.x + a.y * a.y);
}

double dotProduct(Vector &a, Vector &b) {
	return a.x * b.x + a.y * b.y;
}

double crossProduct(Vector &a, Vector &b) {
	return a.x * b.y - a.y * b.x;
}

Vector normalize(Vector &a) {
	return Vector(a.x * (1 / vectorLength(a)), a.y * (1 / vectorLength(a)));
}

Vector moveCW(Vector &v1) {
	return Vector(v1.y, -v1.x);	
}

Vector moveCCW(Vector &v1) {
	return Vector(-v1.y, v1.x);
}                        

double distance(Point p1, Line l) {
	Point p2 = l.getPoint(0), p3 = l.getPoint(1);
	Vector v1(p2, p1), v2(p3, p1);
	return fabs(crossProduct(v1, v2)) / pointDistance(p2, p3);
}

Point lineIntersection(Line l1, Line l2) { 
    double z = l1.a * l2.b - l2.a * l1.b;
    if (!z) {
    	return Point(-INF, -INF);
    }
	Point ans;
	ans.y = (-l1.a * l2.c + l2.a * l1.c) / z;
	ans.x = (l1.b * l2.c - l2.b * l1.c) / z; 
	return ans;
}       

Point from, to;

int n;
Line lines[maxn];
                          
map <double, int> inters;

int solve() {    
	int ans = 0;
	Line main_l(from, to);                                           
	int left = min(from.x, to.x);
	int right = max(from.x, to.x);       
	forn(i, 1, n) {
		Point cross = lineIntersection(main_l, lines[i]);
		if (lss(cross.x, left) || grter(cross.x, right)) continue;
		++ans;
	//	++inters[cross.x];
	}
	return ans;		
}

int vert_solve() {
	int ans = 0;
	Line main_l(from, to);
	int bot = min(from.y, to.y);
	int top = max(from.y, to.y);
	forn(i, 1, n) {
		Point cross = lineIntersection(main_l, lines[i]);
		if (lss(cross.y, bot) || grter(cross.y, top)) continue;
		++ans;
	//	++inters[cross.x];
	}
	return ans;	
}                         

                           
int main() {                   
//	freopen(file"in", "r", stdin);   
//	freopen(file"out", "w", stdout);

	cin >> from.x >> from.y;
	cin >> to.x >> to.y;

	cin >> n;
	forn(i, 1, n) 
		cin >> lines[i].a >> lines[i].b >> lines[i].c;

	if (from.x == to.x)	
		cout << vert_solve();
	else
		cout << solve();	
 
	return 0; 	
}
  