#include<iostream>
using namespace std;
const long long m=(1<<30);
bool bit(int mask,int pos){
   return (mask&(1<<pos));
}
long long a[21],ans;
int i,j,n;
int main(){
       cin>>n;
       for(i=0;i<n;++i)
        cin>>a[i];
        for(i=0;i<(1<<n);++i){
            long long power=1;
               for(j=0;j<n;++j)
                if(bit(i,j))
                 power=(power*a[j])%m;
                   if(ans<power)
                   ans=power;
        }
        cout<<ans;
return 0;}