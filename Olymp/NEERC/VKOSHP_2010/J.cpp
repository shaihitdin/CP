#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int a[10],b[10];
int main(){
	freopen("shield.in","r",stdin);
	freopen("shield.out","w",stdout);
	cin>>a[1]>>a[2]>>a[3];
	cin>>b[1]>>b[2]>>b[3];
	sort(a+1,a+4);
	sort(b+1,b+4);
	cout<<a[1]+a[2]+abs((b[3]-a[3]))+b[2]+b[1];
	return 0;
}