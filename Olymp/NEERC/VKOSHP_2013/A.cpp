#include<iostream>
#include<stdio.h>
using namespace std;
int type[1001];
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	cin >> n;
	for (i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	if(a[i]>0){
		puts("0");
		return 0;
	}
	memset(type,-1,sizeof(type));
	for (i = 2; i <= n; ++i) {
		if (i + a[i] > n) {
			puts("0");
			return 0;
		}
		for (j = j - 1; j >= 2; --j) {
			if(j + z[j] >= i - 1){
				if(
			}
		}
	}
	return 0;
}