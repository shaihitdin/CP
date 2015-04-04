#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 1;

int n, k, l, r, done;
vector <int> temp;
bool u[N];
int main () {
	
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	scanf ("%d%d", &n, &k);
	if (double (k) < sqrt (double (n))) {
		printf ("-1");
		return 0;
	}
	bool flag = 1;
	l = 1, r = n;
	temp.resize (k);
	int ttt = n / k + (n % k != 0);	
	for (int i = 1; i <= n; ++i, flag = !flag) {
		temp.resize (0);
		//if (flag) {
			for (; l <= n && temp.size() < k; ++l) {
				if (!u[l]) {
					temp.push_back (l);
					u[l] = 1;
					++done;
				}		
			}
			for (auto it = temp.rbegin(); it != temp.rend(); ++it)
				printf ("%d ", *it);
		//}
		/*
		 else {
			for (; r >= 1 && temp.size() < k; --r) {
				if (!u[r]) {
					temp.push_back (r);
					u[r] = 1;
					++done;
				}
			}
			cerr << temp.size() << "\n";
			for (auto it = temp.begin(); it != temp.end(); ++it) {
				cerr << *it << " ";
				printf ("%d ", *it);
			}
			cerr << "\n\n";
		}
		*/
		/*
		if ((k - 1 != 0) && i + ((n - done) / (k - 1) + ( (n - done) % (k - 1) != 0)) <= ttt) {
			ttt = i + ((n - done) / (k - 1) + ( (n - done) % (k - 1) != 0));
			--k;
		
		}
		*/ 
	}

	return 0;
}