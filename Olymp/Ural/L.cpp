#include<iostream>
#include<stdio.h>
using namespace std;
int x,y,c;
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	cin>>x>>y>>c;
	if(c-x<=y){
		if(c-x>=0)
			cout<<x<<" "<<c-x;
		if(c-x<0)
			cout<<c<<" "<<0;
		return 0;
	}
	if(c-y<=x){
		if(c-y>=0)
			cout<<y<<" "<<c-y;
		if(c-y<0)
			cout<<c<<" "<<0;
		return 0;
	}
	cout<<"Impossible";
	return 0;
}