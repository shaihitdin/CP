#include<iostream>
#include<vector>
using namespace std;
vector<int> g[21];
long long a[21],ans,x,y;
int i,j,n,m;

int main(){
       cin>>n>>m;
       for(i=1;i<=m;++i){
          cin>>x>>y;
          g[x].push_back(y);
          g[y].push_back(x);
       }
       for(i=2;i<=n;++i)
         if(g[i].size()<2)
           ++ans;
           cout<<ans;
return 0;}