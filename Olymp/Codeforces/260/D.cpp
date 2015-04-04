#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
const int N=100005,root=0;
struct node{
	int nx[26];
	int win,lose;
}t[N]; 
long long n,x,y,d[N],i,tmp,flag[N],ans,sz,k,j;
string s;
inline void dfs(int v){
	if(t[v].lose || t[v].win)
		return;
	for(i=0;i<26;++i){
		if(t[v].nx[i]!=0){
			dfs(t[v].nx[i]);
			t[v].win=(t[v].win || !(t[t[v].nx[i]].win));
			t[v].lose=(t[v].lose || !(t[t[v].nx[i]].lose));
		}
	}		
}
int main(){
	#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    for(i=1;i<=n;++i){
    	cin>>s;
    	tmp=root;
    	for(j=0;j<s.size();++j){
    		int c=s[j]-'a';
    		t[tmp].lose=0;
    		if(t[tmp].nx[c]==0){
    			t[tmp].nx[c]=++sz;
    		}
    		tmp=t[tmp].nx[c];
    	}
    	t[tmp].lose=1;
    }
    dfs(root);
    cerr<<t[root].lose<<" "<<t[root].win<<"\n";
    if(t[root].lose && t[root].win){
		cout<<"First";	
    }
    else if(!t[root].win){
    	cout<<"Second";
    }
    else{
    	if(k&1){
    		cout<<"First";
    	}
    	else{
    		cout<<"Second";
    	}
    }
	return 0;
}