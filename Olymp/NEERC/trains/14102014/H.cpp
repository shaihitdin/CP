#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<map>
using namespace std;
///tmppos 1 - both, 2 - homo, 3 - hetero, 4 - neither
map<int,int> mp;
int tmppos=4,n;
string q;
inline void print(){
	if(tmppos==1){
		cout<<"both";
	}
	if(tmppos==2){
		cout<<"homo";
	}
	if(tmppos==3){
		cout<<"hetero";
	}
	if(tmppos==4){
		cout<<"neither";
	}
}
int main(){
	freopen("dragon.in","r",stdin);
	freopen("dragon.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;++i){
		cin>>q>>x;
		if(q=="insert"){
			if(tmppos==1){
			
			}
			else if(tmppos==2){
				if(mp[x]==1){
					tmppos=1;
				}
			}
			else if(tmppos==3){
				if(mp[x]==1){
					tmppos=1;
				}
			}
			else if(tmppos==4){
				if(mp.size()==1){
					if(mp[x]==1){
						tmppos=2;
					}
					else{
						tmppos=3;
					}
				}
			}
			++mp[x];
		}
		else{
			if(!mp[x]){
				continue;
			}
			if(tmppos==1){
				if(mp[x]
			}
			if(tmppos==2){
			
			}
			if(tmppos==3){
			
			}
			if(tmppos==4){

			}		
			++mp[x];
		}
		print();
	}
	return 0;
}