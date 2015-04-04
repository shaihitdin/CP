#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
using namespace std;
#define F first
#define S second
long long fact[15], n, k, i, perm[15], mx;
vector<int> v;
string a[15];
pair<string, int> ab[15];
int main() {
	freopen("letter.in", "r", stdin);
	freopen("letter.out", "w", stdout);
	cin >> n >> k;
	fact[0] = 1;
	for (i = 1; i <= n; ++i) {
		cin >> a[i];
		ab[i].F = a[i];
		ab[i].S = i;
		fact[i] = fact[i - 1] * i;
		v.push_back(i);
		mx = max(mx, a[i].size() * 1ll);
	}
	--k;
	for(i = 1; i <= n; ++i) {
		while((int)ab[i].F.size() < mx) {
			ab[i].F.push_back(char(255));
		}
	}
	sort(ab + 1, ab + n + 1);
	for (i = 1; i < n; ++i) {
		perm[i] =	v[k/fact[n-i]];
		v.erase (v.begin() + k/fact[n-i]);
		k -= k / fact[n-i] * fact[n-i];
	}
	perm[n] = v[0];
	for (i = 1; i <= n; ++i) {
		cout << a[ab[perm[i]].S];
	}
	return 0;
}