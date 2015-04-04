#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> ans;
const int N=2000001;
int tmp=0,n,i,cons,a[N],sum;
bool u[N];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	sum=a[n];
	for(i=1;i<n;++i){
		sum-=a[i];
		if(sum<0)	break;
	}
	printf("%d",1+(i-1));
	return 0;
}