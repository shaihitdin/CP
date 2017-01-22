#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int mn[N], l[N], r[N];
int n;

inline void PRINT (vector <int> q) {
	cout << q.size () << "\n";
	for (int i = 0; i < q.size (); ++i) {
		cout << q[i] << " ";
	}
	cout << endl;
	fflush (stdout);
}

inline void run () {
	vector <int> q1, q2;
	for (int i = 1; i <= n; ++i) {
		int mid = (r[i] + l[i]) / 2;
		for (int j = l[i]; j <= mid; ++j) {
			q1.emplace_back (j);
		}
		for (int j = mid + 1; j <= r[i]; ++j) {
			q2.emplace_back (j);
		}
	}
	sort (q1.begin (), q1.end ());
	q1.resize (unique (q1.begin (), q1.end ()) - q1.begin ());
	sort (q2.begin (), q2.end ());
	q2.resize (unique (q2.begin (), q2.end ()) - q2.begin ());
	PRINT (q1);
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		if (binary_search (q1.begin (), q1.end (), i))
			continue;
		l[i] = (l[i] + r[i]) / 2 + 1;
		mn[i] = min (mn[i], x);
	}
	PRINT (q2);
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		if (binary_search (q2.begin (), q2.end (), i))
			continue;
		r[i] = (l[i] + r[i]) / 2;
		mn[i] = min (mn[i], x);
	}
}

int main () {

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		l[i] = 1, r[i] = n;
		mn[i] = 2e9;
	}
	
	while (1) {
		bool flag = 1;
		for (int i = 1; i <= n; ++i) {
			if (l[i] != r[i]) {
				run ();
				flag = 0;
				break;
			}
		}
		if (flag)
			break;
	}
	
	cout << "-1\n";

	for (int i = 1; i <= n; ++i) {
		cout << mn[i] << " ";
	}
	cout << endl;
		
	fflush (stdout);

	return 0;
}