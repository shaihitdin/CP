#include<iostream>
#include<stdio.h>
using namespace std;
bool a[256];
char c;
int ans,i;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	getchar();
	while(true){
		c=getchar();
		if(c=='}'){
			break;
		}
		a[c]=1;
		c=getchar();
		if(c==','){
			getchar();
		}
		else{
			break;
		}
	}
	for(i=0;i<256;++i){
		ans+=a[i];
	}
	cout<<ans;
	return 0;
}