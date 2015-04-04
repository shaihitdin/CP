#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int n,kk,d[101][101][101],i,j,k;
char stck[10001],stck_sz;
string ans;
int main(){
	freopen("num2brackets.in","r",stdin);
	freopen("num2brackets.out","w",stdout);
    scanf("%d%d",&n,&kk);
    n<<=1;
    d[0][0][0]=1;
    for(i=0;i<=n;++i){
        for(j=0;j<=n;++j){
            for(k=0;k<=n;++k){
                d[i+1][j+1][k]+=d[i][j][k];
                d[i+1][j][k+1]+=d[i][j][k];
                if(j!=0)    d[i+1][j-1][k]+=d[i][j][k];
                if(k!=0)    d[i+1][j][k-1]+=d[i][j][k];
            }
        }
    }
    int unc1,unc2,total;
    unc1=unc2=total=0;
    for(i=n;i>=1;--i){
    	cerr<<kk<<"\n";
		if(total<n/2){
    	    if(kk>d[i-1][unc1+1][unc2]){
    	        kk-=d[i-1][unc1+1][unc2];
    	    }
    	    else{
    	        ans+="(";
    	        stck[++stck_sz]='(';
    	        ++total;
    	        ++unc1;
    	        continue;
    	    }
    	}
        if(unc1!=0 && stck[stck_sz]=='('){
            if(kk>d[i-1][unc1-1][unc2]){
                kk-=d[i-1][unc1-1][unc2];
            }
            else{
                ans+=")";
                --stck_sz;
                --unc1;
                continue;
            }
        }
        if(total<n/2){
       		 if(kk>d[i-1][unc1][unc2+1]){
       		     kk-=d[i-1][unc1][unc2+1];
       		 }
       		 else{
       		     ans+="[";
       		     stck[++stck_sz]='[';
       		     ++total;
       		     ++unc2;
       		     continue;
       		 }
       	}
        if(unc2!=0 && stck[stck_sz]=='['){
        	ans+="]";
            --stck_sz;
            --unc2;
        }
    }
    /*
    if(stck[stck_sz]=='('){
        ans+=")";
    }
    else{
        ans+="]";
    }
    */
    cout<<ans;
    return 0;
}