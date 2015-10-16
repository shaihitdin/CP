#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
#define F first
#define S second
int n,i,j,p[100001],x;
pair<string,int> a[100001*2];
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(i=1;i<=2*n;i+=2){
    	cin>>a[i].F>>a[i+1].F;
    	a[i].S=a[i+1].S=i/2+1;
    }
    for(i=1;i<=n;++i){
    	cin>>p[i];
    }
    sort(a+1,a+n+n+1);
/*    
    for(i=1;i<=2*n;++i){
    	cerr<<a[i].F<<" "<<a[i].S<<"\n";
    }
*/
    j=1;
    for(i=1;i<=n+n;++i){
    	if(a[i].S==p[j])	++j;
//    	cerr<<j<<"\n";
    	if(j==n+1)	break;
    }
    if(j==n+1)
    	cout<<"YES";
  	else{
  		cout<<"NO";
  	}
  	return 0;
}