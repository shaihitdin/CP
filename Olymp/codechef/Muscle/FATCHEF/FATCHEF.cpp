#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
char col[100001],q;
long long ans,n,m,t,i,pos,last;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>t;
	++t;
	while(--t){
		memset(col,0,sizeof(col));
		cin>>n>>m;
		ans=1;
		for(i=1;i<=m;++i){
			cin>>q>>pos;
			col[pos]=q;
		}
		i=1;
        while(int(col[i])==0){
        	++i;	
        }
       	last=i;
       	for(++i;i<=n;++i){
       		if(int(col[i])!=0){
       			if(col[last]==col[i]){
       				last=i;
       				continue;
       			}
       			else{
       				ans=(ans*(i-last))%1000000009;
       				last=i;
       			}
       		}
       	}
       	cout<<ans<<"\n";
	}
	return 0;
} 