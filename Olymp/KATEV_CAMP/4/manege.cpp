#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
#ifdef _WIN32
	#define I64d "%lld"
#else
	#define I64d "%I64d"
#endif
long long n,k,len,m,j,i;
long long arr[1001];
bool u[30001];
vector<long long> ans[1001];
int main(){
	freopen("manege.in","r",stdin);
	freopen("manege.out","w",stdout);
	scanf(I64d""I64d,&m,&n);
	if((((n*(n+1)))%(2*m))!=0){
		printf("NO");
		return 0;
	}
	if(((n*(n+1)))/(2*m)<n){
		printf("NO");
		return 0;
	}

	len=(n*(n+1))/(2*m);
	for(i=n;i>=1;--i){
		bool flag=0;
		if(u[i]==1)	continue;
		for(j=1;j<=m;++j){
			if(arr[j]+i==len){
				flag=1;
				arr[j]=len;
				u[i]=1;
				ans[j].push_back(i);
				break;
//				cerr<<i<<" == "<<1<<"\n";
			}
		}
		if(flag)	continue;
		for(j=1;j<=m;++j){
			if(len-(arr[j]+i)>0 && len-(arr[j]+i) <=n && u[len-(arr[j]+i)]==0 && len-(arr[j]+i)!=i){
				flag=1;
//				cerr<<i<<" & " <<len-(arr[j]+i)<<" == "<<2<<"\n";
				u[i]=1;
				u[len-(arr[j]+i)]=1;
				ans[j].push_back(i);
				ans[j].push_back(len-(arr[j]+i));
				arr[j]=len;
				break;
			}
		}
		if(flag)	continue;
		long long mx=-1,mxpos;
		for(j=1;j<=m;++j){
			if(len-(arr[j])>0 && mx<(len-(arr[j]))){
				mx=(len-(arr[j]));
				mxpos=j;
			}
		}
		if(mx==-1){
			puts("NO");
//			cerr<<i;
			return 0;
		}
//		cerr<<i<<" == "<<3<<"\n";
		ans[mxpos].push_back(i);
		u[i]=1;
		arr[mxpos]+=i;
	}
	puts("YES");
	for(i=1;i<=m;++i){
		printf("%d\n",ans[i].size());
		for(j=0;j<ans[i].size();++j){
			printf(I64d" ",ans[i][j]);
//			cerr<<ans[i][j]<<" ";
		}
		printf("\n");
	}
	return 0;
}