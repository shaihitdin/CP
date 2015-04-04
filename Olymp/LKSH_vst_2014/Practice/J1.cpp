#include<stdio.h>
#include<string.h>
using namespace std;
char s[1000001],t[1000001],f[1000001];
int i,j,z[1000001],li[1000001],l,r,sz,ssize,tsize,fsize;
int main(){
     freopen("template.in","r",stdin);
     freopen("template.out","w",stdout);
       scanf("%s\n%s",s,t);
       ssize=strlen(s);
       tsize=strlen(t);
       fsize=ssize+1+tsize;
       for(i=0;i<tsize;++i)
         f[i]=t[i];

       f[tsize]=char(32);

       for(i=tsize+1,j=0;j<ssize;++j,++i)
	     f[i]=s[j];
	
      for (i=1, l=-1, r=0; i<fsize; ++i) {
		if (i <= r)
			z[i] =((r-i+1>z[i-l])? z[i-l] : r-i+1);
		while (i+z[i] < fsize && (f[z[i]] == f[i+z[i]] || f[z[i]]=='?'))
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	for(i=tsize+1;i<fsize;++i) if(z[i]==tsize) li[++sz]=i-tsize;
     printf("%d\n",sz);
     for(i=1;i<=sz;++i)printf("%d ",li[i]);
return 0;
}