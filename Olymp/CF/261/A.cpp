#include <iostream>
#include <stdio.h>
using namespace std;
int x[5],y[5];
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	cin>>x[0]>>y[0]>>x[1]>>y[1];
	if(x[0]==x[1]){
		cout<<y[1]<<" "<<	
	}
	else if(y[0]==y[1]){
		cout<<""
	}
	else{
		cout<<x[0]<<" "<<y[1]<<" "<<x[1]<<" "<<y[0];
	}
	return 0;
}