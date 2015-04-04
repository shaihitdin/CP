#include <iostream>
using namespace std;
long long n,A,B,C,fact[5001],ans,M=1000000007,i,j;
int main(){
      cin>>n>>A>>B>>C;
      fact[0]=1;
	for(i=1;i<=n;i=i+1)
	fact[i]=(fact[i-1]*i);

	for(i=A;i<=n;++i)
	for(j=B;C<=n-i-j;j=j+1){
	   ans=(ans+((((fact[n]/(fact[n-i]*fact[i])))*((fact[n-i]/(fact[n-i-j]*fact[j]))))));
	}
	cout<<ans%M;
return 0;}