#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
const double eps = 0.0000001;                            
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
point poo, all[5];
vector v1, v2;
int t_ans, x, y, n;
double ans, ans1;
int main() {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf ("%d%d", &x, &y);
		poo = mk_p (x, y);
		scanf ("%d%d", &x, &y);
		all[1] = mk_p (x, y);
		scanf ("%d%d", &x, &y);
		all[2] = mk_p (x, y);
		scanf ("%d%d", &x, &y);
		all[3] = mk_p (x, y);
		scanf ("%d%d", &x, &y);
		all[4] = mk_p (x, y);
		ans1 = 0;
		for (int j = 1; j <= 4; ++j){
			v1 = mk_v (poo, all[j]);
			v2 = mk_v (poo, all[(j + 1) > 4 ? 1 : j + 1]);
			ans1 += fabs( pseudo_scalar (v1, v2) / 2.0 );
		}
		ans = get_distance (all[1], all[2]) * get_distance (all[2], all[3]);
		if( ans1 > ans ) {
			swap (ans, ans1);
		}
		if( ans - ans1 <= eps) ++t_ans;
		cerr<< ans1 << " " << ans << "\n";
	}
	printf("%d", t_ans);
	return 0;
}