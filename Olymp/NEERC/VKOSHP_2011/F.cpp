#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
long long a[100001], n, k, ans;
int main(){
	freopen("shop.in","r",stdin);
	freopen("shop.out","w",stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}	
	sort (a + 1, a + n + 1);
	for (int i = n; i >= 1; --i) {
		for(int j = 1; i >= 1 && j < k; ++j, --i) {
			ans += a[i];
		}
	}
	cout << ans;
	return 0;
}