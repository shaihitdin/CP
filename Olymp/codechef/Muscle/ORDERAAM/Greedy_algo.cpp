#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
const int N=201;
struct order{
  int st,num,dl,pen;
}a[N];
bool cmp(order &const l,order &const r){
	return l.pen<r.pen;
}
int n,i,j;
int main(){
		#ifndef ONLINE_JUDGE	
	freopen("in","r",stdin);
	freopen("out","w",stdout);
		#endif
       int t;
       scanf("%d",&t);
       while(t--){
       	int penalty=0;
       	for(i=1;i<=n;++i)
       	  scanf("%d %d %d %d",&a[i].st,&a[i].num,&a[i].dl,&a[i].pen);
       	sort(a+1,a+n+1,cmp);

       }

return 0;}
/*
       	         if(a[i].st<=a[j].dl && a[j].dl<=a[i].dl && a[i].st<=a[j].st && a[j].st<=a[i].dl){
       	           
       	         }
       	         else if(a[i].st<=a[j].st && a[j].st<=a[i].dl){
       	         
       	         }
       	         else if(a[i].st<=a[j].dl && a[j].dl<=a[i].dl){
       	         
       	         }
*/