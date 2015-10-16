#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
const int INF=1000000001;
int i,j,n,m,sum[1001],ans,x,y,a[1001];
bool l[1001][1001],del[1001];
int main(){
	#ifndef ONLINE_JUDGE
     freopen("in","r",stdin);
     freopen("out","w",stdout);
	#endif
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;++i){
	  scanf("%d",&a[i]);
//	  sum[i]=a[i];
	}
	for(i=1;i<=m;++i){
	  scanf("%d %d",&x,&y);
	   l[x][y]=1;
	   l[y][x]=1;
	   sum[x]+=a[y];
	   sum[y]+=a[x];
	}
	for(int step=1;step<n;++step){
		int mn=INF,mn_id=0;
	    for(i=1;i<=n;++i)
	    	if(!del[i] && sum[i]<mn)
	    	     mn=sum[i],mn_id=i;
	    for(i=1;i<=n;++i)
		  cerr<<sum[i]<<" ";
	    cerr<<": "<<mn;
	    ans+=mn;
	    sum[mn_id]=0;
	    del[mn_id]=1;
	    cerr<<"\n";
	    for(i=1;i<=n;++i){
	    	    if(l[mn_id][i]==1){
	    	       sum[i]-=a[mn_id];
	    	       l[mn_id][i]=0;
	    	       l[i][mn_id]=0;
	    	    }
	    }
	}
	printf("%d",ans);
return 0;}