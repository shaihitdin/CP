#include<iostream>
#include<stdio.h>
#include<set>
#include<algorithm>

using namespace std;
#define mkp make_pair
#define F first
#define S second
const int N=1000001;
int pos[N],a[N],s_pos[N],cnt[N],ans[N],n,m,i,y,x;
set<pair<int,int> > s;
set<pair<int,int> > :: iterator it;

int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)	
		s.insert(mkp(0,i));
//	cerr<<distance(s.begin(), s.lower_bound(mkp(0, 1)))<<"\n";
	for(i=1;i<=n;++i){
		scanf("%d",&a[i]);
		if(a[i]>800000){
			return 0;
		}
		s_pos[a[i]]=i;
		it=(s.upper_bound(mkp(a[i],m)));
		if(it!=s.begin())
			--it;
		x=it->F;
		y=it->S;
//		fprintf(stderr,"%d %d\n",x,y); 
		pos[a[i]]=y;
		s.erase(it);
		s.insert(mkp(a[i],y));
	}
	for(i=1;i<=n;++i){
		printf("%d ",pos[a[i]]);
	}
	printf("\n");
	sort(a+1,a+n+1);
	for(i=n;i>=1;--i){
		ans[s_pos[a[i]]]=++cnt[pos[a[i]]];
	}
	for(i=1;i<=n;++i){
		printf("%d ",ans[i]);
	}          
	return 0;
}