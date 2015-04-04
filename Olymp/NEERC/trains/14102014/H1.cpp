#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<map>
using namespace std;
///tmppos 1 - both, 2 - homo, 3 - hetero, 4 - neither
map<int,int> mp;
int tmppos=4,n,homo,i,x;
string q;
inline void print(){
	if(tmppos==1){
		cout<<"both\n";
	}
	if(tmppos==2){
		cout<<"homo\n";
	}
	if(tmppos==3){
		cout<<"hetero\n";
	}
	if(tmppos==4){
		cout<<"neither\n";
	}
}
int main(){
	freopen("homo.in","r",stdin);
	freopen("homo.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;++i){
		cin>>q>>x;
		if(q=="insert"){
			++mp[x];
			if(mp[x]==2)
				++homo;
		}
		else{
			if(mp[x]==0){
				mp.erase(x);
			}
			else if(mp[x]==1){
				mp.erase(x);
			}
			else{
				--mp[x];
				if(mp[x]==1)
					--homo;
			}
		}
//		cerr<<mp.size()<<" "<<homo<<"\n";
		if(mp.size()>=2){
			if(homo)	tmppos=1;
			else	tmppos=3;
		}
		else{
			if(homo)	tmppos=2;
			else	tmppos=4;
		}
		print();
	}
	return 0;
}