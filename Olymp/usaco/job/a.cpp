#include <bits/stdc++.h>

using namespace std;


vector <int> v1, v2;

int n, m1, m2;

int a[1000], b[1000], c[1000], d[1000];

int main () {

	freopen ("job.in", "r", stdin);
	freopen ("job.out", "w", stdout);

	cin >> n >> m1 >> m2;

	for (int i = 1; i <= m1; ++i)
		cin >> a[i];
	for (int i = 1; i <= m2; ++i)
		cin >> b[i];


	for (int i = 1; i <= m1; ++i)
		c[i] = a[i];
	for (int i = 1; i <= m2; ++i)
		d[i] = b[i];

   	for (int i = 1; i <= n; ++i) {
   		int mn_pos = 1;
   		for (int j = 1; j <= m1; ++j) {
			if (c[mn_pos] > c[j])
				mn_pos = j;   		
   		}
   		v1.push_back (c[mn_pos]);
   		c[mn_pos] += a[mn_pos];
   		mn_pos = 1;
   		for (int j = 1; j <= m2; ++j) {
   			if (d[mn_pos] > d[j])
   				mn_pos = j;
   		}
   		v2.push_back (d[mn_pos]);
   		d[mn_pos] += b[mn_pos];
   	}

	reverse (v2.begin (), v2.end ());

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = max (ans, v1[i] + v2[i]);
	}
	
	cout << v1.back () << " " << ans;
	
	return 0;
}