#include<iostream>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
using namespace std;
long long n,l,l1,l2,r,r1,r2,mid,mid1,mid2,b1,b2,middle1,middle2,i,j;
inline long long get(const long long a,const long long b,const long long c){
	if(2*(a*b+c*b+c*a)<=n){
		return a*b*c;
	}
	else
		return -1;
}
inline long long get_c(const long long a,const long long b){
	long long f=(a*b)*2;
	long long s=(b*2);
	long long t=(a*2);
	if(s+t==0){
		return 0;
	}
	if(n>=f)
		return 	(n-f)/(s+t);
	return 0;
}
inline long long get_b(const long long a){
		l1=1,r1=n/a;
		if(r1<=2)
			r1=3;
	while(r1-l1>2){
		mid1=l1+(r1-l1)/3;
		mid2=r1-(r1-l1)/3;
		if(get(a,mid1,get_c(a,mid1))<get(a,mid2,get_c(a,mid2))){
			l1=mid1;
		}
		else{
			r1=mid2;
		}
	}	
	if(l1>=1000)
		l1-=1000;
	else
		l1=1;
	for(i=l1;i<=(r1+1000);++i){
		if(get(a,i,get_c(a,i))>get(a,l1,get_c(a,l1))){
			l1=i;
		}
	}
	return l1;
}
long long mx,mxans1,mxans2,cnt;
int main(){
	freopen("gift.in","r",stdin);
	freopen("gift.out","w",stdout);
	srand(time(0));
		cin>>n;
		l=1;
		r=n;
		while(r-l>2){
			middle1=l+(r-l)/3;
			middle2=r-(r-l)/3;
			b1=get_b(middle1);
			b2=get_b(middle2);
			if(get(middle1,b1,get_c(middle1,b1))<get(middle2,b2,get_c(middle2,b2))){
				l=middle1;
			}
			else{
				r=middle2;
			}
		}
		if(l>=1000)
			l-=1000;
		else
			l=1;
		for(long long i=l;i<=r+1000;++i){
			b1=get_b(i);
			b2=get_b(l);
			if(get(i,b1,get_c(i,b1))>get(l,b2,get_c(l,b2))){
				l=i;
			}	
		}
		b1=get_b(l);
		cout<<get(l,b1,get_c(l,b1))<<"\n"<<l<<" "<<b1<<" "<<get_c(l,b1);
	return 0;
}