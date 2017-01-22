#include <iostream>

using namespace std;

int main () {

	int n, sum = 0;
	
	cin >> n;

	int mn = 1000000000, mnpos = 0;
	int mx = -mn, mxpos = 0;
	int cnt = 0;	
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		if (x % 3 == 0)
			cnt++;
		sum += x;
		if (mn > x)
			mnpos = i, mn = x;
		if (mx < x)
			mxpos = i, mx = x;
	}
	
	cout << "Sum = " << sum << endl;
	cout << "Average = " << double (sum / n) << endl;
	cout << "Maximum = " << mx << ", minimum = " << mn << endl;
	cout << "Index max = " << mxpos << endl;
	cout << "Index min = " << mnpos << endl;
	if (cnt == n)
		cout << "True";
	else
		cout << "False";
	
	return 0;
}