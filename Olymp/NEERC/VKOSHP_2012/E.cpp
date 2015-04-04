#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
#define mkp make_pair
#define F first
#define S second
set <pair <int,int> > st[3];
const int N=100001;
int num[N],n,i,pos[N],j,y,cost1,cost2,step,d[N],campus,it,x;
vector<int> a[N];
long long ans=10000000001;
int main(){
	freopen("jediacademy.in","r",stdin);
	freopen("jediacademy.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d%d",pos+i,num+i);
		for(j=1;j<=num[i];++j){
			scanf("%d",&y);
			a[y].push_back(i);
		}
	}
	scanf("%d%d",&cost1,&cost2);
	for(step=1;step<=2;++step){
		for(i=1;i<=2;++i){
			st[i].clear();
		}
		for(i=1;i<=n;++i)
			st[pos[i]].insert(mkp(num[i],i));
		for(i=1;i<=n;++i)
			d[i]=num[i];
		campus=step;
		for(it=1;;++it){
			if(st[campus].size()==0)	break;
			if(st[campus].begin()->F!=0){
				break;
			}
			while(st[campus].size()!=0 && st[campus].begin()->F==0){
				x=st[campus].begin()->S;
				st[campus].erase(st[campus].begin());
				for(i=0;i<a[x].size();++i){
					int to=a[x][i];
					st[pos[to]].erase(mkp(d[to],to));
					--d[to];
					st[pos[to]].insert(mkp(d[to],to));
				}
			}
			campus=((campus==1)?(2):(1));
		}
		//cerr<<it<<"\n";
		/*
		for(i=1;i<=n;++i){
			cerr<<d[i]<<" ";
		}
		*/
		//cerr<<"\n";
		//cerr<<st[1].size()<<" "<<st[2].size()<<"\n";
		if(st[1].size() || st[2].size()){
			continue;
		}
		ans=min(ans,((it-1)*1ll*cost1+(n)*1ll*cost2));
	}
	printf("%I64d",ans);
	return 0;
}