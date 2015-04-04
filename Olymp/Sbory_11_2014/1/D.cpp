#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
double d[10][1001];
int a[5], b[5];
double ans[10];
double coeff;
const double eps = 0.0000001;
int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	for (int i = 1; i <= 4; ++i)
		cin >> a[i] >> b[i];    
	coeff = (1.0 / double((b[1] - a[1] + 1) * (b[2] - a[2] + 1)));
	for (int i = a[1]; i <= b[1]; ++i){
		for (int j = a[2]; j <= b[2]; ++j) {
			d[1][i + j] += coeff;
		}
	}
	coeff = (1.0 / double((b[3] - a[3] + 1) * (b[4] - a[4] + 1)));
	for (int i = a[3]; i <= b[3]; ++i){
		for (int j = a[4]; j <= b[4]; ++j) {
			d[2][i + j] += coeff;
		}
	}
	for (int i = 1; i <= 2; ++i) {
		double cnt = 0;
		for (int j = 1; j <= 200; ++j) {
			if (d[i][j] < eps)
				continue;
			cnt += 1;
			ans[i] += (d[i][j] * double(j));
		}
		ans[i] /= double(cnt);
	}
	cerr << ans[1] << " " << ans[2] << "\n";
	if ( (fabs(ans[1]-ans[2])) < eps) {
		cout << "Tie";
		return 0;
	}
	if (ans[1] > ans[2]) {
		cout << "Emma";
		return 0;
	}
	if (ans[2] > ans[1]) {
		cout << "Gunnar";
	}
	return 0;
} 