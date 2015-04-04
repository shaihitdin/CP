#include<iostream>
#include<map>
#include<string>
using namespace std;
map<string,int> mp;
int n,i,x;
string s;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;++i){
		cin>>s;
		x=mp[s];
		if(x==0){
			cout<<"OK\n";
		}
		else{
			cout<<s<<x<<"\n";
		}
		++mp[s];
	}
	return 0;
}