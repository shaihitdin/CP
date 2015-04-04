#include<iostream>
#include<stdio.h>
using namespace std;
const int N=1000001;
long long q[N*2],ql,qr,q1[N*2],t,n,i,x,ans,balance;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin>>t;
	++t;
	while(--t){
		cin>>n;
		ql=qr=ans=0;
		for(i=1;i<=n;++i){
			cin>>x;
			if(!x)	continue;
			if(!balance){
				q[++qr]=x,q1[qr]=i;			
				balance+=x;
				continue;
			}
			balance+=x;
			if(x>0){
				if(q[qr]>0){
					q[++qr]=x,q1[qr]=i;
				}
				else{
					while(ql-1<=qr && (-q[ql])<=x){
						ans+=(i-q1[ql])*(-q[ql]),
						x+=q[ql];
						cerr<<(i-q1[ql])*(-q[ql])<<" ";
						++ql;	
					}
					if(ql-1>qr && x!=0)	q[++qr]=x,q1[qr]=i;
					else{	
						ans+=(i-q1[ql])*(x);
						cerr<<(i-q1[ql])*(x)<<" ";
						q[ql]+=x;
					}
				}
			}
			else{
				if(q[qr]<0){
					q[++qr]=x,q1[qr]=i;
				}
				else{
					while(ql-1<=qr && q[ql]<=(-x)){
						ans+=(i-q1[ql])*(q[ql]),
						x+=q[ql];
						cerr<<(i-q1[ql])*(q[ql])<<" ";	
						++ql;
					}
					if(ql-1>qr && x!=0)	q[++qr]=x,q1[qr]=i;
					else{	
						ans+=(i-q1[ql])*(-x);
						cerr<<(i-q1[ql])*(-x)<<" ";
						q[ql]+=x;
					}				
				}			
			}
			cerr<<"\n";
		}
		cout<<ans<<"\n";
		cerr<<"\n";
	}
	return 0;
}