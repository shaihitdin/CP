/*
ID: shaihit1
PROG: transform
LANG: C++
*/
#include <iostream>
#include <stdio.h>
using namespace std;
char a[11][11],b[11][11],c[11][11],f[11][11];
int i,n,j,ans=10;
inline bool check(const char ch1[][11], const char ch2[][11]){
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j){
			if(ch1[i][j]!=ch2[i][j]){
				return 0;
			}
		}
	}
	return 1;
}
int main() {
    freopen("transform.in","r",stdin);
    freopen("transform.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;++i){
    	for(j=1;j<=n;++j){
    		cin>>a[i][j];
    	}
    }
    for(i=1;i<=n;++i){
    	for(j=1;j<=n;++j){
    		cin>>b[i][j];
    	}
    }
    if(check(a,b)){
    	ans=min(ans,6);
    }
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j){
			f[n-j+1][i]=a[i][j];
		}
	}
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j){
			a[i][j]=f[i][j];
		}
	}
	if(check(a,b)){
		ans=min(ans,3);
		 
	}
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j){
			f[n-j+1][i]=a[i][j];
		}
	}
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j){
			a[i][j]=f[i][j];
		}
	}
	if(check(a,b)){
		ans=min(ans,2);		 
	}
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j){
			f[n-j+1][i]=a[i][j];
		}
	}
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j){
			a[i][j]=f[i][j];
		}
	}
	if(check(a,b)){
		ans=min(1,ans);
		 
	}
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j){
			f[n-j+1][i]=a[i][j];
		}
	}
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j){
			a[i][j]=f[i][j];
		}
	}
	for(i=1;i<=n;++i){
		for(j=0;j<n/2;++j){
			swap(a[i][1+j],a[i][n-j]);
		}
	}
	if(check(a,b)){
		ans=min(ans,4);
		 
	}
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j){
			f[n-j+1][i]=a[i][j];
		}
	}
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j){
			a[i][j]=f[i][j];
		}
	}
	if(check(a,b)){
		ans=min(ans,5);
		 
	}
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j){
			f[n-j+1][i]=a[i][j];
		}
	}
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j){
			a[i][j]=f[i][j];
		}
	}
	if(check(a,b)){
		ans=min(ans,5);
		 
	}
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j){
			f[n-j+1][i]=a[i][j];
		}
	}
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j){
			a[i][j]=f[i][j];
		}
	}
	if(check(a,b)){
		ans=min(ans,5);		 
	}
	if(ans==10){
		ans=7;
	}
	cout<<ans<<"\n";
    return 0;
}                    	