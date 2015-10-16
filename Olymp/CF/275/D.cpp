#include<iostream>
#include<stdio.h>
#include<set>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
#define F first
#define S second
#define mkp make_pair
const long long N=200001;
set<long long> st1[31];
long long n,m,i,l,r,a[N],element,q,pos,j,k,cnt[N];
vector<pair<long long,pair<long long,long long> > > v[N];
inline bool bit(long long mask,long long pos){
    return (mask&(1<<pos));
}
map<long long,long long> mp;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    #endif
    scanf("%I64d%I64d",&n,&m);
    for(i=1;i<=m;++i){
        scanf("%I64d%I64d%I64d",&l,&r,&q);
        v[l].push_back(mkp(1,mkp(q,i)));
        v[r].push_back(mkp(0,mkp(q,i)));
    }
    long long tmp_el=0;
    for(i=1;i<=n;++i){
        sort(v[i].begin(),v[i].end());
        for(j=int(v[i].size())-1;j>=0 && v[i][j].F==1;--j){
            element=v[i][j].S.F;
            pos=v[i][j].S.S;
            cnt[pos]=mp[element];
            for(k=0;k<=30;++k){
                if(bit(element,k)){
                    st1[k].insert(pos);
                }
            }
        }
        tmp_el=0;
        for(k=0;k<=30;++k){
            tmp_el=tmp_el|((!st1[k].empty())<<k);
        }
        a[i]=tmp_el;
        ++mp[tmp_el];
        for(;j>=0;--j){
            element=v[i][j].S.F;
            pos=v[i][j].S.S;
            if(mp[element]-cnt[pos]==0){
                printf("NO");
                return 0;
            }
            for(k=0;k<=30;++k){
                st1[k].erase(pos);
            }
        }       
    }
    printf("YES\n");
    for(i=1;i<=n;++i){
        printf("%I64d ",a[i]);
    }
    return 0;
}