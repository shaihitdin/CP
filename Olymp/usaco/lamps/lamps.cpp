/**
ID: shaihit1
PROG: lamps
LANG: C++11
**/

#include <bits/stdc++.h>

using namespace std;


inline int bit (const int &mask, const int &pos) {
	return (mask >> pos) & 1;
}

int c, q, n;
int u[101];
bool flag;
vector <int> must[2];
vector <vector <int> > ans; 
int main() {
	
	freopen ("lamps.in", "r", stdin);
	freopen ("lamps.out", "w", stdout);
	
	cin >> n >> c;

	for (;;) {
		cin >> q;
		if (q == -1)
			break;
		must[1].push_back (q - 1);
	}
	
	for (;;) {
		cin >> q;
		if (q == -1)
			break;
		must[0].push_back (q - 1);
	}

	vector <int> temp;
	for (int i = 0; i < (1 << 4); ++i) {		
		for (int j = 0; j < n; ++j)
			u[j] = 1;
		int cnt = 0;
		for (int j = 0; j < 4; ++j)
			cnt += bit (i, j);		
		if (cnt > c || (cnt & 1) != (c & 1))
			continue;
		if (bit (i, 0))
			for (int j = 0; j < n; ++j)
				u[j] ^= 1;		
		if (bit (i, 1))
			for (int j = 0; j < n; j += 2)
				u[j] ^= 1;		
		if (bit (i, 2))
			for (int j = 1; j < n; j += 2)
				u[j] ^= 1;
		if (bit (i, 3))
			for (int j = 0; j < n; j += 3)
				u[j] ^= 1;
		bool flag = 0;		
		for (auto it : must[1])
			if (!u[it])
				flag = 1;		
		for (auto it : must[0])
			if (u[it])
				flag = 1;
		if (flag)
			continue;		
		temp.resize (0);		
		for (int j = 0; j < n; ++j)
			temp.push_back (u[j]);
		ans.push_back (temp);
	}
	if (!ans.size()) {
		puts ("IMPOSSIBLE");
		return 0;
	}
	sort (ans.begin(), ans.end());
	unique (ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); ++i) {
		for (auto it : ans[i])
			cout << it;
		cout << "\n";
	}
	return 0;
}
