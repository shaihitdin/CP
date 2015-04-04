#include<stdio.h>
#include<map>
#include<set>
#include"grader.h"
using namespace std;
#define mkp make_pair
set<int> map1[10000001];
const int N=300001;
struct cmp{
    bool operator()  (const pair<int,int>& lhs ,const pair<int,int>& rhs ) const
    {
         if(map1[lhs].!=rhs.first){
         return lhs.first<rhs.first;
         }
        else
           return *map1[lhs.second].begin() < *map1[rhs.second].begin();
        
    }
};
set<pair<int,int> ,cmp> set1;
int n,i,x,a[N],b[N],m,y;
char q;
void change(int i,int y){
    set1.erase(mkp(map1[b[i]].size(),b[i]));
    map1[b[i]].erase(i);
    if(map1[b[i]].size()){
       set1.insert(mkp(map1[b[i]].size(),b[i]));
    }
    set1.erase(mkp(map1[y].size(),y));
    b[i]=y;
    map1[b[i]].insert(i);
    set1.insert(mkp(map1[b[i]].size(),b[i]));
    
}
int get(){
    return *map1[set1.begin()->second].begin();
}
void init(int n,int* a){
         for(i=0;i<n;++i){
         	  b[i]=a[i];
            map1[b[i]].insert(i);
            }
	    for(i=0;i<n;++i)
	       set1.insert(mkp(map1[b[i]].size(),b[i]));  
return ;}
void finish (void)
{
}
/*
int main(){
         freopen("in","r",stdin);
         freopen("out","w",stdout);
           cin>>n;
            for(i=0;i<n;++i)
             cin>>a[i];
            init(n,a);
            scanf("%d",&m);
            for(int j=0;j<m;++j){
               cin>>q;
               if(q=='?'){
                  for(int k=1;k<=n;++k){
                    cerr<<"a[i] is: "<<k<<" and counter is:"<<map1[k].size()<<" first early insertion is:"<<*map1[k].begin()<<"\n";
                  }
                  cerr<<"\n";
                 cout<<get()<<" counter is:"<<set1.begin()->first<<" & a[i] is:"<<set1.begin()->second<<"\n";

               }
               else{
               	cin>>i>>y;
                 change(i,y);	
               }
            }
return 0;}
  */