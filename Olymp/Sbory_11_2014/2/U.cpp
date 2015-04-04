#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>

using namespace std;
const int N = 100001;
int l1[N], l2[N];
int n;
int cnt[N];
int type, a, t;
int l, r;
int main() {
	freopen ("queue.in", "r", stdin);
	freopen ("queue.out", "w", stdout);
	ios_base :: sync_with_stdio(0);
	cin >> n;  
	for (int i = 1; i <= n; ++i) {
		cin >> type >> t >> a;
		if (type == 1) {
			++cnt[a];
		}
		else {
			l1[r] = a;
			l2[r] = t;
			++r;
		}
		for(;l < r; ++l) {
			if (cnt[l1[l]]) {
				cout << t - l2[l] << " ";
				--cnt[l1[l]];
			}
			else
				break;
		}
	}
	while (l < r) {
		cout << -1 << " ";
		++l;
	}
	return 0;
}