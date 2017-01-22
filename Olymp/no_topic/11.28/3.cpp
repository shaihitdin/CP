#include <iostream>

using namespace std;

int mxsum[100], a[100][100], main_diagonal, sum[100], black[10000], white[10000], cnt_black, cnt_white, mx_sum;

int main () {

    int n, m;

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= m; ++j) {
    		cin >> a[i][j];
    		sum[i] += a[i][j];
    		if (i == j) {
    			main_diagonal += a[i][j];
    		}
    	}
    	if (sum[mx_sum] < sum[i])
    		mx_sum = i;
    }
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if ((i % 2 + j % 2) % 2 == 0) {
				++cnt_black;
				black[cnt_black] = a[i][j];
			} else {
				++cnt_white;
				white[cnt_white] = a[i][j];
			}
		}
	}

	for (int i = 1; i <= n; ++i)
		cout << sum[i] << " ";
	cout << endl;

	cout << main_diagonal << endl;

	cout << mx_sum << endl;

	for (int i = 1; i <= cnt_black; ++i)
		cout << black[i] << " ";
	
	return 0;
}