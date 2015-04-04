#include<string.h>
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<vector>
using namespace std;
const int N=10001;
int ans_array[N],az,n,m,i,j,x,q[N];
vector<int> v[N];
vector<int> an[4];
int main(){
	freopen("disease.in","r",stdin);
	freopen("disease.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i){
		ans_array[i]=2;
	}
	for(i=1;i<=m;++i){
		for(j=1;j<=n;++j){
			scanf("%d",&x);
			if(x){
				v[i].push_back(j);
			}
		}
		scanf("%d",&q[i]);
		if(q[i]==1){
			int cnt=0;
			for(j=0;j<v[i].size();++j){
				if(ans_array[v[i][j]]==0){
					++cnt;
				}
				else{
					az=v[i][j];
				}
			}
			if(cnt==v[i].size()){
				puts("Incorrect");
				return 0;
			}
			if(v[i].size()-cnt==1){
				ans_array[az]=1;
			}			
		}
		else{
		    for(j=0;j<v[i].size();++j){
		    	if(ans_array[v[i][j]]==1){
					puts("Incorrect");
					return 0;		    	
		    	}
				ans_array[v[i][j]]=0;		    
		    }
		}
	}
	for(i=1;i<=m;++i){
		if(q[i]==1){
			int cnt=0;
			for(j=0;j<v[i].size();++j){
				if(ans_array[v[i][j]]==0){
					++cnt;
				}
				else{
					az=v[i][j];
				}
			}
			if(cnt==v[i].size()){
				puts("Incorrect");
				return 0;
			}
			if(v[i].size()-cnt==1){
				ans_array[az]=1;
			}			
		}
		else{
		    for(j=0;j<v[i].size();++j){
		    	if(ans_array[v[i][j]]==1){
					puts("Incorrect");
					return 0;		    	
		    	}
				ans_array[v[i][j]]=0;		    
		    }
		}
	}
	
	for(i=1;i<=n;++i){
		an[ans_array[i]].push_back(i);
	}
	for(j=0;j<=2;++j){
		printf("%d ",an[j].size());
		for(i=0;i<an[j].size();++i){
			printf("%d ",an[j][i]);
		}
		printf("\n");
	}
	return 0;
}