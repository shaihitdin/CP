#include<iostream>
#include<set>
#include<stdio.h>
#include<assert.h>
using namespace std;
multiset<int> s;
multiset<int> :: iterator it;
const int N=500001;
int n,cnt[N],ans,i,x;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;++i){
		cin>>x;
		s.insert(x);
		++cnt[x];
	}
	for(i=N-1;i>=1;--i){
		while(cnt[i]>0){
			it=s.end();
			if(it==s.begin()){
				break;
			}
			--it;
			if(*it<i*2){
				ans+=cnt[i];
				break;
			}
			--cnt[i];
			--cnt[*it];
			s.erase(it);
			it=s.find(i);
			s.erase(it);
		}	
	}
	cout<<ans;
	return 0;
}