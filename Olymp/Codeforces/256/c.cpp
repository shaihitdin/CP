#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
const int N=5001;
int a[N],n,i,j,painted[N],step,mid,l,r,ans;
int mn[N][N];
int st1[N*N],st2[N*N],ste;
//st1 - r , st2 - =
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	
	for(i=1;i<=n;++i)
		mn[i][i]=a[i];
	for(i=1;i<=n;++i){
		for(j=i+1;j<=n;++j){
			mn[i][j]=min(mn[i][j-1],a[j]);
		}
	}
	
	for(i=1;i<=n;++i){
		while(ste>=0 && i>st1[ste])
			--ste;
		ste=max(ste,0);
		painted[i]=st2[ste];
		cerr<<i<<": "<<painted[i]<<" ||| ";
		while(painted[i]!=a[i]){
			l=i;
			r=n;
			while(r!=l){
				if(r-l<=1){
				  if(mn[i][r]>painted[i]){
						l=r;
						break;
					}  
				  else
				  		break;
				}
				mid=(r+l)>>1;
				if(mn[i][mid]>painted[i]){
					l=mid;
				}
				else{
					r=mid;
				}
			}
			if(l==i){
			painted[i]=a[i];
			++ans;
			cerr<<"vertical"<<" "<<i;
			break;
			}
			else{
				++ste;
				st1[ste]=l;
				st2[ste]=mn[i][l];
				ans+=min(mn[i][l]-(painted[i]+1)+1,mn[i][l]);
				cerr<<"horizontal"<<" cut "<<i<<" "<<l<<" "<<mn[i][l]<<"\n";
			}
			if(ste){
				painted[i]=st2[ste];
			}
		}
		cerr<<"||"<<ans<<"||\n";
		cerr<<"\n";
	}
	printf("%d",ans);
return 0;}