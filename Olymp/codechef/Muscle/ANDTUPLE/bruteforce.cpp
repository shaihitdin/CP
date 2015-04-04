#include<iostream>
#include<stdio.h>
using namespace std;
int k,n,j,l,ans,i,q;
int main(){

	freopen("in","r",stdin);
	freopen("out","w",stdout);

	for(int step=0;step<100;++step){
		q=4;
		n=step;		
		ans=0;
		if(q==3){
			for(i=0;i<=n;++i)	
				for(j=0;j<=n-i;++j)
					for(k=0;k<=n-i-j;++k)
						if((((i&j)==j) && ((j&k)==k)) && i+j+k==n){
							++ans;
						}	
		}
		if(q==4){
		    for(i=0;i<=n;++i)
				for(j=0;j<=n-i;++j)
					for(k=0;k<=n-i-j;++k)
						for(l=0;l<=n-i-j-k;++l)
								if((((i&j)==j) && ((j&k)==k) && ((k&l)==l)) && i+j+k+l==n){
								printf("%d %d %d %d\n",i,j,k,l);
								++ans;		
								}
		}
		printf("\nfor %d ans is:%d\n\n",step,ans);
	}
	return 0;
}