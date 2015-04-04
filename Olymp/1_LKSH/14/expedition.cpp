#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<vector>
using namespace std;
inline int dist(int sx,int sy,int sz,int fx,int fy,int fz){
	return (abs(sx-fx)+abs(sy-fy)+abs(sz-fz));
}
int n,m,q,sx,sy,sz,fx,fy,fz,d,i,j,k;
int connected[101][101][101];
int dx[]={-1,0,1},dy[]={-1,0,1},dz[]={-1,0,1};
vector<int> ans;
int main(){
	freopen("expedition.in","r",stdin);
	freopen("expedition.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&k,&q);
	++q;
	while(--q){
		scanf("%d%d%d%d%d%d",&sx,&sy,&sz,&fx,&fy,&fz);
		connected[sx][sy][sz]+=1;
		while(dist(sx,sy,sz,fx,fy,fz)){
			for(i=0;i<3;++i)
			for(j=0;j<3;++j)
			for(k=0;k<3;++k){
				if(dist(sx,sy,sz,fx,fy,fz)>dist(sx+dx[i],sy+dy[j],sz+dz[k],fx,fy,fz)){
					d=dist(sx+dx[i],sy+dy[j],sz+dz[k],fx,fy,fz);
					sx+=dx[i];
					sy+=dy[j];
					sz+=dz[k];
					connected[sx][sy][sz]+=1;
					if(connected[sx][sy][sz]>1){
							ans.push_back(sx-dx[i]);
							ans.push_back(sy-dy[j]);
							ans.push_back(sz-dz[k]);
							ans.push_back(sx);
							ans.push_back(sy);
							ans.push_back(sz);
					}
					goto ff;
				}
			}
			ff:;
		}
	}
	for(i=0;i<(int)ans.size();i+=6){
		printf("%d %d %d %d %d %d\n",ans[i],ans[i+1],ans[i+2],ans[i+3],ans[i+4],ans[i+5]);
	}
return 0;
}