#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;
#define mkp make_pair
const int N=100001;
map< pair < int, pair< int, int> >, bool> mp;
bool tmp[N];
int l[N][4], i, ans, n;
inline void rec(int step,int v,int v1,int v2){
	if(step == 1){
		for(int i=1;i<=3;++i){
			rec(step+1,v,l[v][i],0);
		}
	}
	if(step == 2){
		for(int i=1;i<=3;++i){
			if(l[v1][i]!=v){
				rec(step+1,v,v1,l[v1][i]);
			}
		}
	}
	if(step == 3){
		for(int i=1;i<=3;++i){
			if(l[v2][i]==v){
				rec(step+1,v,v1,v2);
			}
		}
	}
	if(step == 4){
		for(int i=1;i<=3;++i){
			if(l[v][i]!=v1 && l[v][i]!=v2){
				tmp[l[v][i]]=1;
			}
		}
		for(int i=1;i<=3;++i){
			if(l[v1][i]!=v && l[v1][i]!=v2){
				if(tmp[l[v1][i]]==1)
					return;
				tmp[l[v1][i]]=1;				
			}
		}
		for(int i=1;i<=3;++i){
			if(l[v2][i]!=v && l[v2][i]!=v1){
				if(tmp[l[v2][i]]==1)
					return;
				tmp[l[v2][i]]=1;				
			}		
		}
		if(!mp[mkp(v,mkp(v1,v2))]){
//			cerr<<v<<" "<<v1<<" "<<v2<<"\n";
			++ans;
			mp[mkp(v,mkp(v1,v2))]=1;
			mp[mkp(v,mkp(v2,v1))]=1;
			mp[mkp(v1,mkp(v,v2))]=1;
			mp[mkp(v1,mkp(v2,v))]=1;
			mp[mkp(v2,mkp(v,v1))]=1;
			mp[mkp(v2,mkp(v1,v))]=1;
		}
		for(int i=1;i<=3;++i){
				tmp[l[v][i]]=0;
		}
		for(int i=1;i<=3;++i){
				tmp[l[v1][i]]=0;				
		}
		for(int i=1;i<=3;++i){
				tmp[l[v2][i]]=0;				
		}
		return;
	}
}
int main(){
	freopen("sixheroes.in","r",stdin);
	freopen("sixheroes.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d%d%d",&l[i][1],&l[i][2],&l[i][3]);
	}
	for(int i=1;i<=n;++i){
		rec(1,i,0,0);
	}
	printf("%d",ans);
	return 0;
}