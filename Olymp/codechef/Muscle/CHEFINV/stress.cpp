#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<time.h>
#include<stdlib.h>
using namespace std;
#define mkp make_pair
#define F first
#define S second
vector<pair<int,int> > v[21];
long long t[21],a[21],x[21],y[21],priority[21],total,k,q[21],n,m,i,j,q1[21];
pair<long long,long long> b[21];
inline long long get(int r){
	long long ans=0;
	for(int i=r;i>=1;i=(i&(i+1))-1){
		ans+=t[i];		
	}
	return ans;
}
inline void upd(int pos,long long inc){
	for(int i=pos;i<=20;i=i|(i+1)){
		t[i]+=inc;		
	}
	return;
}
void print(long long num){
	printf("%I64d %I64d\n",n,m);
	for(i=1;i<=n;++i){
		printf("%I64d ",a[i]);
	}
	printf("\n");
	for(i=1;i<=m;++i){
		printf("%I64d %I64d\n",x[i],y[i]);
	}
	printf("ERROR FOUND AT %I64d query\n %I64d vs %I64d",num,q[num],q1[num]);
	return;
} 
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	srand(time(0));
	while(true){
	cerr<<"OK";
		n=rand()%10;
		++n;
		m=rand()%(n*2);
		++m;
		for(i=1;i<=n;++i)
			v[i].resize(0);
		for(i=1;i<=n;++i){
			a[i]=rand()%10000;
		}
		for(i=1;i<=20;++i)
			t[i]=0;
		for(i=1;i<=n;++i){
			b[i].F=a[i];
			b[i].S=i;	
		}
		sort(b+1,b+n+1);
		for(i=1;i<=n;++i){
			priority[b[i].S]=priority[b[i-1].S];
			if(b[i].F!=b[i-1].F){
				++priority[b[i].S];
			}
		}
		for(i=1;i<=m;++i){
			x[i]=(rand()%n)+1,y[i]=(rand()%n)+1;
			if(x[i]>y[i]) swap(x[i],y[i]);
			if(a[x[i]]!=a[y[i]]) ++q[i];		
			v[x[i]].push_back(mkp(y[i],i));
			v[y[i]].push_back(mkp(x[i],i));
		}  	
		for(i=1;i<=n;++i){
			long long tmp=(get(20)-get(priority[i]));
			total+=tmp;
			for(j=0;j<v[i].size();++j){
				int pos=v[i][j].F,id=v[i][j].S;
				q[id]-=tmp; q[id]+=(get(20)-get(priority[pos]));
			}
			upd(priority[i],1);
		}
		for(i=1;i<=20;++i)
			t[i]=0;
		for(i=n;i>=1;--i){
			long long tmp=(get(priority[i]-1));
			for(j=0;j<v[i].size();++j){
				long long pos=v[i][j].F,id=v[i][j].S;
				q[id]-=tmp; q[id]+=(get(priority[pos]-1));
			}	
			upd(priority[i],1);
		}
		for(i=1;i<=m;++i){
			swap(a[x[i]],a[y[i]]);
			for(j=1;j<=n;++j){
				for(k=j+1;k<=n;++k){
					if(a[j]>a[k]) ++q1[i];
				}
			}
			swap(a[x[i]],a[y[i]]);
			if(q1[i]!=total+q[i]){
				print(i);
				exit(0);
			}
			q1[i]=0;
		}
	}
	return 0;
}