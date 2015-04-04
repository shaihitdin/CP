#include<iostream>
#include<stdio.h>
using namespace std;
const int inf = 1000000009,N=1001;
int t[N*5],t1[N*5],sz=1,n,m,k,p,a[N][N],ans,i,j,sum,pen1,pen2,x;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d %d %d %d",&n,&m,&k,&p);
	while(n>=sz)
	  sz<<=1;
	for(i=1;i<=n;++i)
	   for(j=1;j<=m;++j)
	   	 scanf("%d",&a[i][j]);
	for(i=1;i<=n;++i){
		sum=0;
	   for(j=1;j<=m;++j){
	     sum+=a[i][j];
	   }
	   t[sz+i-1]=sum;
	   t1[sz+i-1]=i;
	}
	for(i=1;i<=m;++i){
		sum=0;
	   for(j=1;j<=n;++j){
	     sum+=a[j][i];
	   }
	   t[sz+i-1+n]=sum;
	   t1[sz+i-1+n]=i+n;
	}
	
	for(i=sz-1;i>=1;--i){
	   if(t[i*2]>t[i*2+1]){
	     t[i]=t[i*2];
	     t1[i]=t1[i*2];
	   }
	   else{
	     t[i]=t[i*2+1];
	     t1[i]=t1[i*2+1];
	   }
	}
	for(i=1;i<=k;++i){
	     if(t1[1]<=n){
	        //pen1 his
             if(t[1]-pen1>=0){
               ans+=t[1]-pen1;
               t[sz+t1[1]-1]-=(p*m);
               pen2+=p;
             }
             else
               break;
	     }
	     else{
	        //pen2 his
             if(t[1]-pen2>=0){
               ans+=t[1]-pen2;
               t[sz+t1[1]-1]-=(p*n);
               pen1+=p;
             }
             else
               break;
	     }
	     x=t1[1];
	     cerr<<x<<"\n";
	     for(x>>=1;x>=1;x>>=1){
	   		if(t[x*2]>t[x*2+1]){
	     		t[x]=t[x*2];
	     		t1[x]=t1[x*2];
	   		}
	   		else{
	     		t[x]=t[x*2+1];
	     		t1[x]=t1[x*2+1];
	   		}	     	
	     }
	}
	printf("%d",ans);
return 0;}