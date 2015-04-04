#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
using namespace std;
int n,b[1001],mn,mx,i,t;
int a[1001];
int main(){
		cin>>t;
		cout<<t<<"\n\n";
		while(t--){
       cin>>n;
       cout<<n<<"\n";
       for(i=1;i<=n;++i)
        cin>>a[i];
        sort(a+1,a+n+1);
        next_permutation(a+1,a+n+1);
       for(i=1;i<=n;++i)
        cout<<a[i]<<" ";
        cout<<"\n\n";
	}
return 0;}