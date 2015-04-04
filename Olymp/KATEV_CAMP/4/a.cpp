#include<iostream>
#include<stdio.h>
#include<cassert>
using namespace std;
#ifdef _WIN32
	#define I64d "%lld"
#else
	#define I64d "%I64d";
#endif
const int N=100002;
long long p[3],ans=10000000000000000,pref[3][N],suff[3][N],n,m,a,b,i,j,ans_pref,ans_suff,ans_suff_id,ans_pref_id;
bool suff_f[3][N],pref_f[3][N];
int main(){
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
	scanf(I64d""I64d,&n,&m);
	assert(m<=2);
	scanf(I64d""I64d,&a,&b);
	for(i=0;i<m;++i){
		scanf(I64d,&p[i]);
	}
	for(i=0;i<m;++i){
		for(j=1;j<=p[i];++j){
			pref[i][j]=(a*(p[i]-1))+(b*j);
		}
		for(j=p[i]+1;j<=n;++j){
			pref[i][j]=(a*(p[i]-1)*2)+(j-p[i])*a+(b*j);
			if(min(pref[i][j],(b*j)+(a*(j-p[i])*2)+(a*(p[i]-1)))==(b*j)+(a*(j-p[i])*2)+(a*(p[i]-1))){
				pref[i][j]=(b*j)+(a*(j-p[i])*2)+(a*(p[i]-1));
				pref_f[i][j]=1;
			}
			
		}
		for(j=n;j>=p[i];--j){
			suff[i][j]=(a*(n-p[i]))+(b*(n-j+1));
		}
		for(j=p[i]-1;j>=1;--j){
			suff[i][j]=(a*(n-p[i])*2)+(p[i]-j)*a+(b*(n-j+1));
			if(min(suff[i][j],(a*(n-p[i]))+(p[i]-j)*a*2+(b*(n-j+1)))==(a*(n-p[i]))+(p[i]-j)*a*2+(b*(n-j+1))){
				suff[i][j]=(a*(n-p[i]))+(p[i]-j)*a*2+(b*(n-j+1));
				suff_f[i][j]=1;
			}
			
		}
	}
	if(m==1){
		printf(I64d"\n",min(pref[0][n],suff[0][1]));
		printf(I64d" ",n);
		if(pref[0][n]<suff[0][1]){
			if(pref_f[0][n]==0){
				for(i=p[0];i>=1;--i){
					printf(I64d" ",i);
				}
				for(i=p[0]+1;i<=n;++i){
					printf(I64d" ",i);				
				}
			}
			else{
				for(j=n;j>=1;--j){
					printf(I64d" ",j);
				}						
			}
		
		}
		else{
			if(suff_f[0][1]==0){
				for(i=p[0];i<=n;++i){
					printf(I64d" ",i);
				}
				for(i=p[0]-1;i>=1;--i){
					printf(I64d" ",i);				
				}		
			}
	
			else{
				for(j=1;j<=n;++j){
					printf(I64d" ",j);
				}
			}	
		}
		return 0;
	}
	for(i=0;i<=1;++i){
		for(j=0;j<=n;++j){
			if(max(pref[i][j],suff[i^1][j+1])<ans){
				ans=max(pref[i][j],suff[i^1][j+1]);
				ans_pref=j;
				ans_pref_id=i;
				ans_suff=j+1;
				ans_suff_id=i^1;
			}
		}
	}
	printf(I64d"\n",ans);
	for(i=0;i<m;++i){
		if(ans_pref_id==i){
			printf(I64d" ",ans_pref);
			if(pref_f[i][ans_pref]==0){
				for(j=min(p[i],ans_pref);j>=1;--j){
					printf(I64d" ",j);
				}
				for(j=min(p[i],ans_pref)+1;j<=ans_pref;++j){
					printf(I64d" ",j);			
				}
			}
			
			else{			
				for(j=ans_pref;j>=1;--j){
					printf(I64d" ",j);
				}			
			}
			
		}
		else{
			printf(I64d" ",n-ans_suff+1);
			if(suff_f[i][ans_suff]==0){
				for(j=max(p[i],ans_suff);j<=n;++j){
					printf(I64d" ",j);			
				}
				for(j=max(p[i],ans_pref)-1;j>=ans_suff;--j){
					printf(I64d" ",j);			
				}		
			}
			
			else{			
				for(j=ans_suff;j<=n;++j){
					printf(I64d" ",j);
				}			
			}
			
		}
		printf("\n");
	}
	return 0;
}