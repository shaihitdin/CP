#include<stdio.h>
using namespace std;
int n,t,a[100001],b[100001],x,ans=1000000009,i,palms[100001];
int solve(int n,int t,int* palms){         
        for(i=0;i<n;++i)
            b[i]=b[i-1]+palms[i];
        for(i=1;i<n;++i)
            printf("%d ",b[i]);
        for(i=t;i<=n;++i)
           if(ans>b[i]-b[i-t+1])
              ans=b[i]-b[i-t+1];
          if(ans==1000000009)
            return -1;
          else
            return ans;
}

int main(){
     freopen("in","r",stdin);
     freopen("out","w",stdout);
       scanf("%d %d",&n,&t);
         for(i=1;i<=n;++i)
         scanf("%d",&palms[i]);
           printf("%d",solve(n,t,palms));
return 0;}
