#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
long long fact[15], n, k, i, perm[15], check[15], or_k;
vector<int> v;
string a[15];
int main() {
	freopen("letter.in", "r", stdin);
	freopen("letter.out", "w", stdout);
	fact[0] = 1;
	for (i = 1; i <= 14; ++i)
		fact[i] = fact[i - 1] * i;
	for(n = 1; n <= 10; ++n) {	
		for(i = 1; i <= n; ++i)
			check[i] = i;
		for(or_k = 1; or_k <= fact[n]; ++or_k) {
			k = or_k;
			fact[0] = 1;
			for (i = 1; i <= n; ++i) {
				v.push_back(i);
			}
			--k;
			for (i = 1; i < n; ++i) {		
				perm[i] =	v[k/fact[n-i]];
				v.erase (v.begin() + k/fact[n-i]);
				k -= k / fact[n-i] * fact[n-i];
			}
			perm[n] = v[0];
			v.erase(v.begin());
			/*
			for (i = 1; i <= n; ++i) {
				cerr<<check[i]<<" ";
			}
			cerr<<" check\n";
			for (i = 1; i <= n; ++i) {
				cerr<<perm[i]<<" ";
			}
			cerr<<" perm\n";
			*/
			for (i = 1; i <= n; ++i) {
				if(check[i] != perm[i]) {
					cerr<<"NOT OK " << n <<" "<<or_k;
					return 0;
				}
			}
			next_permutation(check + 1, check + n + 1);
		}
	}
	cerr<<"ALL OK";
	return 0;
}