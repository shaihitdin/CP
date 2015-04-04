#include<iostream>
#include<stdio.h>
using namespace std;
int n,ans;
inline void rec (int x,int prev) {
	if (!x) {
		++ans;
		return;
	}
	for (int i=1;i<=min(x,prev);++i){
		rec(x-i,i);
	}
}
int main () {
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	scanf("%d",&n);
	rec (n,n);
	printf("%d",ans);
	return 0;
}