#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <complex>

#define pb push_back
#define mp make_pair

#define f first
#define s second

using namespace std;

const int N = (int) 1e3 + 7;
const double PI = acos(-1);

typedef long long ll;

struct item
{
    double x,y;
}a[2222222],b[2222222],c[2222222];

ll sz1,sz2,sz,n,m,l,w,ans,x,p[111][11111],q[111][3333];

item mul(item a, item b)
{
    item c;
    c.x=a.x*b.x-a.y*b.y;
    c.y=a.x*b.y+a.y*b.x;
    return c;
}

ll rev(ll x, ll len)
{
    ll ans=0;
    for(ll i=0;i<len;i++)
    {
        ans=ans*2+x%2;
        x/=2;
    }
    return ans;
}

void fft(item a[], ll n,bool ch)
{
    ll lenn=0;
    for(;(1LL<<lenn)<n;lenn++);
    for(ll i=0;i<n;i++)
    {
        ll j=rev(i,lenn);
        if(j>i)
            swap(a[i],a[j]);
    }
    for(ll len=2;len<=n;len*=2)
    {
        ll len2=len/2;
        item w,w1;
        w.x=1,w.y=0;
        w1.x=cos(2*(ch?-1:1)*PI/len),w1.y=sin(2*(ch?-1:1)*PI/len);
        for(ll i=0;i<n;i+=len)
        {
            w.x=1,w.y=0;
            for(ll j=0;j<len2;j++)
            {
                item u=a[i+j];
                item v=mul(a[i+j+len2],w);
                a[i+j].x=u.x+v.x;
                a[i+j].y=u.y+v.y;
                a[i+j+len2].x=u.x-v.x;
                a[i+j+len2].y=u.y-v.y;
                w=mul(w,w1);
            }
        }
    }
    if(ch)
        for(ll i=0;i<n;i++)
            a[i].x/=n;
}

int main() {
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
    #else
        //#define FNAME
        //freopen(FNAME".in", "r", stdin);
        //freopen(FNAME".out", "w", stdout);
    #endif
    cin>>n>>l>>m>>w;
    for(ll i=1;i<=m;i++)
        for(ll j=1;j<=n;j++)
            scanf("%lld",&p[i][j]);
    for(ll i=1;i<=m;i++)
        for(ll j=1;j<=l;j++)
            scanf("%lld",&q[i][j]);

    for(ll x=1;x<=n-l+1;x++){
        for(ll i=1;i<=m;i++)
            for(ll j=1;j<=l;j++)
                sum+=q[i][j]*p[i][j+x-1];
    }
    return 0;
}
