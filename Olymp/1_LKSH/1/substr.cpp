#include<iostream>
#include<stdio.h>
#include<string>
#include<map>

using namespace std;

#define mkp make_pair
 
const int N = 11;
const unsigned long long p = 31;

int n, i, j, mid;
string s[N];
unsigned long long h[N][N * 1000], p_pow[N * 1000], tmp, tmp1;
map<unsigned long long, int> mp;
int pos[100001];

inline unsigned long long to_pow(int i, unsigned long long hash) {
	return hash*p_pow[10001-i];
}

int main() {
	freopen("substr.in", "r", stdin);
	freopen("substr.out", "w", stdout);
	ios_base :: sync_with_stdio(false);
	cin >> n;
	for (i = 1; i <= n; ++i)
		cin >> s[i];
	if(n == 1) {
		cout << s[1];
		return 0;
	}
	p_pow[0] = 1;
	for (i = 1; i <= 10001; ++i) 
		p_pow[i] = p_pow[i-1]*p;
	for (i = 1; i <= n; ++i)
		for(j = 0; j < (int)s[i].size(); ++j) {
			h[i][j] = ((s[i][j] - 'a' + 1)*p_pow[j]);
			if(j > 0) h[i][j] += h[i][j-1];
		}
	int l = -1, r = (int)s[1].size();
	while (r - l > 1) {
		int mid = (r + l) / 2;
		bool total_flag = 0;
			for (j = 1; j <= n; ++j) {
				for (int k = 0; k + mid < (int)s[j].size(); ++k) {
					tmp1 = (h[j][k+mid]);
					if (k > 0) tmp1 -= h[j][k-1];
					tmp1 = to_pow(k, tmp1);
					if(mp[tmp1] == j - 1) {
						mp[tmp1] = j;
						if(j == n) {
							pos[mid] = k;
							total_flag = 1;
						}
					}
				}
			}
		if(total_flag)
			l = mid;
		else
			r = mid;
		mp.clear();
	}
	for(i = pos[l]; i <= pos[l] + l; ++i) {
		cout << s[n][i];
	}
	return 0;
}