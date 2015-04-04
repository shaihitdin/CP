#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
vector<int> ans;
const int N=2000001;
int tmp=0,n,x[N],y[N],i,cons;
bool u[N];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d%d",&x[i],&y[i]);
		if(x[i]>((x[i]+y[i])/2))	++tmp;	
	}
	cons=n;
	for(i=1;tmp<=cons/2 && i<n;++i){
		if((x[i]+x[i+1]>(x[i]+x[i+1]+y[i]+y[i+1])/2) && !((x[i]>(x[i]+y[i])/2) && (x[i+1]>(x[i+1]+y[i+1])/2))){
        	--cons;
            ans.push_back(i);
            ans.push_back(i+1);
            ++i;
        }
    }
	if(tmp<=cons/2){
		puts("-1");
		return 0;
	}
	printf("%d\n",ans.size()/2);
	for(i=0;i<ans.size();i+=2){
		printf("%d %d\n",ans[i],ans[i+1]);
	}
	return 0;
}