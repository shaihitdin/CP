#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;
int n,i;
char x,y;
char ch[256];
string s;
vector<int> ans;
int main(){
	freopen("palindromes.in","r",stdin);
	freopen("palindromes.out","w",stdout);
	cin>>s;
	cin>>n;
	for(i=1;i<=n;++i){
		cin>>x>>y;
		ch[x]=y;
	}
	s="#"+s;
	for(i=1;i<=(s.size()-1)/2;++i){
		if(s[i]==s[s.size()-i])	continue;
		if(ch[s[i]]!=0 && ch[s[i]]==s[s.size()-i]){
			ans.push_back(i);
			continue;
		}
		if(ch[s[s.size()-i]]!=0 && ch[s[s.size()-i]]==s[i]){
			ans.push_back(s.size()-i);
			continue;
		}
		if(ch[s[i]]!=0 && ch[s[s.size()-i]]!=0 && ch[s[i]]==ch[s[s.size()-i]]){
			ans.push_back(i);
			ans.push_back(s.size()-i);
			continue;
		}
		printf("-1");
		return 0;
	}
	cout<<ans.size()<<"\n";
	for(i=0;i<ans.size();++i)
		cout<<ans[i]<<" ";
	return 0;
}