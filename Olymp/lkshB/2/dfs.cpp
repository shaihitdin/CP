#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
#define mkp make_pair
#define F first
#define S second
const int N=1001;
int l[N],a[N],sz;
int n,m,i,j,k;
bool del[N],u[N][N];
int last[N];
vector<int> ans1,ans2;
bool ansv[N][N];
int tmp[N];
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;++i)
	   scanf("%d",&a[i]);

	for(i=1;i<=m;++i){
	    for(j=i+1;j<=m;++j){
	    		if(a[i]==a[j]){
	    			if(j!=i+1)
	    			 tmp[a[i]]=a[i+1];
	    			 cerr<<a[i]<<" & "<<tmp[a[i]]<<"\n";
	    		   for(k=i+1;k<=j;++k){
	    		     if(tmp[a[i]]<=a[k]){
	    		       ansv[a[i]][a[k]]=1,ansv[a[k]][a[i]]=1;
	    		     }
	    		   }
	    		 break;
	    		}
	    }
	}
	for(i=1;i<=n;++i)
	 for(j=i+1;j<=n;++j)
	 	if(ansv[i][j]){
	  ans1.push_back(i),ans2.push_back(j);
		}
	printf("%d\n",ans1.size());
	for(i=0;i<ans1.size();++i){
	  printf("%d %d\n",ans1[i],ans2[i]);
	}
return 0;}


/*
		cerr<<i<<":";
		bool flag=0;
	    for(j=1;j<=sz;++j){
	       if(l[j]==a[i] && !del[j]){
	          del[j]=1;
	          break;
	       }
	    }
	    for(j=1;j<=sz;++j){
	      if(!del[j] && !u[l[j]][a[i]] && !u[a[i]][l[j]] && last[l[j]]<a[i]){
	      	ans.push_back(mkp(l[j],a[i]));
	      	u[l[j]][a[i]]=1;
	      	last[l[j]]=a[i];
	      }
	    }

	    for(j=i+1;j<=m;++j){
	    	  if(a[i]==a[j]){
	    	    l[++sz]=a[i];
	    	     break;
	    	  }
	    }
	    for(j=1;j<=sz;++j)
	    	 	if(!del[j])
	     cerr<<l[j]<<" ";
	     cerr<<"\n";
*/