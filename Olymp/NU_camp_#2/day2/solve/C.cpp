#include "grader.h"
using namespace std;
int n,t,a[100001],z[100001],x,perm,ans=1000000009,i,l,r;
set<int> s;
int solve(int n,int* a){         
   for (i = 1,l=-1,r=0; i < n; ++i) {
      if (z[i-l]+i <= r) z[i] = z[i-l];
      else {
         l = i;
         if (i > r) r = i;
         for (z[i] = r-i; r < n; ++r, ++z[i])
            if (a[r] != a[z[i]]) break;
         r--;
      }
      if(z[i]+i>=n)
       return z[i];
   }   
   /*
       while(!s.empty()){
       x=*s.begin();
	  perm=x;
       bool flag=0;
       for(i=0;i<n;++i,--x){
           if(z[i]>=perm)
              x=perm;
              if(x==0){
               flag=1;
               break;
              }
       }
       if(flag)
        s.erase(s.begin());
       else
        return perm;
    }
   */
    return n;

}
/*
int main(){
     freopen("in","r",stdin);
     freopen("out","w",stdout);
       scanf("%d",&n);
         for(i=0;i<n;++i)
         scanf("%d",&a[i]);
           printf("%d",solve(n,a));
return 0;}
*/