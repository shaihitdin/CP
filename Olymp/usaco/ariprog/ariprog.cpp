/*
ID: shaihit1
PROG: ariprog
LANG: C++11
*/
#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

const int N = 2e6, inf = 1000000000;
bool u[N];
int n, m;
vector <pair <int, int> > ans;
inline bool cmp (const pair <int, int> &a, const pair <int, int> &b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
    freopen ("ariprog.in", "r", stdin);
    freopen ("ariprog.out", "w", stdout);
    cin >> n >> m;
    int bound = m * m * 3;

    for (int i = 0; i <= m; ++i)
    	for (int j = 0; j <= m; ++j)
    		u[i * i + j * j] = 1;
    for (int i = 0; i <= bound; ++i) {
    	if (u[i]) {
    		for (int j = 1; j <= bound; ++j) {
    			if (i + j * (n - 1) > bound)
    				break;
    			bool flag = 0;
    			for (int k = 1; k < n; ++k) {
    				if (!u[i + j * k]) {
    					flag = 1;
    					break;
    				}
    			}
				if (!flag)
					ans.push_back (make_pair (i, j));
    		}
    	}
    }
    sort (ans.begin(), ans.end(), cmp);
    if (!ans.size())
    	puts ("NONE");
    for (auto it : ans)
    	cout << it.first << " " << it.second << "\n";
    return 0;
}