#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
const double eps = 0.0000001;
const int N = 10001;               
struct point {
	double x, y;

};

struct vector {
	double x, y;

};

inline point mk_p (const double &x, const double &y) {
	point tmp = {x, y};
	return tmp;
}

inline vector mk_v (const point &a, const point &b) {
	vector tmp = {b.x - a.x, b.y - a.y};
	return tmp;
}

inline double get_distance (const point &a, const point &b) {
	return sqrt( (a.x-b.x) * (a.x-b.x) + (a.y-b.y) * (a.y-b.y) );
}

inline double pseudo_scalar (const vector &a, const vector &b) {
	return (a.x * b.y - b.x * a.y);
}
bool cmp (const point &lhs, const point &rhs){
	return (lhs.x == rhs.x) ? lhs.y < rhs.y : lhs.x < rhs.x;
}
inline 
point all[N];
vector v1, v2;
int t_ans, x, y, n;
double ans, ans1;
int main() {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d",&x,&y);
		all[i] = mk_p (x, y);
	}
/*
	sort (all + 1, all + n + 1, &cmp);
	int p1 = all[1];
*/
	v1 = mk_v (all[1],all[2]);
	v2 = mk_v (all[1],all[3]);
	cerr << pseudo_scalar (v1, v2) << "\n";
	return 0;
}