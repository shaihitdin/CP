#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
#define F first
#define S second
#define mkp make_pair
const int N=1002;
int n,i,a,b,m,k;
int sz[11][N][N];
pair<int,int> p[11][N][N],p1,p2;
pair<int,int> get_dsu(int i,int x,int y){
    if(p[i][x][y].F==x && p[i][x][y].S==y){
    	   return p[i][x][y];
    }
    return p[i][x][y]=get_dsu(i,p[i][x][y].F,p[i][x][y].S);
}
void unite_1(int i,int x1,int y1,int x2,int y2){
    if(sz[i][x2][y2]==0)
    return;
    p1=get_dsu(i,x1,y1);
    p2=get_dsu(i,x2,y2);
     x1=p1.F;
     y1=p1.S;
     x2=p2.F;
     y2=p2.S;
     if(rand()&1){
	   sz[i][x1][y1]+=sz[i][x2][y2];
	   p[i][x2][y2]=get_dsu(i,x1,y1);
	}
	else{
	   sz[i][x2][y2]+=sz[i][x1][y1];
	   p[i][x1][y1]=get_dsu(i,x2,y2);	
	}
	
}
void justdoit(int x1,int y1){
	int x2,y2;

	x2=x1;
	y2=y1-1;
	unite_1(1,x1,y1,x2,y2);
     x2=x1;
	y2=y1+1;
	unite_1(1,x1,y1,x2,y2);

	
	x2=x1-1;
	y2=y1;
	unite_1(2,x1,y1,x2,y2);
	x2=x1+1;
	y2=y1;
	unite_1(2,x1,y1,x2,y2);

	
	x2=x1-1;
	y2=y1-1;
	unite_1(3,x1,y1,x2,y2);
	x2=x1+1;
	y2=y1+1;
	unite_1(3,x1,y1,x2,y2);
	
	
	x2=x1-1;
	y2=y1+1;
	unite_1(4,x1,y1,x2,y2);
	x2=x1+1;
	y2=y1-1;
	unite_1(4,x1,y1,x2,y2);
	
}
int main(){
    freopen("xx.in","r",stdin);
    freopen("xx.out","w",stdout);
    srand(time(0));
       scanf("%d %d %d",&n,&k,&m);
       for(i=1;i<=m;++i){
       	scanf("%d %d",&a,&b);
       	  p[1][a][b]=mkp(a,b);
       	  p[2][a][b]=mkp(a,b);
       	  p[3][a][b]=mkp(a,b);
       	  p[4][a][b]=mkp(a,b);
       	  sz[1][a][b]=1;
       	  sz[2][a][b]=1;
       	  sz[3][a][b]=1;
       	  sz[4][a][b]=1;
       	  justdoit(a,b);
       	  for(int j=1;j<=4;++j)
       	    if(sz[j][get_dsu(j,a,b).F][get_dsu(j,a,b).S]>=k){
       	      printf("%d",i);
       	      return 0;
       	    }
       }
       printf("0");
return 0;}