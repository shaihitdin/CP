#include<iostream>
#include<stdio.h>
using namespace std;
long long a[200001*4],s[200001*4],b[200001*4],z[200001*4],n,m,i,l,r,ans;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%I64d%I64d",&n,&m);
	for(i=1;i<=n;++i){
		scanf("%I64d",&a[i]);
	}
	for(i=1;i<=m;++i){
		scanf("%I64d",&b[i]);
	}
	if(m==1){
		printf("%I64d",n);
		return 0;
	}
	for(i=0;i<m-1;++i){
		s[i]=b[i+2]-b[i+1];
//		cerr<<s[i]<<" ";
	}
	s[m-1]=-1000000000000000;
//	cerr<<s[m]<<" ";
	for(i=2;i<=n;++i){
		s[i+m-2]=a[i]-a[i-1];
//		cerr<<s[i+m]<<" ";
	}
/*
	for(i=0;i<n+m-1;++i){
		cerr<<s[i]<<" ";
	}
	cerr<<"\n";
*/
	for(i=1, l=0, r=0; i<m; ++i){
		if(i < r){
			z[i] = min(r-i+1,z[i-l]);
		}
		while(i+z[i] < m && s[z[i]] == s[i+z[i]]) ++z[i];
		if(i+z[i]-1 > r){
			l = i, r = i+z[i]-1;
		}
//		cerr<<z[i]<<" ";
	}
//	cerr<<"\n";
//	cerr<<"\n";
	for(i=m, l=0, r=0; i<n+m-1; ++i){
		if(i < r){
			z[i] = min(r-i+1,z[i-l]);
		}
		while(i+z[i] < n+m-1 && s[z[i]] == s[i+z[i]]) ++z[i];
		if(i+z[i]-1 > r){
			l = i, r = i+z[i]-1;
		}
		if(z[i]==m-1){
			++ans;
		}
//		cerr<<z[i]<<"\n";
//		cerr<<z[i]<<" ";
	}
	printf("%I64d",ans);
return 0;}